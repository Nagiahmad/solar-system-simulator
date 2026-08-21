#include "Game.hpp"
#include "Physics.hpp"

#include <iostream>
#include <optional>


Game::Game()
    : window(
        sf::VideoMode({1280, 720}),
        "Felicette Project"
    )
{
    window.setFramerateLimit(60);

    view = window.getDefaultView();

    // =========================
    // SUN
    // =========================

    sunPosition = sf::Vector2f(640.f, 360.f);

    sun.setRadius(20.f);
    sun.setOrigin({20.f, 20.f});
    sun.setPosition(sunPosition);
    sun.setFillColor(sf::Color::Yellow);


    // =========================
    // FONT
    // =========================

    if (!font.openFromFile("assets/arialceb.ttf"))
    {
        std::cout << "Failed to load font\n";
    }


    // =========================
    // SOLAR SYSTEM
    // =========================

    createSolarSystem();


    // =========================
    // UI
    // =========================

    setupUI();
}


// ============================================================
// SOLAR SYSTEM
// ============================================================

void Game::createSolarSystem()
{
    planets.emplace_back(
        "Mercury",
        4.f,
        100.f,
        sf::Color(180, 180, 180),
        sf::Vector2f(740.f, 360.f),
        sf::Vector2f(0.f, -220.f)
    );

    planets.emplace_back(
        "Venus",
        7.f,
        200.f,
        sf::Color(255, 180, 80),
        sf::Vector2f(820.f, 360.f),
        sf::Vector2f(0.f, -180.f)
    );

    planets.emplace_back(
        "Earth",
        8.f,
        250.f,
        sf::Color::Blue,
        sf::Vector2f(920.f, 360.f),
        sf::Vector2f(0.f, -160.f)
    );

    planets.emplace_back(
        "Mars",
        6.f,
        180.f,
        sf::Color::Red,
        sf::Vector2f(1040.f, 360.f),
        sf::Vector2f(0.f, -140.f)
    );
}


// ============================================================
// UI SETUP
// ============================================================

void Game::setupUI()
{
    // --------------------------------------------------------
    // HEADER
    // --------------------------------------------------------

    headerPanel.setSize({1280.f, 70.f});
    headerPanel.setPosition({0.f, 0.f});
    headerPanel.setFillColor(
        sf::Color(15, 18, 25, 235)
    );

    headerPanel.setOutlineThickness(1.f);
    headerPanel.setOutlineColor(
        sf::Color(70, 75, 90)
    );


    titleText.setString("FCT 1.3");
    titleText.setCharacterSize(24);
    titleText.setFillColor(sf::Color::White);
    titleText.setPosition({25.f, 12.f});


    subtitleText.setString("SOLAR SYSTEM SIMULATOR");
    subtitleText.setCharacterSize(12);
    subtitleText.setFillColor(
        sf::Color(150, 155, 170)
    );
    subtitleText.setPosition({27.f, 43.f});


    statusText.setString("SIMULATION");
    statusText.setCharacterSize(16);
    statusText.setFillColor(
        sf::Color(100, 220, 140)
    );
    statusText.setPosition({1080.f, 25.f});


    // --------------------------------------------------------
    // PLANET INFO PANEL
    // --------------------------------------------------------

    infoPanel.setSize({310.f, 300.f});
    infoPanel.setPosition({20.f, 90.f});

    infoPanel.setFillColor(
        sf::Color(15, 18, 25, 225)
    );

    infoPanel.setOutlineThickness(1.f);
    infoPanel.setOutlineColor(
        sf::Color(70, 75, 90)
    );


    infoTitleText.setString("PLANET INFORMATION");
    infoTitleText.setCharacterSize(16);
    infoTitleText.setFillColor(
        sf::Color(120, 190, 255)
    );
    infoTitleText.setPosition({40.f, 110.f});


    infoText.setCharacterSize(14);
    infoText.setFillColor(
        sf::Color(220, 225, 235)
    );
    infoText.setPosition({40.f, 145.f});


    // --------------------------------------------------------
    // CONTROL PANEL
    // --------------------------------------------------------

    controlPanel.setSize({310.f, 150.f});
    controlPanel.setPosition({20.f, 530.f});

    controlPanel.setFillColor(
        sf::Color(15, 18, 25, 225)
    );

    controlPanel.setOutlineThickness(1.f);
    controlPanel.setOutlineColor(
        sf::Color(70, 75, 90)
    );


    controlTitleText.setString("SIMULATION CONTROL");
    controlTitleText.setCharacterSize(16);
    controlTitleText.setFillColor(
        sf::Color(120, 190, 255)
    );
    controlTitleText.setPosition({40.f, 550.f});


    controlText.setCharacterSize(13);
    controlText.setFillColor(
        sf::Color(190, 195, 205)
    );
    controlText.setPosition({40.f, 580.f});


    // --------------------------------------------------------
    // FOOTER
    // --------------------------------------------------------

    footerText.setString(
        "W A S D  Camera     SCROLL  Zoom     SPACE  Pause"
    );

    footerText.setCharacterSize(12);

    footerText.setFillColor(
        sf::Color(130, 135, 150)
    );

    footerText.setPosition({25.f, 690.f});
}


// ============================================================
// UI UPDATE
// ============================================================

void Game::updateUI()
{
    // --------------------------------------------------------
    // STATUS
    // --------------------------------------------------------

    if (timeManager.isPaused())
    {
        statusText.setString("?  PAUSED");

        statusText.setFillColor(
            sf::Color(255, 190, 80)
        );
    }
    else
    {
        statusText.setString("?  SIMULATION");

        statusText.setFillColor(
            sf::Color(100, 220, 140)
        );
    }


    // --------------------------------------------------------
    // CONTROL INFO
    // --------------------------------------------------------

    controlText.setString(
        "Time Scale     x" +
        std::to_string(
            timeManager.getTimeScale()
        ) +

        "\n\n"
        "SPACE          Pause / Resume"
        "\n"
        "UP             Speed Up"
        "\n"
        "DOWN           Slow Down"
    );


    // --------------------------------------------------------
    // PLANET INFO
    // --------------------------------------------------------

    if (!selectedPlanet)
    {
        infoText.setString(
            "No planet selected."
            "\n\n"
            "Click a planet to view"
            "\n"
            "its information."
        );

        return;
    }


    sf::Vector2f pos =
        selectedPlanet->getPosition();

    sf::Vector2f vel =
        selectedPlanet->getVelocity();


    std::string info =
        selectedPlanet->getName() +

        "\n"
        "--------------------------"

        "\n\n"
        "Mass"
        "\n" +
        std::to_string(
            (int)selectedPlanet->getMass()
        ) +

        "\n\n"
        "Gravity"
        "\n" +
        std::to_string(
            selectedPlanet->getGravity()
        ) +

        "\n\n"
        "Position"
        "\n"
        "X: " +
        std::to_string((int)pos.x) +

        "\n"
        "Y: " +
        std::to_string((int)pos.y) +

        "\n\n"
        "Velocity"
        "\n"
        "X: " +
        std::to_string((int)vel.x) +

        "\n"
        "Y: " +
        std::to_string((int)vel.y);


    infoText.setString(info);
}


// ============================================================
// UI DRAW
// ============================================================

void Game::drawUI()
{
    window.draw(headerPanel);

    window.draw(titleText);
    window.draw(subtitleText);
    window.draw(statusText);


    window.draw(infoPanel);

    window.draw(infoTitleText);
    window.draw(infoText);


    window.draw(controlPanel);

    window.draw(controlTitleText);
    window.draw(controlText);


    window.draw(footerText);
}


// ============================================================
// GAME LOOP
// ============================================================

void Game::run()
{
    sf::Clock clock;

    while (window.isOpen())
    {
        float dt =
            clock.restart().asSeconds();

        processEvents();

        update(dt);

        render();
    }
}


// ============================================================
// EVENTS
// ============================================================

void Game::processEvents()
{
    while (const std::optional event =
        window.pollEvent())
    {
        // ----------------------------------------------------
        // WINDOW CLOSE
        // ----------------------------------------------------

        if (event->is<sf::Event::Closed>())
        {
            window.close();
        }


        // ----------------------------------------------------
        // ZOOM
        // ----------------------------------------------------

        if (const auto* wheelScrolled =
            event->getIf<
                sf::Event::MouseWheelScrolled>())
        {
            if (wheelScrolled->delta > 0)
            {
                view.zoom(0.9f);
            }
            else
            {
                view.zoom(1.1f);
            }
        }


        // ----------------------------------------------------
        // PLANET CLICK
        // ----------------------------------------------------

        if (const auto* mousePressed =
            event->getIf<
                sf::Event::MouseButtonPressed>())
        {
            if (mousePressed->button ==
                sf::Mouse::Button::Left)
            {
                sf::Vector2f mouseWorld =
                    window.mapPixelToCoords(
                        mousePressed->position,
                        view
                    );


                for (auto& planet : planets)
                {
                    if (planet.isClicked(mouseWorld))
                    {
                        selectedPlanet = &planet;
                    }
                }
            }
        }


        // ----------------------------------------------------
        // TIME CONTROL
        // ----------------------------------------------------

        if (const auto* keyPressed =
            event->getIf<
                sf::Event::KeyPressed>())
        {
            if (keyPressed->scancode ==
                sf::Keyboard::Scancode::Space)
            {
                timeManager.togglePause();
            }


            if (keyPressed->scancode ==
                sf::Keyboard::Scancode::Up)
            {
                timeManager.speedUp();
            }


            if (keyPressed->scancode ==
                sf::Keyboard::Scancode::Down)
            {
                timeManager.slowDown();
            }
        }
    }
}


// ============================================================
// UPDATE
// ============================================================

void Game::update(float dt)
{
    // UI harus tetap diperbarui
    // meskipun simulasi sedang pause.

    updateUI();


    // --------------------------------------------------------
    // PAUSE
    // --------------------------------------------------------

    if (timeManager.isPaused())
        return;


    dt *= timeManager.getTimeScale();


    // --------------------------------------------------------
    // CAMERA
    // --------------------------------------------------------

    float cameraSpeed = 500.f * dt;


    if (sf::Keyboard::isKeyPressed(
        sf::Keyboard::Key::W))
    {
        view.move({
            0.f,
            -cameraSpeed
        });
    }


    if (sf::Keyboard::isKeyPressed(
        sf::Keyboard::Key::S))
    {
        view.move({
            0.f,
            cameraSpeed
        });
    }


    if (sf::Keyboard::isKeyPressed(
        sf::Keyboard::Key::A))
    {
        view.move({
            -cameraSpeed,
            0.f
        });
    }


    if (sf::Keyboard::isKeyPressed(
        sf::Keyboard::Key::D))
    {
        view.move({
            cameraSpeed,
            0.f
        });
    }


    // --------------------------------------------------------
    // PHYSICS
    // --------------------------------------------------------

    for (auto& planet : planets)
    {
        sf::Vector2f gravity =
            Physics::calculateGravity(
                planet.getPosition(),
                planet.getMass(),
                sunPosition,
                sunMass
            );


        planet.applyForce(gravity);
    }


    for (auto& planet : planets)
    {
        planet.update(dt);
    }
}


// ============================================================
// RENDER
// ============================================================

void Game::render()
{
    window.clear(
        sf::Color(5, 7, 12)
    );


    // --------------------------------------------------------
    // SOLAR SYSTEM
    // --------------------------------------------------------

    window.setView(view);


    window.draw(sun);


    for (auto& planet : planets)
    {
        planet.draw(window);
    }


    // --------------------------------------------------------
    // UI
    // --------------------------------------------------------

    window.setView(
        window.getDefaultView()
    );


    drawUI();


    window.display();
}
