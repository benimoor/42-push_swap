NAME = push_swap
BONUS = checker
CC = cc
OBJS_DIR = objs
BONUS_OBJS_DIR = bonus_objs
SRCS_DIR = src
BONUS_DIR = src
FLAGS =  -Wall -Werror -Wextra -g -Iincludes
SRCS = $(filter-out $(SRCS_DIR)/checker.c $(SRCS_DIR)/main_bonus.c $(SRCS_DIR)/actions_bonus.c, $(wildcard $(SRCS_DIR)/*.c))
BONUS_SRCS = $(filter-out $(SRCS_DIR)/main.c, $(wildcard $(SRCS_DIR)/*.c))
OBJS = $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))
BONUS_OBJS = $(patsubst $(BONUS_DIR)/%.c, $(BONUS_OBJS_DIR)/%.o, $(BONUS_SRCS))
RM = rm -rf
MKDIR = mkdir -p

.DEFAULT_GOAL = all
all: $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJS_DIR):
	$(MKDIR) $(OBJS_DIR)

$(BONUS_OBJS_DIR):
	$(MKDIR) $(BONUS_OBJS_DIR)


$(NAME): $(OBJS) | $(OBJS_DIR)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

# bonus : 
bonus:	  $(BONUS_OBJS_DIR) $(BONUS)


$(BONUS_OBJS_DIR)/%.o: $(BONUS_DIR)/%.c | $(BONUS_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(BONUS): $(BONUS_OBJS) | $(BONUS_OBJS_DIR)
	$(CC) $(FLAGS) $(BONUS_OBJS) -o $(BONUS)
clean:
	$(RM) $(OBJS_DIR) $(BONUS_OBJS_DIR)

fclean: clean
	$(RM) $(NAME) $(BONUS)

re: fclean all

push:
	@git add .
	@git commit -m "$m"
	@git push

.PHONY: all clean fclean re bonus push
