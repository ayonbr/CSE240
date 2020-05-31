
// CSE240 Fall 2019 HW6

// Write the compiler used: gcc

// READ BEFORE YOU START:
// You are given a partially completed program that creates a linked list of employee records.
// Each record(struct) has this information: employee's name, supervisor's name, department of the employee, room number.
// The struct 'employeeRecord' holds information of one employee. Department is enum type.
// A linked list called 'list' is made to hold the list of employees.
// To begin, you should trace through the given code and understand how it works.
// Please read the instructions above each required function and follow the directions carefully.
// You should not modify any of the given code, the return types, or the parameters, you risk getting compile error.
// You are not allowed to modify main ().
// You can use string library functions.
// ***** WRITE COMMENTS FOR IMPORANT STEPS OF YOUR CODE. 10% deduction for not using comments *****
// ***** GIVE MEANINGFUL NAMES TO VARIABLES. *****


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable: 4996) // for Visual Studio Only

#define MAX_NAME_LENGTH 25

typedef enum { HR = 0, Marketing, IT } departmentType; // enum type 

struct employeeRecord {
	char employeeName[MAX_NAME_LENGTH];
	char supervisorName[MAX_NAME_LENGTH];
	departmentType department;
	unsigned int roomNumber;
	struct employeeRecord* next;	// pointer to next node
} *list = NULL;					// Declare linked list 'list'

// forward declaration of functions (already implemented)
void flushStdIn();
void executeAction(char);

// functions that need implementation:
int add(char* employeeName_input, char* supervisorName_input, char* department_input, unsigned int roomNumber_input); // 10 points
void displayList();						// 10 points
int countNodes();						// 5 points
int deleteNode(char* employeeName_input);	// 10 points
void swapNodes(struct employeeRecord* node1, struct employeeRecord* node2);	// 5 points
void sortList();						// 10 points


int main()
{	
	char selection = 'i';		// initialized to a dummy value
	printf("\nCSE240 HW6\n");
	do
	{
		printf("\nCurrently %d employee(s) on the list.", countNodes());	// NOTE: countNodes() called here
		printf("\nEnter your selection:\n");
		printf("\t a: add a new employee\n");
		printf("\t d: display employee list\n");
		printf("\t r: remove a employee from the list\n");
		printf("\t s: sort employee list by supervisor's name in descending order\n");
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
// Read the code in the function, case by case
void executeAction(char c)
{
	char employeeName_input[MAX_NAME_LENGTH], supervisorName_input[MAX_NAME_LENGTH];
	unsigned int roomNumber_input, result = 0;
	char department_input[20];
	switch (c)
	{
	case 'a':	// add employee
		// input employee details from user
		printf("\nEnter employee name: ");
		fgets(employeeName_input, sizeof(employeeName_input), stdin);
		employeeName_input[strlen(employeeName_input) - 1] = '\0';	// discard the trailing '\n' char
		printf("Enter supervisor name: ");
		fgets(supervisorName_input, sizeof(supervisorName_input), stdin);
		supervisorName_input[strlen(supervisorName_input) - 1] = '\0';	// discard the trailing '\n' char

		printf("Enter whether employee is in 'HR' or 'Marketing' or 'IT': ");
		fgets(department_input, sizeof(department_input), stdin);
		department_input[strlen(department_input) - 1] = '\0';	// discard the trailing '\n' char
		printf("Please enter room number: ");
		scanf("%d", &roomNumber_input);
		flushStdIn();

		// add the employee to the list
		result = add(employeeName_input, supervisorName_input, department_input, roomNumber_input);
		if (result == 0)
			printf("\nEmployee is already on the list! \n\n");
		else if (result == 1)
			printf("\nEmployee successfully added to the list! \n\n");
		
		break;

	case 'd':		// display the list
		displayList();
		break;

	case 'r':		// remove a employee
		printf("\nPlease enter employee name: ");
		fgets(employeeName_input, sizeof(employeeName_input), stdin);
		employeeName_input[strlen(employeeName_input) - 1] = '\0';	// discard the trailing '\n' char

		// delete the node
		result = deleteNode(employeeName_input);
		if (result == 0)
			printf("\nEmployee does not exist! \n\n");
		else if (result == 1)
			printf("\nEmployee successfully removed from the list. \n\n");
		else
			printf("\nList is empty! \n\n");
		break;

	case 's':		// sort the list
		sortList();
		break;

	case 'q':		// quit
		break;
	default: printf("%c is invalid input!\n",c);
	}
}

// Q1 : add (10 points)
// This function is used to insert a new employee into the list. You can insert the new employee to the end of the linked list.
// Do not allow the employee to be added to the list if that employee already exists in the list. You can do that by checking the names of the employees already in the list.
// If the employee already exists then return 0 without adding employee to the list. If the employee does not exist in the list then go on to add the employee at the end of the list and return 1.
// NOTE: You must convert the string 'department_input' to an enum type and store it in the list because the struct has enum type for department.

int add(char* employeeName_input, char* supervisorName_input, char* department_input, unsigned int roomNumber_input) // 20 points
{

	struct employeeRecord* tempList = list; // work on a copy of list
    
	if(tempList == NULL)
    {

	    //allocating enough space for new node that will be added to list
	    tempList = (struct employeeRecord*)malloc(sizeof(struct employeeRecord));

        //adding user-inputted parameters to node
	    strcpy(tempList->employeeName, employeeName_input);
        strcpy(tempList->supervisorName, supervisorName_input);

        //converting string department_input to enum type
        if(strcmp(department_input, "HR") == 0)
        {
            tempList->department = HR;
        }
        else if(strcmp(department_input, "Marketing") == 0)
        {
            tempList->department = Marketing;
        }
        else{
            tempList->department = IT;
        }

        tempList->roomNumber = roomNumber_input;

        //inserting node at end position
        tempList->next = list;
        list = tempList;
        return 1;
    }
	else{
	    //traversing tempList if it not already NULL
	    while (tempList != NULL)
        {
            //check if for any element, the employee already exists
	        if(strcmp(tempList->employeeName, employeeName_input) == 0)
            {
                return 0; //if employee already exists
            }
	        tempList = tempList->next;
        }
	    //tempList = list;

        //allocating enough space for new node that will be added to list
        tempList = (struct employeeRecord*)malloc(sizeof(struct employeeRecord));


        //adding user-inputted parameters to node
        strcpy(tempList->employeeName, employeeName_input);
        strcpy(tempList->supervisorName, supervisorName_input);

        //converting string_department string to enum type
        if(strcmp(department_input, "HR") == 0)
        {
            tempList->department = HR;
        }
        else if(strcmp(department_input, "Marketing") == 0)
        {
            tempList->department = Marketing;
        }
        else{
            tempList->department = IT;
        }
        tempList->roomNumber = roomNumber_input;

        //inserting node at end position
        tempList->next = list;
        list = tempList;


        return 1; //edit this line as needed
	}

}

// Q2 : displayList (10 points)
// This function displays the linked list of employees, with all details (struct elements). 
// Parse through the linked list and print the employee details one after the other. See expected output screenshots in homework question file.
// NOTE: Department is stored in the struct as enum type. You need to display a string for department.
void displayList()
{

    struct employeeRecord* tempList = list; // work on a copy of list


    //list is empty
    if(tempList == NULL)
    {
        printf("List is empty\n");
    }
    else
    {

        //traverse through list and printing values of employee details
        while(tempList != NULL)
        {
            printf("Employee name: %s\n", tempList->employeeName);
            printf("Supervisor name: %s\n", tempList->supervisorName);

            //converting enum type to string
            if (tempList->department == 0) {
                printf("Department: %s\n", "HR");
            } else if (tempList->department == 1) {
                printf("Department: %s\n", "Marketing");
            } else {
                printf("Department: %s\n", "IT");
            }
            printf("Room number: %d\n", tempList->roomNumber);
            printf("\n");

            //increment position of tempList
            tempList = tempList->next;
        }
    }

}

// Q3: countNodes (5 points)
// This function counts the number of employees on the linked list and returns the number.
// You may use this function in other functions like deleteNode(), sortList(), addNode(), if needed. 
// It can helpful to call this function in other functions, but not necessary.
// This function is called in main() to display number of employees along with the user menu.
int countNodes()
{
    struct employeeRecord* tempList = list;
    int count = 0;

    //traverse and increment value of count for every node
    while(tempList != NULL)
    {
        count++;
        tempList = tempList->next;
    }

	return count;	// edit this line as needed
}

// Q4 : deleteNode (10 points)
// This function deletes the node specified by the employee name.
// Parse through the linked list and remove the node containing this employee name.
// NOTE: After you remove the node, make sure that your linked list is not broken.
// (Hint: Visualize the list as: list......-> node1 -> node_to_remove -> node2 -> ...end. 
//        After removing "node_to_remove", the list is broken into "list ....node1" and "node2.... end". Stitch these lists.)

int deleteNode(char* employeeName_input)
{

    struct employeeRecord* tempList = list->next;		// work on a copy of 'list'
	struct employeeRecord* previous = NULL;

	//list is empty
	if(list == NULL)
    {
	    printf("The list is empty.");
    }


	//traverse through list
    while (tempList != NULL) {
        //finds the node that user is attempting to delete
        if (strcmp(tempList->employeeName, employeeName_input) == 0) {

            //transferring data over in order to free the tempList node that was chosen to be deleted
            if (previous == NULL) {
                tempList = list;
                list = list->next;
            }
            else {
                tempList = previous->next;
                previous->next = tempList->next;
            }

            free(tempList);//garbage collection
            return 1;
        }
        //readjusting positions after deleting chosen node
        previous = tempList;
        tempList = tempList->next;
    }

    return 0; //edit this line as needed

}


// Q5 : swapNodes (5 points)
// This function swaps the elements of parameters 'node1' and 'node2' (Here node1 does NOT mean 1st node of the list. 'node1' is just the name of the node)
// This function should not alter the 'next' element of the nodes. Only then will the nodes be swapped.
// Hint: The swap logic is similar to swapping two simple integer/string variables.
// NOTE: This function can be used in the sorting logic in sortList()

void swapNodes(struct employeeRecord* node1, struct employeeRecord* node2){

    struct employeeRecord* tempList;
    //allocating enough space for node
	tempList = (struct employeeRecord*)malloc(sizeof(struct employeeRecord));

	//used to keep string array of department type
    char tempDep[20];


    //converting enum type to String type
    if (tempList->department == 0) {
        strcpy(tempDep, "HR");
    } else if (tempList->department == 1) {
        strcpy(tempDep, "MARKETING");
    } else {
        strcpy(tempDep, "IT");
    }

    //transferring node1 data onto tempList
	strcpy(tempList->employeeName, node1->employeeName);
    strcpy(tempList->supervisorName, node1->supervisorName);
    //tempList->department = node1->department;
    strcpy(tempList,tempDep);
    tempList->roomNumber = node1->roomNumber;

    //transferring node2 data onto node1
    strcpy(node1->employeeName, node2->employeeName);
    strcpy(node1->supervisorName, node2->supervisorName);
    //node1->department = node2->department;
    strcpy(node1,tempDep);
    node1->roomNumber = node2->roomNumber;

    //transferring tempList data onto node2 to complete swap
    strcpy(node2->employeeName, tempList->employeeName);
    strcpy(node2->supervisorName, tempList->supervisorName);
    //node2->department = tempList->department;
    strcpy(node2,tempDep);
    node2->roomNumber = tempList->roomNumber;


}


// Q6 : sortList (10 points)
// This function sorts the linked list by alphabetical order of employee name.
// Parse the list and compare the employee names to check which one should appear before the other in the list.
// Sorting should happen within the list. That is, you should not create a new linked list of employees having sorted employees.
// Hint: One of the string library function can be useful to implement this function because the sorting needs to happen by employee name which is a string.
//       Use swapNodes() to swap the nodes in the sorting logic

void sortList()
{

     struct employeeRecord* tempList = list;				// work on a copy of 'list'
	// enter code here
	//next value in which to compare current to
    struct employeeRecord* node = tempList->next;

	//using previous function to get count of nodes
    int count = countNodes();


    //if 0 or 1 nodes, cannot sort
	if(count < 2)
    {
	    printf("Not enough nodes to complete sorting\n");
    }
	else{


	    //traversing through as long as there are values in which to compare
        while(tempList->next->next != NULL) {
            while (node->next != NULL)
            {
                //comparing to see if current value is smaller than next
                //Then the two nodes can be swapped using their values in the swapNodes function
                if(strcmp(tempList->supervisorName,node->supervisorName)<0){
                    swapNodes(tempList,node);
                }
                //adjusting position of node (incrementing position)
                node = node->next;
            }
            //increment position of tempList
            tempList = tempList->next;
        }
	}




	printf("\nEmployee list sorted! Use display option 'd' to view sorted list.\n");
}
