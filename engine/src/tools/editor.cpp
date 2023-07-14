#include "lunarpch.h"
#include "editor.h"
#include <imgui.h>

namespace lunar
{
    void Editor::Debug()
    {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGui::StyleColorsDark();
        //ImGui::ShowDemoWindow();
    }
}