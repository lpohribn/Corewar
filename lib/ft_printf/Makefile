# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/28 17:17:15 by rnovodra          #+#    #+#              #
#    Updated: 2018/04/28 17:17:19 by rnovodra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS	+=	-s

NAME		=	libftprintf.a
HEADER		=	$(INC_DIR)ft_printf.h

SRC			=	ft_printf.c					\
				ft_dprintf.c				\
				ft_vdprintf.c				\
				ft_fprintf.c				\
				ft_print_buff.c				\
				ft_spec.c					\
				ft_set_flags.c				\
				ft_conv.c					\
				ft_star.c					\
				ft_count_arg.c				\
				ft_int.c					\
				ft_printf_itoa.c			\
				ft_count_dig.c				\
				ft_width_prec_sign.c		\
				ft_char.c					\
				ft_string.c					\
				ft_wstring.c				\
				ft_write_nbr_chr.c			\
				ft_float.c					\
				ft_printf_dtoa.c			\
				ft_handle_nan.c				\
				ft_get_float_val.c			\
				ft_expo_form.c				\
				ft_g_float.c				\
				ft_color.c					\
				ft_nonprint_char_str.c		\
				ft_print_date.c				\
				ft_two_dimensional_array.c	\
				ft_a_float.c
				
OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

SRC_DIR		=	src/
OBJ_DIR		=	obj/
INC_DIR		=	inc/

INC_LIBDIR	=	./../libft/$(INC_DIR)

HEAD_FLAGS	=	-I $(INC_DIR) -I $(INC_LIBDIR)

CC_FLAGS	=	-Wall -Werror -Wextra -std=c11 -O3

TB			=	"\\033[36m"
TG			=	"\\033[32m"
TR			=	"\\033[31m"
EOC			=	"\\033[0m"
K			=	"\\033[K"

all: $(NAME)
	tput cnorm

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	printf "$(TG)$@ created$(EOC)$(K)\n"
	
$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	tput civis
	$(CC) -c $< -o $@ $(CC_FLAGS) $(HEAD_FLAGS)
	printf "$(TB)$(NAME): $@$(EOC)$(K)\r"

clean:
	rm -f $(OBJ)
	printf "$(TR)$@ $(NAME)$(EOC)\n"

fclean:
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)
	printf "$(TR)$@ $(NAME)$(EOC)\n"

re: fclean all

.PHONY: all fclean clean re 
