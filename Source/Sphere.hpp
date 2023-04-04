#ifndef SPHERE_H
#define SPHERE_H

#include "Object.hpp"

namespace RT
{
    class Sphere : public Object
    {
        public:
            Sphere();

            virtual ~Sphere() override;

            virtual bool TestIntersection(const RT::Ray &castRay, qbVector<double> &intPoint, qbVector<double> &localNormal, qbVector<double> &localColor);
        private:
            
    };
}

#endif