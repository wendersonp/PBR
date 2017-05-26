#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include <glm/glm.hpp>
#include "primitive.h"
#include "intersection_record.h"
#include "ray.h"

#include <algorithm>

class Triangle : public Primitive
{
    bool flipNormal_;
public:

    Triangle( void );

    Triangle( const glm::vec3 &point1, const glm::vec3 &point2, const glm::vec3 &point3,  
    Material* material, bool flipNormal = false);

    bool intersect( const Ray &ray,
                    IntersectionRecord &intersection_record ) const;

    glm::vec3 point1_ = { -1.0f, 0.0f, 0.0f };
    
    glm::vec3 point2_ = { 1.0f, 0.0f, 0.0f };

    glm::vec3 point3_ = { 0.0f, 1.0f, 0.0f };

  //  glm::vec3 min_components(const glm::vec3 &vecA, const glm::vec3 &vecB);

 //   glm::vec3 max_components(const glm::vec3 &vecA, const glm::vec3 &vecB);
     BBox getAABB( void ) const;
    
//private:

    //static const float kIntersectionTestEpsilon_;
};


#endif /* SPHERE_H_ */

