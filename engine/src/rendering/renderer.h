#pragma once

#include "core/core.h"
#include "maths/vector.h"

struct SDL_Renderer;
struct SDL_Window;

namespace lunar
{
    class Renderer
    {
    public:
        Renderer() = default;
        ~Renderer() = default;
        void Init(SDL_Window* window);
        void Destroy();
        void Clear();
        void Present();
        void DrawRectangle(vec2 position, vec2 size, vec4 color);
        inline SDL_Renderer* GetSDLRenderer() const { return m_Renderer; }

    private:
        SDL_Renderer* m_Renderer = nullptr;
    };
}