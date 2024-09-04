#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "car.h"

#define CAR_FILE_PATH "data/cars.txt"

void displayAllCars() {

    FILE *file = fopen(CAR_FILE_PATH, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    struct Car car;

    printf("Displaying all cars\n");
    printf("--------------------\n");

    while (
        fscanf(
            file, 
            "%s %s %d %f %s %s %d",
            car.make, 
            car.model, 
            &car.year, 
            &car.price,
            car.vin, 
            car.engineType, 
            (int*)&car.isAvailable) == 7
                ) { 

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


void displayCar(char *field, char *value) {
    FILE *file = fopen(CAR_FILE_PATH, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    struct Car car;

    printf("Displaying car by %s\n", field);
    printf("--------------------\n");

    while (fscanf(file, "%s %s %d %f %s %s %d", car.make, car.model, &car.year, &car.price, car.vin, car.engineType, (int*)&car.isAvailable) == 7) {
        if ((strcmp(field, "Make") == 0 && strcmp(car.make, value) == 0) ||
            (strcmp(field, "Model") == 0 && strcmp(car.model, value) == 0) ||
            (strcmp(field, "Year") == 0 && car.year == atoi(value)) ||
            (strcmp(field, "Price") == 0 && car.price <= atof(value)) ||
            (strcmp(field, "VIN") == 0 && strcmp(car.vin, value) == 0) ||
            (strcmp(field, "EngineType") == 0 && strcmp(car.engineType, value) == 0) ||
            (strcmp(field, "Availability") == 0 && car.isAvailable == (strcmp(value, "1") == 0))) {
            printf("Make: %s\n", car.make);
            printf("Model: %s\n", car.model);
            printf("Year: %d\n", car.year);
            printf("Price: %.2f\n", car.price);
            printf("VIN: %s\n", car.vin);
            printf("Engine Type: %s\n", car.engineType);
            printf("Available: %s\n", car.isAvailable ? "Yes" : "No");
            printf("--------------------\n");
        }
    }
}