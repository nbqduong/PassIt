# PassIt

## Game demo
![Demo](https://github.com/nbqduong/PassIt/blob/main/demo/demo-gameplay.gif)

**[Detail gameplay and explainations](GamePlay.md)**

## Technical
**This is a small puzzle game built with C++ from scratch**.
- Language: C++17 standard
- External libraries: SDL2
- Programming technique: OOAD, Design patterns
- External libraries installed and managed by
  - [CPM](https://github.com/cpm-cmake/CPM.cmake) Package Manager
- Unit testing using [Catch2](https://github.com/catchorg/Catch2) v2


## Structure

``` text
├── CMakeLists.txt
├── app
│   ├── CMakesLists.txt
│   └── main.cc
├── cmake
│   └── cmake modules
├── docs
│   ├── Doxyfile
│   └── html/
├── external
│   ├── CMakesLists.txt
│   ├── ...
├── src
│   ├── CMakesLists.txt
│   ├── /...
│   └── /...
└── tests
    ├── CMakeLists.txt
    └── test_*.cc
```

Library code goes into [src/](src/), main program code in [app/](app) and tests go in [tests/](tests/).

## Building

First, clone this repo and do the preliminary work:



- App Executable

```shell
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --config Release --target main
cd app
./main
```
