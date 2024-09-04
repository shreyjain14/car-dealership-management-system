#include <stdio.h>
#include <stdlib.h>
#include "car.h"
#include "carDisplay.h"

void car_query() {
    int choice;

    printf("\n-------------------------\n");
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
    case 4:
        char make[50];
        printf("Enter make: ");
        scanf("%s", make);
        displayCar("Make", make);
        break;
    case 5:
        char model[50];
        printf("Enter model: ");
        scanf("%s", model);
        displayCar("Model", model);
        break;
    case 6:
        int year;
        char yearStr[10];
        printf("Enter year: ");
        scanf("%d", &year);
        sprintf(yearStr, "%d", year);
        displayCar("Year", yearStr);
        break;
    case 7:
        float price;
        char priceStr[20];
        printf("Enter price: ");
        scanf("%f", &price);
        sprintf(priceStr, "%.2f", price);
        displayCar("Price", priceStr);
        break;
    case 8:
        char vin[20];
        printf("Enter VIN: ");
        scanf("%s", vin);
        displayCar("VIN", vin);
        break;
    case 9:
        char engineType[30];
        printf("Enter engine type: ");
        scanf("%s", engineType);
        displayCar("Engine Type", engineType);
        break;
    case 10:
        int isAvailable;
        char availabilityStr[2];
        printf("Is the car available? (1 for Yes, 0 for No): ");
        scanf("%d", &isAvailable);
        sprintf(availabilityStr, "%d", isAvailable);
        displayCar("Availability", availabilityStr);
        break;
    default:
        printf("Invalid choice.\n");
        break;
    }

}