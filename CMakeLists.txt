cmake_minimum_required(VERSION 3.22)
#-------------------DEFINE ZONE----------------------#
# Cross-compilation setup for MinGW-w64
if(WIN32 OR MINGW)
    set(CMAKE_SYSTEM_NAME Windows)
    set(CMAKE_C_COMPILER x86_64-w64-mingw32-gcc)
    set(CMAKE_CXX_COMPILER x86_64-w64-mingw32-g++)
    set(CMAKE_RC_COMPILER x86_64-w64-mingw32-windres)
    set(CMAKE_FIND_ROOT_PATH /usr/x86_64-w64-mingw32)
    set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
    set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
    set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
endif()

##INFORMATION AND CONFIGURATION
project(
        "PassIt"
        VERSION 1.0.0
        LANGUAGES C CXX)

# Project/Library Names
set(EXECUTABLE_NAME "main")
set(LIBRARIES "CommandAndLogic" ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})


# Global CMake variables are set here
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
#set(SDL2_IMAGE_LIBRARIES "/usr/local/lib/libSDL2_image.so")
#----------------------------------------------------#

if(WIN32 OR MINGW)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -static-libgcc -static-libstdc++")
endif()


set(CMAKE_BUILD_WITH_INSTALL_RPATH OFF)

option(USE_CPM "Whether to use CPM." ON)



# CMAKE MODULES
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")
# include(ConfigSafeGuards)
# include(AddGitSubmodule)
# include(Docs)
# include(Tools)

if(ENABLE_WARNINGS)
    include(Warnings)
endif()

# add_cmake_format_target()
# add_clang_format_target()

# EXTERNAL LIBRARIES
if(USE_CPM)
    message(STATUS "Using CPM")
    include(CPM)

    # FreeType library for font rendering - build this first
    cpmaddpackage(
        NAME freetype
        GITHUB_REPOSITORY freetype/freetype
        GIT_TAG VER-2-13-2
        OPTIONS
            "FT_DISABLE_ZLIB ON"
            "FT_DISABLE_BZIP2 ON"
            "FT_DISABLE_PNG ON"
            "FT_DISABLE_HARFBUZZ ON"
            "FT_DISABLE_BROTLI ON"
            "BUILD_SHARED_LIBS OFF"
    )

    if(TARGET freetype)
        add_library(Freetype::Freetype ALIAS freetype)
        # Set the variables that SDL2_ttf looks for
        set(FREETYPE_FOUND TRUE)
        set(FREETYPE_LIBRARIES freetype)
        get_target_property(FREETYPE_INCLUDE_DIRS freetype INTERFACE_INCLUDE_DIRECTORIES)
    endif()

    # For cross-compilation, we need to specify Windows-compatible SDL builds
    cpmaddpackage(
        NAME SDL2
        GITHUB_REPOSITORY libsdl-org/SDL
        GIT_TAG release-2.30.6
        OPTIONS 
            "SDL_SHARED OFF"
            "SDL_STATIC ON"
            "SDL_MAIN_HANDLED ON"
    )
    
    cpmaddpackage(
        NAME SDL2_image
        GITHUB_REPOSITORY libsdl-org/SDL_image
        GIT_TAG release-2.8.2
        OPTIONS
            "SDL2IMAGE_DEPS_SHARED OFF"
            "BUILD_SHARED_LIBS OFF"
    )
    
    # Set FreeType variables before configuring SDL2_ttf
    if(TARGET freetype)
        get_target_property(FREETYPE_INCLUDE_DIRS freetype INTERFACE_INCLUDE_DIRECTORIES)
        set(FREETYPE_LIBRARY freetype)
        set(FREETYPE_LIBRARIES freetype)
        set(FREETYPE_FOUND TRUE)
    endif()
    
    cpmaddpackage(
        NAME SDL2_ttf
        GITHUB_REPOSITORY libsdl-org/SDL_ttf
        GIT_TAG release-2.22.0
        OPTIONS
            "BUILD_SHARED_LIBS OFF"
            "SDL2TTF_FREETYPE_VENDORED OFF"
    )
    
    if(ENABLE_TESTING)
        cpmaddpackage("gh:catchorg/Catch2#v3.5.3")
        list(APPEND CMAKE_MODULE_PATH ${Catch2_SOURCE_DIR}/extras)
    endif()
endif()

# find_package(SDL2)

# After the CPM FreeType setup, make sure the target is available
if(TARGET freetype)
    # FreeType is available as 'freetype' target
    set(FREETYPE_TARGET freetype)
else()
    message(FATAL_ERROR "FreeType target not found")
endif()

add_subdirectory(configured)
add_subdirectory(external)
add_subdirectory(src)
add_subdirectory(app)

if(ENABLE_TESTING)
    include(CTest)
    enable_testing()
    add_subdirectory(tests)
endif()

# INSTALL TARGETS

install(
        TARGETS ${EXECUTABLE_NAME}
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)

install(
        TARGETS ${LIBRARIES}
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib)