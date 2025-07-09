libacc
-------------------------------------------------------------------------------
This project offers a header only acceleration structure library including
implementations for a BVH- and KD-Tree. Applications may include ray
intersection tests, closest surface point or nearest neighbor searches.

Requirements
-------------------------------------------------------------------------------
Compiler with C++17 support - parallel tree construction is implemented with
`std::thread` and `std::atomic` and type traits are required for supporting
vector classes with different function names for the squared norm.

CMake
-------------------------------------------------------------------------------
The library has CMake exported targets and GNUInstallDirs to make it easy to
add to CMake projects. Include in CMakeLists.txt:

    find_package(libacc)
    target_link_libraries(your_project_name libacc)

If libacc is installed globally or in a subdirectory of `CMAKE_PREFIX_PATH`
it is found automatically. Otherwise set the `libacc_DIR` variable to the
path to `CMAKE_INSTALL_PREFIX/share/libacc/cmake`.

License
-------------------------------------------------------------------------------
The software is licensed under the BSD 3-Clause license,
for more details see the LICENSE.txt file.
