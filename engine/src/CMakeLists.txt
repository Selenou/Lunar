add_library(lunar STATIC)

target_include_directories(lunar PRIVATE
"${LUNAR_ROOT}/engine/src"
"${LUNAR_ROOT}/vendor/imgui"
"${LUNAR_ROOT}/vendor/stb_image/include"
)

target_precompile_headers(lunar PRIVATE lunarpch.h)

target_sources(lunar PRIVATE
 "lunarpch.cpp"
 "lunarpch.h"
 "lunar/core/assert.h"
 "lunar/core/core.h"
 "lunar/core/logger.h"
 "lunar/graphics/window.h"
 "lunar/maths/vector.h"
 "lunar/tools/editor.cpp"
 "lunar/tools/editor.h"
 "lunar/tools/imguibuild.cpp"
 "platforms/sdl/renderer.cpp"
 "platforms/sdl/renderer.h"
 "platforms/sdl/sdlwindow.cpp"
 "platforms/sdl/sdlwindow.h"
 "${LUNAR_ROOT}/vendor/stb_image/stb_image.cpp")

# link libs (sdl3, imgui)
target_link_libraries(lunar PRIVATE SDL3::SDL3 imgui)