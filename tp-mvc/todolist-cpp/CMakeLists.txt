cmake_minimum_required( VERSION 3.0 )
project( todolist-cpp )
include_directories( include )

# library
add_library( todolist-cpp-lib
    src/todolist-cpp/Task.cpp
    src/todolist-cpp/View.cpp
    src/todolist-cpp/Board.cpp )

# executable
add_executable( todolist-cpp-app
  app/main.cpp )
target_link_libraries( todolist-cpp-app todolist-cpp-lib )

# install
install( TARGETS todolist-cpp-app DESTINATION bin )

# testing
add_executable( todolist-cpp-test
    test/todolist-cpp/Task-test.cpp
    test/todolist-cpp/View-test.cpp
    test/todolist-cpp/Board-test.cpp
    test/main.cpp )
target_link_libraries( todolist-cpp-test todolist-cpp-lib )
enable_testing()
add_test( NAME todolist-cpp-test COMMAND todolist-cpp-test )

