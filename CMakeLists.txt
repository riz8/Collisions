cmake_minimum_required (VERSION 3.8)

project ("Collisions")

#add_compile_definitions(SFML_STATIC)

#include_directories(${CMAKE_SOURCE_DIR}/SFML_2_5_0/include)
#link_directories(${CMAKE_SOURCE_DIR}/SFML_2_5_0/lib)

add_executable (Collisions "main.cpp")

set_target_properties( Collisions PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin )

#target_link_libraries(Collision sfml-graphics-s-d)
#target_link_libraries(Collision sfml-window-s-d)
#target_link_libraries(Collision sfml-system-s-d)

#target_link_libraries(Collision opengl32)
#target_link_libraries(Collision freetype)
#target_link_libraries(Collision winmm)
#target_link_libraries(Collision gdi32)
