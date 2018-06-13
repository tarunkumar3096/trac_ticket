#include <stdio.h>
#include <stdbool.h>
#define North(x,y) find_path(x, y-1, square)
#define East(x,y) find_path(x+1, y, square)
#define South(x,y) find_path(x, y+1, square)
#define West(x,y) find_path(x-1, y, square)
#define MAZE_MAX_LEN 10
char a[MAZE_MAX_LEN][MAZE_MAX_LEN];

bool find_path(int x, int y, int square)
{
	//printf("one\n");
	printf("x=%d\ty=%d\n",x,y);
	int i = 0;
	int j = 0;
	
	for (i = 0;i < square; i++) {
		for (j = 0;j <= square; j++) {
			printf("%c", a[i][j]);
		}
	}
	sleep(1);
	if ((x < 0) || (x >= square) || (y < 0) || (y >= square)) {
		printf("out of boundary\n");
		return false;
	}
	printf("two\n");
	if (a[x][y] == 'G')
		return true;
	printf("three\n");
	if (a[x][y] == '#')
		return false;
	if (a[x][y] == '+')
		return false;
	a[x][y] = '+';
	printf("four\n");
	if (North(x,y) == true)
		return true;
	printf("five\n");
	if (East(x,y) == true)
		return true;
	printf("six\n");
	if (South(x,y) == true)
		return true;
	printf("7\n");
	if (West(x,y) == true)
		return true;
	a[x][y] = 'x';
	printf("8\n");
	return false;
}

int get_maze_size(void)
{
	int square;
	
	printf("enter the square of the matrix\n");
	scanf("%d", &square);
	getchar();
	if ((square < 0) && (square > MAZE_MAX_LEN))
		return false;

	return square;
}
	
int read_input(int square)
{
	int i = 0;
	int j = 0;

	printf("in\n");
	for (i = 0; i < square; i++) {
		for (j = 0;j <= square; j++) {
			scanf("%c", &a[i][j]);
		}
		if (a[i][j-1] != '\n')
			return false;
	}
	return true;
}

int input_validate(int square)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < square; i++) {
		for (j = 0;j < square; j++) {
			if (!((a[i][j] == 'S')  || (a[i][j] == 'G') ||
			      (a[i][j] == '.') || (a[i][j] == '#')))
				return false;
		}
	}
	return true;
}

int starting_location(int *i, int *j, int square)
{
	int starting_count = 0;
	int row;
	int column;
	for (i = 0; i < square; i++) {
		for (j = 0;j < square; j++) {
			if (a[i][j] == 'S') {
				row = i;
				column = j;
				starting_count++;
			}
		}
	}

	if (starting_count == 1)
		return true;

	return false;
}

int main()
{
	int i = 0;
	int j = 0;	
	int square;

	//getchar();
	square = get_maze_size();
	printf("hello\n");
	printf("i=%d\n", square);
	if (square && read_input(square) && input_validate(square)) {		
		printf("\n");
		for (i = 0;i < square; i++) {
			for (j = 0;j <= square; j++) {
				printf("%c", a[i][j]);
			}
			//printf("\n");
		}
		find_path(0,0,square);
		for (i = 0;i < square; i++) {
			for (j = 0;j <= square; j++) {
				printf("%c", a[i][j]);
			}
			//printf("\n");
		}
	}
	return 0;
}
