#include <stdio.h>
#include <dynamic_maze.h>
#include <stdlib.h>
int x_location;
int y_location;

int direction(int x, int y, int square, char **maze)
{
	if (NORTH(x, y))
		return 1;
	if (EAST(x, y))
		return 1;
	if (SOUTH(x, y))
		return 1;
	if (WEST(x, y))
		return 1;

	return 0;
}

void clear_buffer(void)
{
	char c;

	while ((c = getchar()) != '\n')
		;
}

int find_path(int x, int y, int square, char **maze)
{
	if ((x < 0) || (x >= square) || (y < 0) || (y >= square))
		return 0;
	if ((maze[x][y] == 'G') || (maze[x][y] == 'g')) {
		x_location = x;
		y_location = y;
		return 1;
	}
	if (maze[x][y] == '#')
		return 0;
	if (maze[x][y] == '+')
		return 0;
	if (maze[x][y] == 'x')
		return 0;
	if (maze[x][y] != 'x')
		maze[x][y] = '+';
	if (direction(x, y, square, maze))
		return 1;
	maze[x][y] = 'x';

	return 0;
}

int get_maze_size(void)
{
	int square;

	printf("enter the square of the matrix\n");
	scanf("%d", &square);
	clear_buffer();
	if ((square <= 1) || (square > MAZE_MAX_LEN))
		return 0;

	return square;
}

char **read_input(int square)
{
	int i = 0;
	char **maze = malloc(sizeof(char) * square);

	for (i = 0; i < square; i++)
		*(maze+i) = malloc(sizeof(char) * square);
	printf("enter the %dx%d maze with S ", square, square);
	printf("as starting point and G as goal\n");
	for (i = 0; i < square; i++) {
		fgets(maze[i], square+2, stdin);
		if (maze[i][square] != '\n') {
			clear_buffer();
			return NULL;
		}
		maze[i][square] = '\0';
	}

	return maze;
}

int input_validate(int square, char **maze)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < square; i++) {
		for (j = 0; j < square; j++) {
			if (!((maze[i][j] == 'S')  || (maze[i][j] == 'G') ||
			      (maze[i][j] == '.') || (maze[i][j] == '#') ||
			      (maze[i][j] == 's')  || (maze[i][j] == 'g')))
				return 0;
		}
	}

	return 1;
}

int starting_location(int *row, int *column, int square, char **maze)
{
	int starting_count = 0;
	int i;
	int j;

	for (i = 0; i < square; i++) {
		for (j = 0; j < square; j++) {
			if ((maze[i][j] == 'S') || (maze[i][j] == 's')) {
				*row = i;
				*column = j;
				starting_count++;
			}
		}
	}
	if (starting_count == 1)
		return 1;

	return 0;
}

void display(int square, char **maze)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < square; i++) {
		for (j = 0; j < square; j++)
			printf("%c", maze[i][j]);
		printf("\n");
	}
}

int maze_runner(int square)
{
	int row;
	int column;
	int goal_found = 0;
	char **maze;

	if (square) {
		maze = read_input(square);
		if (maze && input_validate(square, maze)) {
			if (starting_location(&row, &column, square, maze)) {
				find_path(row, column, square, maze);
				maze[row][column] = 's';
				if ((maze[x_location][y_location] == 'G') ||
				    (maze[x_location][y_location] == 'g')) {
					goal_found = 1;
				} else {
					printf("No path to reach\n");
				}
			} else {
				printf("No starting location\n");
			}
		}
	}
	if (goal_found) {
		printf("\nPath to Goal!!!!\n");
		display(square, maze);
		return 1;
	}

	return 0;
}

int main(void)
{
	int square;

	while (1) {
		square = get_maze_size();
		if (maze_runner(square))
			break;
		printf("Not a valid input\n");
	}

	return 0;
}
