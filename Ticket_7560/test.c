#include <vector.h>
#include <stdio.h>
#include <stdlib.h>
#include <test.h>

static void display(struct vector_node *element)
{
	switch(TYPE(element)) {
	case CHAR:
		printf("%c  ",  VALUE(element));
		break;
	case SHORT:
		printf("%hd  ",  VALUE(element));
		break;
	case INT:
		printf("%d  ",  VALUE(element));
		break;
	case LONG:
		printf("%ld  ",  VALUE(element));
		break;
	case FLOAT:
		printf("%f   ",  VALUE_F(element));
		break;
	case DOUBLE:
		printf("%lf  ",  VALUE_D(element));
		break;
	}	
}


int main(void)
{
	struct vector *v = malloc(sizeof(struct vector));
	struct element t1;
	struct element t2;
	struct vector *h;
	int val1 = 10;
	char val2 = 'a';
	short val3 = 34;
	long val4 = 4560007867645;
	float val6 = 34.333;
	double val7 = 3456.9999;

	if (v == NULL)
		return 0;
	vector(v);
	v->append(v, ELEMENT(val6, FLOAT));	
	v->append(v, ELEMENT(val4, LONG));
	v->append(v, ELEMENT(val2, CHAR));
	v->append(v, ELEMENT(val7, DOUBLE));
	v->append(v, ELEMENT(val1, INT));
	v->prepend(v, ELEMENT(val3, SHORT));
	v->prepend(v, ELEMENT(val7, DOUBLE)); 

	printf("Reverse:\n");
	h = v;
	for_each_rev(element, h)
	 	display(element);  
	printf("\n");

	printf("Non Reverse:\n");
	h = v;
	for_each(element1, h)
	 	display(element1); 
	printf("\n");
	printf("\nInserting at 6 element:\n");
	v->insert(v, 6, ELEMENT(val2, CHAR));
	h = v;
	for_each(element2, h)
	 	display(element2);
	printf("\n");
	for_each_rev(element3, h)
	 	display(element3);	

	printf("\n\nChoping at end\n");
	v->chop(v);
	h = v;
	for_each(element2, h)
	 	display(element2);
	printf("\n");
	for_each_rev(element3, h)
	 	display(element3);	

	printf("\n\nBehead at front\n");
	v->behead(v);
	h = v;
	for_each(element2, h)
	 	display(element2);
	printf("\n");
	for_each_rev(element3, h)
	 	display(element3);	

	printf("\n\nDeleting at 3\n");
	v->delete(v, 3);
	h = v;
	for_each(element2, h)
	 	display(element2);
	printf("\n");
	for_each_rev(element3, h)
	 	display(element3);

	printf("\n\nSize of vector\n");
	printf("size = %d\n", v->size(v));

	printf("\nset value in pos 3\n");
	v->set(v, 5, ELEMENT(val7, DOUBLE));
	h = v;
	for_each(element2, h)
	 	display(element2);
	printf("\n");

	printf("get at los 3\n");
	v->get(v, 3, &t1);
	printf("%d %d\n", t1.field, t1.field_type);
	printf("\n");

	printf("\nmoving data in list\n");
	v->move(v, 1, 3);
	h = v;
	for_each(element2, h)
	 	display(element2);
	printf("\n");

	/* printf("\nspliting vector into two\n"); */
	/* h = v->splice(v, 3); */
	/* for_each(element2, h) */
	/*  	display(element2); */
	/* printf("\n");	 */

	printf("\nset value in pos 1\n");
	v->set(v, 1, ELEMENT(val1, INT));	
	h = v;
	for_each(element2, h)
	 	display(element2);
	printf("\n");

	printf("geting first element\n");
	v->clear(v);
	h = v;
	for_each(element2, h)
	 	display(element2);	
	/* v->first(v, &t1); */
	/* printf("%d %d\n", t1.field, t1.field_type); */
	/* printf("\n"); */

	/* printf("\nset value in pos 3\n"); */
	/* v->set(v, 3, ELEMENT((val1 + 3), INT)); */
	/* h = v; */
	/* for_each(element2, h) */
	/*  	display(element2); */
	/* printf("\n"); */

	/* printf("geting last element\n"); */
	/* v->last(v, &t1); */
	/* printf("%c %d\n", t1.field, t1.field_type); */

	/* v->destruct(v); */
	/* v = NULL; */
	/* if (v != NULL) */
	/* 	v->insert(v, 6, ELEMENT(val2, CHAR)); */
	return 0;
}
