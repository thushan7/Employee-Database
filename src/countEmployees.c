#include "../include/headerA3.h"

/*This function counts the number of employees in the linked list.
headLL contains the linked list.
Returns an int containing the number of employees in the linked list.*/
int countEmployees(a3Emp * headLL) {
  a3Emp * temp; //used to traverse linked list and count number of employees
  int num = 0; //number of employees

  if (headLL == NULL) { //let user know that list is empty if head doesn't point to anything
    printf("List is empty.\n");
  }
  else { //continue as normal otherwise
    temp = headLL;

    while (temp != NULL) { //counts employees
      num++;
      temp = temp->nextEmployee;
    }
  }

  return num;
}
