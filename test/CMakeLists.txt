
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(test_vending_machine test_vending_machine.cpp)
target_link_libraries(test_vending_machine ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} vending_machine)

# changed library output path
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

