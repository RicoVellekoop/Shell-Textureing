cmake_minimum_required (VERSION 3.1)
project (opengl-cmake-skeleton)


# Find packages
find_package(glfw3 CONFIG REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(imgui CONFIG REQUIRED)

# The main executable
add_executable(opengl-cmake-skeleton
  src/main.cpp
  src/shader.cpp
  src/shader.h
  src/mesh.cpp
  src/mesh.h
  src/application.cpp
  src/application.h
  src/appwindow.cpp
  src/appwindow.h
  src/camera.cpp
  src/camera.h
  src/object.cpp
  src/object.h
  src/texture.cpp
  src/texture.h
)

set_property(TARGET opengl-cmake-skeleton PROPERTY CXX_STANDARD 11)
target_compile_options(opengl-cmake-skeleton PRIVATE)

target_link_libraries(opengl-cmake-skeleton 
  PRIVATE glfw 
  PRIVATE GLEW::GLEW 
  PRIVATE glm::glm 
  PRIVATE OpenGL::GL 
  PRIVATE imgui::imgui
)

# Copy shaders to build directory
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/shaders DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# Copy assets to build directory
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

target_include_directories(opengl-cmake-skeleton
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
  PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/src
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib
)