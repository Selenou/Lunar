#pragma once

#include "lunar/core/core.h"
#include "lunar/maths/vector.h"
#include <string>

namespace lunar
{
    struct WindowProperties
    {
        i32 Width;
        i32 Height;
        std::string Title;
        std::string Icon;
    };

    class Window
    {
    public:
        Window() = default;
        virtual ~Window() = default;
        virtual void Init(const WindowProperties& properties) = 0;
        virtual void PollEvents() = 0;
        virtual void Destroy() = 0;
        virtual ivec2 GetSize() const = 0;
        virtual bool ShouldClose() const = 0;
        virtual void* GetNativeWindow() const = 0;
    };
}