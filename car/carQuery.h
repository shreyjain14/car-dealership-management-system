#include <stdio.h>
#include <stdlib.h>
#include "car.h"
#include "carDisplay.h"

void car_query() {
    int choice;

    printf("\n\n-------------------------\n");
    printf(" 1. Add Car\n");
    printf(" 2. Update Car by VIN\n");
    printf(" 3. Display all Cars\n");
    printf(" 4. Search Car by Make\n");
    printf(" 5. Search Car by Model\n");
    printf(" 6. Search Car by Year\n");
    printf(" 7. Search Car by Price\n");
    printf(" 8. Search Car by VIN\n");
    printf(" 9. Search Car by Engine Type\n");
    printf("10. Search Car by Availability\n");
    printf("-------------------------\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    // TODO switch case for car query

    switch (choice)
    {
    case 1:
        addCar();
        break;
    case 3:
        displayAllCars();
        break;
    case 8:
        searchCar("VIN", "001");
        break;
    default:
        printf("Invalid choice.\n");
        break;
    }

}