add_library(lunar STATIC)
target_include_directories(lunar PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${LUNAR_ROOT}/vendor/imgui)
target_precompile_headers(lunar PRIVATE lunarpch.h)

target_sources(lunar PRIVATE
 "lunarpch.cpp"
 "lunarpch.h"
 "core/assert.h"
 "core/core.h"
 "core/logger.h"
 "core/window.cpp"
 "core/window.h"
 "maths/vector.h"
  "rendering/renderer.cpp"
 "rendering/renderer.h"
 "tools/editor.cpp"
 "tools/editor.h"
 "tools/imguibuild.cpp")

# link libs (sdl3, imgui)
target_link_libraries(lunar PRIVATE SDL3::SDL3 imgui)