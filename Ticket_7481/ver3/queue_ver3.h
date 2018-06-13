#define FLOW_CONTROLLED 1
#define DISCARD_ON_OVERFLOW 2
#define PARTIAL_RW 3
#define INITIAL_LOCATION -1

struct queue_info
{
	int front;
	int rear;
	int queue_len;
	char *array;
};

/*
 * counter() - This function will count the number of element in queue
 *
 * @arg1 - It is pointer for struture queue_info
 * 
 * This function will count number of element in queue from front to rear.
 * Return - 0 for no element and positive integer for count.
 */ 
int counter(struct queue_info *queue);

/*
 * queue_init() - initization process for queue
 * @arg1 - It is pointer for struture queue_info
 * @arg2 - It is pointer to the character
 * @arg3 - It is integer value
 * 
 * This function use to initization of front, rear, queue length, queue buffer
 * of the queue.
 *
 */
void queue_init(struct queue_info *queue, char *queue_buf, int queue_len);

/*
 * queue_put () - This function use to put data in queue
 * @arg1 - It is pointer for structure queue_info
 * @arg2 - It is character
 * 
 * This function use to insert the agrument value in the queue. 
 * If there is free space is available in queue.
 * Return - 0 for success and -1 for failure
 *
 */
int queue_put(struct queue_info *queue, char value);

/*
 * queue_get() - this function use to get the data from queue
 * @arg1 - It is the pointer to the structure queue_info
 * @arg2 - It is pointer to character
 *
 * This function use to get the data from queue and return by argument. 
 * If there is a data available in queue.
 * Return - 0 for sucess and -1 failure
 *
 */
int queue_get(struct queue_info *queue, char *value);

/*
 * queue_put_bulk() - This function use to put bulk data in queue
 * @arg1 - It is pointer for structure queue_info
 * @arg2 - It is pointer to character
 * @arg3 - It is integer datatype
 * 
 * This function use to insert the agrument values in the queue based on the length. 
 * If there is free space is available in queue.
 * return number of element inserted.
 * Return - positive for success and -1 for failure
 */
int queue_put_bulk(struct queue_info *queue, char *values, int len);

/*
 * queue_get_bulk() - This function use to get the bulk data from queue
 *
 * @arg1 - It is pointer for structure queue_info
 * @arg2 - It is pointer to character
 * @arg3 - It is integer datatype
 * 
 * This function use to get the data from queue and return by argument values. 
 * If there is a data available in queue.
 * returns number of elements obtained from queue.
 * 
 * Return - positive for sucess and -1 failure
 */
int queue_get_bulk(struct queue_info *queue, char *values, int len);

/*
 * queue_reset() - This function will reset the front and rear value.
 *
 * This function will reset the front and rear value to initial value.
 */
void queue_reset(struct queue_info *queue);

/*
 * data_flush() - This function will flush the data from the queue
 *
 * @arg1 - It is the pointer to structure queue_info
 * @arg2 - It is the pointer to character
 * @arg3 - It is the pointer to integer 
 * 
 * This function will flush the queue and save the flused data into the argument. 
 * returns the length of the flushed data by argument.
 *
 * Return - -1 for failure 0 for success
 */ 
int queue_flush(struct queue_info *queue, char *values, int *len);

/*
 * queue_config() - This function will configure the operation on queue
 *
 * @arg1 - It is the pointer to structure queue_info
 * @arg2 - It is the pointer to integer
 *
 * The following flag can be used to configure FLOW_CONTROLLED, 
 * DISCARD_ON_OVERFLOW, PARTIAL_RW 
 */
int queue_config(struct queue_info *queue, int config); 
