#include "lunarpch.h"
#include "window.h"
#include <SDL3/SDL.h>

//TODO : TMP
#include <backends/imgui_impl_sdl3.h>

namespace lunar
{
    void Window::Init(const WindowProperties& properties)
    {
        SDL_Init(SDL_INIT_VIDEO);
        m_Window = SDL_CreateWindow(properties.Title, properties.Width, properties.Height, SDL_WINDOW_RESIZABLE);
    }

    void Window::PollEvents()
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            ImGui_ImplSDL3_ProcessEvent(&event); //TODO : TMP
            switch (event.type)
            {
            case SDL_EVENT_QUIT:
                m_ShouldClose = true;
                break;
            }
        }
    }

    void Window::Destroy()
    {
        SDL_DestroyWindow(m_Window);
        m_Window = nullptr;
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