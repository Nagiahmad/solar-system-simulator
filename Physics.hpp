#pragma once

#include <SFML/System.hpp>

namespace Physics
{
    sf::Vector2f calculateGravity(
        sf::Vector2f pos1,
        float mass1,
        sf::Vector2f pos2,
        float mass2
    );
}
