#define INITIAL_LOCATION -1

union g_datatype
{
	char char_d;
	short short_d ;
	int int_d;
	long long_d;
	float float_d;
	double double_d;
};

struct queue_info
{
	int front;
	int rear;
	int queue_len;
	int type;
	union g_datatype *array;	
};

enum g_typename {
	char_g = 1,
	short_g,
	int_g,
	long_g,
	float_g,
	double_g,
};
/*
 * queue_init_generic() - initization process for queue
 * @arg1 - It is pointer for struture queue_info
 * @arg2 - It is pointer to the union g_datatype
 * @arg3 - It is enum daatype
 * @arg4 - It is integer value
 * 
 * This function use to initization of front, rear, queue length, queue buffer, type
 * of the queue.
 *
 */
void queue_init_generic(struct queue_info *queue, union g_datatype *generic, enum g_typename type, int queue_len);

/*
 * queue_put_generic() - This function use to put data in queue
 * @arg1 - It is pointer for structure queue_info
 * @arg2 - It is pointer to union g_datatype
 * 
 * This function use to insert the agrument in the queue. 
 * If there is free space is available in queue.
 * Return - 0 for success and -1 for failure
 *
 */
int queue_put_generic(struct queue_info *queue, union g_datatype *generic);

/*
 * queue_get_generic() - this function use to get the data from queue
 * @arg1 - It is the pointer to the structure queue_info
 * @arg2 - It is pointer to character
 *
 * This function use to get the data from queue and return by argument. 
 * If there is a data available in queue.
 * Return - 0 for sucess and -1 failure
 *
 */
int queue_get_generic(struct queue_info *queue, union g_datatype *generic);
