#pragma once

#include "lunar/core/core.h"
#include "lunar/maths/vector.h"

struct SDL_Renderer;

namespace lunar
{
    class Renderer
    {
    public:
        Renderer() = default;
        ~Renderer() = default;
        void Init(void* window);
        void Destroy();
        void Clear();
        void Present();
        void DrawRectangle(vec2 position, vec2 size, vec4 color);
        inline SDL_Renderer* GetSDLRenderer() const { return m_Renderer; }

    private:
        SDL_Renderer* m_Renderer = nullptr;
    };
}