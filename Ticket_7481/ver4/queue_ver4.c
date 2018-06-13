#include <stdio.h>
#include <queue_ver4.h>

void queue_init_generic(struct queue_info *queue,
			union g_datatype *generic,
			enum g_typename type, int queue_len)
{
	queue->front = INITIAL_LOCATION;
	queue->rear = INITIAL_LOCATION;
	queue->queue_len = queue_len;
	queue->type = type;
	queue->array = generic;
}

int queue_put_generic(struct queue_info *queue, union g_datatype *generic)
{
	if (queue->front == (queue->rear + 1) % queue->queue_len)
		return -1;

	if (queue->front == INITIAL_LOCATION)
		queue->front = 0;
	queue->rear = (queue->rear + 1) % queue->queue_len;

	queue->array[queue->rear] = *generic;

	return 0;
}

int queue_get_generic(struct queue_info *queue, union g_datatype *generic)
{
	if ((queue->front == INITIAL_LOCATION) && (queue->rear == INITIAL_LOCATION))
		return -1;

	*generic = queue->array[queue->front];

	if (queue->front == queue->rear) {
		queue->front = INITIAL_LOCATION;
		queue->rear = INITIAL_LOCATION;
	} else {
		queue->front = (queue->front + 1) % (queue->queue_len);
	}

	return 0;
}
