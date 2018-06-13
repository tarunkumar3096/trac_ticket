#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue_ver5.h>

void queue_init_g(struct queue_info *queue, void *generic,
		  enum g_typename type, int queue_len)
{
	queue->front = INITIAL_LOCATION;
	queue->rear = INITIAL_LOCATION;
	queue->type = type;
	queue->queue_len = queue_len;
	queue->array = generic;
}

int queue_put(struct queue_info *queue, void *value, int location)
{
	if (queue->front == (queue->rear + 1) % queue->queue_len)
		return -1;

	if (queue->front == INITIAL_LOCATION)
		queue->front = 0;
	queue->rear = (queue->rear + 1) % queue->queue_len;

	printf("rear = %d\n", queue->rear);
	switch (queue->type) {
	case char_d:
		((char *)queue->array)[queue->rear] =
			(((char *)value)[location]);
		break;
	case short_d:
		((short *)queue->array)[queue->rear] =
			(((short *)value)[location]);
		break;
	case int_d:
		((int *)queue->array)[queue->rear] =
			(((int *)value)[location]);
		break;
	case long_d:
		((long *)queue->array)[queue->rear] =
			(((long *)value)[location]);
		break;
	case float_d:
		((float *)queue->array)[queue->rear] =
			(((float *)value)[location]);
		break;
	case double_d:
		((double *)queue->array)[queue->rear] =
			(((long *)value)[location]);
		break;
	}
	return 0;
}

int queue_get(struct queue_info *queue, void *value, int location)
{
	if ((queue->front == INITIAL_LOCATION) && (queue->rear == INITIAL_LOCATION))
		return -1;

	switch (queue->type) {
	case char_d:
		(((char *)value)[location]) =
			(((char *)queue->array)[queue->front]);
		break;
	case short_d:
		(((short *)value)[location]) =
			((short *)queue->array)[queue->front];
		break;
	case int_d:
		(((int *)value)[location]) =
			((int *)queue->array)[queue->front];
		break;
	case long_d:
		(((long *)value)[location]) =
			((long *)queue->array)[queue->front];
		break;
	case float_d:
		(((float *)value)[location]) =
			((float *)queue->array)[queue->front];
		break;
	case double_d:
		(((double *)value)[location]) =
			((double *)queue->array)[queue->front];
		break;
	}

	if (queue->front == queue->rear) {
		queue->front = INITIAL_LOCATION;
		queue->rear = INITIAL_LOCATION;
	} else {
		queue->front = (queue->front + 1) % (queue->queue_len);
	}

	return 0;
}

int queue_get_g(struct queue_info *queue, void *generic, int *len)
{
	int temp = 0;

	while (temp != *len) {
		if (queue_get(queue, generic, temp++))
			break;
	}

	if (temp) {
		*len = temp;
		return 0;
	}

	return -1;
}

int queue_put_g(struct queue_info *queue, void *generic, int *len)
{
	int temp = 0;

	while (temp != *len) {
		printf("temp = %d\n", temp);
		if (queue_put(queue, generic, temp++))
			break;
	}

	if (temp) {
		*len = temp;
		return 0;
	}

	return -1;
}
