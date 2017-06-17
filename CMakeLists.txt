cmake_minimum_required(VERSION 3.6)
project(corevar)

link_directories(libftprintf)
include_directories(inc asm/ virtual_machine/)

set(CMAKE_CXX_STANDARD 11)
set(FLAGS "-lncurses")

set(SOURCE_FILES_ASM
        asm/src/main.c
        asm/src/pars_check_data.c
        asm/src/pars_check_instructions.c
        asm/src/pars_init_data.c
        asm/src/pars_lines.c
        asm/src/pars_read_file.c
        asm/src/pars_separate_lines.c
        asm/src/write_code.c
        asm/src/write_base_fun.c
        asm/src/write_init_mark.c
        asm/src/write_code_comand.c
        asm/src/write_code_mark.c
        asm/src/clean_data.c
        asm/src/error_management.c
        op.h)

set (SOURCE_FILES_CORWAR
        virtual_machine/src/main.c
        virtual_machine/src/init_function.c
        virtual_machine/src/base_function.c
        virtual_machine/src/pars_alloc_and_free.c
        virtual_machine/src/pars_parsing_file.c
        virtual_machine/src/pars_search_flags.c
        virtual_machine/src/pars_valid_name.c
        virtual_machine/src/pars_move_players_by_n.c
        virtual_machine/src/exec_pc_0.c
        virtual_machine/src/exec_pc_1.c
        virtual_machine/src/f00_helpfun_0.c
        virtual_machine/src/f00_helpfun_1.c
        virtual_machine/src/f00_live.c
        virtual_machine/src/f01_ld.c
        virtual_machine/src/f02_st.c
        virtual_machine/src/f03_add.c
        virtual_machine/src/f04_sub.c
        virtual_machine/src/f05_and.c
        virtual_machine/src/f06_or.c
        virtual_machine/src/f07_xor.c
        virtual_machine/src/f08_zjmp.c
        virtual_machine/src/f09_ldi.c
        virtual_machine/src/f10_sti.c
        virtual_machine/src/f11_fork.c
        virtual_machine/src/f12_lld.c
        virtual_machine/src/f13_lldi.c
        virtual_machine/src/f14_lfork.c
        virtual_machine/src/f15_aff.c
        virtual_machine/src/visual_0.c
        virtual_machine/src/visual_1.c
        virtual_machine/src/visual_2.c
        virtual_machine/src/visual_3_dump.c
        virtual_machine/src/wav_audio.c
        virtual_machine/src/vm.h
        op.h)

add_executable(asm ${SOURCE_FILES_ASM})
add_executable(corwar ${SOURCE_FILES_CORWAR})

target_link_libraries(asm libftprintf.a)
target_link_libraries(corwar libftprintf.a ncurses)