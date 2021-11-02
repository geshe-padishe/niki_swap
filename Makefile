NAME			= push_swap_libft
EX_NAME			= push_swap

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror

FLAGS			= -L ${LIBFT_D} -lft
RM				= rm -f
AR				= ar rcs

SRC_D			= srcs
SRCS_LIST		= ft_ps_dsort2_utils.c ft_ps_parse_utils.c \
                  ft_push_swap.c ft_push_swap2.c ft_ps_sort_utils.c \
                  ft_ps_dsort_utils.c ft_ps_move.c ft_ps_parse.c
SRC_C			= $(addprefix ${SRC_D}/, ${SRCS_LIST})

INC_D			= includes
HEADER_LIST		= ft_push_swap.h
HEADER_H		= $(addprefix ${INC_D}/, ${HEADER_LIST})

LIBFT			= libft.a
LIBFT_D			= libft
LIBFT_A			= $(addprefix ${LIBFT_D}/, ${LIBFT})

OBJS			= ${SRC_C:.c=.o}

all:			${NAME}

${NAME}:		${OBJS}
				make -C ${LIBFT_D}
				cp ${LIBFT_D}/${LIBFT} ${NAME}
				${AR} ${NAME} ${OBJS}
				${CC} ${NAME} -o ${EX_NAME}

%.o: %.c ${HEADER_H}
				${CC} ${CFLAGS} -I${INC_D} -I${LIBFT_D} -o $@ -c $<

clean:
				$(MAKE) -C ${LIBFT_D} clean
				${RM} ${OBJS}

fclean: clean
				$(MAKE) -C ${LIBFT_D} fclean
				${RM} ${NAME} ${EX_NAME}

re: 			fclean all
