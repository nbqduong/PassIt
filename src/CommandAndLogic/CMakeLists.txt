#-------------------DEFINE ZONE----------------------#
#this library
set(LIBRARY_NAME "CommandAndLogic")
set(SDL2_INCLUDE_DIRS "${CMAKE_BINARY_DIR}/_deps/sdl2_image-src/include")
set(LIBRARY_INCLUDES 
        "./" 
        "${CMAKE_BINARY_DIR}/configured_files/include"
        "${SDL2_INCLUDE_DIRS}")

set(LIBRARY_SOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/Input.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Engine.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/CommandDispatcher.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/AbstractManager.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/WindowManager.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/MovementManager.cpp"

)
set(LIBRARY_HEADERS
        "${CMAKE_CURRENT_SOURCE_DIR}/Input.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/Engine.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/CommandDispatcher.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/AbstractManager.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/WindowManager.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/MovementManager.h"

)

# Use static SDL2 targets instead of variables, and link privately
set(LIBRARIES_TO_LINK 
    Display 
    Object
)

# SDL2 dependencies - these should be PRIVATE to avoid propagating dynamic library references
set(SDL2_DEPS
    SDL2::SDL2-static
    SDL2::SDL2main
    SDL2_image::SDL2_image-static
    SDL2_ttf::SDL2_ttf-static
)
#----------------------------------------------------#

add_library(${LIBRARY_NAME} STATIC ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})
target_include_directories(${LIBRARY_NAME} PUBLIC ${LIBRARY_INCLUDES})

# Link your own libraries publicly (so they're available to dependents)
target_link_libraries(${LIBRARY_NAME} PUBLIC ${LIBRARIES_TO_LINK})

# Link SDL2 libraries privately (so they don't propagate to dependents)
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
