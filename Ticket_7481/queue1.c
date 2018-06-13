#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct queue_info
{
	int front;
	int rear;
	int queue_len;
	char *array;
};

void display(struct queue_info *queue)
{
	int i;

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
	printf("\n");
}

void queue_init(struct queue_info *queue, char *queue_buf, int queue_len)
{
	queue->queue_len = queue_len;
	queue->array = queue_buf;
	queue->front = -1;
	queue->rear = -1;
}

int queue_put(struct queue_info *queue, char value)
{
	int temp = queue->rear;

	if ((queue->rear == -1) && (queue->front == -1)) {
		queue->rear = 0;
		queue->front = 0;		
	} else if ((queue->rear == queue->queue_len - 1)
		   && (queue->front != 0)) {
		queue->rear = 0;
	} else {
		queue->rear++;
	} 

	if ((queue->rear < queue->front)
	    || ((queue->rear == 0) && (queue->front == 0))) {
		queue->array[queue->rear] = value;
		return 0;
	} else if (queue->rear <= (queue->queue_len - 1)
		   && (queue->rear != queue->front)) {
		queue->array[queue->rear] = value;
		return 0;
	}
	queue->rear = temp;

	return -1;
}

int queue_get(struct queue_info *queue, char *value)
{
	if ((queue->front == -1) && (queue->rear == -1)) {
		return -1;
	} 
	
	*value = queue->array[queue->front];

	if (queue->front == queue->rear) {
		queue->front = -1;
		queue->rear = -1;
	}
	else
		queue->front = (queue->front + 1) % (queue->queue_len);

	return 0;
}

int queue_put_bulk(struct queue_info *queue, char *values, int len)
{
	int temp = 0;

	while (temp != len) {
		if (queue_put(queue, values[temp]))
			break;
		temp++;
	}
	if (temp)
		return 0;

	return -1;
}



int queue_get_bulk(struct queue_info *queue, char *values, int len)
{
	int temp = 0;
	char get;

	while (temp != len) {
		if (!queue_get(queue, &get))
			values[temp] = get;
		else
			return -1;
		temp++;
	}

	return 0;
}
	
int main()
{
	int i = 2;
	char a[9] = {0};
	char b[10] = {0};
	char c[10] = {0};
	char get;
	struct queue_info line;
	queue_init(&line, a, 9);
	while (i-- != 1) {
		sleep(1);	
		if (!queue_get_bulk(&line, b, 3)) {
			printf("out = %s\n", b);
		} else {
			printf("partial read\n");
			printf("out = %s\n", b);
		}
		if (!queue_put_bulk(&line, "Tarun.t.u", 9))
		 	display(&line);
		else {
		 	printf("No place to insert\n");
		 	display(&line);
		}
		queue_get(&line, &get);
		queue_get(&line, &get);
		queue_get(&line, &get);
		queue_get(&line, &get);
		queue_get(&line, &get);
		queue_get(&line, &get);		
	 	display(&line);
		if (!queue_put_bulk(&line, "systems", 6))
		 	display(&line);
		else {
		 	printf("No place to insert\n");
		 	display(&line);
		}

		if (!queue_get_bulk(&line, b, 8)) {
			printf("out = %s\n", b);
		} else {
			printf("partial read\n");
			printf("out = %s\n", b);
		}
	}	
	return 0;
}
	
