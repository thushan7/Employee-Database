#include "../include/headerA3.h"

/*This function sorts the employees in the linked list based on their empIds.
headLL contains the linked list.*/
void sortEmployeesId(struct employee * headLL) {
  //Bubble Sort
  //since list is not passed by reference, we cannot swap nodes and must swap data within nodes

  a3Emp * temp; //used to traverse list and sort employees
  int swaps = -1; //number of swaps made in each pass
  int num = countEmployees(headLL); //number of nodes in linked list
  char tempName[MAX_LENGTH]; //used to swap first and last names
  int tempId; //used to swap empIds
  int tempNum; //used to swap numDependents
  char ** tempDependents; //used to swap dependents

	
  if (num > 1) {
    //if num == 0, countEmployees already outputs that list is empty and we return from function
    //if num == 1, no need to sort the list and we return from function

    while (swaps != 0) { //keep making passes until no swaps are made
      temp = headLL;
      swaps = 0;

      while (temp->nextEmployee != NULL) {
	if (temp->empId > temp->nextEmployee->empId) {

	  //swap first names
	  strcpy(tempName, temp->fname);
	  strcpy(temp->fname, temp->nextEmployee->fname);
	  strcpy(temp->nextEmployee->fname, tempName);

	  //swap last names
	  strcpy(tempName, temp->lname);
	  strcpy(temp->lname, temp->nextEmployee->lname);
	  strcpy(temp->nextEmployee->lname, tempName);

	  //swap empIds
	  tempId = temp->empId;
	  temp->empId = temp->nextEmployee->empId;
	  temp->nextEmployee->empId = tempId;

	  //swap numDependents
	  tempNum = temp->numDependents;
	  temp->numDependents = temp->nextEmployee->numDependents;
	  temp->nextEmployee->numDependents = tempNum;

	  //swap dependents
	  tempDependents = temp->dependents;
	  temp->dependents = temp->nextEmployee->dependents;
	  temp->nextEmployee->dependents = tempDependents;

	  //no need to swap nextEmployee pointers since the data is being swapped accordingly

	  swaps++;
        }

	temp = temp->nextEmployee;
      }
    }
  }
}
