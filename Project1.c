#include <stdio.h>
#include <string.h>

struct Product {
    int id;
    char name[50];
    float price;
    int quantity;
};

struct Product products[] = {
    {1, "Chips", 15, 30},
    {2, "Chocolate", 100, 20},
    {3, "Soda", 35, 16},
    {4, "Cake", 40, 15},
    {5, "Biscuit", 20, 30},
    {6, "Ice Cream", 50, 15}
};

void menu() {
    printf("\n\n====== Vending Machine Menu ======\n\n");
    printf("%-3s %-15s %-10s   %-20s\n", "ID", "Product Name", "Price (Tk.)",   "Quantity Available");
    for (int i = 0; i < sizeof(products) / sizeof(products[0]); i++) {
        printf("%-3d %-15s %-10.2f     %-20d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
    printf("\n");
}

void select(int productID, int quantity, float* balance) {
    if (productID < 1 || productID > 6) {
        printf("Invalid selection. Please enter a valid product ID.\n");
        return;
    }
    int n = productID - 1;
    if (quantity > products[n].quantity) {
        printf("Sorry, we don't have enough quantity of %s. Please choose a smaller quantity.\n", products[n].name);
        return;
    }
    if (products[n].quantity > 0) {
        if (*balance >= products[n].price * quantity) {
            printf("Enjoy your %d %s!\n", quantity, products[n].name);
            products[n].quantity -= quantity;
            *balance -= products[n].price * quantity;
        } else printf("Insufficient balance. Please insert more money.\n");
    } else printf("Sorry, %s is out of stock. Please choose another product.\n", products[n].name);
}

int main() {
    float balance = 100.0, totalCost = 0;
    int productID, quantity, productCount = 0;
    int Quantity[6];
    for(int i = 0; i <6; i++) Quantity[i] = products[i].quantity;
    printf("Welcome to the Vending Machine!\n");

    while (1) {
        printf("Current Balance: $%.2f\n", balance);
        menu();
        printf("Enter the product ID or 0 to exit: ");
        scanf("%d", &productID);

        if (productID == 0) break;
        printf("Enter the quantity you want to purchase: ");
        scanf("%d", &quantity);

        select(productID, quantity, &balance);

        int n = productID - 1;
        totalCost += products[n].price * quantity;
        productCount++;
    }

    printf("\n\n\n\n        ............ Shopping Cart ............\n\n");

    if (productCount > 0) {
        printf(",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n");
        printf("| %-5s %-20s %-12s %-12s |\n", "Qty", "Product", "Price(Tk.)", "Total");
        printf("|``````````````````````````````````````````````````````|\n");
        for (int i = 0; i < 6; i++) {
            int quantity = Quantity[i] - products[i].quantity;
            float productTotalCost = quantity * products[i].price;
            printf("|  %-4d %-20s %-12.2f %-12.2f |\n", quantity, products[i].name, products[i].price, productTotalCost);
        }
        printf("|,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,|\n");
        printf("                            Total cost: %-8.2f\n", totalCost);
    } else printf("Your cart is empty.\n\n");
    printf("\nThank you for using the Vending Machine! Your remaining balance is: %-8.2f\n\n\n", balance);
    return 0;
}
#include <stdio.h>
#include <string.h>

struct Product {
    int id;
    char name[50];
    float price;
    int quantity;
};

struct Product products[] = {
    {1, "Chips", 15, 30},
    {2, "Chocolate", 100, 20},
    {3, "Soda", 35, 16},
    {4, "Cake", 40, 15},
    {5, "Biscuit", 20, 30},
    {6, "Ice Cream", 50, 15}
};

void menu() {
    printf("\n\n====== Vending Machine Menu ======\n\n");
    printf("%-3s %-15s %-10s   %-20s\n", "ID", "Product Name", "Price (Tk.)",   "Quantity Available");
    for (int i = 0; i < sizeof(products) / sizeof(products[0]); i++) {
        printf("%-3d %-15s %-10.2f     %-20d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
    printf("\n");
}

void select(int productID, int quantity, float* balance) {
    if (productID < 1 || productID > 6) {
        printf("Invalid selection. Please enter a valid product ID.\n");
        return;
    }
    int n = productID - 1;
    if (quantity > products[n].quantity) {
        printf("Sorry, we don't have enough quantity of %s. Please choose a smaller quantity.\n", products[n].name);
        return;
    }
    if (products[n].quantity > 0) {
        if (*balance >= products[n].price * quantity) {
            printf("Enjoy your %d %s!\n", quantity, products[n].name);
            products[n].quantity -= quantity;
            *balance -= products[n].price * quantity;
        } else printf("Insufficient balance. Please insert more money.\n");
    } else printf("Sorry, %s is out of stock. Please choose another product.\n", products[n].name);
}

int main() {
    float balance = 100.0, totalCost = 0;
    int productID, quantity, productCount = 0;
    int Quantity[6];
    for(int i = 0; i <6; i++) Quantity[i] = products[i].quantity;
    printf("Welcome to the Vending Machine!\n");

    while (1) {
        printf("Current Balance: $%.2f\n", balance);
        menu();
        printf("Enter the product ID or 0 to exit: ");
        scanf("%d", &productID);

        if (productID == 0) break;
        printf("Enter the quantity you want to purchase: ");
        scanf("%d", &quantity);

        select(productID, quantity, &balance);

        int n = productID - 1;
        totalCost += products[n].price * quantity;
        productCount++;
    }

    printf("\n\n\n\n        ............ Shopping Cart ............\n\n");

    if (productCount > 0) {
        printf(",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n");
        printf("| %-5s %-20s %-12s %-12s |\n", "Qty", "Product", "Price(Tk.)", "Total");
        printf("|``````````````````````````````````````````````````````|\n");
        for (int i = 0; i < 6; i++) {
            int quantity = Quantity[i] - products[i].quantity;
            float productTotalCost = quantity * products[i].price;
            printf("|  %-4d %-20s %-12.2f %-12.2f |\n", quantity, products[i].name, products[i].price, productTotalCost);
        }
        printf("|,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,|\n");
        printf("                            Total cost: %-8.2f\n", totalCost);
    } else printf("Your cart is empty.\n\n");
    printf("\nThank you for using the Vending Machine! Your remaining balance is: %-8.2f\n\n\n", balance);
    return 0;
}
