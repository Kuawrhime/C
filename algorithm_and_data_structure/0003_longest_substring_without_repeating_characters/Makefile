##
## KORO PROJECT, 2026
##
## File description:
## 
##

SRC		=	longest_substring_without_repeating_characters.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-Wall -Wextra

TESTS_SRC	=	unit_test/longest_substring_without_repeating_characters_test.c

all:		$(OBJ)

$(OBJ):		$(SRC)
		gcc -c $(SRC) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f unit_tests

re:		fclean all

tests_run:	all
		gcc -o unit_tests $(SRC) $(TESTS_SRC) $(CFLAGS) -lcriterion
		./unit_tests; ret=$$?; rm -f unit_tests; exit $$ret

.PHONY:		all clean fclean re tests_run
