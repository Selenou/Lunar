#include "lunarpch.h"
#include "renderer.h"
#include <SDL3/SDL.h>

namespace lunar
{
    void Renderer::Init(void* window)
    {
        m_Renderer = SDL_CreateRenderer(static_cast<SDL_Window*>(window), nullptr, SDL_RENDERER_ACCELERATED);
    }

    void Renderer::Destroy()
    {
        SDL_DestroyRenderer(m_Renderer);
    }

    void Renderer::Clear()
    {
        SDL_RenderClear(m_Renderer);
    }

    void Renderer::Present()
    {
        SDL_RenderPresent(m_Renderer);
    }

    void Renderer::DrawRectangle(vec2 position, vec2 size, vec4 color)
    {
        SDL_SetRenderDrawColor(m_Renderer, color.r, color.g, color.b, color.a);
        const SDL_FRect r = { position.x, position.y, size.x, size.y };
        SDL_RenderFillRect(m_Renderer, &r);
        SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 255);
    }
}