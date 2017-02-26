#include "perspective_camera.h"

PerspectiveCamera::PerspectiveCamera( void )
{}

PerspectiveCamera::PerspectiveCamera( const float min_x,
                                        const float max_x,
                                        const float min_y,
                                        const float max_y,
                                        const glm::ivec2 &resolution,
                                        const glm::vec3 &position,
                                        const glm::vec3 &up_vector,
                                        const glm::vec3 &look_at ) :
        Camera::Camera{ resolution, 
                        position,
                        up_vector,
                        look_at },
        min_x_{ min_x },
        max_x_{ max_x },
        min_y_{ min_y },
        max_y_{ max_y }
{}

Ray PerspectiveCamera::getWorldSpaceRay( const glm::vec2 &pixel_coord ) const
{
    glm::vec3 a(max_x_ - min_x_, 0.0f, 0.0f);
    glm::vec3 b(0.0f, min_y_ - max_y_, 0.0f);
    glm::vec3 c(min_x_, max_y_, - 2.0f);
    float u = (pixel_coord[0] + 0.5f)/ static_cast<float>( resolution_[0] ) ;
    float v = (pixel_coord[1] + 0.5f) / static_cast<float>( resolution_[1] );
    glm::vec3 s = c + u*a + v*b;
    glm::vec3 origin{ 0.0f, 0.0f, 0.0f };
    
     return Ray{ onb_.getBasisMatrix() * origin + position_, 
                glm::normalize( onb_.getBasisMatrix() * s - origin ) };
}