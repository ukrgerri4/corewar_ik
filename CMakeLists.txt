cmake_minimum_required(VERSION 3.6)
project(corevar)

link_directories(libftprintf)
include_directories(inc asm/ virtual_machine/)

set(CMAKE_CXX_STANDARD 11)
set(FLAGS "-lncurses")

set(SOURCE_FILES_ASM
                    asm/main.c
                    asm/asm.h
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
                    asm/ik_write_mark.c
                    op.h)

set (SOURCE_FILES_CORWAR
                    virtual_machine/ik_init_pc.c
                    virtual_machine/ik_base_function.c
                    virtual_machine/ik_visualization.c
                    virtual_machine/ik_start_pc.c
                    virtual_machine/ik_init_function.c

                    virtual_machine/main.c
                    virtual_machine/allocation_memory.c
                    virtual_machine/free_memory.c
                    virtual_machine/ft_error.c
                    virtual_machine/ft_parsing_file.c
                    virtual_machine/ft_search_flags.c
                    virtual_machine/ft_valid_name.c
                    virtual_machine/support_instructions.c
                    virtual_machine/instruction_live.c
                    virtual_machine/checking_instructions.c
                    virtual_machine/instruction_live.c
                    virtual_machine/instruction_ld.c
                    virtual_machine/instruction_st.c
                    virtual_machine/instruction_add.c
                    virtual_machine/instruction_sub.c
                    virtual_machine/instruction_and.c
                    virtual_machine/instruction_or.c
                    virtual_machine/instruction_xor.c
                    virtual_machine/instruction_zjmp.c
                    virtual_machine/instruction_ldi.c
                    virtual_machine/instruction_sti.c
                    virtual_machine/instruction_fork.c
                    virtual_machine/instruction_lld.c
                    virtual_machine/instruction_lldi.c
                    virtual_machine/instruction_lfork.c
                    virtual_machine/virtual_machine.h
                    virtual_machine/instructions.h
                    op.h virtual_machine/instruction_aff.c virtual_machine/ik_init_windows.c)

add_executable(asm ${SOURCE_FILES_ASM})
add_executable(corwar ${SOURCE_FILES_CORWAR})

target_link_libraries(asm libftprintf.a)
target_link_libraries(corwar libftprintf.a ncurses)