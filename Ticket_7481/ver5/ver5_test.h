/* 
 * get_int() - It will get the integer input from user
 * 
 * This function vaildate the input from the user and get the integer input
 * 
 * Return - It will return integer data
 */ 
static int get_int(void);

/*
 * display() - It will display the data in the queue
 *
 * @arg1 - It is pointer to the structure queue_info
 *
 * THis function will display the data in queue from front to rear
 * 
 * Return - 0 for success and -1 for failure.
 * 
 */
static int display(struct queue_info *queue);

/*
 * put_data() - This will get the data from user and insert into queue
 * 
 * @arg1 - It is pointer to the structure queue_info
 *
 * This will get data from user and pass the value to API
 *
 * Return - 0 for success and -1 for failure.
 *
 */
static int put_queue(struct queue_info *queue);

/*
 * get_data() - This will get the data from queue
 *
 * @arg1 - It is pointer to the structure queue_info
 *
 * This get the data from queue.
 *
 * Return - 0 for success and -1 for failure.
 * 
 */
static int get_queue(struct queue_info *queue);

/*
 * queue_operation() - This function used to get the type of operation from user
 * 
 * @arg1 - It is pointer to the structure queue_info
 * @arg2 - It is integer data type
 * 
 * This function used for getting operation to perform on the queue
 *
 * Return - 1 for non-vaild input 0 for success  
 */
static int queue_operation(struct queue_info *queue, int queue_number);

/*
 * queue_buffer() - This function will create buffer for every queue
 * 
 * @arg1 - It is pointer to the structure queue_info
 * @arg2 - It is integer data type
 * @arg3 - It is void pointer
 * @arg4 - It is integer data type
 * 
 * This function will create buffer for queue based on the argument passed 
 * with the length from obtained from the user.
 *
 * Return - It will return void pointer
 */
static void *queue_buffer(struct queue_info *queue, int queue_number,
			 void *queue_buf, int count);


/*
 * queue_form - This function used to jump between queues
 *
 * @arg1 - It is integer datatype
 *
 * This function used to jump between queues based on the input from user.
 */
static void queue_form(int count);
