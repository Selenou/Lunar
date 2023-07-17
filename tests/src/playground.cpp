#include <catch2/catch_test_macros.hpp>
#include <lunar.h>
#include <platforms/sdl/sdlwindow.h>

TEST_CASE("Playground")
{
    lunar::Window* window = new lunar::SDLWindow();
    lunar::Renderer renderer;
    LUNAR_DEV_ONLY(lunar::Editor editor;)

    window->Init({ .Width = 1280, .Height = 720, .Title = "Playground", .Icon = "resources/moon.png" });
    renderer.Init(window->GetNativeWindow());
    LUNAR_DEV_ONLY(editor.Init(window->GetNativeWindow(), renderer.GetSDLRenderer());)

    while (!window->ShouldClose())
    {
        window->PollEvents();

        renderer.Clear();

        renderer.DrawRectangle({ 200, 200 }, { 200, 400 }, { 128, 128, 0, 255 });
        renderer.DrawRectangle({ 600, 350 }, { 300, 100 }, { 0, 128, 255, 255 });

        LUNAR_DEV_ONLY(
        editor.NewFrame();
        editor.Render();
        editor.EndFrame();)

        renderer.Present();
    }

    LUNAR_DEV_ONLY(editor.Destroy();)
    renderer.Destroy();
    window->Destroy();
    delete(window);
}