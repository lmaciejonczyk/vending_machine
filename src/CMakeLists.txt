
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_library(vending_machine STATIC vending_machine.cpp)

# generate compile flag to json file
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

