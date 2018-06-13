#include <queue_ver1.h>
#include <stdio.h>
#include <stdlib.h>

struct vector vector(struct vector *vector)
{

	vector->head = NULL;
	vector->tail = NULL;

	vector->append = &append;
	/* vector->prepend = &prepend; */
	/* vector->insert = &insert; */
	/* vector->chop = &chop; */
	/* vector->behead = &behead; */
	/* vector->delete = &delete; */
	/* vector->set = &set; */
	/* vector->get = &get; */
	/* vector->is_empty = &is_empty; */
	/* vector->size = &size; */
	/* vector->clear = &clear; */
	/* vector->destruct = &destruct; */
	/* vector->move = &move; */
	/* vector->first = &first; */
	/* vector->last = &last; */
	/* vector->splice = &splice; */
	return *vector;
}

int append(struct vector *vector, struct element element)
{
	struct vector_node *temp;
	struct vector *path = vector;

	printf("%ld\n", element.field);
	temp = malloc(sizeof(struct vector_node));
	temp->element = element;
	temp->next = NULL;
	temp->prev = NULL;

	if (vector->head == NULL) {
		vector->head = temp;
		vector->tail = temp;
	} else {
		while (path->head->next != NULL)
			path->head = path->head->next;
		path->head->next = temp;
		vector->tail = temp;
	}
}

