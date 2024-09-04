#include <stdio.h>
#include <stdlib.h>
#include "customer.h"
#include "customerDisplay.h"

void customer_query() {
    int choice;

    printf("\n\n-------------------------\n");
    printf(" 1. Add Customer\n");
    printf(" 2. Update Customer\n");
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
        case 1:
            addCustomer();
            break;
        case 2:
            // TODO updateCustomer();
            break;
        case 3:
            displayAllCustomers();
            break;
        case 4:
            int id;
            printf("Enter ID: ");
            scanf("%d", &id);
            displayCustomerByID(id);
            break;
        case 5:
            char name[50];
            printf("Enter name: ");
            scanf("%s", name);
            displayCustomerByName(name);
            break;
        case 6:
            char phone[15];
            printf("Enter phone: ");
            scanf("%s", phone);
            displayCustomerByPhone(phone);
            break;
        case 7:
            char email[50];
            printf("Enter email: ");
            scanf("%s", email);
            displayCustomerByEmail(email);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

}