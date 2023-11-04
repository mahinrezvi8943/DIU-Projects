#include <stdio.h>
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
    printf("\n           ╻━━━━━━━━━━━━━━━━━━━━━━━━╻        \n");
    printf("           ┃ Welcome to vending app ┃    \n");
    printf("           ╹━━━━━━━━━━━━━━━━━━━━━━━━╹        \n");
    printf("╻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╻\n");
    printf("┃ %-6s %-15s %-12s %-2s ┃\n", "ID", "Name", "Price", "Quantity");
    
    printf("┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n");
    for (int i = 0; i < 6; i++) {
        printf("┃  %-5d %-15s %-12.2f %-2d       ┃\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
    printf("┃▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁┃\n\n");
    printf("\n");
}

void SELECT(int productID, int quantity, float* balance, float* totalCost) {
    if (productID < 1 || productID > 6) {
        printf("Invalid SELECTion. Please enter a valid product ID.\n");
        return;
    }
    int n = productID - 1;
    if (quantity > products[n].quantity) {
        printf("Sorry, we don't have enough quantity of %s. Please choose a smaller quantity.\n", products[n].name);
        return;
    }

    float cost = products[n].price * quantity;
    if (cost > *balance) {
        printf("Insufficient balance. Please insert more money.\n");
        return;
    }

    if (products[n].quantity > 0) {
        printf("Enjoy your %d %s!\n", quantity, products[n].name);
        products[n].quantity -= quantity;
        *balance -= cost;
        *totalCost += cost;
    } else {
        printf("Sorry, %s is out of stock. Please choose another product.\n", products[n].name);
    }
}

int main() {
    float balance = 100.0, totalCost = 0;
    int productCount = 0;
    int Quantity[6];
    for (int i = 0; i < 6; i++) Quantity[i] = products[i].quantity;
    
    while (1) {
        menu();
        printf("Current Balance: $%.2f\n", balance);
        int productID, quantity;

        printf("Enter the product ID or 0 to exit: ");
        scanf("%d", &productID);

        if (productID == 0) break;

        printf("Enter the quantity you want to purchase: ");
        scanf("%d", &quantity);

        SELECT(productID, quantity, &balance, &totalCost);

        int n = productID - 1;

        if (products[n].quantity < Quantity[n]) {
            int purchasedQuantity = Quantity[n] - products[n].quantity;
            float productTotalCost = purchasedQuantity * products[n].price;
            printf("Added to Shopping Cart: %-2d %s for $%.2f\n", purchasedQuantity, products[n].name, productTotalCost);
            productCount++;
        }
    }
    printf("\n\n\n\n                    ╻━━━━━━━━━━━━━━━╻\n");
    printf("        ............┃ Shopping Cart ┃............\n");

    printf("                    ╹━━━━━━━━━━━━━━━╹\n\n");
    if (productCount > 0) {
        printf("╻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╻\n");
        printf("┃ %-5s %-20s %-12s %-12s ┃\n", "Qty", "Product", "Price(Tk.)", "Total");
        printf("┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n");
        for (int i = 0; i < 6; i++) {
            int quantity = Quantity[i] - products[i].quantity;
            float productTotalCost = quantity * products[i].price;
                printf("┃  %-4d %-20s %-12.2f %-12.2f ┃\n", quantity, products[i].name, products[i].price, productTotalCost);
        }
        printf("╹━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╹\n");
        printf("                            Total cost: %.2f Tk.\n", totalCost);
    } else {
        printf("Your cart is empty.\n\n");
    }

    printf("\nThank you for using the Vending Machine! Your remaining balance is: %.2f Tk.\n\n\n", balance);

    return 0;
}
