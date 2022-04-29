#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char name[40];
    char phone_no[10];
    struct node *left;
    struct node *right;
};

struct node *head = NULL;
char temp_n[40];
char temp_p[10];

struct node *createNode(char *name, char *phone_no)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    strcpy(new_node->name, name);
    strcpy(new_node->phone_no, phone_no);
    new_node->left = new_node->right = NULL;
    return new_node;
}

void insert(char *name, char *phone_no)
{
    struct node *root = head;
    struct node *prev = NULL;
    if (root == NULL)
    {
        struct node *new_node = createNode(name, phone_no);
        head = new_node;
        return;
    }
    while (root != NULL)
    {
        prev = root;
        if (strcmp(root->name, name) == 0)
        {
            printf("Name is already present !");
            return;
        }
        else if (strcmp(root->name, name) > 0)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct node *New = createNode(name, phone_no);
    if (strcmp(prev->name, name) > 0)
    {
        prev->left = New;
    }
    else
    {
        prev->right = New;
    }
}

struct node *inorderpre(struct node *node)
{
    while (node->right != NULL)
        node = node->right;

    return node;
}

struct node *deleteNode(struct node *root, char *name)
{
    if (root == NULL)
        return root;

    if (strcmp(root->name, name) > 0)
        root->left = deleteNode(root->left, name);

    else if (strcmp(root->name, name) < 0)
        root->right = deleteNode(root->right, name);

    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node *temp = inorderpre(root->left);
        strcpy(root->name, temp->name);
        root->left = deleteNode(root->left, temp->name);
    }
    return root;
}

void searchbyno(struct node *root, char *phone)
{
    if (root != NULL)
    {
        searchbyno(root->left, phone);
        if (strstr(root->phone_no, phone))
        {
            printf("\033[1;35m");
            printf("\n\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("\033[0m");
            printf("\033[1;36m");
            printf("\n\t\t\t\t\t\t\t\t\t\t\tName : %-10s | Phone No.: %-10s \n", root->name, root->phone_no);
            printf("\033[0m");
        }
        searchbyno(root->right, phone);
    }
}

void searchbyname(struct node *root, char *name)
{
    if (root != NULL)
    {
        searchbyname(root->left, name);
        if (strstr(root->name, name))
        {
            printf("\033[1;35m");
            printf("\n\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("\033[0m");
            printf("\033[1;36m");
            printf("\n\t\t\t\t\t\t\t\t\t\t\tName : %-10s | Phone No.: %-10s \n", root->name, root->phone_no);
            printf("\033[0m");
        }
        searchbyname(root->right, name);
    }
}

void show_ascending(struct node *root)
{
    if (root != NULL)
    {
        show_ascending(root->left);
        printf("\033[1;35m");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\tName : %-10s | Phone No.: %-10s \n", root->name, root->phone_no);
        printf("\033[0m");
        show_ascending(root->right);
    }
}

void show_descending(struct node *root)
{
    if (root != NULL)
    {
        show_descending(root->right);
        printf("\033[1;35m");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\tName : %-10s | Phone No.: %-10s \n", root->name, root->phone_no);
        printf("\033[0m");
        show_descending(root->left);
    }
}

int main()
{
    printf("\e[1;1H\e[2J");
    menu:
    printf("\033[1;35m");
    printf("\n\n\n\n\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
    printf("\033[0m");
    printf("\033[1;33m");
    printf("\n\t\t\t\t\t\t\t\t\t\t ------------- PHONE - BOOK -------------\n\n\n");
    printf("\033[0m");
    printf("\033[1;37m");
    printf("\t\t\t\t\t\t\t\t\t\t\t1. Add Contact\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t2. Delete Contact\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t3. Search Contact By Number\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t4. Search Contact By Name\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t5. Show in Descending Order\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t6. Show in Ascending Order\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t7. Exit Program\n");
    printf("\033[0m");
    printf("\033[1;35m");
    printf("\n\n\n\n\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
    printf("\033[0m");
    int choice;
    printf("\033[1;32m"); 
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\tEnter Choice : ");
    printf("\033[0m");
    scanf("%d", &choice);
    printf("\e[1;1H\e[2J");
    printf("\n");
    if (choice == 1)
    {
        printf("\033[3;32m");
        printf("\n\t\t\t\t\t\t\t\t\t\t ------------- ADD CONTACT -------------\n\n\n");
        printf("\033[0m");
        printf("\033[1;35m");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\tEnter Name : ");
        printf("\033[0m");
        while ((getchar()) != '\n')
            ;
        scanf("%[^\n]%*c", temp_n);

        printf("\033[1;35m");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\tEnter Phone no. : ");
        printf("\033[0m");
        scanf("%[^\n]%*c", temp_p);
        insert(temp_n, temp_p);
        printf("\e[1;1H\e[2J");
    }
    else if (choice == 2)
    {
        printf("\033[3;32m");
        printf("\n\t\t\t\t\t\t\t\t\t\t ------------ DELETE CONTACT ------------\n\n\n");
        printf("\033[0m");
        if (head == NULL)
        {
            printf("\033[1;31m");
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\tNo contacts to delete !\n");
            printf("\033[0m");
            goto menu;
        }
        printf("\033[0;31m");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\tEnter Exact Name to delete : ");
        printf("\033[0m");
        while ((getchar()) != '\n')
            ;
        scanf("%[^\n]%*c", temp_n);
        head = deleteNode(head, temp_n);
        printf("\e[1;1H\e[2J");
    }
    else if (choice == 3)
    {
        printf("\033[3;32m");
        printf("\n\t\t\t\t\t\t\t\t\t\t ------------ SEARCH CONTACT ------------\n\n\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t --------------- BY NUMBER --------------\n\n\n");
        printf("\033[0m");
        struct node *root = head;
        if (root == NULL)
        {
            printf("\033[1;31m");
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\tNo Contacts to search !\n");
            printf("\033[0m");
            goto menu;
        }
        printf("\033[1;32m");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\tEnter Phone no. : ");
        printf("\033[0m");
        while ((getchar()) != '\n')
            ;
        scanf("%[^\n]%*c", temp_p);
        printf("\n");
        searchbyno(root, temp_p);
        printf("\n");
        printf("\033[1;35m");
        printf("\n\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("\033[0m");
        getchar();
        printf("\e[1;1H\e[2J");
    }
    else if (choice == 4)
    {
        printf("\033[3;32m");
        printf("\n\t\t\t\t\t\t\t\t\t\t ------------ SEARCH CONTACT ------------\n\n\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t ---------------- BY NAME ---------------\n\n\n");
        printf("\033[0m");
        struct node *root = head;
        if (root == NULL)
        {
            printf("\033[1;31m");
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\tNo Contacts to search !\n");
            printf("\033[0m");
            goto menu;
        }
        printf("\033[1;32m");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\tEnter Name : ");
        printf("\033[0m");
        while ((getchar()) != '\n')
            ;
        scanf("%[^\n]%*c", temp_p);
        printf("\n");
        searchbyname(root, temp_p);
        printf("\n");
        printf("\033[1;35m");
        printf("\n\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("\033[0m");
        getchar();
        printf("\e[1;1H\e[2J");
    }
    else if (choice == 5)
    {
        printf("\033[3;32m");
        printf("\n\t\t\t\t\t\t\t\t\t\t ----------------- CONTACTS -----------------\n\n\n");
        printf("\033[0m");
        struct node *root = head;
        if (root == NULL)
        {
            printf("\033[1;31m");
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\tNo Contacts are there !\n");
            printf("\033[0m");
            goto menu;
        }
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\tCONTACTS in Descending Order :\n");
        show_descending(root);
        printf("\n");
    }
    else if (choice == 6)
    {
        printf("\033[3;32m");
        printf("\n\t\t\t\t\t\t\t\t\t\t ----------------- CONTACTS -----------------\n\n\n");
        printf("\033[0m");
        struct node *root = head;
        if (root == NULL)
        {
            printf("\033[1;31m");
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\tNo Contacts are there !\n");
            printf("\033[0m");
            goto menu;
        }
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\tCONTACTS in Ascending Order :\n");
        show_ascending(root);
        printf("\n");
    }
    else if (choice == 7)
    {
        exit(0);
    }
    else
    {
        printf("\033[1;31m");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t Please Enter Valid Number !\n");
        printf("\033[0m");
    }
    goto menu;
    return 0;
}