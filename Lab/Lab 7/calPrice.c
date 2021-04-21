#include<stdio.h>

//Tracy Michaels Lab 7 part 1 #2
//This program asks user for information about an item and displays it's info in a formatted fasion

int main(){

    int item_num, quantity, month, day, year;
    double unit_price;

    //get information
    printf("Enter item number: ");
    scanf("%d", &item_num);
    printf("Enter unit price: ");
    scanf("%lf", &unit_price);
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    printf("Enter purchase date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month, &day, &year);

    double total = (double) unit_price * quantity;

    //display results
    printf("Item\tUnit Price\tQTY\tPurchase Date\tTotal Amount\t\n");
    printf("%-d\t$%9.2lf\t%-d\t%-d/%-d/%-d\t$%11.2lf\t\n", item_num, unit_price, quantity, month, day, year, total);
}