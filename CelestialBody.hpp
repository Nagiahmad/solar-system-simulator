// =========================
// CelestialBody.hpp
// =========================

#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class CelestialBody
{
protected:
    std::string name;

    float radius;

    sf::CircleShape shape;

public:
    CelestialBody(
        const std::string& name,
        float radius,
        sf::Color color
    );

    virtual void update(float dt) = 0;

    virtual void draw(sf::RenderWindow& window);

    bool isClicked(sf::Vector2f mousePos);

    std::string getName() const;
};