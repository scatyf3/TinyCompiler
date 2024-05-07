cmake_minimum_required(VERSION 3.16)
project(lab02)
set(CMAKE_CXX_STANDARD 14)
add_compile_options(-pedantic)
# add_compile_options(-fsanitize=address)
# add_link_options(-fsanitize=address)

add_executable(Compilerlab2
        lex.yy.cpp
)

target_compile_features(Compilerlab2 PRIVATE cxx_std_14)

add_custom_command(
        OUTPUT lex.yy.cpp
        COMMAND flex -o ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.cpp ${CMAKE_CURRENT_SOURCE_DIR}/tokenrizer.l
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/tokenrizer.l
)

add_custom_target(GenerateLexer DEPENDS lex.yy.cpp)

add_dependencies(Compilerlab2 GenerateLexer)
