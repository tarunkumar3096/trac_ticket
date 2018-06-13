
/**
 * precedence() - The function use to return operator rank
 * @arg1 - It is integer argument
 * 
 * Function will return precendence of the operator.
 *
 * Return - returns precedence of operator
 */
int precedence(int operator);

/**
 * push() - The function use to push the element into array
 * @arg1 - It is integer argument
 * @arg2 - It is integer argument
 *
 * Function will push the operand into the array based on the conditon.
 *
 */
void push(int condition, int operand);

/**
 * pop() - The function use to return the data from array
 * @arg1 - It is integer argument
 * 
 * Function will return data from array based on the condition.
 *
 * Return - returns integer data from array
 */
int pop(int condition);

/**
 * check_expr() - The function use to check the given expression
 * @arg1 - It is the pointer to the character.
 * 
 * Function will return the integer based on the input expression.
 *
 * Return - returns boolean value based on error condition.
 */
bool check_expr(char *input);

/**
 * arthimetic_operation() - The function use to perform the arthimetic operation of the operand
 * @arg1 - It is the integer argument
 * 
 * Function will perform the arthimetic operation of the operand based on the input operator
 *
 * Return - returns boolean value based on the input opertor
 */	
static bool arthimetic_operation(int operator);

/**
 * evaluate_postfix() - The function use to push and pop the expression
 * @arg1 - It is the pointer to the character.
 * 
 * Function will push the operand or do arthimetic operation when operand is the operator.
 *
 * Return - returns boolean value based on the input expression.
 */
bool evaluate_postfix(char *expr);

/**
 * display() - The function use to display the output.
 * 
 * Function will display the output of the postfix expression.
 *
 */	
void display();

/**
 * read_input() - The function use to read the input from the user.
 * @arg1 - It is a integer argument.
 * 
 * Function will get the input expression from the user based on the input condition.
 *
 * Return - returns character pointer of the expression.
 */
char *read_input(int condition);

/**
 * postfix_expr() - The function use to evaluate the postfix expression
 * @arg1 - It is the pointer to the character.
 * 
 * Function will evaluate the postfix expression and return the error condition.
 *
 * Return - returns boolean value based on the input expression.
 */
bool postfix_expr(char *expr);
	
	
	
	
