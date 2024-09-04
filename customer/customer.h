#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <stdio.h>
#include <stdlib.h>


struct Customer
{
    int id;
    char name[50];
    char phone[15];
    char email[50];
};


void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        // Discard characters until the end of the line
    }
}

int getNextCustomerID()
{
    FILE *file = fopen("data/customers.txt", "r");
    if (file == NULL)
    {
        return 1;
    }

    int lines = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF)
    {
        if (ch == '\n')
        {
            lines++;
        }
    }
    fclose(file);
    return lines + 1;
}


void addCustomer()
{
    struct Customer customer;
    customer.id = getNextCustomerID();

    printf("Adding customer with ID %d\n", customer.id);

    printf("Enter name: ");
    scanf("%49s", customer.name);
    clearInputBuffer();

    printf("Enter phone: ");
    scanf("%14s", customer.phone);
    clearInputBuffer();

    printf("Enter email: ");
    scanf("%49s", customer.email);
    clearInputBuffer();

    FILE *file = fopen("data/customers.txt", "a");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "%s %s %s %d\n", customer.name, customer.phone, customer.email, customer.id);
    fclose(file);

    printf("Customer added successfully.\n");
}

#endif