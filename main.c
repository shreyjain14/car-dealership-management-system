#include <stdio.h>
#include <stdlib.h>

struct Car {
    char make[50];
    char model[50];
    int year;
    float price;
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

    FILE *file = fopen("cars.txt", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "%s %s %d %.2f\n", car.make, car.model, car.year, car.price);
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
    while (fscanf(file, "%s %s %d %f", car.make, car.model, &car.year, &car.price) != EOF) {
        printf("Make: %s\n", car.make);
        printf("Model: %s\n", car.model);
        printf("Year: %d\n", car.year);
        printf("Price: %.2f\n", car.price);
        printf("--------------------\n");
    }

    fclose(file);
}

int main() {
    int choice;

    while (1) {
        printf("Car Dealership Management System\n");
        printf("1. Add Car\n");
        printf("2. Display Cars\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCar();
                break;
            case 2:
                displayCars();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}