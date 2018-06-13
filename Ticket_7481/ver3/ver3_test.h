/* 
 * get_int() - It will get the integer input from user
 * 
 * This function vaildate the input from the user and get the integer input
 * 
 * Return - It will return integer data
 */ 
static int get_int(void);

/*
 * counter() - It will count the number of elements in queue
 * 
 * @arg1 - It is pointer to structure queue_info
 *
 * This will count number of data in queue from front to rear
 * Return - count integer form
 */
static int counter(struct queue_info *queue);

/*
 * display() - It will display the data in the queue
 *
 * @arg1 - It is pointer to the structure queue_info
 *
 * THis function will display the data in queue from front to rear
 * 
 * Return - 0 for success and -1 for failure
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
 * Return - 0 for success and -1 for failure
 *
 */
static int put_data(struct queue_info *queue);

/*
 * get_data() - This will get the data from queue
 *
 * @arg1 - It is pointer to the structure queue_info
 *
 * This get the data from queue.
 * 
 * Return - -1 for failure positive value for success
 */
static int get_data(struct queue_info *queue);

/*
 * put_data() - This will get the bulk data from user and insert into queue
 * 
 * @arg1 - It is pointer to the structure queue_info
 *
 * This will get bulk data from user and pass the value to API
 * 
 * Return - postivie for success and -1 for failure
 *
 */
static int put_bulk(struct queue_info *queue);

/*
 * get_data() - This will get the bulk data from queue
 *
 * @arg1 - It is pointer to the structure queue_info
 *
 * This get the bulk data from queue.
 * 
 * Return - -1 for failure positive value for success
 */
static int get_bulk(struct queue_info *queue);

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
 * @arg3 - It is pointer to the character
 * @arg4 - It is integer data type
 * 
 * This function will create buffer for queue based on the argument passed 
 * with the length from obtained from the user
 *
 */
static char *queue_buffer(struct queue_info *queue, int queue_number,
			 char *queue_buf, int count);


/*
 * queue_form - This function used to jump between queues
 *
 * @arg1 - It is integer datatype
 *
 * This function used to jump between queues based on the input from user.
 */
static void queue_form(int count);

/*
 * data_flush() - This function will flush the data from the queue
 *
 * @arg1 - It is the pointer to structure queue_info
 * 
 * This function will get the length of the buffer to save the flused data from the user. 
 * returns the error condition based on the input.
 *
 * Return - -1 for failure 0 for success
 */ 
static int data_flush(struct queue_info *queue);

/*
 * config_queue - This function used to configure the queue.
 *
 * @arg1 - It is the pointer to structure queue_info
 *
 * This function will get the input from user to configure the queue.
 */
static void config_queue(struct queue_info *queue);
