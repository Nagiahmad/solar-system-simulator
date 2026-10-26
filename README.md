# Solar System Simulator v1.3

## Overview

This repository was created as my final vocational project. My teacher gave me the freedom to choose any project, as long as it was developed using C++.

I decided to create a physics simulation of the Solar System, focusing on the orbital movement of the inner planets.

## Features

* View the orbital movement of Mercury, Venus, Earth, and Mars.
* Control the simulation time by speeding it up, slowing it down, pausing, or playing it.
* View information about each planet.

## Tech Stack

* C++
* SFML

## How It Works

The simulation works by continuously updating the positions of the celestial bodies based on the simulation time.

The basic process is:

1. SFML creates and manages the application window.
2. The Sun and planets are created as objects with their respective positions.
3. The Sun and planets are drawn on the screen.
4. As the simulation time progresses, the positions of the planets change.
5. The updated positions are rendered again, creating the appearance of orbital movement.

## Project Structure

```text
/assets
    arialceb.ttf
CelestialBody.cpp
CelestialBody.hpp
Fct1.3.exe
Game.cpp
Game.hpp
Physics.cpp
Physics.hpp
Planet.cpp
Planet.hpp
```

## Getting Started

You need a C++ compiler and the required dependencies to run this project. I developed and tested this project using **MSYS2 MinGW64**.

### Running the Application

1. Open the MinGW64 terminal.

2. Navigate to the folder where the program is stored.

   ```bash
   cd C:/Download/sss
   ```

3. Run the executable:

   ```bash
   ./Fct1.3.exe
   ```

## Learning / What I Learned

This project helped me improve both my C++ programming skills and my understanding of how a simulation works.

Through this project, I learned:

• How to apply object-oriented programming to represent planets and other celestial bodies.
 • How to use SFML to create a window, draw objects, handle input, and update a simulation in real time.
• How to separate simulation time from real time, allowing the simulation to be sped up, slowed down, paused, or resumed.
• How to organize physics calculations separately from the rendering logic.
• How to break a larger problem into smaller components and gradually turn a physics concept into a working program.

## Roadmap

*This section will be updated.*

* [x] Basic Solar System simulation
* [x] Planet orbital movement
* [x] Time control
* [x] Planet information
* [ ] ...

## Screenshots

*Screenshots will be added later.*

## License

...
