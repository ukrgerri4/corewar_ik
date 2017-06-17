all:
	@cd asm && make
	@cd virtual_machine && make

clean:
	@cd asm && make clean
	@cd virtual_machine && make clean

fclean:
	@cd asm && make fclean
	@cd virtual_machine && make fclean

re: fclean all
