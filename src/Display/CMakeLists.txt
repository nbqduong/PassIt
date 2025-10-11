#-------------------DEFINE ZONE----------------------#
#this library
set(LIBRARY_NAME "Display")
set(SDL2_INCLUDE_DIRS "${CMAKE_BINARY_DIR}/_deps/sdl2_image-src/include"
                     "${CMAKE_BINARY_DIR}/_deps/sdl2_ttf-src"
                     "${CMAKE_BINARY_DIR}/_deps/sdl2-src/include")
set(LIBRARY_INCLUDES 
        "./" 
        "${CMAKE_BINARY_DIR}/configured_files/include"
        "${SDL2_INCLUDE_DIRS}")

set(LIBRARY_SOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/Window.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/TextureFactory.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/TextureManager.cpp"
)
set(LIBRARY_HEADERS
        "${CMAKE_CURRENT_SOURCE_DIR}/Window.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/TextureFactory.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/TextureManager.h"
)

#include more
set(LIBRARIES_TO_LINK Utilities)
set(SDL2_DEPS
    SDL2::SDL2-static
    SDL2::SDL2main
    SDL2_image::SDL2_image-static
    SDL2_ttf::SDL2_ttf-static
)
#----------------------------------------------------#

add_library(${LIBRARY_NAME} STATIC ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})
target_include_directories(${LIBRARY_NAME} PUBLIC ${LIBRARY_INCLUDES})
target_link_libraries( ${LIBRARY_NAME} PUBLIC ${LIBRARIES_TO_LINK})
target_link_libraries(${LIBRARY_NAME} PRIVATE ${SDL2_DEPS})

if(${ENABLE_WARNINGS})
    target_set_warnings(
            TARGET
            ${LIBRARY_NAME}
            ENABLE
            ${ENABLE_WARNINGS}
            AS_ERRORS
            ${ENABLE_WARNINGS_AS_ERRORS})
endif()

if(${ENABLE_LTO})
    target_enable_lto(
            TARGET
            ${LIBRARY_NAME}
            ENABLE
            ON)
endif()

if(${ENABLE_CLANG_TIDY})
    add_clang_tidy_to_target(${LIBRARY_NAME})
endif()
