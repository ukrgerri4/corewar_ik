cmake_minimum_required(VERSION 3.6)
project(corevar)

link_directories(libftprintf)
include_directories(inc asm virtual_machine)

set(CMAKE_CXX_STANDARD 11)
#set(FLAGS "-lncurses")

set(SOURCE_FILES_ASM
                    asm/main.c
                    asm/check_data.c
                    asm/check_instructions.c
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

set (SOURCE_FILES_CORVAR
                    virtual_machine/ik_init_pc.c
                    virtual_machine/ik_base_function.c
                    virtual_machine/ik_visualization.c
                    virtual_machine/ik_start_pc.c

                    virtual_machine/main.c
                    virtual_machine/allocation_memory.c
                    virtual_machine/free_memory.c
                    virtual_machine/ft_error.c
                    virtual_machine/ft_parsing_file.c
                    virtual_machine/ft_search_flags.c
                    virtual_machine/ft_valid_name.c)

add_executable(asm ${SOURCE_FILES_ASM})
add_executable(corvar ${SOURCE_FILES_CORVAR})

target_link_libraries(asm libftprintf.a)
target_link_libraries(corvar libftprintf.a ncurses)