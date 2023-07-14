#include "lunarpch.h"
#include "window.h"
#include <SDL3/SDL.h>

namespace lunar
{
    void Window::Init(const WindowProperties& properties)
    {
        SDL_Init(SDL_INIT_VIDEO);
        m_Window = SDL_CreateWindow(properties.Title, properties.Width, properties.Height, SDL_WINDOW_VULKAN | SDL_WINDOW_RESIZABLE);
    }

    void Window::PollEvents()
    {
        bool loopShouldStop = false;
        static SDL_Renderer* renderer = SDL_CreateRenderer(m_Window, nullptr, SDL_RENDERER_ACCELERATED);
        
        while (!loopShouldStop)
        {
            SDL_Event event;
            while (SDL_PollEvent(&event))
            {
                switch (event.type)
                {
                case SDL_EVENT_QUIT:
                    loopShouldStop = true;
                    break;
                }
            }
            SDL_RenderClear(renderer);

            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            const SDL_FRect r{ 50,50,150,50 };
            SDL_RenderRect(renderer, &r);
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

            SDL_RenderPresent(renderer);
        }
    }

    void Window::Destroy()
    {
        SDL_DestroyWindow(m_Window);
        SDL_Quit();
    }

    ivec2 Window::GetSize() const
    {
        ivec2 size{};
        SDL_GetWindowSize(m_Window, &size.x, &size.y);
        return size;
    }

    const char* Window::GetTitle() const
    {
        return SDL_GetWindowTitle(m_Window);
    }
}