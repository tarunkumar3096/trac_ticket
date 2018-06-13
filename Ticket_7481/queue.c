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

	if ((queue->rear == 0) && (queue->front == 0)) {
		queue->array[queue->rear] = value;
		return 0;
	} else if (queue->rear < queue->front) {
		queue->array[queue->rear] = value;
		return 0;
	} else if (queue->rear <= (queue->queue_len - 1)
		   && (queue->rear != queue->front)) {
		queue->array[queue->rear] = value;
		return 0;
	}
	queue->rear = temp;

	printf("out\n");
	return -1;
}

int queue_get(struct queue_info *queue, char *value)
{
	printf("rear = %d\t front = %d\n", queue->rear, queue->front);
	if ((queue->front == -1) && (queue->rear == -1)) {
		printf("queue is empty\n");
		return -1;
	} else if ((queue->front == -1) && (queue->rear != -1))
		queue->front = 0;
	
	*value = queue->array[queue->front];
	if (queue->front == queue->rear) {
		queue->front = -1;
		queue->rear = -1;
	} else if (queue->front == (queue->queue_len - 1)) {
		queue->front = 0;
	} else {
		queue->front++;
	}
	
	return 0;
}
	
int main()
{
	int i = 90;
	char array[11] = {0};
	char a[11] = {0};
	char get;
	struct queue_info line;
	struct queue_info counter;
	queue_init(&line, array, 11);
	queue_init(&counter, a, 11);
	display(&line);

	while (i-- != 84) {
		sleep(1);
		/* /\* if (queue_get(&line, &get)) {	 *\/ */
		/* /\* 	printf("get = %c\n", get); *\/ */
		/* /\* 	display(&line); *\/ */
		/* /\* } *\/	 */
		if (!queue_put(&line, i))
			display(&line);
		else
			printf("No place to insert\n");
	}
	i = 90;
	while (i-- != 50) {
		if (!queue_get(&line, &get)) {	 
			printf("get = %c\n", get); 
			display(&line); 
		}
	}
	return 0;
}
	
