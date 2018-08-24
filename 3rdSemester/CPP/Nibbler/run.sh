#export CXX=`whereis clang++`
mkdir -p build
cd build
cmake ..
make -j2