# unit-tests with Catch2
add_executable(lunartests)
target_include_directories(lunartests PRIVATE "${LUNAR_ROOT}/engine/src")

target_sources(lunartests PRIVATE
"core/loggertest.cpp"
"core/windowtest.cpp"
"maths/vectortest.cpp"
"playground.cpp")

target_link_libraries(lunartests PRIVATE lunar Catch2::Catch2WithMain)

# Automatic test registration (Test Explorer VS22)
list(APPEND CMAKE_MODULE_PATH "${LUNAR_ROOT}/vendor/Catch2/extras")
include(Catch)
catch_discover_tests(lunartests)

# Copy SDL3.dll to be able to run tests
if(WIN32)
add_custom_command(
    TARGET lunartests PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${LUNAR_BINARY_ROOT}/vendor/SDL/SDL3.dll
    $<TARGET_FILE_DIR:lunartests>
)
endif()