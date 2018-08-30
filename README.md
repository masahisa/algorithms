# algorithms

This is my algorithm library in C/C++.

## Project structure

The project structure is shown below.

```
algorithms/
    CMakeLists.txt
    bin/
    build/
    include/
    lib/
    src/
        CMakeLists.txt
        main.cpp
    test/
        CMakeLists.txt
        run_all_tests.cpp
```

`bin`: the output directory of executables  
`build`: the building directory  
`include`: header files of the project  
`lib`: the output directory of shared libraries and archives  
`src`: source files of the project  
`test`: source files for all the tests

## Build and test

```
$ mkdir build
$ cd build
$ cmake ..
$ make
$ ctest -V
```