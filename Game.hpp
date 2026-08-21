#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Planet.hpp"
#include "TimeManager.hpp"

class Game
{
private:
    // =========================
    // WINDOW & CAMERA
    // =========================

    sf::RenderWindow window;
    sf::View view;


    // =========================
    // SOLAR SYSTEM
    // =========================

    std::vector<Planet> planets;

    sf::Vector2f sunPosition;
    float sunMass = 50000.f;

    sf::CircleShape sun;


    // =========================
    // GAME SYSTEM
    // =========================

    TimeManager timeManager;

    Planet* selectedPlanet = nullptr;


    // =========================
    // UI
    // =========================

    sf::Font font;

    // Header
    sf::RectangleShape headerPanel;

    sf::Text titleText{font};
    sf::Text subtitleText{font};
    sf::Text statusText{font};


    // Planet information
    sf::RectangleShape infoPanel;

    sf::Text infoTitleText{font};
    sf::Text infoText{font};


    // Simulation controls
    sf::RectangleShape controlPanel;

    sf::Text controlTitleText{font};
    sf::Text controlText{font};


    // Footer
    sf::Text footerText{font};


private:
    void processEvents();

    void update(float dt);

    void render();

    void createSolarSystem();


    // =========================
    // UI FUNCTIONS
    // =========================

    void setupUI();

    void updateUI();

    void drawUI();


public:
    Game();

    void run();
};
