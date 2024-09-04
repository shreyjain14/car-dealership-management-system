#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <stdio.h>
#include <stdlib.h>

// Define the customer structure
struct customer
{
    int id;
    char name[50];
    char phone[15]; // Adjusted size for phone number
    char email[50];
};

// Function to clear the input buffer
void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        // Discard characters until the end of the line
    }
}

// Function to get the next available customer ID based on the number of lines in the file
int getNextCustomerID()
{
    FILE *file = fopen("data/customers.txt", "r");
    if (file == NULL)
    {
        return 1; // Start with ID 1 if the file doesn't exist or can't be opened
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
    return lines + 1; // Return the next available ID
}

// Implement the addCustomer function
void addCustomer()
{
    struct customer customer;
    customer.id = getNextCustomerID(); // Auto-generate ID

    printf("Adding customer with ID %d\n", customer.id);

    printf("Enter name: ");
    scanf("%49s", customer.name); // Limit input to prevent buffer overflow
    clearInputBuffer();           // Clear the input buffer after each scanf

    printf("Enter phone: ");
    scanf("%14s", customer.phone); // Limit input to prevent buffer overflow
    clearInputBuffer();

    printf("Enter email: ");
    scanf("%49s", customer.email); // Limit input to prevent buffer overflow
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

#endif // CUSTOMER_H
