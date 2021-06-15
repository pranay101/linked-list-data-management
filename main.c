#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>


// function to test the program
#include "test.h"

#include "linked_list.h"

/*  READ ME


*   promt user until user enter Q
*   if a single char doesnt work then try same character twice
*   example:
*   enter: p (doesnt work)
*   enter: pp (will work) 


*/


// Utility Function 

void hold_for_enter()
{
    char enter  = getchar();
    enter = getchar();
}


void red(){
  printf("\033[1;31m");
}

void green() {
  printf("\033[0;32m");
}

void reset(void) {
  printf("\033[0m");
}

int main(void)
{
    Node* head = NULL;
    char ch;
    char enter;

    
    while(true)
    {   
        // system("cls");
        puts("\n -------------------------------");
        printf("|\t\t\t\t|\n|\tP to print all contact\t|\n|\tD to delete contact\t|\n|\tA to add new contact\t|\n|\tQ to save and quit\t|\n|\tT to run tests\t|\n");
        puts(" -------------------------------\nEnter: "); ch = tolower(getchar());

        switch (ch)
        {
        case 'p':
        {    if (head == NULL)
            {
                printf("Sorry, 0 contact found\n");
                getchar();  //get char to from user to continue
            }
            else
            {
                Traverse(head);
            }
            break;
        }
        case 'a': 
        {   
            printf("inside insert");
            int number;        /*unique account number*/
            char name[20];     /*contains name*/  
            char phone[15];    /*contains phone number*/
            char email[20];    /*contains email */
            //***************************
            printf("\nNumber: ");
            scanf("%i",&number);
            
            printf("Name: ");
            scanf("%s",name);
            
            printf("Phone: ");
            scanf("%s",phone);

            printf("Email: ");
            scanf("%s",email);
            
            //***************************
            if (head == NULL)
            {
                head = createNode(number,name,phone,email);
            }
            else
            {
                head = insert(number,name,email,phone,head);
            }
            break;
        }
        case 'd': 
           { int z;
            if (head == NULL)
            {
                printf("contact list empty.\n");
                getchar(); //get char to from user to continue
            }
            else
            {
                Traverse(head);
                printf("Enter ID number to delete: ");
                scanf("%i",&z);
                head = DELETE(z,head);
                printf("\nID: %i Deleted successfully\n");
            }
            break;
        }
        case 'q':
        {   printf("\nclosing...");
            return 0;
            break;
        }
        case 't':
        {
            printf("\n Running test 1 ");
            int test_result = test_create_node();
            if (test_result == 1)
            {
                printf("\n Test 1 passed.. !!");
                hold_for_enter();
            }
            else
            {
                printf("/n/t Code failed at test 1 !!");
                printf("/n/t Exit Code Status: %d", test_result);
            }
            break;
        }
        case '\n':
            break;

        default:
            printf("\ninvalid input\n your input should be P, D, A or Q\n");
            getchar();  //get char to from user to continue
            break;
        }
    }

}