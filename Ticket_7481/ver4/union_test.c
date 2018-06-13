#include <stdio.h>
#include <queue_ver4.h>
#include <strings.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <union_test.h>
#define MAX_QUEUE 10
#define MAX_LENGTH 15
int queue_used[MAX_LENGTH];

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

	if ((queue->rear == -1) && (queue->front == -1))
		return -1;

	do {
		if (front == queue->queue_len)
			front = 0;
		switch (queue->type) {
		case char_g:
			printf("%c\t", queue->array[front].char_d);
			break;
		case short_g:
			printf("%d\t", queue->array[front].short_d);
			break;
		case int_g:
			printf("%d\t", queue->array[front].int_d);
			break;
		case long_g:
			printf("%ld\t", queue->array[front].long_d);
			break;
		case float_g:
			printf("%f\t", queue->array[front].float_d);
			break;
		case double_g:
			printf("%.10lf\t", queue->array[front].double_d);
			break;
		}
	} while (front++ != (queue->rear));
	printf("\n");
	return 0;
}

static int put_data(struct queue_info *queue)
{
	union g_datatype data_sender;
	int check = 0;

	printf("Enter the data to put in queue\n");

	switch (queue->type) {
	case char_g:
		check = scanf(" %c", &data_sender.char_d);
		break;
	case short_g:
		check = scanf("%hd", &data_sender.short_d);
		break;
	case int_g:
		check = scanf("%d", &data_sender.int_d);
		break;
	case long_g:
		check = scanf("%ld", &data_sender.long_d);
		break;
	case float_g:
		check = scanf("%f", &data_sender.float_d);
		break;
	case double_g:
		check = scanf("%lf", &data_sender.double_d);
		break;
	}
	__fpurge(stdin);
	if (check && queue_put_generic(queue, &data_sender))
		printf("Queue is full\n");
	else if (!check)
		return -1;

	return 0;
}

static void get_data(struct queue_info *queue)
{
	union g_datatype data_receiver;
	if (queue_get_generic(queue, &data_receiver)) {
		printf("Queue is empty");
	} else {
		switch (queue->type) {
		case char_g:
			printf("get char = %c\n", data_receiver.char_d);
			break;
		case short_g:
			printf("get short = %d\n", data_receiver.short_d);
			break;
		case int_g:
			printf("get int = %d\n", data_receiver.int_d);
			break;
		case long_g:
			printf("get long = %ld\n", data_receiver.long_d);
			break;
		case float_g:
			printf("get float = %f\n", data_receiver.float_d);
			break;
		case double_g:
			printf("get double = %lf\n", data_receiver.double_d);
			break;
		}
	}
}

static int queue_operation(struct queue_info *queue, int queue_number)
{
	int opr;

	while (1) {
		printf("\nData in buffer[%d]:\t", queue_number + 1);
		if (display(queue))
			printf("No data in buffer\n");
		printf("1.put\t2.get\t3.exit\n");
		opr = get_int();
		switch (opr) {
		case 1:
			if(put_data(queue))
				printf("Invalid data\n");
			break;
		case 2:
			get_data(queue);
			break;
		case 3:
			return 0;
		default:
			printf("Invalid options\n");
		}
	}
	return 1;
}

static union g_datatype *queue_buffer(struct queue_info *queue, int queue_number,
				      union g_datatype *queue_buf, int count)
{
	int queue_length;
	enum g_typename type;

	printf("%p\n", queue_buf);
	while (1) {
		while (queue_used[queue_number] != 1) {
			printf("Enter the details for queue[%d]:\n",
			       queue_number + 1);
			printf("Enter the Queue length within ");
			printf("%d for queue[%d]\n",
			       MAX_LENGTH, queue_number + 1);
			queue_length = get_int();
			if ((queue_length > MAX_LENGTH) || (queue_length < 1)) {
				printf("invalid data\n");
				continue;
			}
			queue_buf = malloc(sizeof(union g_datatype) *
					   queue_length);
			printf("Enter the type of datatype");
			printf("\n1.char\n2.short\n");
			printf("3.int\n4.long\n5.float\n6.double\n");
			type = get_int();
			if ((type < 1) || (type > 6)) {
				printf("invalid data\n");
				continue;
			}
			queue_used[queue_number] = 1;
			queue_init_generic(queue, queue_buf, type, queue_length);
		}
		while (1) {
			if (!queue_operation(queue, queue_number)) {
				return queue_buf;
			}
		}
	}
}

static void queue_form(int count)
{
	struct queue_info queue[count];
	union g_datatype *queue_buf[count];
	int queue_number;
	char queue_switcher;
	int i = 0;

	while (1) {
		printf("Enter the queue number to switch between %d\n", count);
		queue_number = get_int();
		queue_number -= 1;
		if ((queue_number >= count) || (queue_number < 0)) {
			printf("invalid data\n");
			continue;
		}
		queue_buf[queue_number] = queue_buffer(&queue[queue_number], queue_number,
						       queue_buf[queue_number], count);
		printf("want to switch queue(y/n)\n");
		scanf(" %c", &queue_switcher);
		__fpurge(stdin);
		if (!((queue_switcher == 'y') || (queue_switcher == 'Y')))
			break;
	}

	while (i != count) {
		if (queue_used[i])
			free(queue_buf[i]);
		i++;
	}
}

int main(void)
{
	int count;

	while (1) {
		printf("Enter the number of queue within %d\n", MAX_QUEUE);
		count = get_int();
		if ((count >= MAX_QUEUE) || (count < 1)) {
			printf("Invalid data\n");
			continue;
		}
		break;
	}
	queue_form(count);
	return 0;

}
