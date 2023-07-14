#pragma once

#include "core.h"
#include "maths/vector.h"

struct SDL_Window;

namespace lunar
{
    struct WindowProperties
    {
        i32 Width;
        i32 Height;
        const char* Title;
    };

    class Window
    {
    public:
        Window() = default;
        ~Window() = default;
        void Init(const WindowProperties& properties);
        void PollEvents();
        void Destroy();
        ivec2 GetSize() const;
        const char* GetTitle() const;
    private:
        SDL_Window* m_Window = nullptr;
    };
}