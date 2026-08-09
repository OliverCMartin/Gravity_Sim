#include "Camera.h"

Camera::Camera(int screenWidth, int screenHeight)
{
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;

    // Initially, one pixel represents 1 billion metres
    metresPerPixel = 1.0e9;

    // Physical sizes are initially correct at 500 x true astronomical scale
    visualScale = 500.0;
}

double Camera::worldToScreenX(double worldX) const
{
    return (worldX / metresPerPixel) + (screenWidth / 2.0);
}

double Camera::worldToScreenY(double worldY) const
{
    return (worldY / metresPerPixel) + (screenHeight / 2.0);
}

double Camera::worldToScreenDistance(double distance) const
{
    return distance / metresPerPixel;
}

void Camera::zoomIn()
{
    metresPerPixel /= 1.2;
}

void Camera::zoomOut()
{
    metresPerPixel *= 1.2;
}

double Camera::worldToScreenRadius(double radius) const
{
    return (radius / metresPerPixel) * visualScale;
}

void Camera::increaseVisualScale()
{
    visualScale *= 1.2;
}

void Camera::decreaseVisualScale()
{
    visualScale /= 1.2;
}

double Camera::getMetresPerPixel() const
{
    return metresPerPixel;
}

double Camera::getVisualScale() const
{
    return visualScale;
}