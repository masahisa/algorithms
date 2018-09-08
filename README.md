# algorithms

This is my algorithm library in C/C++.

## Project structure

The project structure is shown below.

```
algorithms/
    CMakeLists.txt
    bin/
    build/
    doc/
        CMakeLists.txt
        Doxyfile.in
        doxygen/
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
`doc`: the document directory  
`doc/doxygen`: the output directory of doxygen  
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
$ make doc
$ ctest -V
```

## References

Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest and Clifford Stein, [*Introduction to Algorithms, Third Edition*](https://mitpress.mit.edu/books/introduction-algorithms-third-edition), The MIT Press, 2009.