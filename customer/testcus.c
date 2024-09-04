#include <stdio.h>
#include <stdlib.h>
#include "customerDisplay.h"

void customerQuery()
{
    int choice;

    printf("-------------------------\n");
    printf(" 3. Display all Customers\n");
    printf(" 4. Search Customer by ID\n");
    printf(" 5. Search Customer by Name\n");
    printf(" 6. Search Customer by Phone\n");
    printf(" 7. Search Customer by Email\n");
    printf("-------------------------\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    // switch case for Customer query
    switch (choice)
    {
    case 3:
        displayAllCustomers();
        break;
    case 4:
    {
        int id;
        printf("Enter Customer ID: ");
        scanf("%d", &id);
        displayCustomerByID(id);
        break;
    }
    case 5:
    {
        char name[50];
        printf("Enter Customer Name: ");
        scanf("%s", name);
        displayCustomerByName(name);
        break;
    }
    case 6:
    {
        char phone[10];
        printf("Enter Customer Phone: ");
        scanf("%s", phone);
        displayCustomerByPhone(phone);
        break;
    }
    case 7:
    {
        char email[50];
        printf("Enter Customer Email: ");
        scanf("%s", email);
        displayCustomerByEmail(email);
        break;
    }
    default:
        printf("Invalid choice.\n");
        break;
    }
}