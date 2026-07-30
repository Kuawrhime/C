##
## KORO PROJECT, 2025
## 
## File description:
## Makefile for gpa_calculator
##

NAME		=	gpa_calculator

SRC		=	main.c gpa_calculator_output_writer.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-Wall -Wextra

TESTS_SRC	=	unit_test/gpa_calculator_test.c

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

tests_run:	$(NAME)
		gcc -o unit_tests $(TESTS_SRC) $(CFLAGS) -lcriterion
		./unit_tests; ret=$$?; rm -f unit_tests; exit $$ret


.PHONY:		all clean fclean re tests_run
