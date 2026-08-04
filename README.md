*This project has been created as part of the 42 curriculum by memillet, leauvray.*

# cub3D

## Description

cub3D is a first-person maze explorer rendered with raycasting, inspired by
the original Wolfenstein 3D. Written in C using the miniLibX graphics library,
it reads a scene description file (`.cub`) and renders a real-time 3D view of
a maze from the player's perspective.

The program parses a map made of walls, empty spaces and a single starting
position, validates it thoroughly, then casts one ray per screen column to
build the 3D projection. Walls are textured differently depending on the
direction they face (North, South, East, West), and the floor and ceiling are
filled with configurable colors.

### Features

- Real-time raycasting render with per-face wall textures
- Configurable floor and ceiling colors
- Movement with `W`, `A`, `S`, `D` and view rotation with the arrow keys [and the mouse, if you kept it]
- Strict `.cub` scene parsing with explicit error reporting
- Clean exit via `ESC` and the window's close button, with no memory leaks

### Bonus

- Minimap overlay showing the map and the player's position
- Openable / closable doors [key to open: E — CONFIRM YOUR KEY]

## Instructions

### Requirements

- A Linux system with X11 (the project uses miniLibX for Linux)
- `cc`, `make`, and the standard build tools
- The X11 development libraries (`libxext-dev`, `libx11-dev`)

### Compilation

```sh
make
```

This compiles the libft, the miniLibX, and the project, producing the `cub3D`
executable.

Available rules:

- `make` / `make all` — build the project
- `make clean` — remove object files
- `make fclean` — remove object files and the executable
- `make re` — rebuild everything from scratch
- `make bonus` — [DESCRIBE: since your bonuses are in the main build, say what this does]

### Usage

```sh
./cub3D <path_to_map.cub>
```

Example:

```sh
./cub3D maps/example.cub
```

### Controls

| Key            | Action                        |
|----------------|-------------------------------|
| `W` / `S`      | Move forward / backward       |
| `A` / `D`      | Strafe left / right           |
| `←` / `→`      | Rotate the view left / right  |
| `E`            | Open / close a door           |
| `ESC`          | Quit the program              |

### The `.cub` scene file

A scene file describes the textures, colors and map. Identifiers can appear in
any order, but the map must always come last.

NO ./path/to/north_texture.xpm
SO ./path/to/south_texture.xpm
WE ./path/to/west_texture.xpm
EA ./path/to/east_texture.xpm
D ./path/to/door_texture.xpm

```
F 220,100,0
C 225,30,0

111111
100101
1010N1
111111
```

- `NO`, `SO`, `WE`, `EA` — paths to the wall textures for each cardinal direction
- `D` — path to the door texture [bonus; CONFIRM your identifier]
- `F`, `C` — floor and ceiling colors, as `R,G,B` with each value in [0, 255]
- Map characters: `0` (empty), `1` (wall), `N`/`S`/`E`/`W` (player start and
  facing direction). The map must be closed off by walls.

## Resources

- https://fr.wikipedia.org/wikiInfographie_tridimensionnelle]
- https://rosettacode.org/wiki/Ray-casting_algorithm
- https://www.youtube.com/watch?v=gYRrGTC7GtA&t=42s
- https://lodev.org/cgtutor/raycasting.html
- https://harm-smits.github.io/42docs/projects/cub3d

### Use of AI

We used AI to explain some notions and help with the planning of the projects. AI helps us too to do this Readme.