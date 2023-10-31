# Projects Settings
cmake_minimum_required (VERSION 3.1)
project (opengl-cmake-skeleton)

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
)

set_property(TARGET opengl-cmake-skeleton PROPERTY CXX_STANDARD 11)
target_compile_options(opengl-cmake-skeleton PRIVATE -Wall)

add_definitions(-DGLEW_STATIC)
add_subdirectory(lib/glfw EXCLUDE_FROM_ALL)
add_subdirectory(lib/glew EXCLUDE_FROM_ALL)
add_subdirectory(lib/glm EXCLUDE_FROM_ALL)

target_link_libraries(opengl-cmake-skeleton
  PRIVATE glfw
  PRIVATE libglew_static
  PRIVATE glm
)

target_include_directories(opengl-cmake-skeleton
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
  PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/src
)
