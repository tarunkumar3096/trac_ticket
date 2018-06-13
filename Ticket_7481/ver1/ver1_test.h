#define MAX_LENGTH 15
#define INITIAL_LOCATION -1

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
