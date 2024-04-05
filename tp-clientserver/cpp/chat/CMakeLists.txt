cmake_minimum_required( VERSION 3.10 )
project( chat )

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable( chat-server server.cpp )
target_link_libraries( chat-server hv )

add_executable( chat-client client.cpp )
target_link_libraries( chat-client hv )

find_package( PkgConfig REQUIRED )
pkg_check_modules( GTKMM REQUIRED gtkmm-3.0 )
include_directories( ${GTKMM_INCLUDE_DIRS} )
add_executable( chat-gui gui.cpp )
target_link_libraries( chat-gui hv ${GTKMM_LIBRARIES} )

install( TARGETS chat-server chat-client chat-gui 
    DESTINATION bin )

