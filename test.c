#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 500

typedef struct node Node;

struct node
{
    int id;
    char *name;
    char *email;
    char *phone;
};
// aakash hello!!
void print_temp(Node *temp)
{
    printf("%i ",temp->id);
    printf("%s ",temp->name);
    printf("%s ",temp->email);
    printf("%s \n",temp->phone);
}


Node * pull_from_list(char* line)
{
    Node *temp = NULL;
    int counter=1;
    // Returns first token
    char *token = strtok(line, ",");
   
    // Keep printing tokens while one of the
    // delimiters present in str[].
    while (token != NULL)
    {
        printf("%s \n",token);
        if (counter == 1)
        {
            temp->id = atoi(token);
            // strcpy(temp->id,token);
            counter++;
        }
        if (counter ==  2)
        {
            temp->name = token;
            counter++;
        }
        if (counter == 3)
        {
            temp -> phone = token;
            counter++;
        }
        if (counter ==  4)
        {
            temp-> email = token ;
            counter++;
        }
        else
        {    counter ++;
            return temp;
        }
        // counter++;
        // // printf("%s\n", token);
        // // token = strtok(NULL, ",");
        token = strtok(NULL, ",");
    }
 
    return temp;
}

int main()
{
    Node *temp = NULL;
    FILE* stream = fopen("file.csv", "r");

    char line[500];
    while (fgets(line, 500, stream))
    {
        char* tmp = strdup(line);
        temp = pull_from_list(tmp);
        // printf("%s \n", put_on_list(tmp));
        // NOTE strtok clobbers tmp
        print_temp(temp);
        free(tmp);
    }
}
