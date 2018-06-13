#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <queue_ver5.h>
#define MAX_QUEUE 3
#define MAX_LENGTH 15
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

	if ((queue->rear == -1) && (queue->front == -1))
		return -1;

	do {
		//printf("front = %d\trear= %d\n", front, queue->rear);
		if (front == queue->queue_len)
			front = 0;
		switch (queue->type) {
		case char_d:
			printf("%c   ", *(((char *)queue->array) + front));
			break;
		case short_d:
			printf("%hd   ", *(((short *)queue->array) + front));
			break;
		case int_d:
			printf("%d   ", *(((int *)queue->array) + front));
			break;
		case long_d:
			printf("%ld   ", *(((long *)queue->array) + front));
			break;
		case float_d:
			printf("%f    ", *(((float *)queue->array) + front));
			break;
		case double_d:
			printf("%.10lf   ", *(((double *)queue->array) + front));
			break;
		}
	} while (front++ != (queue->rear));
	printf("\n");
	return 0;
}

static int get_queue(struct queue_info *queue)
{
	int i = 0;
	void *queue_buf;
	int buf_length;

	printf("enter the length the get queue\n");
	buf_length = get_int();
	if ((buf_length > MAX_LENGTH) || (buf_length < 1))
		return -1;
	printf("Data from queue:\t");
	switch (queue->type) {
	case char_d:
		queue_buf = malloc(buf_length * sizeof(char));
		if (queue_get_g(queue, queue_buf, &buf_length) != -1) {
			for (i = 0; i < buf_length; i++)
				printf(" %c", *(((char *)queue_buf) + i));
		} else {
			printf("Queue is empty\n");
		}
		break;
	case short_d:
		queue_buf = malloc(buf_length * sizeof(short));
		if (queue_get_g(queue, queue_buf, &buf_length) != -1) {
			for (i = 0; i < buf_length; i++)
				printf(" %hd", *(((short *)queue_buf) + i));
		} else {
			printf("Queue is empty\n");
		}
		break;
	case int_d:
		queue_buf = malloc(buf_length * sizeof(int));
		if (queue_get_g(queue, queue_buf, &buf_length) != -1) {
			for (i = 0; i < buf_length; i++)
				printf(" %d", *(((int *)queue_buf) + i));
		} else {
			printf("Queue is empty\n");
		}
		break;
	case long_d:
		queue_buf = malloc(buf_length * sizeof(long));
		if (queue_get_g(queue, queue_buf, &buf_length) != -1) {
			for (i = 0; i < buf_length; i++)
				printf(" %ld", *(((long *)queue_buf) + i));
		} else {
			printf("Queue is empty\n");
		}
		break;
	case float_d:
		queue_buf = malloc(buf_length * sizeof(float));
		queue_get_g(queue, queue_buf, &buf_length);
		if (queue_get_g(queue, queue_buf, &buf_length) != -1) {
			for (i = 0; i < buf_length; i++)
				printf(" %f", *(((float *)queue_buf) + i));
		} else {
			printf("Queue is empty\n");
		}
		break;
	case double_d:
		queue_buf = malloc(buf_length * sizeof(double));
		queue_get_g(queue, queue_buf, &buf_length);
		if (queue_get_g(queue, queue_buf, &buf_length) != -1) {
			for (i = 0; i < buf_length; i++)
				printf(" %lf", *(((double *)queue_buf) + i));
		} else {
			printf("Queue is empty\n");
		}
		break;
	}

	free(queue_buf);
	return 0;
}

static int put_queue(struct queue_info *queue)
{
	int i = 0;
	void *queue_buf;
	int buf_length;

	printf("enter the length the put queue\n");
	buf_length = get_int();
	if ((buf_length > MAX_LENGTH) || (buf_length < 1))
		return -1;
	printf("Enter the data to put of length %d\n", buf_length);
	switch (queue->type) {
	case char_d:
		queue_buf = malloc(buf_length * sizeof(char));
		for (i = 0; i < buf_length; i++) {
			printf("Enter data %d:  ", i+1);
			scanf(" %c", (char *)queue_buf + i);
			__fpurge(stdin);
		}
		break;
	case short_d:
		queue_buf = malloc(buf_length * sizeof(short));
		for (i = 0; i < buf_length; i++) {
			printf("Enter data %d:  ", i+1);
			scanf(" %hd", (short *)queue_buf + i);
			__fpurge(stdin);
		}
		break;
	case int_d:
		queue_buf = malloc(buf_length * sizeof(int));
		for (i = 0; i < buf_length; i++) {
			printf("Enter data %d:  ", i+1);
			scanf(" %d", (int *)queue_buf + i);
			__fpurge(stdin);
		}
		break;
	case long_d:
		queue_buf = malloc(buf_length * sizeof(long));
		for (i = 0; i < buf_length; i++) {
			printf("Enter data %d:  ", i+1);
			scanf(" %ld", (long *)queue_buf + i);
			__fpurge(stdin);
		}
		break;
	case float_d:
		queue_buf = malloc(buf_length * sizeof(float));
		for (i = 0; i < buf_length; i++) {
			printf("Enter data %d:  ", i+1);
			scanf(" %f", (float *)queue_buf + i);
			__fpurge(stdin);
		}
		break;
	case double_d:
		queue_buf = malloc(buf_length * sizeof(double));
		for (i = 0; i < buf_length; i++) {
			printf("Enter data %d:  ", i+1);
			scanf(" %lf", (double *)queue_buf + i);
			__fpurge(stdin);
		}
		break;
	}
	if (queue_put_g(queue, queue_buf, &buf_length) == -1)
		printf("Queue is Full\n");

	free(queue_buf);
	return 0;
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
			if (put_queue(queue))
				printf("Invaild data\n");
			break;
		case 2:
			if (get_queue(queue))
				printf("Invaild data\n");
			break;
		case 3:
			return 0;
		case 4:
			printf("Invalid options\n");
		}
	}
	return 1;

}

static void *queue_buffer(struct queue_info *queue, int queue_number,
		  void *queue_buf, int count)
{
	int queue_len;
	int data_type;
	enum g_typename type;

	while (1) {
		while (queue_used[queue_number] != 1) {
			printf("Enter the details for queue[%d]:\n",
			       queue_number + 1);
			printf("Enter the Queue length within ");
			printf("%d for queue[%d]\n",
			       MAX_LENGTH, queue_number + 1);
			queue_len = get_int();
			if ((queue_len > MAX_LENGTH) || (queue_len < 1)) {
				printf("invalid data\n");
				continue;
			}
			printf("Enter the type of datatype");
			printf("\n1.char\n2.short\n");
			printf("3.int\n4.long\n5.float\n6.double\n");
			data_type = get_int();
			type = data_type;
			if ((type < 1) || (type > 6)) {
				printf("invaild data\n");
				continue;
			}
			switch (type) {
			case char_d:
				queue_buf = malloc(sizeof(char) * queue_len);
				break;
			case short_d:
				queue_buf = malloc(sizeof(short) * queue_len);
				break;
			case int_d:
				queue_buf = malloc(sizeof(int) * queue_len);
				break;
			case long_d:
				queue_buf = malloc(sizeof(long) * queue_len);
				break;
			case float_d:
				queue_buf = malloc(sizeof(float) * queue_len);
				break;
			case double_d:
				queue_buf = malloc(sizeof(double) * queue_len);
				break;
			}
			queue_used[queue_number] = 1;
			queue_init_g(queue, queue_buf, type, queue_len);
		}
		while (1) {
			if (!queue_operation(queue, queue_number))
				return queue_buf;
		}
	}
}

static int queue_form(int count)
{
	struct queue_info queue[count];
	void *queue_buf1 = NULL;
	void *queue_buf2 = NULL;
	void *queue_buf3 = NULL;
	int queue_number;
	char queue_switcher;

	while (1) {
		printf("Enter the queue number to switch between %d\n", count);
		queue_number = get_int();
		queue_number -= 1;
		if ((queue_number >= count) || (queue_number < 0)) {
			printf("invalid data\n");
			continue;
		}
		switch (queue_number) {
		case 0:
			queue_buf1 = queue_buffer(&queue[queue_number], queue_number,
						  queue_buf1, count);
			break;
		case 1:
			queue_buf2 = queue_buffer(&queue[queue_number], queue_number,
						  queue_buf2, count);
			break;
		case 2:
			queue_buf3 = queue_buffer(&queue[queue_number], queue_number,
						  queue_buf3, count);
			break;
		}
		printf("want to switch queue(y/n)\n");
		scanf(" %c", &queue_switcher);
		__fpurge(stdin);
		if ((queue_switcher == 'y') || (queue_switcher == 'Y'))
			continue;
		else
			break;
	}

	if (queue_used[0] == 1)
		free(queue_buf1);
	if (queue_used[1] == 1)
		free(queue_buf2);
	if (queue_used[2] == 1)
		free(queue_buf3);
	return 0;
}

int main(void)
{
	int count;

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
