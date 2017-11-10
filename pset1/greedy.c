#include <stdio.h>
#include <cs50.h>

int main(void) {
    int change;
    int quarters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;
    
    do {
        printf("How much change is due?\n");
        change = (get_float() * 100);
    }
    while (change < 0);
    
    // while change is greater than each coin's cent amount
    while (change >= 25) {
        quarters += 1;
        change -= 25;
    }
    while (change >= 10) {
        dimes += 1;
        change -= 10;
    }
    while (change >= 5) {
        nickels += 1;
        change -= 5;
    }
    while (change > 0) {
        pennies += 1;
        change -= 1;
    }
    
    int total = quarters + dimes + nickels + pennies;
    printf("%i\n", total);
}
