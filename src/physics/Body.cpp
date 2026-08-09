#include "Body.h"

Body::Body(double mass, double radius)
{
    this->mass = mass;
    this->radius = radius;

    x = 0.0;
    y = 0.0;

    velocityX = 0.0;
    velocityY = 0.0;
}

void Body::update(){
}

void Body::setPosition(double x, double y){
    this->x = x;
    this->y = y;
}

double Body::getMass() const
{
    return mass;
}

double Body::getRadius() const
{
    return radius;
}

double Body::getX() const
{
    return x;
}

double Body::getY() const
{
    return y;
}

double Body::getVelocityX() const
{
    return velocityX;
}

double Body::getVelocityY() const
{
    return velocityY;
}