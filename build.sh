cmake -S . -B build
cmake --build build
cd build && ctest
ln -s compile_commands.json ../
