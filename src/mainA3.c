#include "../include/headerA3.h"

/*Assignment 3: proFile
This menu-driven program performs a variety of functions on linked lists.*/
int main(int argc, char * argv[]) {
  a3Emp * head = NULL; //head of linked list
  int option; //user's chosen menu option
  int pos; //user-inputted position for printOne, fireOne, lookOnId, and lookOnFullName
  int id; //user-inputted empId for lookOnId
  char name[100]; //user-inputted name for lookOnFullName
  int num; //number of employees for countEmployees
  char ans; //user-inputted answer for fireAll
  a3Emp * temp; //used to free memory at end of program

  loadEmpData(&head, "proFile.txt"); //loads employee data from text file to linked list

  do {
    printf("--------------------------------------------------\n");

    //print menu
    printf("1. Add a new employee\n");
    printf("2. Print data of all employees\n");
    printf("3. Print data of the nth employee\n");
    printf("4. Search for employee based on empId\n");
    printf("5. Search for employee based on full name\n");
    printf("6. Count the total number of employees\n");
    printf("7. Sort the employees based on their empId\n");
    printf("8. Remove the nth employee in the current LL\n");
    printf("9. Remove all employees in the current LL\n");
    printf("10. Exit\n\n");

    //get user's menu option
    printf("Choose a menu option: ");
    scanf("%d", &option);
    getchar(); //catches "enter" key from input to prevent issues with fgets later on
    printf("\n\n");

    //perform task according to user's menu pick
    switch (option) {
      case 1: //add employee
	recruitEmployee(&head);
	break;

      case 2: //print all employees
	printAll(head);
	break;

      case 3: //print one employee
	num = countEmployees(head);
	if (num != 0) { //only continue if list isn't empty, error message printed otherwise
	  printf("Enter a position: ");
	  scanf("%d", &pos);
	  printf("\n\n");
	  printOne(head, pos);
	}
	break;

      case 4: //search using empId
	num = countEmployees(head);
	if (num != 0) { //countEmployees tells user that list is empty when num = 0
	  printf("Enter an employee ID: ");
	  scanf("%d", &id);
	  printf("\n\n");
	  pos = lookOnId(head, id);
	  if (pos != -1) { //if employee is found, print their data
	    printOne(head, pos);
	  }
	  else { //if employee is not found, print message to user
	    printf("No employee with this ID exists.\n");
	  }
	}
	break;

      case 5: //search using full name
	num = countEmployees(head);
	if (num != 0) { //countEmployees tells user that list is empty when num = 0
	  printf("Enter the full name of the employee: ");
	  fgets(name, 100, stdin);
	  name[strlen(name)-1] = '\0';
	  printf("\n\n");
	  pos = lookOnFullName(head, name);
	  if (pos != -1) { //if employee is found, print their data
	    printOne(head, pos);
	  }
	  else { //if employee is not found, print message to user
	    printf("No employee with this name exists.\n");
	  }
	}
	break;

      case 6: //count employees
	num = countEmployees(head);
	if (num != 0) { //countEmployees tells user that list is empty when num = 0
	  printf("Total number of employees = %d\n", num);
	}
	break;

      case 7: //sort employees
	num = countEmployees(head);
	if (num != 0) { //only continue if list isn't empty, error message printed otherwise
	  sortEmployeesId(head);
	  printf("After sorting on empId, the employees are as follows:\n\n");
	  printAll(head);
	}
	break;

      case 8: //fire one employee
	num = countEmployees(head);
	if (num != 0) { //countEmployees tells user that list is empty when num = 0
	  printf("Currently there are %d employees.\n", num);

	  //continually prompt user until they enter a valid value
	  do {
	    printf("Which employee do you wish to fire - enter a value between 1 and %d: ", num);
	    scanf("%d", &pos);
	  } while (pos<1 || pos>num);

	  fireOne(&head, pos);

	  printf("There are now %d employees.\n", num-1);
	}
	break;

      case 9: //fire all employees
	num = countEmployees(head);
	if (num != 0) { //only continue if list isn't empty, error message printed otherwise
	  printf("Are you sure you want to fire everyone: ");
	  scanf(" %c", &ans);

	  if (ans == 'y' || ans == 'Y') { //fire all if user is sure, otherwise return to menu
	    fireAll(&head);
	    printf("All fired. Linked list is now empty.\n");
	  }
	}
	break;
    }
  } while (option>0 && option<10); //keep asking user for menu option until they exit or enter an invalid option

  //free memory at end of program
  while (head!=NULL) {
    temp = head;
    head = temp->nextEmployee;

    for (int i=0; i<temp->numDependents; i++) {
      free(temp->dependents[i]);
    }
    free(temp->dependents);
    free(temp);
  }

  return 0;
}
