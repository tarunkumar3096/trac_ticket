#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <conv_utils.h>
#include <infix.h>
#define OP_STACK 0
extern char opstack[100];
extern int flag;
extern int top;
char expr[100];
int post_exp;

static void append(int operand)
{
	if (flag == 0) {
		expr[post_exp++] = operand;
	} else {
		expr[post_exp++] = ' ';
		expr[post_exp++] = operand;
		flag = 0;
	}
}

static char *evaluate_infix(char *input)
{
	int i = 0;
	char token;

	top = -1;
	for (i = 0; input[i] != '\0'; i++) {
		if (isdigit(input[i])) {
			append(input[i]);
		} else if (input[i] == '(') {
			push(OP_STACK, input[i]);
		} else if (input[i] == ')') {
			token = pop(OP_STACK);
			while (token != '(') {
				flag = 1;
				append(token);
				token = pop(OP_STACK);
			}
		} else {
			while ((top != -1) &&
			       (precedence(opstack[top])
				>= precedence(input[i]))) {
				flag = 1;
				append(pop(OP_STACK));
			}
			flag = 1;
			push(OP_STACK, input[i]);
		}
	}
	while (top != -1) {
		flag  = 1;
		append(pop(OP_STACK));
	}
	return expr;
}

static bool input_validate(char *input)
{
	int i = 0;
	int check = 0;
	int operator = 0;

	while (input[i] != '\0') {
		if (!isdigit(input[i]) &&
		    ((precedence(input[i]) >= 2)
		     && (precedence(input[i+1])) >= 2))
			return 0;
		if (precedence(input[i]) == 1)
			check++;
		if (precedence(input[i]) >= 2)
			operator++;
		if (isdigit(input[i])
		    || precedence(input[i]))
			i++;
		else
			return 0;
	}
	if ((!isdigit(input[0]) && !(precedence(input[0]) == 1)) ||
	    ((!isdigit(input[i-1])) && !(precedence(input[i-1]) == 1)))
		return 0;
	if (((check % 2) == 1) || (!operator))
		return 0;
	return 1;
}

int main(void)
{
	char *postfix;
	char *expr;
	int breaker = 1;

	while (breaker) {
		expr = read_input(OP_STACK);
		if (input_validate(expr)) {
			postfix = evaluate_infix(expr);
			if (!postfix_expr(postfix))
				continue;
			breaker = 0;
		} else {
			printf("Not a valid input\n");
		}
	}
	return 0;
}
