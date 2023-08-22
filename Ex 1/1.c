#include <stdio.h>

int main()
{
    // declaring necessary variables
    float bus_price;
    float taxi_price;
    float money;
    int selection;

    // taking user input for bus ticket, taxi ticket and their balance
    printf("Enter price for bus ticket (euros):");
    scanf("%f", &bus_price);

    printf("Enter price for taxi trip (euros):");
    scanf("%f", &taxi_price);

    printf("Enter how much money you have (euros):");
    scanf("%f", &money);

    while (money >= bus_price)
    {
        // diplaying bus and taxi price, user balance and taking user input for choice of transport
        printf("\n(1) Bus: %.2f euros (2) Taxi: %.2f euros\nYour balance is: %.2f euros\nWhat do you want to take?:", bus_price, taxi_price, money);
        scanf("%d", &selection);

        switch (selection) {
            case 1:
                if (money < bus_price)
                {
                    printf("\nYou cannot travel with the bus, please walk.\n");
                    break;
                }
                money -= bus_price;
                printf("\nTaking the bus.\n");
                break;

            case 2:
                if (money < taxi_price)
                {
                    printf("\nYou cannot travel with the taxi, please take the bus or walk.\n");
                    break;
                }
                money -= taxi_price;
                printf("\nTaking the taxi.\n");
                break;

            default:
                // if choice is anything other than 1 or 2 then gives this message:
                printf("\nInvalid selection. Please choose 1 for the bus or 2 for the taxi.\n");
                break;
        }
    }

    if (money < bus_price && money < taxi_price)
    {
        // gives this message when user has no balance for either form of transport:
        printf("\nYou don't have enough money for either option. Please walk.\n");
    }

    return 0;
}
