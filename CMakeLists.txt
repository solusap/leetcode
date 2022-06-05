project(leet_test CXX)

cmake_minimum_required(VERSION 3.16.0)

set(CMAKE_CXX_COMPILER /usr/bin/clang++)
set(CMAKE_C_COMPILER clang)


set(srclist
${CMAKE_CURRENT_SOURCE_DIR}/src/leet_35.cxx
)

set(include_dir 
    ${CMAKE_CURRENT_SOURCE_DIR}/include/
)

add_executable(leet
    ${srclist}
)

target_include_directories(leet PUBLIC
    $<BUILD_INTERFACE:${include_dir}>
)

target_compile_options(leet PUBLIC
        -std=c++20
        -g
        -O1
        -fsanitize=address
        -fno-omit-frame-pointer
        -stdlib=libstdc++
        -Wall
        -Werror
)


target_link_libraries(leet
    pthread
    dl
    rt
    asan.a
    fmt.a
    -stdlib=libstdc++
)

add_custom_command(
    COMMAND ./leet
    OUTPUT leet.output
)

add_custom_target(run
    DEPENDS leet
    leet.output    
)