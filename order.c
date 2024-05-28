#include <stdio.h>
#include <string.h>

// Function to search the database for dish information
int searchDatabase(char dishCode[], char dishName[], double *dishPrice) {
    // Simulate the database search (you can replace this with a real database)
    if (dishCode[0] == 'C' && dishCode[1] >= '1' && dishCode[1] <= '3' && dishCode[2] == '\0') {
        if (dishCode[1] == '1') {
            strcpy(dishName, "SPICY PORK BARBECUE");
            *dishPrice = 20.00;
        } else if (dishCode[1] == '2') {
            strcpy(dishName, "VEGETABLE PORK BARBECUE");
            *dishPrice = 10.00;
        } else if (dishCode[1] == '3') {
            strcpy(dishName, "OVEN PORK BARBECUE");
            *dishPrice = 15.00;
        }
        return 1;
    }
    return 0; // Dish not found
}

int main() {
    int customer_count;
    char dishCode[5], dishName[100];
    double dishPrice, totalCost = 0.0;
    char name[100], password[10];

    // Password entry
    while (1) {
        printf("Enter password: ");
        scanf("%s", password);
        if (strcmp(password, "20123456") == 0) {
            break;
        } else {
            printf("Incorrect password. Please try again.\n");
        }
    }

    // Display user information
    printf("User name: John Doe\n");

    // Display welcome message
    printf("Welcome to the restaurant!\n");

    // Input number of customers
    do {
        printf("Customer Number: ");
        scanf("%d", &customer_count);
    } while (customer_count < 1 || customer_count > 6);

    for (int customer_number = 1; customer_number <= customer_count; customer_number++) {
        printf("Customer %d:\n", customer_number);
        totalCost = 0.0;

        while (1) {
            printf("Dish entry for customer %d:\n", customer_number);
            printf("Dish Code (F to finish): ");
            scanf("%s", dishCode);

            if (dishCode[0] == 'F' && dishCode[1] == '\0') {
                break;
            }

            if (searchDatabase(dishCode, dishName, &dishPrice)) {
                printf("Code Dish Price\n");
                printf("%s %s %.2lf\n", dishCode, dishName, dishPrice);
                totalCost += dishPrice;
            } else {
                printf("This dish code does not exist! Try again!\n");
            }
        }

        printf("Customer %d Total Cost: %.2lf\n", customer_number, totalCost);
    }

    // Display receipt and input cash
    printf("THANK YOU FOR DINING HERE!\n");
    printf("Here is your receipt:\n");

    for (int customer_number = 1; customer_number <= customer_count; customer_number++) {
        printf("Customer %d:\n");
        // Print customer's orders and update totalCost accordingly
    }

    printf("TOTAL COST: %.2lf\n", totalCost);

    double cashReceived;
    while (1) {
        printf("Cash Received: ");
        scanf("%lf", &cashReceived);
        if (cashReceived >= totalCost) {
            break;
        } else {
            printf("Received cash is less than the total cost. Please try again.\n");
        }
    }

    double change = cashReceived - totalCost;
    printf("Change Given: %.2lf\n", change);

    return 0;
}
