#pragma once

class Camera
{
public:
    Camera(int screenWidth, int screenHeight);

    double worldToScreenX(double worldX) const;
    double worldToScreenY(double worldY) const;

    double worldToScreenDistance(double distance) const;
    double worldToScreenRadius(double radius) const;

    void zoomIn();
    void zoomOut();

    void increaseVisualScale();
    void decreaseVisualScale();

    double getMetresPerPixel() const;
    double getVisualScale() const;

private:
    int screenWidth;
    int screenHeight;

    // How many metres are represented by one pixel
    double metresPerPixel;

    // Visual multiplier for the size of bodies
    double visualScale;
};