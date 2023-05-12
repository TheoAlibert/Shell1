##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## library MY
##
SRC = my_compute_power_rec.c	\
	my_compute_square_root.c	\
	my_find_sup.c	\
	my_getnbr.c	\
	my_is_prime.c	\
	my_isneg.c	\
	my_put_nbr.c	\
	my_putchar.c	\
	my_putstr.c	\
	my_putfloat.c	\
	my_putfloat_prec.c	\
	my_putsci.c	\
	my_put_address.c	\
	my_revstr.c	\
	my_show_word_array.c	\
	my_str_isalpha.c	\
	my_str_islower.c	\
	my_str_isnum.c	\
	my_str_isprintable.c	\
	my_str_isupper.c	\
	my_str_to_word_array.c	\
	my_strcapitalize.c	\
	my_biggest_len.c	\
	my_strcat.c	\
	my_strcmp.c	\
	my_strcpy.c	\
	my_strlen.c	\
	my_strlowcase.c	\
	my_strncat.c	\
	my_strncmp.c	\
	my_strncpy.c	\
	my_strstr.c	\
	my_strupcase.c	\
	my_swap.c	\
	my_printf.c	\
	struct_my_printf.c	\
	check_flag.c	\
	my_nbrlen.c	\
	my_convert_base.c	\
	flag_i.c	\
	flag_base.c	\
	flag_f.c	\
	flag_e.c	\
	flag_g.c	\
	flag_c.c	\
	flag_s.c	\
	flag_p.c

OBJ = $(SRC:.c=.o)

NAME = libmy.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
	cp my.h ../../include/

clean:
	rm -f $(OBJ)
	rm -f test_my_printf
	rm -f *.gcda
	rm -f *.gcno

fclean:
	rm -f $(OBJ)
	rm -f $(NAME)
	rm -f ../$(NAME)
	rm -f test_my_printf
	rm -f *.gcda
	rm -f *.gcno
	rm -f ../../include/my.h

re: fclean all

unit_tests: fclean all
	gcc -o test_my_printf ../../tests/*.c $(OBJ) --coverage -lcriterion

run_tests: unit_tests
	./test_my_printf
