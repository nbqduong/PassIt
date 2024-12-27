cmake_minimum_required(VERSION 3.22)
#-------------------DEFINE ZONE----------------------#
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


set(CMAKE_BUILD_WITH_INSTALL_RPATH OFF)

option(USE_CPM "Whether to use CPM." ON)



# CMAKE MODULES
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")
include(ConfigSafeGuards)
include(AddGitSubmodule)
include(Docs)
include(Tools)

if(ENABLE_WARNINGS)
    include(Warnings)
endif()

add_cmake_format_target()
add_clang_format_target()

# EXTERNAL LIBRARIES

if(USE_CPM)
    message(STATUS "Using CPM")
    include(CPM)

    cpmaddpackage("gh:libsdl-org/SDL#release-2.30.6")
    cpmaddpackage("gh:libsdl-org/SDL_image#release-2.8.2")
    cpmaddpackage("gh:libsdl-org/SDL_ttf#release-2.22.0")
    if(ENABLE_TESTING)
        cpmaddpackage("gh:catchorg/Catch2#v3.5.3")
        list(APPEND CMAKE_MODULE_PATH ${Catch2_SOURCE_DIR}/extras)
    endif()
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