# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/18 19:13:31 by tvermeil          #+#    #+#              #
#    Updated: 2017/09/26 16:22:21 by tvermeil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-print-directory

NAME = libfts.a

SUB_MAKEFILES_PATH = test

SRC_PATH = src
HEADER_PATH = include/libfts
PRIVATE_HEADER_PATH = 

ROOT = .
OBJ_FOLDER = obj/$(NAME)
INC_PATH =	$(HEADER_PATH) \
			$(PRIVATE_HEADER_PATH) \

OBJ_PATH = $(ROOT)/$(OBJ_FOLDER)
DST_PATH = $(ROOT)

CC = nasm
CFLAGS = -f macho64
CPPFLAGS = $(addprefix -I ,$(INC_PATH))
LDFLAGS = -macosx_version_min 10.8
LDLIBS = -lSystem

SRC_NAME = 		ft_bzero.s \
				ft_strcat.s \
				ft_isalpha.s \
				ft_isdigit.s \
				ft_isalnum.s \
				ft_isascii.s \
				ft_isprint.s \
				ft_toupper.s \
				ft_tolower.s \
				ft_puts.s \
				ft_strlen.s \
				ft_memset.s \
				ft_memcpy.s \
				ft_strdup.s \
				ft_cat.s \
				ft_putchar.s \
				ft_putstr.s \
				ft_putstr_fd.s \
				ft_memcmp.s \
				ft_strcmp.s \
				ft_strncmp.s \
				ft_memalloc.s \

HEADER_NAME =	libfts.h \

PRIVATE_HEADER_NAME =	\

OBJ_NAME = $(SRC_NAME:.s=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
DST = $(addprefix $(DST_PATH)/,$(NAME))
HEADER_FILES = $(addprefix $(HEADER_PATH)/,$(HEADER_NAME)) \
			   $(addprefix $(SRC_PATH)/,$(PRIVATE_HEADER_NAME))

all: $(DST)

$(OBJ_PATH)%.o: $(SRC_PATH)%.s $(HEADER_FILES)
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(CPPFLAGS) $< -o $@
	@echo -n .

$(DST): $(OBJ) $(HEADER_FILES)
	@ar rcs $(NAME) $(OBJ)
	@echo " . \033[32m$(NAME)\033[0m done"

clean:
	@-cd $(ROOT) && rm -fv $(addprefix $(OBJ_FOLDER)/,$(OBJ_NAME))
	@rmdir $(OBJ_PATH) $(ROOT)/obj 2> /dev/null || true
	@make -C test clean

fclean: clean
	@-cd $(ROOT) && rm -fv $(addprefix $(DST_PATH)/,$(NAME))
	@make -C test fclean

re: fclean all

ac: all clean

check: $(DST)
	@make -C test check

.PHONY: all clean fclean re ac check
