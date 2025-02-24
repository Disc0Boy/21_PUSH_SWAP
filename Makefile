NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

BOLD        = \033[1m
ITALIC      = \033[3m
BLACK       = \033[38;2;0;0;0m
GRAY        = \033[38;2;146;146;146m
LIGHT_BLUE  = \033[38;2;111;168;220m
TEAL        = \033[38;2;66;180;175m
TURQUOISE   = \033[38;2;82;203;176m
CORAL       = \033[38;2;255;127;80m
SALMON      = \033[38;2;250;128;114m
VIOLET      = \033[38;2;147;112;219m
RESET       = \033[0m

LOADING_BAR = [━━━━━━━━━━━━━━━━━━━━]

SRCS		= src/main.c \
			  src/utils/list_utils.c \
			  src/utils/sort_utils.c \
			  src/utils/validation.c \
			  src/utils/parse_utils.c \
			  src/utils/split_args.c \
			  src/operations/push.c \
			  src/operations/swap.c \
			  src/operations/rotate.c \
			  src/operations/reverse_rotate.c \
			  src/algorithms/small_sort.c \
			  src/algorithms/large_sort.c

OBJS		= $(SRCS:.c=.o)

TOTAL_FILES	= $(words $(SRCS))
CURRENT_FILE	= 0

define update_progress
	$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE)+1))))
	$(eval PERCENTAGE=$(shell echo $$(($(CURRENT_FILE)*100/$(TOTAL_FILES)))))
	printf "\r$(LIGHT_BLUE)$(LOADING_BAR) $(GRAY)$(PERCENTAGE)%% - $(ITALIC)Compiling: $(TEAL)$<$(RESET)"
endef

all: banner $(NAME)

banner:
	@printf "\n$(VIOLET)$(BOLD)"
	@printf "██████╗ ██╗   ██╗███████╗██╗  ██╗    ███████╗██╗    ██╗ █████╗ ██████╗ \n"
	@printf "██╔══██╗██║   ██║██╔════╝██║  ██║    ██╔════╝██║    ██║██╔══██╗██╔══██╗\n"
	@printf "██████╔╝██║   ██║███████╗███████║    ███████╗██║ █╗ ██║███████║██████╔╝\n"
	@printf "██╔═══╝ ██║   ██║╚════██║██╔══██║    ╚════██║██║███╗██║██╔══██║██╔═══╝ \n"
	@printf "██║     ╚██████╔╝███████║██║  ██║    ███████║╚███╔███╔╝██║  ██║██║     \n"
	@printf "╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝    ╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝     \n"
	@printf "$(RESET)\n"
	@printf "$(TEAL)$(ITALIC)Starting compilation process...$(RESET)\n\n"

$(NAME): $(OBJS)
	@printf "\n$(TURQUOISE)$(BOLD)All files compiled successfully!$(RESET)\n"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@printf "$(TURQUOISE)$(BOLD)Executable '$(NAME)' created successfully!$(RESET)\n"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(call update_progress)

clean:
	@$(RM) $(OBJS)
	@printf "$(CORAL)Object files cleaned!$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(SALMON)Executable removed!$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re banner