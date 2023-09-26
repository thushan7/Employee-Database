#include "../include/headerA3.h"

/*This function removes a chosen employee from the linked list.
headLL contains the linked list, whichOne is the position of the employee to be removed.*/
void fireOne(a3Emp ** headLL, int whichOne) {
  a3Emp * curr = *headLL; //current node
  a3Emp * prev = NULL; //previous node

  if (*headLL == NULL) { //lets user know that list is empty if head doesn't point to anything
    printf("List is empty.\n");
  }
  else { //continue as normal otherwise

    //traverse list until curr points to node of employee to be fired
    for (int i=1; i<whichOne; i++) {
      prev = curr;
      curr = curr->nextEmployee;
    }

    //make pointer of prev node point to what the pointer of curr node is pointing at
    //this effectively "bypasses" the curr node, which is the employee to be fired
    if (curr == *headLL) {
      *headLL = curr->nextEmployee;
    }
    else {
      prev->nextEmployee = curr->nextEmployee;
    }

    printf("Employee [ID: %d] fired.\n", curr->empId);

    //free the memory used by the employee that was fired
    for (int i=0; i<curr->numDependents; i++) {
      free(curr->dependents[i]);
    }
    free(curr->dependents);
    free(curr);
  }
}
