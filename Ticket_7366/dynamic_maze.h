#define WEST(x, y) find_path(x, y-1, square, maze)
#define SOUTH(x, y) find_path(x+1, y, square, maze)
#define EAST(x, y) find_path(x, y+1, square, maze)
#define NORTH(x, y) find_path(x-1, y, square, maze)
#define MAZE_MAX_LEN 10

/**
 * direction() - The function use to find the direction of path
 * @arg1 - It is integer argument
 * @arg2 - It is integer argument
 * @arg3 - It is integer argument
 * @arg4 - It is char double pointer
 * Function will returns boolen value of finding path.
 *
 * Return - returns boolean value.
 */
int direction(int, int, int, char **);

/**
 * find_path() - The function use to find the path of the given maze
 * @arg1 - It is integer argument
 * @arg2 - It is integer argument
 * @arg3 - It is integer argument
 * @arg4 - It is char double pointer
 * Function will returns boolen value of finding path.
 *
 * Return - returns boolean value.
 */
int find_path(int, int, int, char **);

/**
 * clear_buffer() - The function will clear the unwanted input from buffer.
 * 
 * Function will clear invalid input given by user.
 *
 */
void clear_buffer(void);

/**
 * get_maze_size() - The function will get the maze size from user.
 * 
 * Function will return size of maze given by user.
 *
 * Return - returns integer as size of the maze.
 */
int get_maze_size(void);

/**
 * read_maze() - The function will get maze from user as 2D matrix.
 * @arg1 - It is integer argument.
 * 
 * Function will return error condition.
 *
 * Return - returns boolean as error condition based on the input.
 */
char **read_input(int);

/**
 * input_validate() - The function use to validate the input given by user.
 * @arg1 - It is integer argument
 * @arg4 - It is char double pointer
 * 
 * Function will returns error condition based on he input maze.
 *
 * Return - returns boolean as error condition based on the input.
 */
int input_validate(int, char **);

/**
 * starting_location() - The function use to returns error condition based on input.
 * @arg1 - It is pointer integer argument
 * @arg2 - It is pointer integer argument
 * @arg3 - It is pointer integer argument
 * @arg4 - It is char double pointer
 * Function will returns error condition based on input.
 *
 * Return - returns boolean as error condition based on the input.
 */
int starting_location(int *, int *, int, char **);

/**
 * precedence() - The function use to display the maze with path.
 * @arg1 - It is integer argument
 * @arg2 - It is char double pointer
 * 
 * Function will display the maze with path in it.
 *
 */
void display(int, char **);

/**
 * maze_runner() - The function use to get input and validate the input and perform the operation.
 * @arg1 - It is integer argument
 * 
 * Function will perform the operation of maze to find path.
 *
 * Return - returns error condition of based maze operation.
 */
int maze_runner(int);
