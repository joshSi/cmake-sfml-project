cmake_minimum_required(VERSION 3.28)
project(SFMLTemplate LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(SFMLTemplate src/main.cpp)

# Add include directory to the project
target_include_directories(SFMLTemplate PRIVATE include)

# Add source files to the project
target_sources(SFMLTemplate PRIVATE
    src/game.cpp
    src/button.cpp)

# Add assets directory to the project
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

target_compile_features(SFMLTemplate PRIVATE cxx_std_17)
target_link_libraries(SFMLTemplate PRIVATE SFML::Graphics)
