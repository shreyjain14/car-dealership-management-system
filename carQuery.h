#include <stdio.h>
#include <stdlib.h>
#include "car.h"
#include "carDisplay.h"

void car_query() {
    int choice;

    printf("\n\n-------------------------\n");
    printf("1. AddCar\n");
    printf("2. Display all Cars\n");
    printf("3. Search Car by Make\n");
    printf("4. Search Car by Model\n");
    printf("5. Search Car by Year\n");
    printf("6. Search Car by Price\n");
    printf("7. Search Car by VIN\n");
    printf("8. Search Car by Engine Type\n");
    printf("9. Search Car by Availability\n");
    printf("-------------------------\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    // switch case for car query

    switch (choice)
    {
    case 1:
        addCar();
        break;
    case 2:
        printf("Displaying all cars\n");
        displayAllCars();
        break;
    case 7:
        searchCar("VIN", "001");
        break;
    default:
        break;
    }

}