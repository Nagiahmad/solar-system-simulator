#pragma once

#include "CelestialBody.hpp"

class Planet : public CelestialBody
{
private:
    float mass;

    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;

public:
    Planet(
        const std::string& name,
        float radius,
        float mass,
        sf::Color color,
        sf::Vector2f startPosition,
        sf::Vector2f startVelocity
    );

    void applyForce(sf::Vector2f force);

    void update(float dt) override;

    sf::Vector2f getPosition() const;

    sf::Vector2f getVelocity() const;

    float getMass() const;

    float getGravity() const;
};
