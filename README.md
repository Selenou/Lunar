# Lunar

A lightweight 2D game library written in C++.

### Configurations
| Mode | Config | Features | Description |
|:---:|:---:|:---:|:---:|
| LUNAR_DEV | LUNAR_DEBUG | Logging/Asserts/Tooling/DebugSymbols | Best for debugging and prototyping |
| LUNAR_DEV | LUNAR_RELEASE | Logging/Asserts/Tooling | Best for prototyping and iterating on data |
| LUNAR_FASTLOAD | LUNAR_DEBUG | Logging/Asserts/BinarizedResources/DebugSymbols | Fast with debugging and benchmarking support |
| LUNAR_FASTLOAD | LUNAR_RELEASE | BinarizedResources | The fastest runtime possible, stripped from anything unnecessary |

### Dependencies
- [Imgui](https://github.com/ocornut/imgui) : tooling
- [SDL3](https://github.com/libsdl-org/SDL) : window & input
- [Catch2](https://github.com/catchorg/Catch2) : test framework
- [stb_image](https://github.com/nothings/stb/blob/master/stb_image.h) : image loading
