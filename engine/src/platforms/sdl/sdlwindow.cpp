#include "lunarpch.h"
#include "sdlwindow.h"
#include <SDL3/SDL.h>
#include <stb_image.h>

#ifdef LUNAR_DEV
#include <backends/imgui_impl_sdl3.h>
#endif

namespace lunar
{
    void SDLWindow::Init(const WindowProperties& properties)
    {
        SDL_InitSubSystem(SDL_INIT_VIDEO);
        m_Window = SDL_CreateWindow(properties.Title.c_str(), properties.Width, properties.Height, SDL_WINDOW_RESIZABLE);

    // TEST ICON :
    /*
    * TODO:
    - FACTORISER /resources loader
    - Filesystem
    - gestion erreur sur tout l'init
    - .Icon pas en string
    */
        if (!properties.Icon.empty())
        {
            int width, height, channels;
            stbi_uc* iconImg = stbi_load(properties.Icon.c_str(), &width, &height, &channels, 0);
            SDL_Surface* icon_surface = SDL_CreateSurfaceFrom(iconImg, width, height, channels * width, SDL_PIXELFORMAT_RGBA8888);
            SDL_SetWindowIcon(m_Window, icon_surface);
            SDL_DestroySurface(icon_surface);
            stbi_image_free(iconImg);
        }
    }

    void SDLWindow::PollEvents()
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            LUNAR_DEV_ONLY(ImGui_ImplSDL3_ProcessEvent(&event);)
            switch (event.type)
            {
            case SDL_EVENT_QUIT:
                m_ShouldClose = true;
                break;
            }
        }
    }

    void SDLWindow::Destroy()
    {
        SDL_DestroyWindow(m_Window);
        m_Window = nullptr;
        SDL_Quit();
    }

    ivec2 SDLWindow::GetSize() const
    {
        ivec2 size{};
        SDL_GetWindowSize(m_Window, &size.x, &size.y);
        return size;
    }
}