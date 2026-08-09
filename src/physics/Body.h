#pragma once

class Body {
public:
    Body(double mass, double radius);

    void update();

    void setPosition(double x, double y);

    double getX() const;
    double getY() const;
    double getRadius() const;
    double getMass() const;
    double getVelocityX() const;
    double getVelocityY() const;




private:
    double mass; // kg
    double radius; // m

    double x; // m
    double y; // m

    double velocityX; // m/s
    double velocityY; // m/s
};