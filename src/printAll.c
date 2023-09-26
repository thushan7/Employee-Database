#include "../include/headerA3.h"

/*This function prints the data of all employees in the linked list.
headLL contains the linked list.*/
void printAll(struct employee * headLL) {
  a3Emp * temp; //used to traverse linked list and print data of all employees
  int count = 0; //keeps track of which employee is being printed and holds number of employees at end

  if (headLL == NULL) { //let user know that list is empty if head doesn't point to anything
    printf("List is empty.\n");
  }
  else { //print all employee data otherwise
    temp = headLL;

    while (temp != NULL) {
      printf("Employee #%d\n", count+1);

      printf("\tEmployee ID: %d\n", temp->empId);

      printf("\tFirst Name: %s\n", temp->fname);

      printf("\tLast Name: %s\n", temp->lname);

      printf("\tDependents [%d]:", temp->numDependents);
      for (int i=0; i<temp->numDependents; i++) {
	printf(" %s", temp->dependents[i]);
	if (i != temp->numDependents-1) {
	  printf(",");
	}
      }
      printf("\n\n");

      temp = temp->nextEmployee;
      count++;
    }

    printf("Currently, there are %d employees.\n", count);
  }
}
