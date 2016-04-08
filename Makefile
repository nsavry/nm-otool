.PHONY: all lib ft_nm ft_otool clean fclean re

all: lib
	@make -C src_nm
	@make -C src_otool

lib:
	@make -C libft

ft_nm: lib
	@make -C src_nm

ft_otool: lib
	@make -C src_otool

clean:
	@make -C libft clean
	@make -C src_nm clean
	@make -C src_otool clean

fclean: clean
	@make -C libft fcleana
	@make -C src_nm fcleana
	@make -C src_otool fcleana

re: fclean all

nm: 
	./ft_nm ft_p/serveur

cnm: ft_nm nm

nmv:
	nm ft_p/serveur

nme: cnm nmv

otool: ft_otool
	./ft_otool
