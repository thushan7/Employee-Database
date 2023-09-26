#include "../include/headerA3.h"

/*This function adds an employee to the linked list.
headLL contains the linked list.*/
void recruitEmployee(struct employee ** headLL) {
  a3Emp * newEmp; //new employee
  char ans; //whether the user wants to continue adding dependents
  char name[MAX_LENGTH]; //used to individually input name of each dependent
  int check; //0 if empId doesn't exist in linked list, 1 if it does
  a3Emp * temp; //used to traverse linked list to check if empId already exists

  newEmp = calloc(1, sizeof(a3Emp)); //allocate memory for new employee

  //----------first name
  printf("Enter the first name of the employee: ");
  scanf("%s", newEmp->fname);

  //----------last name
  printf("Enter the last name of the employee: ");
  scanf("%s", newEmp->lname);
  printf("\n");

  //----------dependents & numDependents
  newEmp->numDependents = 0;
  do {
    printf("Enter name of dependent #%d: ", newEmp->numDependents+1);
    scanf("%s", name);

    //dynamically allocate char* spaces based on number of dependents
    if (newEmp->numDependents==0) {
      newEmp->dependents = calloc(1, sizeof(char*));
    }
    else {
      newEmp->dependents = realloc(newEmp->dependents, sizeof(char*)*(newEmp->numDependents+1));
    }

    //dynamically allocate char spaces based on length of dependent's name
    newEmp->dependents[newEmp->numDependents] = calloc(strlen(name)+1, sizeof(char));

    strcpy(newEmp->dependents[newEmp->numDependents], name);

    newEmp->numDependents = newEmp->numDependents + 1;

    printf("Do you have any more dependents? ");
    scanf(" %c", &ans);
    printf("\n");
  } while (ans == 'y');

  printf("You have %d dependents.\n\n", newEmp->numDependents);

  //----------empId
  newEmp->empId = 0;
  for (int i=0; i<strlen(newEmp->fname); i++) { //sum of ascii values of characters in fname
    newEmp->empId = newEmp->empId + newEmp->fname[i];
  }
  newEmp->empId = newEmp->empId + strlen(newEmp->lname);

  //checks to see if empId already exists, continually changes it until it is unique
  do {
    check = 0;
    temp = *headLL;

    //traverse linked list, set check=1 if empId already exists
    while (temp != NULL) {
      if (temp->empId == newEmp->empId) {
        check = 1;
      }
      temp = temp->nextEmployee;
    }

    if (check == 1) {
      newEmp->empId = newEmp->empId + 1; //continually add 1 to empId until it is unique
    }
  } while (check == 1);

  printf("Your computer-generated empId is %d\n", newEmp->empId);

  //----------nextEmployee
  newEmp->nextEmployee = NULL;

  //now that newEmp has been fully initialized, let's add it to the end of the linked list
  if (*headLL == NULL) { //if the list is empty, the head points to newEmp
    *headLL = newEmp;
  }
  else { //otherwise, traverse to end of linked list and add newEmp there
    temp = *headLL;

    while (temp->nextEmployee != NULL) {
      temp = temp->nextEmployee;
    }

    temp->nextEmployee = newEmp;
  }
}
