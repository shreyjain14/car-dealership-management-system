#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "car.h"

void displayAllCars() {

    FILE *file = fopen("cars.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    struct Car car;

    printf("\nDEBUG 1\n");

    while (
        fscanf(
            file, "%s %s %d %f %s %s %d",
            car.make, 
            car.model, 
            &car.year, 
            &car.price,
            car.vin, 
            car.engineType, 
            (int*)&car.isAvailable
        ) == true) { 

        printf("--------------------\n");
        printf("Make: %s\n", car.make);
        printf("Model: %s\n", car.model);
        printf("Year: %d\n", car.year);
        printf("Price: %.2f\n", car.price);
        printf("VIN: %s\n", car.vin);
        printf("Engine Type: %s\n", car.engineType);
        printf("Available: %s\n", car.isAvailable ? "Yes" : "No"); 
        printf("--------------------\n");

    }

    fclose(file);
}

void searchCar(const char* factor, const char* key) {
    FILE* file = fopen("cars.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    struct Car car;
    bool found = false;
    while (
        fscanf(
            file, "%s %s %d %f %s %s %d",
            car.make, 
            car.model, 
            &car.year, 
            &car.price,
            car.vin, 
            car.engineType, 
            (int*)&car.isAvailable
        ) == true) { 

        if (strcmp(factor, "VIN") == 0 && strcmp(car.vin, key) == 0) {
            found = true;
        } else if (strcmp(factor, "Model") == 0 && strcmp(car.model, key) == 0) {
            found = true;
        } // Add more conditions for other factors

        if (found) {
            printf("--------------------\n");
            printf("Make: %s\n", car.make);
            printf("Model: %s\n", car.model);
            printf("Year: %d\n", car.year);
            printf("Price: %.2f\n", car.price);
            printf("VIN: %s\n", car.vin);
            printf("Engine Type: %s\n", car.engineType);
            printf("Available: %s\n", car.isAvailable ? "Yes" : "No"); 
            printf("--------------------\n");
            found = false;
        }
    }

    fclose(file);
}