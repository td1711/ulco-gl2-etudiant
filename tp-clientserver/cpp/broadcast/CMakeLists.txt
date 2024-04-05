cmake_minimum_required( VERSION 3.10 )
project( broadcast )

add_executable( broadcast-server server.cpp )
target_link_libraries( broadcast-server hv )

add_executable( broadcast-client client.cpp )
target_link_libraries( broadcast-client hv )

install( TARGETS broadcast-server broadcast-client DESTINATION bin )

