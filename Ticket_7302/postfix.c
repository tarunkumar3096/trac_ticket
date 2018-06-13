#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <conv_utils.h>
#include <postfix.h>

int main(void)
{
	char *expr;
	int breaker = 1;

	while (breaker) {
		expr = read_input(POS_STACK);
		if (check_expr(expr) && (evaluate_postfix(expr))) {
			display();
			breaker = 0;
		} else {
			printf("Not a valid input\n");
		}
	}
	return 0;
}
