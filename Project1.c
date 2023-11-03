#include <iostream>
using namespace std;
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

void menu()
{
    cout<<"\n           ,,,,,,,,,,,,,,,,,,,,,,,,,,        "<<endl;
    cout<<"           | Welcome to vending app |    \n";
    cout<<"           ``````````````````````````        \n";
    cout<<"................................................\n";
    printf("| %-6s %-15s %-12s %-2s |\n","ID", "Name", "Price", "Quantity");
    
    cout<<"|``````````````````````````````````````````````|\n";
    for(int i = 0; i < 6; i++)
    {
        printf("|  %-5d %-15s %-12d %-2d      |\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
    cout<<"|,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,|\n";
    cout<<"\n";
}
void select(int productID, int quantity, float* balance, float* totalCost) {
    if (productID < 1 || productID > 6) {
        printf("Invalid selection. Please enter a valid product ID.\n");
        return;
    }
    int n = productID - 1;
    if (quantity > products[n].quantity) {
        printf("Sorry, we don't have enough quantity of %s. Please choose a smaller quantity.\n", products[n].name);
        return;
    }

    float cost = products[n].price * quantity;
    if ( cost > *balance) {
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
    int productID, quantity, productCount = 0;
    int Quantity[6];
    for (int i = 0; i < 6; i++) Quantity[i] = products[i].quantity;
    printf("Welcome to the Vending Machine!\n");

    while (1) {
        printf("Current Balance: $%.2f\n", balance);
        menu();
        printf("Enter the product ID or 0 to exit: ");
        scanf("%d", &productID);

        if (productID == 0) break;
        printf("Enter the quantity you want to purchase: ");
        scanf("%d", &quantity);

        select(productID, quantity, &balance, &totalCost);

        int n = productID - 1;

        if (products[n].quantity < Quantity[n]) {
            int purchasedQuantity = Quantity[n] - products[n].quantity;
            float productTotalCost = purchasedQuantity * products[n].price;
            printf("Added to Shopping Cart: %-2d %s for $%.2f\n", purchasedQuantity, products[n].name, productTotalCost);
            productCount++;
        }
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
        printf("                            Total cost: $%.2f\n", totalCost);
    } else printf("Your cart is empty.\n\n");
    printf("\nThank you for using the Vending Machine! Your remaining balance is: $%.2f\n\n\n", balance);

    return 0;
}
