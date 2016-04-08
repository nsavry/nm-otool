NAME = ../ft_otool

FTC =	ft_main.c\
		ft_nm.c\
		ft_print.c\
		ft_error.c

FTO = $(subst .c,.o,$(FTC))

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(FTO)
	@gcc -o $(NAME) $(FTO) ../libft/libft.a
	@echo "\033[32m\nft_otool created!\033[0m"

%.o: %.c
	@gcc -Wall -Wextra -Werror -I../libft/includes -I./includes -c $<
	@echo "\033[33m.\033[0m\c"

clean:
	@rm -rf $(FTO)
	@echo "\033[33mft_otool object deleted!\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[31mft_otool deleted!\033[0m"

fcleana:
	@rm -rf $(NAME)
	@echo "\033[31mft_otool deleted!\033[0m"

lib:
	@make -C ../libft

re: fclean all
