# File: CMakeLists.txt

cmake_minimum_required(VERSION 3.28)

project(AuroraMediaStudio
    VERSION 1.0.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable automatic compiler rules for Qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Force runtime optimizations and strict errors
if(MSVC)
    add_compile_options(/W4 /WX /utf-8)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

# Find Host Qt Packages (Supporting Qt 6.7 through Qt 6.11+)
find_package(Qt6 REQUIRED COMPONENTS 
    Core 
    Gui 
    Quick 
    Qml 
    OpenGL 
    OpenGLWidgets 
    Widgets
)

# Resolve package management dependencies
include(cmake/Dependencies.cmake)

# Construct unified include/target list
add_subdirectory(src/core)
add_subdirectory(src/modules/shell)
add_subdirectory(src/modules/suno)
add_subdirectory(src/modules/player)
add_subdirectory(src/modules/video)
add_subdirectory(src/app)