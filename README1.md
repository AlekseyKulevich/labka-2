# labka-2
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
const float windowSquare = 2.15 * 1.5;
const float doorSquare = 0.7 * 2.15;
const float windowPrice = 100.0;
const float doorPrice = 150.0;
const float coefficient = 0.15;

void numberOfWindows(int* number)
{
    scanf_s("%d", number);
}

void numberOfBalconies(int* number)
{
    scanf_s("%d", number);
}

void numberOfFloors(int* number)
{
    scanf_s("%d", number);
}

void calculate(int numberOfWindows, int numberOfBalcony, int numberOfFloors)
{
    printf("Glass square: %f\n", numberOfWindows * windowSquare);
    printf("Glass price: %f\n", numberOfWindows * windowPrice);
    printf("Doors price: %f\n", numberOfBalcony * doorPrice);
    float allowance = 0;
    if (numberOfFloors > 1)
        allowance = (numberOfBalcony * doorPrice + numberOfWindows * windowPrice) * coefficient;
    printf("Allowance: %f\n", allowance);
}

void totalPrice(int numberOfWindows, int numberOfBalcony, int numberOfFloors)
{
    float price = (numberOfBalcony * doorPrice + numberOfWindows * windowPrice);
    if (numberOfFloors > 1)
        price += price * coefficient;
    printf("Total price: %f\n", price);
}

void companyInfo()
{
    printf("Directed by company\nPhone number: +3754422814\n");
}

void close()
{
    exit(0);
}

int main()
{
    int numberOfWindow = 0, numberOfBalcony = 0, numberOfFloor = 0;
    while (1)
    {
        system("cls");
        printf("1.numberOfWindows\n2.NumberOfBalconies\n3.NumberOfFloors\n4.Calculate\n5.Total price\n6.Company Info\n7.Close\n");
        int choose;
        while (!scanf_s("%d", &choose))
        {
         printf("Write number\n");
         rewind(stdin);
        }
        switch (choose)
        {
        case 1:
            numberOfWindows(&numberOfWindow);
            break;
        case 2:
            numberOfBalconies(&numberOfBalcony);
            break;
        case 3:
            numberOfFloors(&numberOfFloor);
            break;
        case 4:
            calculate(numberOfWindow, numberOfBalcony, numberOfFloor);
            _getch();
            break;
        case 5:
            totalPrice(numberOfWindow, numberOfBalcony, numberOfFloor);
            _getch();
            break;
        case 6:
            companyInfo();
            _getch();
            break;
        case 7:
            close();
            break;

        }
    }
    
}
