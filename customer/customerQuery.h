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
    default:
        printf("Invalid choice.\n");
        break;
    }

}