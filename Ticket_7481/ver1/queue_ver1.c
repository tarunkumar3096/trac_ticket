#include <stdio.h>
#include <queue_ver1.h>

void queue_init(struct queue_info *queue, char *queue_buf, int queue_len)
{
	queue->queue_len = queue_len;
	queue->array = queue_buf;
	queue->front = INITIAL_LOCATION;
	queue->rear = INITIAL_LOCATION;
}

int queue_put(struct queue_info *queue, char value)
{
	if (queue->front == (queue->rear + 1) % queue->queue_len)
		return -1;

	if (queue->front == INITIAL_LOCATION)
		queue->front = 0;
	queue->rear = (queue->rear + 1) % queue->queue_len;
	queue->array[queue->rear] = value;

	return 0;
}

int queue_get(struct queue_info *queue, char *value)
{
	if ((queue->front == INITIAL_LOCATION) && (queue->rear == INITIAL_LOCATION))
		return -1;

	*value = queue->array[queue->front];
	if (queue->front == queue->rear) {
		queue->front = INITIAL_LOCATION;
		queue->rear = INITIAL_LOCATION;
	} else {
		queue->front = (queue->front + 1) % (queue->queue_len);
	}

	return 0;
}
