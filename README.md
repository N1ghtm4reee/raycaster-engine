# Raycaster Engine

Welcome to the Raycaster Engine project! This project is an implementation of a raycasting engine similar to the ones used in classic games like Wolfenstein 3D and Doom.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Introduction

Raycasting is a rendering technique used to create a 3D perspective in 2D games by casting rays from the player's viewpoint and determining the distance to objects in the game world. This project aims to recreate the feel and functionality of early 3D games using raycasting.

## Features

- **Efficient Raycasting**: Implemented using optimized algorithms to ensure smooth performance.
- **Texture Mapping**: Support for textured walls and floors to enhance visual realism.
- **Player Movement**: Basic player controls for moving and looking around the game world.
- **Collision Detection**: Prevents the player from walking through walls.
- **Expandable Map**: Easily customizable map layout to create new levels and experiences.

## Installation

To build and run the raycaster engine, you'll need to have a C compiler and Make installed on your system. Follow these steps to get started:

1. Clone the repository:
    ```sh
    git clone https://github.com/N1ghtm4reee/raycaster-engine.git
    cd raycaster-engine
    ```

2. Build the project using Make:
    ```sh
    make
    ```

3. Run the executable:
    ```sh
    ./raycaster-engine
    ```

## Usage

Once the engine is running, use the following controls to navigate the game world:

- **W**: Move forward
- **S**: Move backward
- **A**: Turn left
- **D**: Turn right

## Contributing

Contributions are welcome! If you'd like to add new features, fix bugs, or improve the documentation, please follow these steps:

1. Fork the repository.
2. Create a new branch for your changes (`git checkout -b feature-branch`).
3. Commit your changes (`git commit -m 'Add new feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

---

Thank you for checking out the Raycaster Engine project! We hope you enjoy exploring and contributing to this classic game engine.
