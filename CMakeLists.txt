cmake_minimum_required(VERSION 3.6)
project(corevar)

link_directories(libftprintf)
include_directories(inc asm/ virtual_machine/)

set(CMAKE_CXX_STANDARD 11)
set(FLAGS "-lncurses")

set(SOURCE_FILES_ASM
        asm/main.c
        asm/pars_check_data.c
        asm/pars_check_instructions.c
        asm/pars_init_data.c
        asm/pars_lines.c
        asm/pars_read_file.c
        asm/pars_separate_lines.c
        asm/write_code.c
        asm/write_base_fun.c
        asm/write_init_mark.c
        asm/write_code_comand.c
        asm/write_code_mark.c
        asm/clean_data.c
        asm/error_management.c        
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
        virtual_machine/f00_helpfun_0.c
        virtual_machine/f00_helpfun_1.c
        virtual_machine/f00_live.c
        virtual_machine/f01_ld.c
        virtual_machine/f02_st.c
        virtual_machine/f03_add.c
        virtual_machine/f04_sub.c
        virtual_machine/f05_and.c
        virtual_machine/f06_or.c
        virtual_machine/f07_xor.c
        virtual_machine/f08_zjmp.c
        virtual_machine/f09_ldi.c
        virtual_machine/f10_sti.c
        virtual_machine/f11_fork.c
        virtual_machine/f12_lld.c
        virtual_machine/f13_lldi.c
        virtual_machine/f14_lfork.c
        virtual_machine/f15_aff.c
        virtual_machine/visual_0.c
        virtual_machine/visual_1.c
        virtual_machine/visual_3_dump.c
        virtual_machine/vm.h
        op.h virtual_machine/visual_2.c)

add_executable(asm ${SOURCE_FILES_ASM})
add_executable(corwar ${SOURCE_FILES_CORWAR})

target_link_libraries(asm libftprintf.a)
target_link_libraries(corwar libftprintf.a ncurses)