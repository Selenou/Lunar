#include "lunarpch.h"
#include "editor.h"
#ifdef LUNAR_DEV
#include <imgui.h>
#include <backends/imgui_impl_sdl3.h>
#include <backends/imgui_impl_sdlrenderer3.h>
#endif

#ifdef LUNAR_DEV
namespace lunar
{
    void Editor::Init(void* window, SDL_Renderer* renderer)
    {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGui::StyleColorsDark();

        ImGuiIO& io = ImGui::GetIO();
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;		// Enable Keyboard Controls
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;		// Enable Gamepad Controls
        //io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;			// Enable Docking
        //io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;		// Enable Multi-Viewport / Platform Windows

        ImGui_ImplSDL3_InitForSDLRenderer(static_cast<SDL_Window*>(window), renderer);
        ImGui_ImplSDLRenderer3_Init(renderer);
    }

    void Editor::Destroy()
    {
        ImGui_ImplSDLRenderer3_Shutdown();
        ImGui_ImplSDL3_Shutdown();
        ImGui::DestroyContext();
    }

    void Editor::NewFrame()
    {
        ImGui_ImplSDLRenderer3_NewFrame();
        ImGui_ImplSDL3_NewFrame();
        ImGui::NewFrame();
    }

    void Editor::EndFrame()
    {
        ImGui::Render();
        ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData());
    }

    void Editor::Render()
    {
        static bool showDemoWindow = false;

        if (showDemoWindow)
        {
            ImGui::ShowDemoWindow();
        }

        if (ImGui::BeginMainMenuBar())
        {
            if (ImGui::BeginMenu("Examples"))
            {
                ImGui::MenuItem("Show Demo", "", &showDemoWindow);
                ImGui::EndMenu();
            }
            ImGui::EndMainMenuBar();
        }
    }
}
#endif