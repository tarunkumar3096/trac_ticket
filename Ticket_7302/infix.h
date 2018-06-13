/**
 * append() - The function use to append the operand into the stack
 * @arg1 - It is integer argument
 * 
 * Function will append the operand into the stack and perform operation based on flag
 *
 */
static void append(int operand);

/**
 * evaluate_infix() - The function use to push and pop based on expression.
 * @arg1 - It is pointer to the character
 * 
 * Function will push and pop the expression based on the operand.
 *
 * Return - returns the character pointer of the array.
 */
static char *evaluate_infix(char *input);

/**
 * input_validate() - The function use to validate the input expression.
 * @arg1 - It is pointer to the character
 * 
 * Function will valiate the input expression and returns the error.
 *
 * Return - returns the boolean value based on the error value.
 */
static bool input_validate(char *input);


