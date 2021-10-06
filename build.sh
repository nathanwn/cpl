cmake -S . -B build
cmake --build build
cd build && ctest
cp compile_commands.json ../
