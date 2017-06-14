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
        asm/separate_lines.c
        asm/ik_1.c
        asm/ik_2.c
        asm/ik_print_memory.c
        asm/ik_init_struct.c
        asm/ik_write_comand.c
        asm/ik_write_mark.c
        op.h)

set (SOURCE_FILES_CORWAR
        virtual_machine/main.c
        virtual_machine/init_function.c
        virtual_machine/base_function.c
        virtual_machine/pars_alloc_and_free.c
        virtual_machine/pars_parsing_file.c
        virtual_machine/pars_search_flags.c
        virtual_machine/pars_valid_name.c
        virtual_machine/pars_move_players_by_n.c
        virtual_machine/exec_pc_0.c
        virtual_machine/exec_pc_1.c
        virtual_machine/00_helpfun_0.c
        virtual_machine/00_helpfun_1.c
        virtual_machine/00_live.c
        virtual_machine/01_ld.c
        virtual_machine/02_st.c
        virtual_machine/03_add.c
        virtual_machine/04_sub.c
        virtual_machine/05_and.c
        virtual_machine/06_or.c
        virtual_machine/07_xor.c
        virtual_machine/08_zjmp.c
        virtual_machine/09_ldi.c
        virtual_machine/10_sti.c
        virtual_machine/11_fork.c
        virtual_machine/12_lld.c
        virtual_machine/13_lldi.c
        virtual_machine/14_lfork.c
        virtual_machine/15_aff.c
        virtual_machine/visual_0.c
        virtual_machine/visual_1.c
        virtual_machine/visual_2(dump).c
        virtual_machine/vm.h
        virtual_machine/vm_instructions.h
        op.h )

add_executable(asm ${SOURCE_FILES_ASM})
add_executable(corwar ${SOURCE_FILES_CORWAR})

target_link_libraries(asm libftprintf.a)
target_link_libraries(corwar libftprintf.a ncurses)