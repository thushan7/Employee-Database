#include "../include/headerA3.h"

/*This function removes all employees from the linked list.
headLL contains the linked list.*/
void fireAll(a3Emp ** headLL) {
  a3Emp * temp; //used to traverse list and free nodes

  if (*headLL == NULL) { //lets user know that list is empty if head doesn't point to anything
    printf("List is empty.\n");
  }
  else { //continue as normal otherwise
    while (*headLL != NULL) { //traverse list and free nodes until end is reached
      temp = *headLL;

      *headLL = temp->nextEmployee; //"delete" each node from list by manipulating nextEmployee pointers

      //free memory used by deleted node
      for (int i=0; i<temp->numDependents; i++) {
        free(temp->dependents[i]);
      }
      free(temp->dependents);
      free(temp);
    }
  }
}
