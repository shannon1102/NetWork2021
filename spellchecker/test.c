#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// #include "dictionary.h"
int checkSpell(char *wordcheck);
void tolowerStr(char *str);
void load();
typedef struct node
{
    char data[20];
    struct node *next;
}node;
node *rootWord, *curr;


int main()
{
    rootWord = NULL, curr = NULL;
    load();
    char wordIp[50];
    node *temp = rootWord;
    printf("\n\nList elements are - \n");
    while (temp != NULL)
    {
        printf("%s --->", temp->data);
        temp = temp->next;
    }

    printf("Enter the word:\v");
    gets(wordIp);
    printf("Check spellerr %d\n",checkSpell(wordIp));

    return 1;
}
void load() {
    FILE *f;
    int i = 1;
    char word[50];
    f = fopen("words.txt", "r");
    if (f == NULL)
    {
        printf("Error!");
        exit(1);
    }
    while (fscanf(f, "%s", word) != EOF)
    {
        node *new;
        new = (node *)malloc(sizeof(node));
        strcpy(new->data, word);
        new->next = NULL;
        if (rootWord == NULL)
        {
            rootWord = new;
            curr = rootWord;
        }
        else
        {
            curr->next = new;
            curr = curr->next;
            curr->next = NULL;
        }    
    };
    //  printf("Loading. done......\n");
    fclose(f);

}
void tolowerStr(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        str[i] = tolower(str[i]);
    }
}
int checkSpell(char *wordcheck)
{
    tolowerStr(wordcheck);
    node *temp = rootWord;
    // printf("\n\nList elements are - \n");
    while (temp != NULL)
    {
        // printf("%s --->", temp->data);
        if(strcmp(temp->data,wordcheck) == 0) {
            // printf("%s----%d\n",temp->data,strlen(temp->data));
            return 1;
        }
        temp = temp->next;

    }
    return -1;
}