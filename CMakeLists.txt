cmake_minimum_required(VERSION 3.6)
project(corevar)

link_directories(libftprintf)
include_directories(inc asm)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
                    asm/main.c
                    asm/check_data.c
                    asm/clean_data.c
                    asm/error_management.c
                    asm/init_data.c
                    asm/parse_lines.c
                    asm/read_file.c
                    asm/ik_1.c
                    asm/ik_2.c
                    asm/ik_print_memory.c
                    asm/ik_init_struct.c
                    asm/ik_write_comand.c
                    asm/ik_write_mark.c)

add_executable(asm ${SOURCE_FILES})

target_link_libraries(asm libftprintf.a)