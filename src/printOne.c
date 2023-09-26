#include "../include/headerA3.h"

/*This function prints the data of a chosen employee in the linked list.
headLL contains the linked list, whichOne is the position of the employee whose data is to be printed.*/
void printOne(struct employee * headLL, int whichOne) {
  a3Emp * temp; //used to traverse linked list and find employee data to be printed
  int num = 0; //number of employees, makes sure that whichOne is a valid user request

  if (headLL == NULL) { //lets user know that list is empty if head doesn't point to anything
    printf("List is empty.\n");
  }
  else { //continue as normal otherwise

    //first, let's check that whichOne is valid
    temp = headLL;

    while (temp != NULL) { //here we are counting the number of employees to make sure whichOne isn't higher than the number of employees
      num++;
      temp = temp->nextEmployee;
    }

    if (whichOne<1 || whichOne>num) { //print error message if whichOne is less than 1 or greater than number of employees
      printf("Invalid position entered.\n");
    }
    else { //if whichOne is valid, let's search for and print the employee data
      temp = headLL;

      for (int i=1; i<whichOne; i++) { //traverses linked list to the specified employee
	temp = temp->nextEmployee;
      }

      //prints employee data
      printf("Employee ID: %d\n", temp->empId);
      printf("First Name: %s\n", temp->fname);
      printf("Last Name: %s\n", temp->lname);
      printf("Dependents [%d]:", temp->numDependents);
      for (int i=0; i<temp->numDependents; i++) {
	printf(" %s", temp->dependents[i]);
	if (i != temp->numDependents-1) {
	  printf(",");
	}
      }
      printf("\n");
    }
  }
}
