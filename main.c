#include <stdio.h>
#include <stdlib.h>
#include "car/carQuery.h"
// #include "customer/customerQuery.h"


int main() {
    int choice;
    while (1) {
        printf("\n-------------------------\n");
        printf("1. Customer Related Query\n");
        printf("2. Car Related Query\n");
        printf("3. Exit\n");
        printf("-------------------------\n"); 
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                // customer_query();
                break;
            case 2:
                car_query();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}