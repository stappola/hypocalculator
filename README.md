# hypocalculator  

# Build instructions    

mkdir build  
cd build  
cmake ..  
make  

# Test implementation  

cd build  
./hypocalc ../testdata/input1.txt output.txt  


# Build & run unit tests  

git clone https://github.com/google/googletest.git  
cd googletest  
cmake .  
make  

cd ../unittest  
cmake .  
make  


## Run all tests  
./hypocalc_unittest.app  

## Run a subset of tests  
./hypocalc_unittest.app --gtest-filter=[FixtureName].*  

## Run an individual test  
./hypocalc_unittest.app --gtest-filter=[FixtureName].[TestName]  



