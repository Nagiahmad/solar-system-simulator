#include "Planet.hpp"

Planet::Planet(
    const std::string& name,
    float radius,
    float mass,
    sf::Color color,
    sf::Vector2f startPosition,
    sf::Vector2f startVelocity
)
    : CelestialBody(name, radius, color),
      mass(mass),
      position(startPosition),
      velocity(startVelocity)
{
    shape.setPosition(position);
}

void Planet::applyForce(sf::Vector2f force)
{
    acceleration += force / mass;
}

void Planet::update(float dt)
{
    velocity += acceleration * dt;

    position += velocity * dt;

    shape.setPosition(position);

    acceleration = sf::Vector2f(0.f, 0.f);
}

sf::Vector2f Planet::getPosition() const
{
    return position;
}

sf::Vector2f Planet::getVelocity() const
{
    return velocity;
}

float Planet::getMass() const
{
    return mass;
}

float Planet::getGravity() const
{
    return mass / (radius * radius);
}
