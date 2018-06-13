#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <conv_utils.h>
#define POS_STACK 1
#define OP_STACK 0
int flag;
int top;
int stack[100];
int value[100];
char opstack[100];

int precedence(int operator)
{
	if ((operator == '*') || (operator == '/'))
		return 3;
	else if ((operator == '+') || (operator == '-'))
		return 2;
	else if ((operator == '(') || (operator == ')'))
		return 1;
	return 0;
}

void push(int condition, int operand)
{
	int prev = 0;

	if (condition) {
		if (flag == 0) {
			stack[++top] = operand;
			flag = 1;
		} else {
			prev = pop(POS_STACK);
			stack[++top] = operand + (prev * 10);
			flag = 1;
		}
	} else {
		opstack[++top] = operand;
	}
}

int pop(int condition)
{
	if (condition)
		return stack[top--];
	return opstack[top--];
}

bool check_expr(char *input)
{
	int i = 0;

	for (i = 0; input[i] != '\0'; i++) {
		if ((input[i] == ' ') &&
		    ((input[i+1] == ' ') || (input[i+1] == '\0')))
			return 0;
		if (precedence(input[i]) >= 2) {
			if (((input[i-1] == ' ') && ((input[i+1] == ' ') ||
						     (input[i+1] == '\0'))))
				continue;
			else
				return 0;
		}
	}
	return 1;
}

static bool arthimetic_operation(int operator)
{
	int operand1;
	int operand2;
	int output;

	flag = 0;
	operand2 = pop(POS_STACK);
	operand1 = pop(POS_STACK);
	stack[top+1] = 0;
	stack[top+2] = 0;
	switch (operator) {
	case '+':
		output = (operand1) + (operand2);
		push(POS_STACK, output);
		break;
	case '-':
		output = (operand1) - (operand2);
		push(POS_STACK,  output);
		break;
	case '*':
		output = (operand1) * (operand2);
		push(POS_STACK, output);
		break;
	case '/':
		output = (operand1) / (operand2);
		push(POS_STACK, output);
		break;
	default:
		return 0;
	}
	return 1;
}

bool evaluate_postfix(char *expr)
{
	int i;
	bool validation;

	flag = 0;
	top = -1;
	for (i = 0; i < strlen(expr); i++) {
		if (isdigit(expr[i])) {
			push(POS_STACK, expr[i] - '0');
		} else if (expr[i] == ' ') {
			flag = 0;
		} else if (top != 0) {
			if (!arthimetic_operation(expr[i]))
				return 0;
		} else {
			return 0;
		}
	}
	if (stack[1] != 0)
		return 0;
	return 1;
}

void display(void)
{
	if (top < 0)
		printf("stack is empty\n");
	else
		printf("result = %d\n", stack[0]);
}

char *read_input(int condition)
{
	static char expr[100];

	if (condition) {
		printf("Enter the expression\n");
		printf("Provide space between operand and operator\n");
	} else {
		printf("Enter the infix expression\n");
	}
	fgets(expr, 100, stdin);
	expr[strlen(expr) - 1] = '\0';

	return expr;
}

bool postfix_expr(char *expr)
{
	int breaker = 1;

	while (breaker) {
		if (check_expr(expr) && (evaluate_postfix(expr))) {
			printf("Postfix expression = %s\n", expr);
			display();
			breaker = 0;
		} else {
			printf("Not a valid input\n");
			return 0;
		}
	}
	return 1;
}
