#pragma once

#include "lunar/graphics/window.h"

struct SDL_Window;

namespace lunar
{
    class SDLWindow : public Window
    {
    public:
        SDLWindow() = default;
        virtual ~SDLWindow() = default;
        void Init(const WindowProperties& properties) override;
        void PollEvents() override;
        void Destroy() override;
        ivec2 GetSize() const override;
        inline bool ShouldClose() const override { return m_ShouldClose; }
        inline void* GetNativeWindow() const override { return m_Window; }
    private:
        SDL_Window* m_Window = nullptr;
        bool m_ShouldClose = false;
    };
}