cmake_minimum_required(VERSION 3.10)
project(MyOpenGLProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(OpenGL_GL_PREFERENCE GLVND)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(app
        main.cpp
        shaderClass.cpp
        VAO.cpp
        VBO.cpp
        EBO.cpp
        Cube.cpp
        stb.cpp
        src/glad.c
        Circle.cpp
        Timer.cpp
)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/src DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

target_include_directories(app PRIVATE include headers)

target_link_libraries(app
        OpenGL::GL
        glfw
        ${CMAKE_DL_LIBS}
)