#include "Sphere.hpp"
#include <cmath>

RT::Sphere::Sphere()
{
}

RT::Sphere::~Sphere()
{
}

bool RT::Sphere::TestIntersection(const RT::Ray &castRay, qbVector<double> &intPoint, qbVector<double> &localNormal, qbVector<double> &localColor)
{
    qbVector<double> v = castRay.m_lab;
    v.Normalize();

    double b = 2.0 * qbVector<double>::dot(castRay.m_point1, v);
	
	double c = qbVector<double>::dot(castRay.m_point1, castRay.m_point1) - 1.0;
	
	// Testa se ocorre uma interseção
	double intTest = (b*b) - 4.0 * c;
	
	if (intTest > 0.0)
	{
		double numSQRT = sqrtf(intTest);
		double t1 = (-b + numSQRT) / 2.0;
		double t2 = (-b - numSQRT) / 2.0;
		
		/* se t1 ou t2 forem negativos, então parte do objeto
        estará atrás da camera, e portanto vamos ignorá-lo */
		if ((t1 < 0.0) || (t2 < 0.0))
		{
			return false;
		}
		else
		{
			// Determinar qual dos dois pontos de interseção está mais próximo da camera.
			if (t1 < t2)
			{
				intPoint = castRay.m_point1 + (v * t1);
			}
			else
			{
				intPoint = castRay.m_point1 + (v * t2);
			}
		}
		
		return true;
	}
	else
	{
		return false;
	}
	
}
