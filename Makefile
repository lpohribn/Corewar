# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/24 19:41:22 by rnovodra          #+#    #+#              #
#    Updated: 2018/09/24 19:41:24 by rnovodra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS		+=	-s

SRC_DIR			:=	src/
OBJ_DIR			:=	obj/
INC_DIR			:=	inc/
LIB_DIR			:=	lib/

LIBFT_DIR		:=	$(LIB_DIR)libft/
LIBFT			:=	$(LIBFT_DIR)libft.a

PRINTF_DIR		:=	$(LIB_DIR)ft_printf/
LIBPRINTF		:=	$(PRINTF_DIR)libftprintf.a

CW				:=	corewar
CW_DIR			:=	corewar/
CW_SRC_DIR		:=	$(SRC_DIR)$(CW_DIR)
CW_VM_DIR		:=	vm/
CW_OP_DIR		:=	operation/
CW_VIS_DIR		:=	visualization/
CW_NET_DIR		:=	network/

CW_OBJ_DIR		:=	$(OBJ_DIR)$(CW_DIR)
CW_VM_OBJ_DIR	:=	$(CW_OBJ_DIR)$(CW_VM_DIR)
CW_OP_OBJ_DIR	:=	$(CW_OBJ_DIR)$(CW_OP_DIR)
CW_VIS_OBJ_DIR	:=	$(CW_OBJ_DIR)$(CW_VIS_DIR)
CW_NET_OBJ_DIR	:=	$(CW_OBJ_DIR)$(CW_NET_DIR)

CW_SRC_VM		:=	main.c				\
					usage.c				\
					g_fnop.c			\
					xerror.c			\
					xexit.c				\
					get_arg.c			\
					get_arg_val.c		\
					set_reg.c			\
					get_reg.c			\
					handle_option.c		\
					handle_champion.c	\
					handle_arguments.c	\
					handle_file.c		\
					prepare_game.c		\
					game.c				\
					handle_codage.c		\
					change_pc_pos.c		\
					set_memory.c		\
					dump_memory.c		\
					delete_pc.c			\
					create_pc.c			\
					break_plives.c

CW_SRC_OP		:=	arithmetic_op.c		\
					live_op.c			\
					load_op.c			\
					aff_op.c			\
					st_op.c				\
					bitwise_op.c		\
					zjmp_op.c			\
					loadindex_op.c		\
					sti_op.c			\
					fork_op.c

CW_SRC_VIS		:=	init_ncurses.c		\
					prepare_visual.c 	\
					visualize.c			\
					print_window.c		\
					print_memory.c		\
					record_pc.c			\
					print_title.c		\
					key_events.c		\
					print_game.c		\
					print_pc_list.c     \
					print_info.c 		\
					print_winner.c 		\
					print_hearts.c		\
					print_connections.c	\
					record_live.c

CW_SRC_NET		:=	create_server.c		\
					create_client.c		\
					connect_request.c	\
					handle_clients.c	\
					sending_data.c		\
					server.c			\
					is_valid_ip.c		\
					recv_token.c		\
					send_token.c		\
					display_countdown.c	\
					shift_players.c		\
					get_client.c		\
					client.c

CW_SRC			:=	$(CW_SRC_VM:%=$(CW_VM_DIR)%)\
					$(CW_SRC_OP:%=$(CW_OP_DIR)%)\
					$(CW_SRC_VIS:%=$(CW_VIS_DIR)%)\
					$(CW_SRC_NET:%=$(CW_NET_DIR)%)
CW_OBJ			:=	$(CW_SRC:%.c=$(CW_OBJ_DIR)%.o)

CW_HEADER		:=	$(INC_DIR)$(CW_DIR)corewar.h
CW_VIS_HEADER	:=	$(INC_DIR)$(CW_DIR)visualization.h
CW_NET_HEADER	:=	$(INC_DIR)$(CW_DIR)network.h
HCW_FLAGS		:=	-I $(INC_DIR)$(CW_DIR)

NCURSES_FLAGS	:=	-lncurses

CW_HEADERS		:=	$(CW_HEADER) $(CW_VIS_HEADER) $(CW_NET_HEADER)

ASM				:=	asm
ASM_DIR			:=	asm/
ASM_SRC_DIR		:=	$(SRC_DIR)$(ASM_DIR)
ASM_OBJ_DIR		:=	$(OBJ_DIR)$(ASM_DIR)

ASM_SRC			:=	main.c				\
					parcel_line.c		\
					get_header.c		\
					get_labels.c		\
					get_commands.c		\
					get_arguments.c		\
					get_type.c			\
					final_validation.c	\
					save_data.c			\
					write_file.c		\
					print_error.c		\
					print_bot.c

ASM_OBJ			:=	$(ASM_SRC:%.c=$(ASM_OBJ_DIR)%.o)
ASM_HEADER		:=	$(INC_DIR)$(ASM_DIR)asm.h
HASM_FLAGS		:=	-I $(INC_DIR)$(ASM_DIR)

OP_HEADER		:=	$(INC_DIR)op.h
OP_SRC			:=	$(SRC_DIR)op.c
OP_OBJ			:=	$(OBJ_DIR)op.o

HFLAGS			:=	-I $(INC_DIR)
HLIB_FLAGS		:=	-I $(PRINTF_DIR)$(INC_DIR) -I $(LIBFT_DIR)$(INC_DIR)
LIBS_FLAGS		:=	-L $(PRINTF_DIR) -lft -L $(LIBFT_DIR) -lftprintf

CFLAGS			:=	-Wall -Werror -Wextra -std=c11 -O3

TB				:=	"\\033[36m"
TG				:=	"\\033[32m"
TR				:=	"\\033[31m"
EOC				:=	"\\033[0m"
K				:=	"\\033[K"

.PHONY: all

all: $(CW) $(ASM)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(LIBPRINTF):
	make -C $(PRINTF_DIR)

# 
# compiling op.o
# 

$(OP_OBJ): | $(OBJ_DIR)
	$(CC) -c $(OP_SRC) -o $@ $(CFLAGS) $(HFLAGS)
	printf "$(TB) $@$(EOC)$(K)\r"

$(OBJ_DIR):
	mkdir $@

# 
# compiling corewar
# 

$(CW): $(LIBFT) $(LIBPRINTF) $(OP_OBJ) $(CW_OBJ)
	$(CC) $(CW_OBJ) -o $@ $(LIBS_FLAGS) $(OP_OBJ) $(NCURSES_FLAGS)
	printf "$(TG)$@ created$(EOC)$(K)\n"
	tput cnorm

$(CW_OBJ): | $(OBJ_DIR)\
			$(CW_OBJ_DIR)\
			$(CW_VM_OBJ_DIR)\
			$(CW_OP_OBJ_DIR)\
			$(CW_VIS_OBJ_DIR)\
			$(CW_NET_OBJ_DIR)

$(CW_OBJ_DIR):
	mkdir $@

$(CW_VM_OBJ_DIR):
	mkdir $@

$(CW_OP_OBJ_DIR):
	mkdir $@

$(CW_VIS_OBJ_DIR):
	mkdir $@

$(CW_NET_OBJ_DIR):
	mkdir $@

$(CW_OBJ_DIR)%.o: $(CW_SRC_DIR)%.c $(CW_HEADERS) $(OP_HEADER) 
	tput civis
	$(CC) -c $< -o $@ $(CFLAGS) $(HFLAGS) $(HCW_FLAGS) $(HLIB_FLAGS)
	printf "$(TB)$(CW): $@$(EOC)$(K)\r"

# 
# compiling asm
# 

$(ASM): $(LIBFT) $(LIBPRINTF) $(OP_OBJ) $(ASM_OBJ)
	$(CC) $(ASM_OBJ) -o $@ $(LIBS_FLAGS) $(OP_OBJ)
	printf "$(TG)$@ created$(EOC)$(K)\n"
	tput cnorm

$(ASM_OBJ): | $(OBJ_DIR) $(ASM_OBJ_DIR)

$(ASM_OBJ_DIR):
	mkdir $(ASM_OBJ_DIR)

$(ASM_OBJ_DIR)%.o: $(ASM_SRC_DIR)%.c $(ASM_HEADER) $(OP_HEADER)
	tput civis
	$(CC) -c $< -o $@ $(CFLAGS) $(HFLAGS) $(HASM_FLAGS) $(HLIB_FLAGS)
	printf "$(TB)$(ASM): $@$(EOC)$(K)\r"

# 
# cleaning
# 

.PHONY: clean-corewar fclean-corewar

clean-corewar:
	rm -rf $(CW_OBJ_DIR)
	printf "$(TR)$@$(EOC)\n"

fclean-corewar:
	rm -rf $(CW_OBJ_DIR)
	rm -f $(CW)
	printf "$(TR)$@$(EOC)\n"

.PHONY: clean-asm fclean-asm

clean-asm:
	rm -rf $(ASM_OBJ_DIR)
	printf "$(TR)$@$(EOC)\n"

fclean-asm:
	rm -rf $(ASM_OBJ_DIR)
	rm -f $(ASM)
	printf "$(TR)$@$(EOC)\n"

clean: clean-corewar clean-asm
	make clean -C $(PRINTF_DIR)
	make clean -C $(LIBFT_DIR)

fclean: fclean-corewar fclean-asm
	make fclean -C $(PRINTF_DIR)
	make fclean -C $(LIBFT_DIR)
	rm -rf $(OBJ_DIR)

.PHONY: re-corewar re-asm

re-corewar: fclean-corewar $(CW)

re-asm: fclean-asm $(ASM)

re: fclean all

.PHONY: clean fclean re

# 
# usage
# 

.PHONY: help

help:
	printf "usage:	make [all | asm | corewar | clean-asm | clean-corewar | fclean-asm | fclean-corewar]\n"
