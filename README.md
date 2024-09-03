# Cub3D



## Description

The **cub3D** project is inspired by the world-famous game Wolfenstein 3D, the first-ever first-person shooter (FPS). This project will introduce you to ray-casting, where your goal is to create a dynamic view inside a maze, allowing you to navigate and find your way. You will develop a simple 3D graphical representation from a first-person perspective using the miniLibX library.

## Project Objectives

- Learn and implement the basics of ray-casting.
- Create a realistic 3D environment using mathematical principles.
- Work with graphical elements, such as textures and colors, in a windowed environment.
- Improve your understanding of C programming, especially in graphics and game development.

## Content

- **Mandatory Part:**
  - Implement a 3D graphical representation of a maze with the following features:
    - The program should use the miniLibX library to create a window and display the maze.
    - The maze should be represented using a simple .cub file format.
    - The player should be able to move through the maze using the keyboard (W, A, S, D) and rotate the view with the arrow keys.
    - The program must handle different wall textures depending on the direction the wall is facing (North, South, East, West).
    - The floor and ceiling should be rendered with different colors.
    - The program must exit cleanly when the ESC key is pressed or the window is closed.

  - **Program Arguments:**
    - The program takes a single argument: a map file with the .cub extension.

  - **Map File Format:**
    - The map must be composed of only six possible characters:
      - `0` for an empty space
      - `1` for a wall
      - `N`, `S`, `E`, `W` for the player`s starting position and orientation.
    - The map must be surrounded by walls (`1`).
    - The .cub file should also include settings for the textures and colors:
      - `NO` for the path to the north texture.
      - `SO` for the path to the south texture.
      - `WE` for the path to the west texture.
      - `EA` for the path to the east texture.
      - `F` for the floor color in RGB format.
      - `C` for the ceiling color in RGB format.
    - Example of a minimal .cub file:

      ```plaintext
      NO ./path_to_the_north_texture
      SO ./path_to_the_south_texture
      WE ./path_to_the_west_texture
      EA ./path_to_the_east_texture

      F 220,100,0
      C 225,30,0

      1111111111111111111111111
      1000000000110000000000001
      1011000001110000000000001
      1001000000000000000000001
      111111111011000001110000000000001
      100000000011000001110111111111111
      11110111111111011100000010001
      11110111111111011101010010001
      11000000110101011100000010001
      10000000000000001100000010001
      10000000000000001101010010001
      11000001110101011111011110N0111
      11110111 1110101 101111010001
      11111111 1111111 111111111111
      ```

  - **Error Handling:**
    - If the .cub file is misconfigured, the program must exit with an error message and return `Error\n` followed by an explicit error message.

## Compilation

To compile the project, ensure that your Makefile includes the following rules: `all`, `clean`, `fclean`, `re`, and `bonus` (if applicable).

1. **Compile the program:**

   ```bash
   make
   ```

   This will create the `cub3D` executable.

2. **Clean object files:**

   ```bash
   make clean
   ```

3. **Remove all generated files, including the executable:**

   ```bash
   make fclean
   ```

4. **Recompile everything from scratch:**

   ```bash
   make re
   ```

## Usage

To run the cub3D program, use the compiled executable and provide a valid .cub map file as an argument:

```bash
./cub3D map.cub
```

You can navigate the maze using the `W`, `A`, `S`, and `D` keys and rotate the view with the `arrow keys` or the `mouse`. Hold down the `Tab` key to display the cursor. Press the `spacebar` to shoot with your weapon. Press `ESC` or the `red cross` to exit the program.
