#define INITIAL_LOCATION -1

enum g_typename {
	char_d = 1,
	short_d,
	int_d,
	long_d,
	float_d,
	double_d,
};

struct queue_info {
	int front;
	int rear;
	enum g_typename type;
	int queue_len;
	void *array;
};

/*
 * queue_init_g() - initization process for queue
 * @arg1 - It is pointer for struture queue_info
 * @arg2 - It is void pointer
 * @arg3 - It is enum daatype
 * @arg4 - It is integer value
 * 
 * This function use to initization of front, rear, queue length, queue buffer, type
 * of the queue.
 *
 */
void queue_init_g(struct queue_info *queue, void *generic, enum g_typename type, int queue_len);

/*
 * queue_put_g() - This function use to put data in queue
 * @arg1 - It is pointer for structure queue_info
 * @arg2 - It is void pointer
 * @arg3 - It is pointer to integer datatype
 * 
 * This function use to insert the agrument in the queue with the length. 
 * return number of data inserted in queue by return by argument.
 * If there is free space is available in queue.
 * Return - 0 for success and -1 for failure
 *
 */
int queue_get_g(struct queue_info *queue, void *generic, int *len);

/*
 * queue_get_g() - this function use to get the data from queue
 * @arg1 - It is the pointer to the structure queue_info
 * @arg2 - It is void pointer
 * @arg3 - It is pointer to integer datatype
 *
 * This function use to get the data from queue and return by argument with the length. 
 * return number of data obtained from queue by return by argument.
 * If there is a data available in queue.
 * Return - 0 for sucess and -1 failure
 *
 */
int queue_put_g(struct queue_info *queue, void *generic, int *len);
