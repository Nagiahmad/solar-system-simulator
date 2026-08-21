// =========================
// CelestialBody.cpp
// =========================

#include "CelestialBody.hpp"

#include <cmath>

CelestialBody::CelestialBody(
    const std::string& name,
    float radius,
    sf::Color color
)
    : name(name), radius(radius)
{
    shape.setRadius(radius);

    shape.setOrigin({radius, radius});

    shape.setFillColor(color);
}

void CelestialBody::draw(sf::RenderWindow& window)
{
    window.draw(shape);
}

bool CelestialBody::isClicked(sf::Vector2f mousePos)
{
    sf::Vector2f pos = shape.getPosition();

    float dx = mousePos.x - pos.x;
    float dy = mousePos.y - pos.y;

    float distance = std::sqrt(dx * dx + dy * dy);

    return distance <= radius;
}

std::string CelestialBody::getName() const
{
    return name;
}