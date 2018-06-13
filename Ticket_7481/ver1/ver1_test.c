#include <stdio.h>
#include <queue_ver1.h>
#include <ver1_test.h>
#include <stdio_ext.h>

static int display(struct queue_info *queue)
{
	int front = queue->front;

	if ((queue->front == INITIAL_LOCATION) && (queue->rear == INITIAL_LOCATION))
		return -1;

	do {
		if (front == queue->queue_len)
			front = 0;
		printf("%c ", queue->array[front]);
	} while (front++ != (queue->rear));
	printf("\n");

	return 0;
}

static int put_data(struct queue_info *queue)
{
	char data;

	printf("enter the data to put in queue\n");
	scanf(" %c", &data);
	if (queue_put(queue, data))
		return -1;

	return 0;
}

static int get_data(struct queue_info *queue)
{
	char data;

	if (queue_get(queue, &data))
		return -1;

	return data;
}

int main(void)
{
	struct queue_info queue;
	char queue_buf[MAX_LENGTH];
	int queue_length;
	int opr;

	while (1) {
		printf("Enter the details for queue:\n");
		printf("Enter the Queue length within %d\n", MAX_LENGTH);
		scanf("%d", &queue_length);
		__fpurge(stdin);
		if ((queue_length > MAX_LENGTH) || (queue_length < 1)) {
			printf("invalid data\n");
			continue;
		}
		queue_init(&queue, queue_buf, queue_length);
		while (1) {
			printf("\nData in buffer:\t");
			if (display(&queue))
				printf("No data in buffer\n");
			printf("1.put\t2.get\t3.exit\n");
			scanf("%d", &opr);
			__fpurge(stdin);
			switch (opr) {
			case 1:
				if (put_data(&queue))
					printf("Queue is full\n");
				break;
			case 2:
				if (get_data(&queue) == INITIAL_LOCATION)
					printf("Queue is empty\n");
				break;
			case 3:
				break;
			default:
				printf("Invalid options\n");
			}			
		}
	}
	return 0;
}
