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
    scanf("%s", &car.make);
    printf("Enter model: ");
    scanf("%s", &car.model);
    printf("Enter year: ");
    scanf("%d", &car.year);
    printf("Enter price: ");
    scanf("%f", &car.price);
    printf("Enter VIN: ");
    scanf("%s", &car.vin);
    printf("Enter engine type: ");
    scanf("%s", &car.engineType);
    printf("Is the car available? (1 for Yes, 0 for No): ");
    scanf("%d", &car.isAvailable); 

    FILE *file = fopen("cars.txt", "a");
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

void displayCars() {
    FILE *file = fopen("cars.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    struct Car car;
    while (fscanf(file, "%s %s %d %f %s %s %d", 
                  car.make, car.model, &car.year, &car.price, 
                  car.vin, car.engineType, (int*)&car.isAvailable) == true) { 

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
