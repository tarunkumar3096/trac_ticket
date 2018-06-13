#include <stdio.h>
#define NAMES C(cha)C(GREEN)C(BLUE)
#define C(x) x,
enum color { NAMES TOP };
#undef C
#define C(x) #x,
const char * const color_name[] = { NAMES };
int main( void ) 
{
	printf( "The color is %s.\n", color_name[ cha ]);  
	//printf( "There are %d colors.\n", TOP );
}
