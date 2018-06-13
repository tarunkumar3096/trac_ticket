#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio_ext.h>
#include <queue_ver3.h>
#include <ver3_test.h>
#include <string.h>
#define MAX_LENGTH 15
#define MAX_QUEUE 10
int queue_used[MAX_QUEUE];

static int get_int(void)
{
	int temp = -1;
	
	while (1) {
		scanf("%d", &temp);
		__fpurge(stdin);
		if (temp != -1)
			return temp;
		printf("Invaild data\nEnter again:\t");
		continue;
	}

	return 0;
}
	
static int display(struct queue_info *queue)
{
	int front = queue->front;

	if ((queue->front == -1) && (queue->rear == -1))
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
	__fpurge(stdin);
	if (queue_put(queue, data))
		return -1;

	return 0;
}

static int data_flush(struct queue_info *queue)
{
	char *arr;
	int buf_length = 0;
	int count = 0;

	printf("Enter the length of element to flush from queue\n");
	buf_length = get_int();
	arr = malloc(sizeof(char) * buf_length);
	count = queue_flush(queue, arr, &buf_length);
	if (count != -1)
		printf("flused data from queue = %s\n", arr);
	free(arr);

	return count;
}

static void config_queue(struct queue_info *queue)
{
	int config_flag = 0;

	while (1) {
		printf("select configuration from following flags\n");
		printf("1.FLOW_CONTROLLED\t");
		printf("2.DISCARD_ON_OVERFLOW\t3.PARTIAL_RW\n");
		config_flag = get_int();
		if ((config_flag < FLOW_CONTROLLED)
		    && (config_flag > PARTIAL_RW)) {
			printf("Invalid option\n");
			continue;
		}
		queue_config(queue, config_flag);
		break;
	}
}

static int get_data(struct queue_info *queue)
{
	char data;

	if (queue_get(queue, &data))
		return -1;

	return data;
}

static int put_bulk(struct queue_info *queue)
{
	int i = 0;
	char *arr;
	int buf_length = 0;
	int count = 0;

	printf("Enter the length of the bulk data to put:\n");
	buf_length = get_int();
	arr = malloc(sizeof(char) * (buf_length + 2));
	while (1) {
		printf("Enter the data of length %d\n", buf_length);
		fgets(arr, buf_length + 2, stdin);
		while ((arr[i] != '\n') && (i <= buf_length))
			i++;
		arr[i] = '\0';
		if ((arr[buf_length] != '\n') && (arr[buf_length] != '\0'))
			__fpurge(stdin);
		if (strlen(arr) > buf_length)
			count = queue_put_bulk(queue, arr, buf_length);
		else
			count = queue_put_bulk(queue, arr, strlen(arr));
		break;
	}
	free(arr);

	return count;
}

static int get_bulk(struct queue_info *queue)
{
	char *arr;
	int buf_length = 0;
	int count = 0;

	printf("Enter the length of the bulk data to get:\n");
	buf_length = get_int();		
	arr = malloc(sizeof(char) * buf_length);
	count = queue_get_bulk(queue, arr, buf_length);
	if (count != -1)
		printf("Bulk data from queue = %s\n", arr);
	free(arr);

	return count;
}

static int queue_operation(struct queue_info *queue, int queue_number)
{
	int opr = 0;

	printf("\nData in queue[%d] buffer:\t", queue_number + 1);
	if (display(queue))
		printf("No data in buffer\n");
	printf("1.put\t2.get\t3.put_bulk\t4.get_bulk\n");
	printf("5.reset\t6.flush\t7.config\t8.exit\n");
	opr = get_int();
	switch (opr) {
	case 1:
		if (put_data(queue))
			printf("Queue is full\n");
		break;
	case 2:
		if (get_data(queue) == -1)
			printf("Queue is empty\n");
		break;
	case 3:
		if (put_bulk(queue) == -1)
			printf("Queue is full\n");
		break;
	case 4:
		if (get_bulk(queue) == -1)
			printf("Queue is empty\n");
		break;
	case 5:
		queue_reset(queue);
		break;
	case 6:
		if (data_flush(queue) == -1)
			printf("No data to flush\n");
		break;
	case 7:
		config_queue(queue);
		break;
	case 8:
		return 0;		
	default:
		printf("Invalid options\n");
	}

	return 1;
}
static char *queue_buffer(struct queue_info *queue, int queue_number,
		  char *queue_buf, int count)
{
	int queue_length = 0;

	while (1) {
		printf("Enter the details for queue[%d]:\n",
		       queue_number + 1);
		while (queue_used[queue_number] != 1) {
			printf("Enter the Queue length within");
			printf("%d for queue[%d]\n",
			       MAX_LENGTH, queue_number + 1);
			queue_length = get_int();
			queue_buf = malloc(sizeof(char) * queue_length);
			if ((queue_length > MAX_LENGTH) || (queue_length < 1)) {
				printf("invalid data\n");
				continue;
			}
			queue_used[queue_number] = 1;
			queue_init(queue, queue_buf, queue_length);
		}
		while (1) {
			if (!queue_operation(queue, queue_number))
				return queue_buf;
		}
	}
}

static void queue_form(int count)
{
	struct queue_info queue[count];
	char *queue_buf[count];
	int queue_number = 0;
	char queue_switcher = 0;
	int i = 0;

	while (1) {
		printf("Enter the queue number to switch between %d\n", count);
		queue_number = get_int();
		queue_number -= 1;
		if ((queue_number >= count) || (queue_number < 0)) {
			printf("invalid data\n");
			continue;
		}
		queue_buf[queue_number] =  queue_buffer(&queue[queue_number], queue_number,
			     queue_buf[queue_number], count);
		printf("Want to switch queue(y/n)\n");
		scanf(" %c", &queue_switcher);
		__fpurge(stdin);
		if ((queue_switcher == 'y') || (queue_switcher == 'Y'))
			continue;
		else
			break;
	}
	while (i++ != count) {
		if (queue_used[i])
			free(queue_buf[i]);
	}
}

int main(void)
{
	int count = 0;

	while (1) {
		printf("Enter the number of queue within %d\n", MAX_QUEUE);
		count = get_int();
		if ((count > MAX_QUEUE) || (count < 1)) {
			printf("Invalid data\n");
			continue;
		}
		break;
	}
	queue_form(count);
	return 0;
}
