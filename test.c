#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include<conio.h>
#include <string.h>

#include "linked_list.h"



// helpers function


// void red(){
//   printf("\033[1;31m");
// }

// void green() {
//   printf("\033[0;32m");
// }

// void reset() {
//   printf("\033[0m");
// }


// void test_pass(int test_number)
// {
// 	green();
// 	printf("\n\t\t\tTest %d Passed !!\n",test_number);
// 	reset();
// }


// void test_fail(int test_number)
// {
// 	red();
// 	printf("\n\t\t\tTest %d Failed!!\n",test_number);
// 	reset();
// }


// ----------------------------------------------------------------------------------------------------------

// Generates and prints 'count' random
// numbers in range [lower, upper].


struct node
{
    int number;        /*unique account number*/
    char name[20];     /*contains name*/  
    char phone[15];    /*contains phone number*/
    char email[20];    /*contains email address*/
    //int data;
    struct node *next; 
};
typedef struct node Node;

struct data
{
    char name[20];
    int number;       
    char phone[15] ;  
    char email[20];    
};

// // check if insert function is working fine 
// int test_insert_node(int number,char* name,char* phone, char* email)
// {

// }

// Check if create node function is working fine
int test_create_node()
{
    struct data data_1;
    strcpy(&data_1.name[20],"Pranay Prajapati");
    strcpy(&data_1.email[20],"Pranay Prajapati");
    strcpy(&data_1.phone[15],"235852598249");
    data_1.number = 237;

    for (size_t i = 0; i < 10; i++)
    {
        Node* temp  = createNode(data_1.number,data_1.name,data_1.phone,data_1.email);
        // puts(temp->email);
        // puts(data_1.email);
        // printf("%d",strcmp(temp->email ,data_1.email));
        if (!strcmp(temp->email ,data_1.email))
        {
            if (!strcmp(temp->name , data_1.name))
            {
                if (temp->number == data_1.number)
                {
                    if (!strcmp(temp->phone , data_1.phone))
                    {
                        return 1;
                    }
                    else
                        return -4;
                }
                else
                    return -3; 
            }
            else
                return -2;
        }
        else
            return -1;
    }
}

// // Check if delete node function is working fine
// int test_delete_node(int data, Node *head);