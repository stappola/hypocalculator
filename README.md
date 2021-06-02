# hypocalculator

## Build instructions
---------------------

mkdir build
cd build
cmake ..
make


## Test implementation
----------------------

cd build
./hypocalc ../testdata/input1.txt output.txt


## Build unit tests
-------------------

git clone https://github.com/google/googletest.git
cd googletest
cmake .
make


