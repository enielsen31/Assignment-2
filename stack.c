/*
 * This file is where you should implement your stack.  It already contains
 * skeletons of the functions you need to implement (along with documentation
 * for each function).  Feel free to implement any additional functions you
 * might need.  Also, don't forget to include your name and @oregonstate.edu
 * email address below.
 *
 * Name:
 * Email:
 */

#include <stdlib.h>

#include "stack.h"
#include "list.h"

/*
 * This is the structure that will be used to represent a stack.  This
 * structure specifically contains a single field representing a linked list
 * that should be used as the underlying data storage for the stack.
 *
 * You should not modify this structure.
 */
struct stack {
  struct list* list;
};

/*
 * This function should allocate and initialize a new, empty stack and return
 * a pointer to it.
 */
struct stack* stack_create() {
        /*
         * FIXME:
         */
        struct stack* new_stack = malloc(sizeof(struct stack));

    // Check if malloc succeeded
    if (new_stack == NULL) {
        return NULL;  // Return NULL if memory allocation failed
    }

    // Allocate and initialize the list (assuming a list_create function exists)
    new_stack->list = list_create();  // Initialize the list as an empty list

    // Return the newly created stack
    return new_stack;
        return NULL;
}

/*
 * This function should free the memory associated with a stack.  While this
 * function should up all memory used in the stack itself, it should not free
 * any memory allocated to the pointer values stored in the stack.  This is the
 * responsibility of the caller.
 *
 * Params:
 *   stack - the stack to be destroyed.  May not be NULL.
 */
void stack_free(struct stack* stack) {
        /*
         * FIXME:
         */
        // Free the list associated with the stack (assuming there's a function for it)
    if (stack != NULL) {
        list_free(stack->list);  // Free the list (you need to implement list_free)
        free(stack);  // Free the stack structure itself
    }
        return;
}

/*
 * This function should indicate whether a given stack is currently empty.
 * Specifically, it should return 1 if the specified stack is empty (i.e.
 * contains no elements) and 0 otherwise.
 *
 * Params:
 *   stack - the stack whose emptiness is being questioned.  May not be NULL.
 */
int stack_isempty(struct stack* stack) {
        /*
         * FIXME:
         */
        if(list_empty(stack->list) == 1){ // returns 1 when empty

        return 0;
        }

}

/*
 * This function should push a new value onto a given stack.  The value to be
 * pushed is specified as a void pointer.  This function must have O(1)
 * average runtime complexity.
 *
 * Params:
 *   stack - the stack onto which a value is to be pushed.  May not be NULL.
 *   val - the value to be pushed.  Note that this parameter has type void*,
 *     which means that a pointer of any type can be passed.
 */
void stack_push(struct stack* stack, void* val) {
        /*
         * FIXME:
         */
        list_insert(stack->list, val);

        // Create a new node
    //struct node* new_node = malloc(sizeof(struct node));

    // Check for memory allocation failure
   // if (new_node == NULL) {
 //       return;  // Return if memory allocation failed (out of memory)
    }

    // Set the value of the new node
  //  new_node->val = val;

    // Set the new node's next pointer to the current head of the list
//    new_node->next = stack->list->head;

    // Update the head of the list to point to the new node
//    stack->list->head = new_node;
        return;
}

/*
 * This function should return the value stored at the top of a given stack
 * *without* removing that value.  This function must have O(1) average runtime
 * complexity.
 *
 * Params:
 *   stack - the stack from which to query the top value.  May not be NULL.
 */
void* stack_top(struct stack* stack) {
        /*
         * FIXME:
         */
        return value_head(stack->list);
         // Check if the stack is empty
 //   if (stack->list->head == NULL) {
   //     return NULL;  // Return NULL if the stack is empty
    }

    // Return the value stored at the top of the stack (head of the list)
   // return stack->list->head->val;
        return NULL;
}

/*
 * This function should pop a value from a given stack and return the popped
 * value.  This function must have O(1) average runtime complexity.
 *
 * Params:
 *   stack - the stack from which a value is to be popped.  May not be NULL.
 *
 * Return:
 *   This function should return the value that was popped.
 */
void* stack_pop(struct stack* stack) {
        /*
         * FIXME:
         */
return list_remove_val(stack->list);
        // Check if the stack is empty
  //  if (stack->list->head == NULL) {
  //      return NULL;  // Return NULL if the stack is empty
    }

    // Store the value of the top node
  //  void* top_value = stack->list->head->val;

    // Save the current top node to free later
   // struct node* old_top = stack->list->head;

    // Update the head to the next node in the stack
 //   stack->list->head = stack->list->head->next;

    // Free the memory of the old top node
  //  free(old_top);

    // Return the value that was popped
//    return top_value;
        return NULL;
}
