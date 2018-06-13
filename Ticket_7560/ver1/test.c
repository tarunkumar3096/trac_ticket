#include <queue_ver1.h>
#include <stdio.h>
long val1 = 1000;
char val = 'a';

int main()
{
	struct vector v;
	vector(&v);
	//struct element element;
	struct vector *h;

	printf("%ld\n", val1);
	v.append(&v, ELEMENT(val1, LONG));
	//printf("long = %ld\n", element.field);	
	v.append(&v, ELEMENT(val, CHAR));
	//printf("long = %ld\n", element.field);

	h = &v;
	for_each(element1, h) {
	 	printf("%ld %d\n", VALUE(element1), TYPE(element1));  
	}  

	//v.get(v, 1, &element);
	//v.size(v);
}
