#include "../include/headerA3.h"

/*This function searches for an employee based on their full name.
headLL contains the linked list, whichName contains the name to search for.
Returns an int containing the position of the employee if found.*/
int lookOnFullName(struct employee * headLL, char whichName[100]) {
  a3Emp * temp; //used to traverse linked list and search for the employee
  int pos = -1; //position of the employee in the linked list
  int count = 0; //keeps track of which position in the linked list we are on while traversing
  char * userFname = strtok(whichName, " "); //gets first name from string
  char * userLname = strtok(NULL, " "); //gets last name from string
  char * empFname; //holds first name of each employee while traversing list
  char * empLname; //holds last name of each employee while traversing list

  //converts user-inputted first and last name to all lowercase to make comparisons easier
  for (int i=0; i<strlen(userFname); i++) {
    userFname[i] = tolower(userFname[i]);
  }
  for (int i=0; i<strlen(userLname); i++) {
    userLname[i] = tolower(userLname[i]);
  }

  if (headLL == NULL) { //let user know that list is empty if head doesn't point to anything
    printf("List is empty.\n");
  }
  else { //continue as normal otherwise
    temp = headLL;

    while ((temp != NULL) && (pos == -1)) { //traverse linked list until full name is found or end is reached
      count++;

      //we will create copies of each employee's first and last name so we can use tolower() on it without changing the linked list

      //allocate space for copies of employee's first and last name
      if (count == 1) {
        empFname = calloc(strlen(temp->fname)+1, sizeof(char));
	empLname = calloc(strlen(temp->lname)+1, sizeof(char));
      }
      else {
	empFname = realloc(empFname, (strlen(temp->fname)+1)*sizeof(char));
	empLname = realloc(empLname, (strlen(temp->lname)+1)*sizeof(char));
      }

      //copy employee's first and last names into the duplicate strings
      strcpy(empFname, temp->fname);
      strcpy(empLname, temp->lname);

      //convert each employee's first and last name to all lowercase to make comparisons easier
      for (int i=0; i<strlen(empFname); i++) {
	empFname[i] = tolower(empFname[i]);
      }
      for (int i=0; i<strlen(empLname); i++) {
	empLname[i] = tolower(empLname[i]);
      }

      //compare full names and initialize pos once full name is found
      if ((strcmp(userFname, empFname)==0) && (strcmp(userLname, empLname)==0)) { //compares first and last names
	pos = count;
      }

      temp = temp->nextEmployee;
    }
  }

  //freeing memory
  free(empFname);
  free(empLname);

  return pos;
}
