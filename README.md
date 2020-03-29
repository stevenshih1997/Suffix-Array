# Suffix Arrays

## How to build and run
The main dependencies are:
  * CMake (version >=3.10)
  * C++17
1. `mkdir build && cd build`
2. `cmake ../suffix`
3. `make all`
4. `cd suffix && ./suffix` to run the example DNA LCS problem

## Run tests
1. Compile and build by running the steps above
2. `make test` inside the `build` folder
  * Note the difference in speed between a suffix array implemented with a normal sort versus a radix sort.

