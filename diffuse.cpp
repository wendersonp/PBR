#include "diffuse.h"

Diffuse::Diffuse(glm::vec3 emittance, glm::vec3 reflectance): reflectance_(reflectance/(float)M_PI){
	emittance_ = emittance;
}




Ray Diffuse::getRefflectedRay(glm::vec3 normal, glm::vec3 position){
    float theta, phi, r1, r2;
    ONB onb;
    r1 = rand() / (float)RAND_MAX;
    r2 = rand() / (float)RAND_MAX;
    //phi = acos(1 - dist_phi(generator));
    //theta = dist_theta(generator);
    phi = glm::acos(1 - r1);
    theta = 2.0f * float(M_PI) * r2;

    glm::vec3 newRayDirection( sin(phi)*cos(theta), cos(phi), sin(phi) * sin(theta));
	    
    onb.setFromV(normal);
    newRayDirection = glm::normalize(onb.getBasisMatrix() * newRayDirection);

     return Ray(position + (normal * 0.001f), newRayDirection);
}

glm::vec3 Diffuse::getBRDF(){
	return reflectance_;
}
