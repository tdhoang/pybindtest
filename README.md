# pybindtest
my own journey to learn pybind11 and conan


for making things running:
mkdir build
cd build
conan install .. --output-folder cmake-build --build=missing
cmake .. -G "Visual Studio 17 2022" -A x64 -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake
cmake --build . --config Release


for testing, go to release folder:
python
import example
example.pascal(8)
example.pascal(16)
example.pascal(22)
exit()
