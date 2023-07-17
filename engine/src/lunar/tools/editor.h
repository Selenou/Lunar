#pragma once

struct SDL_Renderer;

#ifdef LUNAR_DEV
namespace lunar
{
    class Editor
    {
    public:
        Editor() = default;
        ~Editor() = default;
        void Init(void* window, SDL_Renderer* renderer);
        void Destroy();
        void NewFrame();
        void EndFrame();
        void Render();
    };
}
#endif