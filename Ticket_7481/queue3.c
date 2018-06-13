#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FLOW_CONTROLLED 1
#define DISCARD_ON_OVERFLOW 2
#define PARTIAL_RW 3

struct queue_info
{
	int front;
	int rear;
	int queue_len;
	int config;
	char *array;
};

int display(struct queue_info *queue)
{
	int i = 0;

	if ((queue->front == -1) && (queue->rear == -1))
		return -1;
	
	if (queue->front == -1) {
		for (i = 0; i <= queue->rear; i++)
			printf("%c", queue->array[i]);
	} else if (queue->rear >= queue->front) {
		for (i = queue->front; i <= queue->rear; i++)
			printf("%c", queue->array[i]);
	} else	{
		for (i = queue->front; i < queue->queue_len; i++)
			printf("%c", queue->array[i]);
		for (i = 0; i <= queue->rear; i++)
			printf("%c", queue->array[i]);
	}
	if (i) {
		printf("\n");
		return 0;
	}

	return -1;
}

int counter(struct queue_info *queue)
{
	int i = queue->front;
	int j = 0;

	while(i <= queue->rear) {
		if (i == queue->queue_len)
			i = 0;
		i++;
		j++;
	}

	return j;
}

/* void queue_init_generic(struct queue_info *queue, union g_datatype *generic, enum g_typename, int queue_len); */
/* { */
/* 	queue->queue_len = queue_len; */
/* 	queue->config = PARTIAL_RW; */
/* 	queue->front = -1; */
/* 	queue->rear = -1; */
/* 	switch (g_typename) { */
/* 	case char: */
/* 		queue-> */
			
/* } */

int queue_put(struct queue_info *queue, char value)
{
	if (queue->front == (queue->rear + 1) % queue->queue_len) {
		if (queue->config == DISCARD_ON_OVERFLOW)
			queue->front = (queue->front + 1) % (queue->queue_len);
		else
			return -1;
	}

	if (queue->front == -1)
		queue->front = 0;		
	queue->rear = (queue->rear + 1) % queue->queue_len;
	queue->array[queue->rear] = value;

	return 0;
}

int queue_get(struct queue_info *queue, char *value)
{
	if ((queue->front == -1) && (queue->rear == -1))
		return -1;
	
	*value = queue->array[queue->front];

	if (queue->front == queue->rear) {
		queue->front = -1;
		queue->rear = -1;
	} else {
		queue->front = (queue->front + 1) % (queue->queue_len);
	}

	return 0;
}

int queue_put_bulk(struct queue_info *queue, char *values, int len)
{
	int temp = 0;

	if ((queue->config == DISCARD_ON_OVERFLOW) && (queue->queue_len < len))
		return -1;	    

	if ((queue->config == FLOW_CONTROLLED) && ((queue->queue_len-counter(queue)) <= len))
		return -1;					

	while (temp != len) {
		if (queue_put(queue, values[temp]))
			break;
		temp++;
	}
	if (temp)
		return temp;

	return -1;
}

int queue_get_bulk(struct queue_info *queue, char *values, int len)
{
	int temp = 0;
	char get;

	if ((queue->config == FLOW_CONTROLLED) && (counter(queue) < len))
		return -1;

	while (temp != len) {
		if (!queue_get(queue, &get))
			values[temp] = get;
		else
			break;
		temp++;
	}

	if (temp)
		return temp;

	return -1;
}

void queue_reset(struct queue_info *queue)
{
	char temp;

	while (!(queue_get(queue, &temp)))
		;
}

int queue_flush(struct queue_info *queue, char *values, int *len)
{
	char get;
	int temp = 0;
	
	while (!(queue_get(queue, &get))) {
		if (temp < *len)
			values[temp]  = get;
		temp++;
	}

	if (temp) {
		*len = temp;
		return 0;
	} 

	memset(values, 0, sizeof(values));
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

int main()
{
	int i = 2;
	int len = 20;
	char a[10] = {0};
	char d[7] = "1234567";
	char b[6] = "tarun";
	char c[10] = {0};
	char e[20] = {0};
	char get;
	struct queue_info line;
	queue_init(&line, a, 9);
	queue_config(&line, 1);
	printf("\nflow control\n");
	queue_put_bulk(&line, d, 5); 
	display(&line); 
	if (queue_put_bulk(&line, b, 5))
		printf("no space\n"); 
	display(&line); 
	queue_get_bulk(&line, c, 5); 
	printf("got for 5 element = %s\n", c); 
	queue_get_bulk(&line, e, 5); 
	printf("got for 5 element = %s\n", e); 

	printf("\ndiscard on overflow\n");
	memset(e, 0, sizeof(e));
	memset(c, 0, sizeof(c));	
	queue_config(&line, 2);
	queue_put_bulk(&line, d, 5);
	display(&line);	
	queue_put_bulk(&line, b, 5);
	display(&line);
	queue_put_bulk(&line, b, 5);
	display(&line);
	queue_put_bulk(&line, d, 5);
	display(&line);
	queue_put_bulk(&line, d, 5);
	display(&line);
	queue_get_bulk(&line, e, 5);
	printf("got = %s\n", e);
	if (queue_get_bulk(&line, c, 5) == -1)
		printf("over\n");
	printf("got = %s\n", c);
	display(&line);
	if (queue_get_bulk(&line, c, 5) == -1)
		printf("over\n");
	printf("got = %s\n", c);
	display(&line);
	queue_put_bulk(&line, d, 5);
	display(&line);
	if (queue_get_bulk(&line, c, 5) == -1)
		printf("over\n");
	if (queue_get_bulk(&line, c, 5) == -1)
		printf("over\n");	
	printf("\npartial rw\n");
	memset(e, 0, sizeof(e));
	memset(c, 0, sizeof(c));	
	queue_config(&line, 3);
	queue_put_bulk(&line, d, 7);
	display(&line);
	if (queue_put_bulk(&line, d, 7))
		printf("full\n");
	queue_get_bulk(&line, e, 7);
	printf("got = %s\n", e);
	queue_get_bulk(&line, c, 5);
	printf("got = %s\n", c);	
	display(&line);			
	return 0;
}
	
