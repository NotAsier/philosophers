# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/08 10:38:23 by aarranz-          #+#    #+#              #
#    Updated: 2024/06/12 10:34:30 by aarranz-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	philosophers
SRC_PATH	:=	src
OBJ_DIR		:=	obj
SOURCES		:=	philo.c atoi.c lst_utils.c routine.c time.c print_actions.c parse_philos.c watcher.c
OBJS		:=	$(SOURCES:%.c=$(OBJ_DIR)/%.o)
CC			:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror -I./include -g3 #-fsanitize=address

PAPYRUS=\033[38;5;223m
END=\033[0m

define PHILO
$(PAPYRUS)
                      ░░░░    ░░░░                                  
                    ░░▒▒▓▓██████░░    ░░▒▒██████░░
                    ░░████      ██░░░░░░██      ██░░                
                    ▒▒████    ████░░░░▒▒██    ████░░                
                    ▒▒██▓▓      ██░░░░▒▒██      ██░░                
                      ▒▒████████░░    ▒▒████████▒▒                  
                      ▒▒▒▒██░░██████░░▒▒██░░▓▓▓▓░░                  
                ░░▒▒████████████░░░░██████  ▓▓██████▒▒              
              ▒▒████▒▒░░  ░░░░██░░██░░░░░░████▒▒    ▒▒▓▓            
          ░░▒▒██░░██▒▒▓▓████░░░░██░░░░██░░██▒▒  ▒▒██▓▓░░██          
     ░░░░▒▒██▒▒██░░  ▓▓██▒▒██  ░░████░░██░░  ▒▒▓▓▒▒▓▓████░░░░▒▒░░  
    ░░▒▒██████░░░░  ▓▓▓▓▒▒▒▒▒▒██░░░░░░░░██████▓▓▒▒▒▒▒▒▓▓██▒▒▓▓██████
    ▒▒██░░▓▓████████▓▓▒▒▒▒▒▒▒▒██████████░░██▓▓▒▒▒▒▒▒▒▒▒▒██████░░░░██
  ▒▒▓▓▒▒░░▓▓██▒▒██▓▓▒▒▒▒▒▒▒▒▒▒██░░░░░░██░░▓▓▓▓▒▒▒▒▒▒▒▒▒▒██  ░░████  
  ▒▒██░░▓▓▓▓██░░▒▒██▓▓████████░░░░██████░░░░▒▒██▒▒▒▒▒▒██░░░░██      
  ▒▒██░░██░░▒▒██░░░░██▒▒  ░░░░██████▒▒  ██▓▓▒▒████████░░████░░      
  ▒▒██▒▒██▒▒▒▒██████░░▓▓████░░░░██░░██░░██▓▓  ░░██▒▒████░░          
  ▒▒██████████░░▒▒▒▒██████░░██░░░░████░░  ░░██░░  ██░░              
    ▒▒▓▓██▒▒░░░░████░░░░░░██░░██░░██▓▓██░░░░████  ██▒▒░░            
    ▒▒██░░██████▓▓▒▒██████▒▒░░██░░██▓▓██  ░░████░░  ██░░            
    ▒▒██▓▓▒▒▒▒▒▒▒▒██░░░░░░░░██░░░░██▓▓████  ██▓▓██  ██░░            
      ▒▒▒▒  ░░▒▒██▒▒░░▓▓██████  ██▓▓▒▒████  ██▓▓██░░▓▓▓▓            
              ▒▒██░░████████░░██▒▒▒▒████▒▒██▓▓▒▒██░░██▓▓            
          ▒▒████░░░░▓▓▓▓▓▓████░░▒▒▒▒██▒▒▒▒██▓▓██░░▓▓▓▓              
        ▒▒▒▒████░░  ██▓▓▒▒██▓▓░░░░▒▒██▒▒▒▒██▒▒██░░▒▒▓▓              
        ▒▒██░░░░▒▒██▓▓░░░░░░░░░░░░  ████▓▓▒▒▒▒██░░▓▓▓▓              
        ▒▒████████░░░░  ░░░░░░░░░░          ░░██████░░              
$(END)
endef
export PHILO

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$$PHILO"

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_PATH)/%.c $(OBJ_DIR)
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	@rm -fr $(OBJ_DIR)

fclean:
	@rm -fr $(OBJ_DIR)
	@rm -f $(NAME) philosophers.a

re: fclean all

.PHONY: all clean fclean re

