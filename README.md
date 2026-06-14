# 🖼️ Image Viewer

> A minimal, blazing-fast image viewer written in **C** using SDL2 — one source file, no bloat.

---

## ✨ Features

- 📂 Opens JPEG images at their **native resolution**
- ⚡ **Hardware-accelerated** rendering via SDL2
- 🪶 **Lightweight** — a single `.c` source file (~100 lines)
- 🧹 Clean resource management — zero leaks
- 🖥️ Centered window, proper event loop

---

## 📦 Dependencies

| Library | Purpose |
|---|---|
| [SDL2](https://www.libsdl.org/) | Window creation & rendering |
| [SDL2_image](https://github.com/libsdl-org/SDL_image) | JPEG image loading |

### Install

<details>
<summary><b>Ubuntu / Debian</b></summary>

```bash
sudo apt install libsdl2-dev libsdl2-image-dev
```
</details>

<details>
<summary><b>Fedora / RHEL</b></summary>

```bash
sudo dnf install SDL2-devel SDL2_image-devel
```
</details>

<details>
<summary><b>Arch Linux</b></summary>

```bash
sudo pacman -S sdl2 sdl2_image
```
</details>

<details>
<summary><b>macOS (Homebrew)</b></summary>

```bash
brew install sdl2 sdl2_image
```
</details>

---

## 🔨 Build

```bash
gcc image_viewer.c -o img $(sdl2-config --cflags --libs) -lSDL2_image
```

---

## 🚀 Usage

```bash
./img <path/to/image.jpg>
```

**Example:**
```bash
./img photo.jpg
```

- A window opens **sized to the image's native resolution**, centered on screen
- Press the **window close button** to quit

---

## ⚙️ How It Works

```
1. SDL_Init()        →  Initialize SDL2 video subsystem
2. IMG_Init()        →  Enable JPEG support via SDL2_image
3. IMG_Load()        →  Load image into SDL_Surface
4. SDL_CreateWindow  →  Create window sized to image dimensions
5. SDL_CreateRenderer→  Hardware-accelerated renderer
6. SDL_CreateTexture →  Upload surface to GPU texture
7. Event loop        →  Render each frame, exit on SDL_QUIT
8. Cleanup           →  Destroy texture → renderer → window → quit SDL
```

---

## 🗂️ Project Structure

```
image_viewr/
├── image_viewer.c   # Entire program — ~100 lines of clean C
├── img              # Compiled binary
└── README.md        # You are here
```

---

## 📄 License

```
MIT License

Copyright (c) 2026

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```
