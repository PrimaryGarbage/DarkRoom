cmake_minimum_required(VERSION 3.24)

add_subdirectory(external/SFML)

project(DarkRoom VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

set(BUILD_SHARED_LIBS OFF)
set(SFML_BUILD_EXAMPLES OFF)

### Put the names of your source files here ###
set(SRC_FILES 
    main.cpp
    prim_exception.hpp
    primary_app.hpp primary_app.cpp
    logger.hpp logger.cpp
    time.hpp time.cpp
)

list(TRANSFORM SRC_FILES PREPEND "src/")

add_executable(${PROJECT_NAME} ${SRC_FILES})

add_dependencies(${PROJECT_NAME} sfml-graphics sfml-window sfml-system sfml-audio)

set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX -d)

### Add link directories here ###
target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_BINARY_DIR}/external/SFML/lib)

### Add include directories here ###
target_include_directories(${PROJECT_NAME} PRIVATE external/SFML/include)

### Uncomment this line if you want the standard libraries to be linked statically ###
# target_link_options(${PROJECT_NAME} PRIVATE -static-libgcc -static-libstdc++)

if (WIN32)
    target_link_libraries(${PROJECT_NAME} opengl32 winmm gdi32 freetype openal32 vorbisenc vorbisfile vorbis ogg)
elseif (UNIX)
    target_link_libraries(${PROJECT_NAME} freetype X11 Xrandr Xcursor udev GL ogg vorbis vorbisenc vorbisfile openal pthread)
else()
    message(FATAL_ERROR "Build is only possible on linux or windows system.")
endif()


if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    target_link_libraries(${PROJECT_NAME} sfml-graphics-s-d sfml-window-s-d sfml-system-s-d sfml-audio-s-d)
else()
    target_link_libraries(${PROJECT_NAME} sfml-graphics-s sfml-window-s sfml-system-s sfml-audio-s)
endif()