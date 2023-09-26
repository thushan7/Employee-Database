#include "../include/headerA3.h"

/*This function searches for an employee based on their empId.
headLL contains the linked list, whichEmpId is the empId to search for.
Returns an int containing the position of the employee if found.*/
int lookOnId(struct employee * headLL, int whichEmpId) {
  a3Emp * temp; //used to traverse linked list and search for the employee
  int pos = -1; //position of the employee in the linked list
  int count = 0; //keeps track of which position in the linked list we are on while traversing

  if (headLL == NULL) { //let user know that list is empty if head doesn't point to anything
    printf("List is empty.\n");
  }
  else { //continue as normal otherwise
    temp = headLL;

    while ((temp != NULL) && (pos == -1)) { //traverse linked list until empId is found or end is reached
      count++;

      if (temp->empId == whichEmpId) { //initialize pos once empId is found
        pos = count;
      }

      temp = temp->nextEmployee;
    }
  }

  return pos;
}
