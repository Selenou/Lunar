#include <catch2/catch_test_macros.hpp>
#include <lunar.h>

TEST_CASE("Playground")
{
    lunar::Window window;
    lunar::Renderer renderer;
    lunar::Editor editor;

    window.Init({ .Width = 1280, .Height = 720, .Title = "Playground" });
    renderer.Init(window.GetNativeWindow());
    editor.Init(window.GetNativeWindow(), renderer.GetSDLRenderer());

    while (!window.ShouldClose())
    {
        window.PollEvents();

        renderer.Clear();

        renderer.DrawRectangle({ 200, 200 }, { 200, 400 }, { 128, 128, 0, 255 });
        renderer.DrawRectangle({ 600, 350 }, { 300, 100 }, { 0, 128, 255, 255 });

        editor.NewFrame();
        editor.Render();
        editor.EndFrame();

        renderer.Present();
    }

    renderer.Destroy();
    window.Destroy();
}