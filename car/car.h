#ifndef CAR_H
#define CAR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Car {
    char make[50];
    char model[50];
    int year;
    float price;
    char vin[20];       
    char engineType[30]; 
    bool isAvailable;
};

void addCar() {
    struct Car car;

    printf("Enter make: ");
    scanf("%s", car.make);
    printf("Enter model: ");
    scanf("%s", car.model);
    printf("Enter year: ");
    scanf("%d", &car.year);
    printf("Enter price: ");
    scanf("%f", &car.price);
    printf("Enter VIN: ");
    scanf("%s", car.vin);
    printf("Enter engine type: ");
    scanf("%s", car.engineType);
    printf("Is the car available? (1 for Yes, 0 for No): ");
    scanf("%d", (int*)&car.isAvailable); 

    FILE *file = fopen("data/cars.txt", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "%s %s %d %.2f %s %s %d\n", 
            car.make, car.model, car.year, car.price,
            car.vin, car.engineType, car.isAvailable); 
    fclose(file);

    printf("Car added successfully.\n");
}

#endif // CAR_H