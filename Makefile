NAME		=	cub3d
CFLAGS		=	-Wall -Wextra -Werror
FLAGS       =   -lmlx -framework OpenGL -framework AppKit
CC			=	cc
OBJ			=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))
OBJDIR		=	.objfiles
LIBFT		=	libft/libft.a
RED			=	\033[1;31m
GREEN		=	\033[1;32m
YELLOW		=	\033[1;33m
BLUE		=	\033[1;34m
GRAY		=	\033[1;37m
RESET		=	\033[0m
PARSING		=	check_map.c get_next_line.c utils_00.c utils_01.c\
				check_content.c check_texts_colors.c utils_02.c\
				check_player.c check_surrounded.c check_floor_outside.c\
				get_map.c
RAY			=	tools.c press.c moves.c render.c render3d.c inter.c moves3d.c keys.c minimap.c bigmap.c helpminimap.c helpmoves.c init.c my_mlx_pixel.c init2.c keys2.c helprender3d.c
SRC 		=	cub3d.c $(EXEC_SRC) $(PARSE_SRC)
HEADERS		=	parsing.h
EXEC_SRC	=	$(addprefix raycasting/, $(RAY))
PARSE_SRC	=	$(addprefix parsing/, $(PARSING))
HEADER		=	$(addprefix includes/, $(HEADERS))


all			:	$(NAME)
	
$(NAME)		:	$(LIBFT) $(OBJ)
				@$(CC) $(OBJ) -o $(NAME) $(LIBFT) $(FLAGS) #-fsanitize=address
				@echo "$(BLUE)cub3d$(GREEN)\r\t\t\t compiled$(RESET)"

$(LIBFT)	:
				@make -C ./libft
				@echo "$(GREEN)libft:\r\t\t\t compiled$(RESET)"

$(OBJDIR)/%.o	:	%.c $(HEADER)
				@mkdir -p $(dir $@)
				@$(CC) $(CFLAGS) -c $< -o $@
				@echo "$(BLUE)$<:$(RESET)\r\t\t\t $(GREEN)compiled$(RESET)"

clean		:
				@rm -f $(OBJ) $(BONUS_OBJ)
				@echo "$(YELLOW)object files cleaned$(RESET)"

fclean		:	clean
				@rm -f $(NAME) $(BONUS)
				@echo "$(RED)cub3d cleaned$(RESET)"

re			:	fclean all

norm		:
				@printf "$(RED)"
				@norminette | grep Error
				@printf "$(RESET)"
				
run			:	$(NAME)
				./$(NAME) maps/map.cub

.PHONY		:	clean all fclean re