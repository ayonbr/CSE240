// CSE240 Fall 2019 HW 7 & 8
// Brian Ayon
// Write the compiler used: gcc

// READ BEFORE YOU START:
// You are given a partially completed program that creates a linked list of employee information.
// The global linked list 'list' is a list of employees with each node being struct 'employeeList'.
// 'employeeList' consists of struct 'employee' which has: employee name, room number, and a linked list of 'supervisors'.
// The linked list of supervisors has each node containing simply the name of the supervisor.
// HW7 ignores the 'supervisors' linked list since there is no operation/manipulation to be done on 'supervisors' list in HW7.
// HW8 has operations/manipulations to be done with 'supervisors' list like add a supervisor, display last added supervisor.

// To begin, you should trace through the given code and understand how it works.
// Please read the instructions above each required function and follow the directions carefully.
// If you modify any of the given code, the return types, or the parameters, you risk getting compile error.
// You are not allowed to modify main ().
// You can use string library functions.

// ***** WRITE COMMENTS FOR IMPORANT STEPS OF YOUR CODE. *****
// ***** GIVE MEANINGFUL NAMES TO VARIABLES. *****
// ***** Before implementing any function, see how it is called in executeAction() *****


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable: 4996) // for Visual Studio

#define MAX_NAME 30

// global linked list 'list' contains the list of employees
struct employeeList {
    struct employee* employee;
    struct employeeList* next;
} *list = NULL;				// currently empty list

// structure "employee" contains the employee's name, room number and linked list of supervisors
struct employee {
    char name[MAX_NAME];
    unsigned int roomNumber;
    struct supervisor* supervisors;		// linked list 'supervisors' contains names of supervisors
};

//  structure 'supervisor' contains supervisor's name
struct supervisor {
    char name[MAX_NAME];
    struct supervisor* next;
};

// forward declaration of functions (already implemented)
void flushStdIn();
void executeAction(char);

// functions that need implementation:
// HW 7
void addEmployee(char* employeeNameInput, unsigned int roomNumInput); // 20 points
void displayEmployeeList(struct employeeList* tempList);	      // 15 points
struct employee* searchEmployee(char* employeeNameInput);	      // 15 points
//HW 8
void addSupervisor(char* employeeNameInput, char* supervisorNameInput);	// 15 points
char* lastSupervisor(char* employeeNameInput);				// 15 points
void removeEmployee(char* employeeNameInput);			        // 20 points

int main()
{
    char selection = 'a';		// initialized to a dummy value
    do
    {
        printf("\nCSE240 HW 7,8\n");
        printf("Please enter your selection:\n");
        printf("HW7:\n");
        printf("\t a: add a new employee to the list\n");
        printf("\t d: display employee list (no supervisors)\n");
        printf("\t b: search for an employee on the list\n");
        printf("\t q: quit\n");
        printf("HW8:\n");
        printf("\t c: add a supervisor of a employee\n");
        printf("\t l: display last added supervisor of a employee\n");
        printf("\t r: remove a employee\n");
        printf("\t q: quit\n");

        selection = getchar();
        flushStdIn();
        executeAction(selection);
    } while (selection != 'q');

    return 0;
}

// flush out leftover '\n' characters
void flushStdIn()
{
    char c;
    do c = getchar();
    while (c != '\n' && c != EOF);
}

// Ask for details from user for the given selection and perform that action
// Read the function case by case
void executeAction(char c)
{
    char employeeNameInput[MAX_NAME], supervisorNameInput[MAX_NAME];
    unsigned int roomNumInput;
    struct employee* searchResult = NULL;

    switch (c)
    {
        case 'a':	// add employee
            // input employee details from user
            printf("\nPlease enter employee's name: ");
            fgets(employeeNameInput, sizeof(employeeNameInput), stdin);
            employeeNameInput[strlen(employeeNameInput) - 1] = '\0';	// discard the trailing '\n' char
            printf("Please enter room number: ");
            scanf("%d", &roomNumInput);
            flushStdIn();

            //if (searchEmployee(employeeNameInput) == NULL)	// un-comment this line after implementing searchEmployee()
            if (1)									// comment out this line after implementing searchEmployee()
            {
                addEmployee(employeeNameInput, roomNumInput);
                printf("\nEmployee successfully added to the list!\n");
            }
            else
                printf("\nThat employee is already on the list!\n");
            break;

        case 'd':		// display the list
            displayEmployeeList(list);
            break;

        case 'b':		// search for an employee on the list
            printf("\nPlease enter employee's name: ");
            fgets(employeeNameInput, sizeof(employeeNameInput), stdin);
            employeeNameInput[strlen(employeeNameInput) - 1] = '\0';	// discard the trailing '\n' char

            if (searchEmployee(employeeNameInput) == NULL)	// un-comment this line after implementing searchEmployee()
                //if (0)									// comment out this line after implementing searchEmployee()
                printf("\nEmployee name does not exist or the list is empty! \n\n");
            else
            {
                printf("\nEmployee name exists on the list! \n\n");
            }
            break;

        case 'r':		// remove employee
            printf("\nPlease enter employee's name: ");
            fgets(employeeNameInput, sizeof(employeeNameInput), stdin);
            employeeNameInput[strlen(employeeNameInput) - 1] = '\0';	// discard the trailing '\n' char

            //if (searchEmployee(employeeNameInput) == NULL)	// un-comment this line after implementing searchEmployee()
            if (0)									// comment out this line after implementing searchEmployee()
                printf("\nEmployee name does not exist or the list is empty! \n\n");
            else
            {
                removeEmployee(employeeNameInput);
                printf("\nEmployee successfully removed from the list! \n\n");
            }
            break;

        case 'c':		// add supervisor
            printf("\nPlease enter employee's name: ");
            fgets(employeeNameInput, sizeof(employeeNameInput), stdin);
            employeeNameInput[strlen(employeeNameInput) - 1] = '\0';	// discard the trailing '\n' char

            if (searchEmployee(employeeNameInput) == NULL)	// un-comment this line after implementing searchEmployee()
                //if (0)										// comment out this line after implementing searchEmployee()
                printf("\nEmployee name does not exist or the list is empty! \n\n");
            else
            {
                printf("\nPlease enter supervisor's name: ");
                fgets(supervisorNameInput, sizeof(supervisorNameInput), stdin);
                supervisorNameInput[strlen(supervisorNameInput) - 1] = '\0';	// discard the trailing '\n' char

                addSupervisor(employeeNameInput, supervisorNameInput);
                printf("\nSupervisor added! \n\n");
            }
            break;

        case 'l':		// last supervisor
            printf("\nPlease enter employee's name: ");
            fgets(employeeNameInput, sizeof(employeeNameInput), stdin);
            employeeNameInput[strlen(employeeNameInput) - 1] = '\0';	// discard the trailing '\n' char

            //if (searchEmployee(employeeNameInput) == NULL)	// un-comment this line after implementing searchEmployee()
            if (0)										// comment out this line after implementing searchEmployee()
                printf("\nEmployee name does not exist or the list is empty! \n\n");
            else
            {
                printf("\nLast supervisor added: %s\n\n", lastSupervisor(employeeNameInput));
            }
            break;

        case 'q':		// quit
            break;

        default: printf("%c is invalid input!\n", c);
    }
}

// HW7 Q1: addEmployee (20 points)
// This function is used to insert a new employee in the linked list.
// You must insert the new employee to the head of linked list 'list'.
// You need NOT check if the employee already exists in the list because that is taken care by searchEmployee() called in executeAction(). Look at how this function is used in executeAction().
// Don't bother to check how to implement searchEmployee() while implementing this function. Simply assume that employee does not exist in the list while implementing this function.
// NOTE: The function needs to add the employee to the head of the list.
// NOTE: This function does not add supervisors to the employee info. There is another function addSupervisor() in HW8 for that.
// Hint: In this question, no supervisors means NULL supervisors.

void addEmployee(char* employeeNameInput, unsigned int roomNumInput)
{
    //allocating memory
    struct employeeList* tempList = (struct employeeList*)malloc(sizeof(struct employeeList));
    struct employee* newNode = (struct employee*)malloc(sizeof(struct employee));


    //insert data of employee to the node
    strcpy(newNode->name, employeeNameInput);
    newNode->roomNumber = roomNumInput;
    newNode->supervisors = NULL;

    //setting current employee node to newNode
    tempList->employee = newNode;

    //make new position at head
    tempList->next = list;

    //make head point to current node
    list = tempList;


}

// HW7 Q2: displayEmployeeList (15 points)
// This function displays the employee details (struct elements) of each employee.
// Parse through the linked list 'list' and print the employee details ( name and room number) one after the other. See expected output screenshots in homework question file.
// You should not display supervisor names (because they are not added in HW7).
// You MUST use recursion in the function to get full points. Notice that 'list' is passed to the function argument. Use recursion to keep calling this function till end of list.

void displayEmployeeList(struct employeeList* tempList)
{

    //empty list
    if(tempList == NULL)
    {
        printf("List is empty\n");
        return;
    }
    //printing employee data
    printf("Employee Name: %s\n", tempList->employee->name);
    printf("Room Number: %d\n", tempList->employee->roomNumber);
    printf("\n");

    //case for when list reaches the end
    if(tempList->next == NULL)
    {
        return;
    }
    //recursive call of displayEmployeeList function with the argument being the next element in the list
    displayEmployeeList(tempList->next);
}

// HW7 Q3: searchEmployee (15 points)
// This function searches the 'list' to check if the given employee exists in the list. Search by employee name.
// If it exists then return that 'employee' node of the list. Notice the return type of this function.
// If the employee does not exist in the list, then return NULL.
// NOTE: After implementing this fucntion, go to executeAction() to comment and un-comment the lines mentioned there which use searchEmployee()
//       in case 'a', case 'r', case 'l' (total 3 places)
struct employee* searchEmployee(char* employeeNameInput)
{
    //setting current position to head
    struct employeeList* currentPosition = list;
    //traverse through list
    while(currentPosition!= NULL)
    {
        //return the employee node at the position if found
        if(strcmp(employeeNameInput, currentPosition->employee->name) == 0)
        {
            return currentPosition->employee;
        }
        //move current position forward
        currentPosition = currentPosition->next;
    }

    return NULL;	// edit this line as needed
}



// HW8 Q1: addSupervisor (15 points)
// This function adds supervisor's name to a employee node.
// Parse the list to locate the employee and add the supervisor to that employee's 'supervisors' linked list. No need to check if the employee name exists on the list. That is done in executeAction().
// If the 'supervisors' list is empty, then add the supervisor. If the employee has existing supervisors, then you may add the new supervisor to the head or the tail of the 'supervisors' list.
// You can assume that the same supervisor name does not exist. So no need to check for existing supervisor names, like we do when we add new employee.
// NOTE: Make note of whether you add the supervisor to the head or tail of 'supervisors' list. You will need that info when you implement lastSupervisor()
//       (Sample solution has supervisor added to the tail of 'supervisors' list. You are free to add new supervisor to head or tail of 'supervisors' list.)

void addSupervisor(char* employeeNameInput, char* supervisorNameInput)
{

    struct employeeList* tempList = list;		// work on a copy of 'list'

    //allocating memory
    struct supervisor* current = (struct supervisor*)malloc(sizeof(struct supervisor));
    //add supervisor name given user input
    strcpy(current->name, supervisorNameInput);

    //setting next supervisor to be null in order to only have one
    current->next = NULL;
    //setting position to employee searched for
    tempList->employee = searchEmployee(employeeNameInput);

    //created in order to traverse supervisor list
    struct supervisor* otherList = tempList->employee->supervisors;
    struct supervisor* temp = otherList;

    //if supervisor of employee node is empty
    if(otherList == NULL)
    {
        //sets supervisor pointers to null if there is no supervisors
        otherList = current;
        temp = current;
    }
    else{
        //traverse through supervisors
        while(temp->next != NULL)
        {
            //traverses in order to get value of most recently added supervisor
            temp = temp->next;
        }
        //sets the most recent value of supervisor found to current
        temp->next = current;
        //adjust position
        temp = temp->next;

    }
    //finally adding the value of supervisor to the position of the employee node in the employeeList
    tempList->employee->supervisors = otherList;

}


// HW8 Q2: lastSupervisor (15 points)
// This function returns the name of the last (most recently) added supervisor of a employee.
// Parse the list to locate the employee. No need to check if the employee name exists in the list. That is done in executeAction().
// Then parse the supervisor names to return the most recently added supervisor.
// NOTE: Last supervisor does not necessarily mean the tail of 'supervisors' list. It means the most recently added supervisor.
//       If you are adding supervisor to the head of the list in addSupervisor(), then you should return that supervisor accordingly.

char* lastSupervisor(char* employeeNameInput)
{

    struct employeeList* tempList = list;		// work on a copy of 'list'
    // enter code here
    struct employee* employee;
    //setting current node of list to the node of employee found
    tempList = searchEmployee(employeeNameInput);
    //setting employee node created to that of tempList found
    employee = tempList;

    //if no supervisor
    if(employee->supervisors == NULL)
    {
        return NULL;
    } else{

        while(employee->supervisors->next != NULL)
        {
            //setting supervisor to most recent supervisor
            employee->supervisors = employee->supervisors->next;
        }
        return employee->supervisors->name;
    }

    return NULL;		// edit this line as needed
}

// HW8 Q3: removeEmployee (20 points)
// This function removes an employee from the list.
// Parse the list to locate the employee and delete that 'employee' node.
// You need not check if the employee exists because that is done in executeAction()
//removeEmployee() is supposed to remove employee details like name and room number.
// The function will remove supervisors of the employee too.
// When the employee is located in the 'list', after removing the employee name and room number, parse the 'supervisors' list of that employee
// and remove the supervisors.

void removeEmployee(char* employeeNameInput)
{

    struct employeeList* tempList = list;	// work on a copy of 'list'
    struct employeeList* prev = NULL;
    struct supervisor* tempSupervisor;

        //if first element of list matches employee name
        if(strcmp(tempList->employee->name, employeeNameInput) == 0)
        {
            //removing supervisor of employee node for as long as the employee node does contain a supervisor
            while(list->employee->supervisors != NULL)
            {
                //moving over in order to free the supervisor
                tempSupervisor = list->employee->supervisors;
                list->employee->supervisors = list->employee->supervisors->next;
                free(tempSupervisor);
            }
            //after removing supervisor, the rest of the employee node itself is removed
            list = list->next;
            free(tempList->employee);
            free(tempList);
        }

        else{
            //starting at next element after first element wasn't the one looked for
            tempList = list->next;
            //while next element from beginning has not been removed
            while(prev->next != NULL)
            {
                //if element matches user input
                if(strcmp(tempList->employee->name, employeeNameInput) == 0)
                {
                    //removing supervisor of employee node for as long as the employee node does contain a supervisor
                    while(tempList->employee->supervisors != NULL)
                    {
                        //moving over in over to free the supervisor
                        tempSupervisor = tempList->employee->supervisors;
                        tempList->employee->supervisors = tempList->employee->supervisors->next;
                        free(tempSupervisor);
                    }
                    //removing the rest of the employee node
                    prev->next = tempList->next;
                    free(tempList->employee);
                    free(tempList);
                    break;

                }
                //adjusting positions forward after having removed employee node
                prev = tempList;
                tempList = tempList->next;
            }

        }

}
