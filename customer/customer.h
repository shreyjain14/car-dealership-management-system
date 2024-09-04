#include <stdio.h>
#include <stdlib.h>



struct customer
{
    int id;
    char name[50];
    char phone[10];
    char email[50];
    
};

void addCustomer()
{
    struct customer customer;
    printf("Enter name: ");
    scanf("%s", customer.name);
    printf("Enter phone: ");
    scanf("%s", customer.phone);
    printf("Enter email: ");
    scanf("%s", customer.email);
    printf("Enter id: ");
    scanf("%d", &customer.id);

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