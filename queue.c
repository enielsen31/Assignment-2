#include "queue.h"
#include "dynarray.h"

/*
 * This is the structure that will be used to represent a queue.  This
 * structure specifically contains a single field representing a dynamic array
 * that should be used as the underlying data storage for the queue.
 *
 * You should not modify this structure.
 */
struct queue {
  struct dynarray* array;
};

/*
 * This function should allocate and initialize a new, empty queue and return
 * a pointer to it.
 */
struct queue* queue_create() {
        /*
         * FIXME:
         */
         // Allocate memory for the queue
    struct queue* new_queue = malloc(sizeof(struct queue));

    // Check if memory allocation succeeded
    if (new_queue == NULL) {
        return NULL;  // Return NULL if memory allocation failed
    }

    // Create and initialize the dynamic array (assuming a function like dynarray_create)
    new_queue->array = dynarray_create();

    // Return the newly created queue
    return new_queue;
        return NULL;
}

/*
 * This function should free the memory associated with a queue.  While this
 * function should up all memory used in the queue itself, it should not free
 * any memory allocated to the pointer values stored in the queue.  This is the
 * responsibility of the caller.
 *
 * Params:
 *   queue - the queue to be destroyed.  May not be NULL.
 */
void queue_free(struct queue* queue) {
        /*
         * FIXME:
         */
        // Check if the queue is not NULL
    if (queue == NULL) {
        return;  // If the queue is NULL, there's nothing to free
    }

    // Free the dynamic array associated with the queue
    dynarray_free(queue->array);

    // Free the memory allocated for the queue structure itself
    free(queue);
        return;
}

/*
 * This function should indicate whether a given queue is currently empty.
 * Specifically, it should return 1 if the specified queue is empty (i.e.
 * contains no elements) and 0 otherwise.
 *
 * Params:
 *   queue - the queue whose emptiness is being questioned.  May not be NULL.
 */
int queue_isempty(struct queue* queue) {
        /*
         * FIXME:
         */
        if(dynarray_size(queue->array) == NULL);
        return NULL;
}
        return 1;
}

/*
 * This function should enqueue a new value into a given queue.  The value to
 * be enqueued is specified as a void pointer.  This function must have O(1)
 * average runtime complexity.
 *
 * Params:
 *   queue - the queue into which a value is to be enqueued.  May not be NULL.
 *   val - the value to be enqueued.  Note that this parameter has type void*,
 *     which means that a pointer of any type can be passed.
 */
void queue_enqueue(struct queue* queue, void* val) {
        /*
         * FIXME:
         */
        // Enqueue the value by appending it to the dynamic array
    dynarray_append(queue->array, val);
        return;
}

/*
 * This function should return the value stored at the front of a given queue
 * *without* removing that value.  This function must have O(1) average runtime
 * complexity.
 *
 * Params:
 *   queue - the queue from which to query the front value.  May not be NULL.
 */
void* queue_front(struct queue* queue) {
        /*
         * FIXME:
         */
        // Check if the queue is empty
    if (queue_isempty(queue)) {
        return NULL;  // Return NULL if the queue is empty
    }

    // Return the value stored at the front of the queue (first element in the array)
    return queue->array->data[0];
        return NULL;
}

/*
 * This function should dequeue a value from a given queue and return the
 * dequeued value.  This function must have O(1) average runtime complexity.
 *
 * Params:
 *   queue - the queue from which a value is to be dequeued.  May not be NULL.
 *
 * Return:
 *   This function should return the value that was dequeued.
 */
void* queue_dequeue(struct queue* queue) {
        /*
         * FIXME:
         */
        // Check if the queue is empty
    if (queue_isempty(queue)) {
        return NULL;  // Return NULL if the queue is empty
    }

    // Store the front value (the first element in the dynamic array)
    void* front_value = queue->array->data[0];

    // Shift all elements in the dynamic array to the left by one position
    int size = dynarray_size(queue->array);
    for (int i = 1; i < size; i++) {
        queue->array->data[i - 1] = queue->array->data[i];
    }

    // Decrease the size of the dynamic array (remove the last element)
    dynarray_resize(queue->array, size - 1);

    // Return the dequeued value
    return front_value;
        return NULL;
}
