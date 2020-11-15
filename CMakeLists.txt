cmake_minimum_required (VERSION 3.8)

project ("Collisions")

add_compile_definitions(SFML_STATIC)

include_directories(${CMAKE_SOURCE_DIR}/SFML_2_5_0/include)
link_directories(${CMAKE_SOURCE_DIR}/SFML_2_5_0/lib)

add_executable (Collisions "main.cpp")

set_target_properties( Collisions PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin )

target_link_libraries(Collisions sfml-graphics-s-d)
target_link_libraries(Collisions sfml-window-s-d)
target_link_libraries(Collisions sfml-system-s-d)

target_link_libraries(Collisions opengl32)
target_link_libraries(Collisions freetype)
target_link_libraries(Collisions winmm)
target_link_libraries(Collisions gdi32)
