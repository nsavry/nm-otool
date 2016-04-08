.PHONY: all lib ft_nm ft_otool clean fclean re

all: lib
	@make -C src_nm
#	@make -C src_otool

lib:
	@make -C libft

ft_nm: lib
	@make -C src_nm

#ft_otool: lib
#	@make -C src_client

clean:
	@make -C libft clean
	@make -C src_nm clean
#	@make -C src_client clean

fclean: clean
	@make -C libft fcleana
	@make -C src_nm fcleana
#	@make -C src_client fcleana

re: fclean all

nm: ft_nm
	./ft_nm ft_nm

#otool: ft_otool
#	./ft_otool
