include("/home/nuc/code/PassIt/cmake/CPM.cmake")
CPMAddPackage("NAME;SDL2_image;GITHUB_REPOSITORY;libsdl-org/SDL_image;GIT_TAG;release-2.8.2;OPTIONS;SDL2IMAGE_DEPS_SHARED OFF;BUILD_SHARED_LIBS OFF")
set(SDL2_image_FOUND TRUE)