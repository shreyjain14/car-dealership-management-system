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