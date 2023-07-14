add_subdirectory("catch2")
add_subdirectory("sdl")

# Imgui
add_library(imgui STATIC)
target_sources(imgui PRIVATE
    imgui/imgui.cpp
    imgui/imgui.h
    imgui/imconfig.h
    imgui/imgui_demo.cpp
    imgui/imgui_draw.cpp
    imgui/imgui_internal.h
    imgui/imstb_rectpack.h
    imgui/imgui_tables.cpp
    imgui/imstb_textedit.h
    imgui/imstb_truetype.h
    imgui/imgui_widgets.cpp)