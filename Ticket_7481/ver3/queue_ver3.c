#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue_ver3.h>

int counter(struct queue_info *queue)
{
	int front = queue->front;
	int count = 0;

	if ((queue->front == INITIAL_LOCATION) && (queue->rear == INITIAL_LOCATION))
		return 0;
	
	do {
		if (front == queue->queue_len)
			front = 0;
		count++;
	} while (front++ != queue->rear);

	return count;
}

void queue_init(struct queue_info *queue, char *queue_buf, int queue_len)
{
	queue->queue_len = queue_len;
	queue->array = queue_buf;
	queue->config = PARTIAL_RW;
	queue->front = INITIAL_LOCATION;
	queue->rear = INITIAL_LOCATION;
}

int queue_put(struct queue_info *queue, char value)
{
	if (queue->front == (queue->rear + 1) % queue->queue_len) {
		if (queue->config == DISCARD_ON_OVERFLOW)
			queue->front = (queue->front + 1) % (queue->queue_len);
		else
			return -1;
	}

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

int queue_put_bulk(struct queue_info *queue, char *values, int len)
{
	int temp = 0;

	if ((queue->config == FLOW_CONTROLLED) &&
	    ((queue->queue_len-counter(queue)) <= len))
		return -1;

	while (temp != len) {
		if (queue_put(queue, values[temp++]))
			break;
	}

	if (temp)
		return temp;

	return -1;
}

int queue_get_bulk(struct queue_info *queue, char *values, int len)
{
	int temp = 0;

	if ((queue->config == FLOW_CONTROLLED) && (counter(queue) > len))
		return -1;

	while (temp != len) {
		if (queue_get(queue, &values[temp++]))
			break;
	}

	if (temp)
		return temp;

	return -1;
}

void queue_reset(struct queue_info *queue)
{
	queue->front = INITIAL_LOCATION;
	queue->rear = INITIAL_LOCATION;
}

int queue_flush(struct queue_info *queue, char *values, int *len)
{
	int count = 0;

	if ((queue->config == FLOW_CONTROLLED) && (counter(queue) > *len))
		return -1;

	count = queue_get_bulk(queue, values, *len);
	while ((counter(queue) > 0) && (queue->config == DISCARD_ON_OVERFLOW))
		count += queue_get_bulk(queue, values, *len);

	if (count != INITIAL_LOCATION) {
		*len = count;
		return 0;
	}

	return -1;
}

int queue_config(struct queue_info *queue, int config)
{
	if ((config > 0) && (config < 4)) {
		queue->config = config;
		return 0;
	}

	return -1;
}
