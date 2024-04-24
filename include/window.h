#pragma once
#include "SDL2/SDL.h"

#include "SDL_vulkan.h"

struct Offset2D {
    int x;
    int y;
};
struct Extent2D {
    uint32_t x;
    uint32_t y;
};

namespace core {
void Initialize();
void Finalize();

enum WindowFlags {
    TEST_FLAG = 100000000,
};
struct WindowInfo {
    const char* name;
    Offset2D offset;
    Extent2D extent;
    WindowFlags flags;
};
struct Window {
    SDL_Window* sdl_window;
};

Window CreateWindow(WindowInfo info);
void DestroyWindow(Window window);

void GetInstanceExtensions(Window window, unsigned int* pCount, const char** pNames);
} // namespace core