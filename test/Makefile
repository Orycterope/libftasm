# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/18 19:13:31 by tvermeil          #+#    #+#              #
#    Updated: 2017/09/26 16:07:33 by tvermeil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-print-directory

NAME = tester

ROOT = ..
SRC_PATH = .
DST_PATH = .
LFT_PATH = $(ROOT)
LIBFT = $(LFT_PATH)/libfts.a
HEADER_PATH = $(ROOT)/include/libfts
PRIVATE_HEADER_PATH = .

INC_PATH =	$(HEADER_PATH) \
			$(PRIVATE_HEADER_PATH) \

OBJ_FOLDER = obj/$(NAME)
OBJ_PATH = $(ROOT)/$(OBJ_FOLDER)


CC = gcc -g
LD = gcc -g
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = $(addprefix -I ,$(INC_PATH))
LDFLAGS = -L$(LFT_PATH)
LDLIBS = -lfts

MAIN_NAME =		main.c \

TEST_NAME = 	check_isdigit.c \
				check_isalpha.c \
				check_isalnum.c \
				check_isascii.c \
				check_isprint.c \
				check_toupper.c \
				check_tolower.c \
				check_strcat.c \
				check_bzero.c \
				check_memset.c \
				check_memcpy.c \
				check_strlen.c \
				check_putchar.c \
				check_puts.c \
				check_strdup.c \
				check_cat.c \
				check_putstr.c \
				check_putstr_fd.c \
				check_memalloc.c \
				check_memcmp.c \
				check_strncmp.c \
				check_strcmp.c \

HEADER_NAME =	libfts.h \

PRIVATE_HEADER_NAME =	tester.h \

MAIN_OBJ_NAME = $(MAIN_NAME:.c=.o)
TEST_OBJ_NAME = $(TEST_NAME:.c=.o)


MAIN_SRC = $(addprefix $(SRC_PATH)/,$(MAIN_NAME))
TEST_SRC = $(addprefix $(SRC_PATH)/,$(TEST_NAMES))

MAIN_OBJ = $(addprefix $(OBJ_PATH)/,$(MAIN_OBJ_NAME))
TEST_OBJ = $(addprefix $(OBJ_PATH)/,$(TEST_OBJ_NAME))

HEADER_FILES = $(addprefix $(HEADER_PATH)/,$(HEADER_NAME)) \
			   $(addprefix $(SRC_PATH)/,$(PRIVATE_HEADER_NAME))

TEST_EXECS_NAME =	$(TEST_NAME:.c=_exe)
TEST_EXECS = 		$(addprefix $(DST_PATH)/,$(TEST_EXECS_NAME))

all: $(TEST_EXECS)

$(TEST_OBJ): $(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER_FILES)
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@echo -n .

$(MAIN_OBJ): $(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER_FILES)
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@echo -n .

$(TEST_EXECS): $(DST_PATH)/%_exe: $(OBJ_PATH)/%.o $(MAIN_OBJ) $(LIBFT)
	@$(LD) $(LDFLAGS) $(LDLIBS) $(MAIN_OBJ) $< -o $@
	@echo " . \033[32m$@\033[0m done"

clean:
	@-cd $(ROOT) && rm -fv $(addprefix $(OBJ_FOLDER)/,$(MAIN_OBJ_NAME))
	@-cd $(ROOT) && rm -fv $(addprefix $(OBJ_FOLDER)/,$(TEST_OBJ_NAME))
	@rmdir $(OBJ_PATH) $(ROOT)/obj 2> /dev/null || true

check: $(TEST_EXECS)
	@$(foreach t, $(TEST_EXECS), $(t);)

fclean: clean
	@-rm -fv $(TEST_EXECS_NAME)

re: fclean all

ac: all clean

.PHONY: all clean fclean re ac
