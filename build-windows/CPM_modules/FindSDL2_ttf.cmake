include("/home/nuc/code/PassIt/cmake/CPM.cmake")
CPMAddPackage("NAME;SDL2_ttf;GITHUB_REPOSITORY;libsdl-org/SDL_ttf;GIT_TAG;release-2.22.0;OPTIONS;BUILD_SHARED_LIBS OFF;SDL2TTF_FREETYPE_VENDORED OFF")
set(SDL2_ttf_FOUND TRUE)