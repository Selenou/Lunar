#pragma once

#include "core/core.h"

struct SDL_Window;
struct SDL_Renderer;

namespace lunar
{
    class Editor
    {
    public:
        Editor() = default;
        ~Editor() = default;
        void Init(SDL_Window* window, SDL_Renderer* renderer);
        void Destroy();
        void NewFrame();
        void EndFrame();
        void Render();
    };
}