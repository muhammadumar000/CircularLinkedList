/*
Name: Muhammad Umar
Reg No: FA20-BEE-150
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct carsRecord
{
    char make[10];
    int model;
    float engineSize;
    char ownerName[10];
    struct carsRecord *next;
};

void insertNodeAtEnd(struct carsRecord **head);
void print_menu();
void getNewNodeData(struct carsRecord *newNode);
void deleteNodefromEnd(struct carsRecord **head);
void printList(struct carsRecord *head);
void numberOfRecords(struct carsRecord *head);

int main()
{
    int choice;
    struct carsRecord *head = NULL;
    do
    {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertNodeAtEnd(&head);
            break;
        case 2:
            deleteNodefromEnd(&head);
            break;
        case 3:
            printList(head);
            break;
        case 4:
            numberOfRecords(head);
            break;
        case 5:
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
            break;
        }
    }
    while (1);
}

void print_menu()
{
    printf("\nCars Record list\n");
    printf("1. Insert car to the list\n");
    printf("2. Delete car from the list\n");
    printf("3. Print car list\n");
    printf("4. Print Number of Records in car list\n");
    printf("5. Exit program\n");
}

void getNewNodeData(struct carsRecord *newNode)
{
    printf("\nEnter make : ");
    scanf("%s", newNode->make);
    printf("Enter model: ");
    scanf("%d", &newNode->model);
    printf("Enter engine size (in liters): ");
    scanf("%f", &newNode->engineSize);
    printf("Enter owner name : ");
    scanf("%s", newNode->ownerName);
    printf("\n");
}

void insertNodeAtEnd(struct carsRecord **head)
{

    struct carsRecord *ptr = *head;
    struct carsRecord *newNode = (struct carsRecord*)malloc(sizeof(struct carsRecord));
    getNewNodeData(newNode);

    if(ptr == NULL) /// list is empty...
    {
        *head = newNode;
        newNode->next = *head;
    }
    else /// more than one node
    {
        while(ptr->next != *head)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
        newNode->next = *head;

    }

}

void deleteNodefromEnd(struct carsRecord **head)
{

    struct carsRecord *ptr = *head;
    if(ptr == NULL)
    {
        printf("\nList is Empty...\n");
        exit(0);
    }
    else if(ptr->next == *head)
    {
        /// if list has only one node head...
        free(*head);
        *head = NULL;
    }
    else
    {
        while(ptr->next->next != *head)
        {
            ptr = ptr->next;
        }
        free(ptr->next);
        ptr->next = *head;
    }

}

void printList(struct carsRecord *head)
{
    struct carsRecord *ptr = head;
    int count = 0;
    if(ptr == NULL)
    {
        printf("\nList is Empty...\n");
        exit(0);
    }
    else
    {
        while(1)
        {
            if(ptr->next != head)
            {

                printf("\nCar %d Details: \n",count+1);
                printf("Car Make: %s\n",ptr->make);
                printf("Model: %d\n",ptr->model);
                printf("Owner Name: %s\n",ptr->ownerName);
                printf("Engine Size: %0.2f\n",ptr->engineSize);
                ptr = ptr->next;
                count++;
            }
          else{
            printf("\nCar %d Details: \n",count+1);
            printf("Car Make: %s\n",ptr->make);
            printf("Model: %d\n",ptr->model);
            printf("Owner Name: %s\n",ptr->ownerName);
            printf("Engine Size: %0.2f\n",ptr->engineSize);
            break;
          }

        }
    }
}

void numberOfRecords(struct carsRecord *head)
{
    struct carsRecord *ptr = head;
    int count = 0;
    if(ptr == NULL)
    {
        printf("\n List is Empty...\n");
    }
    else{
        while(1){
            if(ptr->next!=head){
                ptr = ptr->next;
                count++;
            }
            else{
                count++;
                break;
            }
        }
        printf("\nNumber of Records in List: %d\n",count);
    }

}

