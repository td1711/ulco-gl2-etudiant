cmake_minimum_required( VERSION 3.10 )
project( echo )

add_executable( echo-server server.cpp )
target_link_libraries( echo-server hv )

add_executable( echo-client client.cpp )
target_link_libraries( echo-client hv )

install( TARGETS echo-server echo-client DESTINATION bin )

