#ifndef OBJECT_H
#define OBJECT_H

#include "./qbLinAlg-main/qbVector.h"
#include "ray.hpp"

namespace RT
{
    class Object
    {
        public:
            //Construtor e destrutor do objeto.
            Object();
            virtual ~Object();

            //Função que testa a interseção do raio com o objeto.
            virtual bool TestIntersection(const Ray &castRay, qbVector<double> &intPoint, qbVector<double> &localNormal, qbVector<double> &localColor);
    
            //Função que verifica se dois floats são suficientemente próximos a ponto de serem aproximados.
            bool CloseEnough(const double f1, const double f2);

        public: 
            //Estrutura para armazenar as cores do objeto.
            qbVector<double> m_baseColor{3};
    };
}

#endif