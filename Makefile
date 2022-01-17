NAME			= webserv


FILES_PARSING	= parser_request.cpp
FILES			= main.cpp $(addprefix parsing/, ${FILES_PARSING})


INC_PATH		= includes
INC_FILES		= webserv.hpp
INC				= $(addprefix ${INC_PATH}/, ${INC_FILES}) $(addprefix class/, Data.hpp)

SRC_PATH		= .
SRC				= $(addprefix ${SRC_PATH}/, ${FILES})

BIN_PATH		= bin
BIN 			= $(SRC:%.cpp=$(BIN_PATH)/%.o)

CC				= clang++
RM				= rm -rf
FLAGS			= -std=c++98 -Wall -Wextra  -Werror -fsanitize=address -g3

all: 			${NAME}

$(BIN): $(BIN_PATH)/%.o: %.cpp ${INC}
				@mkdir -p $(@D)
				@$(CC) $(FLAGS) -I ${INC_PATH} -o $@ -c $<
				@printf "\e[?25l\e[J $(NAME) : \e[92m$(notdir $<)\e[0m\r"

${NAME}: 		init ${BIN}
				@${CC} ${FLAGS} ${BIN} -o ${NAME} -I ${INC_PATH}
				@printf '\033[?25l\033[J$(NAME) \033[92m✔ \033[0m\033[?25h\n'

clean:
				@${RM} ${BIN_PATH}
				@printf '\033[?25l\033[J$(NAME) DELETED \033[92m✔ \033[0m\033[?25h\n'

fclean:
				@${RM} ${BIN_PATH}
				@${RM} ${NAME}
				@printf '\033[?25l\033[J$(NAME) DELETED \033[92m✔ \033[0m\033[?25h\n'

re:				fclean all

.PHONY: all clean fclean re bonus init