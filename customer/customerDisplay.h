#ifndef CUSTOMER_DISPLAY_H
#define CUSTOMER_DISPLAY_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "customer.h"

// TODO FIX SEARCH LOOK AT DISCORD

#define CUSTOMER_FILE_PATH "data/customers.txt"

void displayAllCustomers()
{
    FILE *file = fopen(CUSTOMER_FILE_PATH, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }

    struct Customer customer;

    printf("--------------------\n");
    
    while (fscanf(file, "%99s %14s %99s %d", customer.name, customer.phone, customer.email, &customer.id) == 4)
    {
        printf("Name: %s\n", customer.name);
        printf("Phone: %s\n", customer.phone);
        printf("Email: %s\n", customer.email);
        printf("ID: %d\n", customer.id);
        printf("--------------------\n");
    }

    fclose(file);
}

// Function to display a customer by their ID
void displayCustomerByID(int id)
{
    FILE *file = fopen(CUSTOMER_FILE_PATH, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }

    struct Customer customer;
    bool found = false;
    printf("--------------------\n");
    while (fscanf(file, "%99s %14s %99s %d", customer.name, customer.phone, customer.email, &customer.id) == 4)
    {
        if (customer.id == id)
        {
            printf("Name: %s\n", customer.name);
            printf("Phone: %s\n", customer.phone);
            printf("Email: %s\n", customer.email);
            printf("ID: %d\n", customer.id);
            printf("--------------------\n");
            found = true;
            break;
        }
    }

    if (!found)
    {
        printf("Customer with ID %d not found.\n", id);
    }

    fclose(file);
}

// Function to display a customer by their name
void displayCustomerByName(const char *name)
{
    FILE *file = fopen(CUSTOMER_FILE_PATH, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }

    struct Customer customer;
    bool found = false;
    printf("--------------------\n");
    while (fscanf(file, "%99s %14s %99s %d", customer.name, customer.phone, customer.email, &customer.id) == 4)
    {
        if (strcmp(customer.name, name) == 0)
        {
            printf("Name: %s\n", customer.name);
            printf("Phone: %s\n", customer.phone);
            printf("Email: %s\n", customer.email);
            printf("ID: %d\n", customer.id);
            printf("--------------------\n");
            found = true;
        }
    }

    if (!found)
    {
        printf("Customer with name %s not found.\n", name);
    }

    fclose(file);
}

// Function to display a customer by their phone number
void displayCustomerByPhone(const char *phone)
{
    FILE *file = fopen(CUSTOMER_FILE_PATH, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }

    struct Customer customer;
    bool found = false;
    printf("--------------------\n");
    while (fscanf(file, "%99s %14s %99s %d", customer.name, customer.phone, customer.email, &customer.id) == 4)
    {
        if (strcmp(customer.phone, phone) == 0)
        {
            printf("Name: %s\n", customer.name);
            printf("Phone: %s\n", customer.phone);
            printf("Email: %s\n", customer.email);
            printf("ID: %d\n", customer.id);
            printf("--------------------\n");
            found = true;
        }
    }

    if (!found)
    {
        printf("Customer with phone %s not found.\n", phone);
    }

    fclose(file);
}

// Function to display a customer by their email address
void displayCustomerByEmail(const char *email)
{
    FILE *file = fopen(CUSTOMER_FILE_PATH, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }

    struct Customer customer;
    bool found = false;
    printf("--------------------\n");
    while (fscanf(file, "%99s %14s %99s %d", customer.name, customer.phone, customer.email, &customer.id) == 4)
    {
        if (strcmp(customer.email, email) == 0)
        {
            printf("Name: %s\n", customer.name);
            printf("Phone: %s\n", customer.phone);
            printf("Email: %s\n", customer.email);
            printf("ID: %d\n", customer.id);
            printf("--------------------\n");
            found = true;
        }
    }

    if (!found)
    {
        printf("Customer with email %s not found.\n", email);
    }

    fclose(file);
}

#endif // CUSTOMER_DISPLAY_H
