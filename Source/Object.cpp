#include "Object.hpp"
#include <math.h>

#define EPSILON 1e-21f;

RT::Object::Object(){}

RT::Object::~Object(){}

bool RT::Object::TestIntersection(const Ray &castRay, qbVector<double> &intPoint, qbVector<double> &localNormal, qbVector<double> &localColor)
{
	return false;
}

bool RT::Object::CloseEnough(const double f1, const double f2)
{
	return fabs(f1-f2) < EPSILON;
}
