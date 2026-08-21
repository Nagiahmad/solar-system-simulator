#include "Physics.hpp"

#include <cmath>

const float G = 100.f;

sf::Vector2f Physics::calculateGravity(
    sf::Vector2f pos1,
    float mass1,
    sf::Vector2f pos2,
    float mass2
)
{
    sf::Vector2f direction = pos2 - pos1;

    float distance =
        std::sqrt(
            direction.x * direction.x +
            direction.y * direction.y
        );

    if (distance < 5.f)
        distance = 5.f;

    direction /= distance;

    float forceMagnitude =
        G * (mass1 * mass2) /
        (distance * distance);

    return direction * forceMagnitude;
}
