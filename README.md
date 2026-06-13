# 🖼️ Image Viewer

A minimal, fast image viewer written in C using **SDL2** and **SDL2_image**. Pass a JPEG image as a command-line argument and it opens in a native window — no dependencies beyond SDL2.

## Features

- Opens and displays JPEG images at their native resolution
- Hardware-accelerated rendering via SDL2
- Lightweight — a single C source file
- Clean resource management (no leaks)

## Dependencies

| Library | Purpose |
|---|---|
| [SDL2](https://www.libsdl.org/) | Window creation, rendering |
| [SDL2_image](https://github.com/libsdl-org/SDL_image) | JPEG image loading |

### Install dependencies

**Ubuntu / Debian:**
```bash
sudo apt install libsdl2-dev libsdl2-image-dev
```

**Fedora / RHEL:**
```bash
sudo dnf install SDL2-devel SDL2_image-devel
```

**Arch Linux:**
```bash
sudo pacman -S sdl2 sdl2_image
```

**macOS (Homebrew):**
```bash
brew install sdl2 sdl2_image
```

## Build

```bash
gcc image_viewer.c -o image_viewer $(sdl2-config --cflags --libs) -lSDL2_image
```

## Usage

```bash
./image_viewer <path/to/image.jpg>
```

**Example:**
```bash
./image_viewer photo.jpg
```

- A window opens sized to the image's native resolution
- Close the window (or press the OS close button) to quit

## How It Works

1. Initializes SDL2 video and SDL2_image (JPEG support)
2. Loads the image into a `SDL_Surface`
3. Creates a window matching the image dimensions
4. Converts the surface to a GPU `SDL_Texture` for hardware-accelerated rendering
5. Runs an event loop — renders the texture each frame and exits on window close

## Project Structure

```
image_viewr/
├── image_viewer.c   # Main source file
└── README.md
```

## License

This project is released into the public domain — use it however you like.
