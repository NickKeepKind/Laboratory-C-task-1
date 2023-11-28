/* Εργαστηριακή	Άσκηση Εξαμήνου */

#include <stdio.h>

// Function declaration
int ATM();
int ATM_ElseIf();

// Main function
int main()
{
    ATM_Siwtch();
    ATM_ElseIf();

    return 0;
}

// ATM operation implemented via Switch
int ATM_Switch()
{
    int choice, numDeposits = 0, numWithdrawals = 0;
    float balance = 0.0, amount;

    while (1)
    {
        // Displaying the menu
        printf("\nATM Menu:\n");
        printf("1. Deposit\n");
        printf("2. Withdrawal\n");
        printf("3. Display Balance\n");
        printf("0. Exit\n");
        printf("Choose an option: ");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1: // Deposit
                printf("Enter deposit amount: ");
                scanf("%f", &amount);

                balance += amount;
                numDeposits++;
                
                printf("Deposited: %.2f\n", amount);
                break;

            case 2: // Withdrawal
                printf("Enter withdrawal amount: ");
                scanf("%f", &amount);

                if (amount > balance)
                {
                    printf("Insufficient balance.\n");
                }
                else
                {
                    balance -= amount;
                    numWithdrawals++;
                    printf("Withdrawn: %.2f\n", amount);
                }
                break;

            case 3: // Display Balance
                printf("Current Balance: %.2f\n", balance);
                break;

            case 0: // Exit
                printf("Exiting...\n");
                printf("Total deposits: %d, Total withdrawals: %d\n", numDeposits, numWithdrawals);
                return 0;

            default: // Invalid choice
                printf("Error. Try again a valid option!\n");
        }
    }

    return 0;
}

// ATM operation implemented via ElseIf
int ATM_ElseIf()
{
    int choice, numDeposits = 0, numWithdrawals = 0;
    float balance = 0.0, amount;

    while (1)
    {
        // Displaying the menu
        printf("\nATM Menu:\n");
        printf("1. Deposit\n");
        printf("2. Withdrawal\n");
        printf("3. Display Balance\n");
        printf("0. Exit\n");
        printf("Choose an option: ");

        scanf("%d", &choice);

        if (choice == 1) // Deposit
        {
            printf("Enter deposit amount: ");
            scanf("%f", &amount);

            balance += amount;
            numDeposits++;
            
            printf("Deposited: %.2f\n", amount);
        }
        else if (choice == 2) // Withdrawal
        {
            printf("Enter withdrawal amount: ");
            scanf("%f", &amount);

            if (amount > balance)
            {
                printf("Insufficient balance.\n");
            }
            else
            {
                balance -= amount;
                numWithdrawals++;
                printf("Withdrawn: %.2f\n", amount);
            }
        }
        else if (choice == 3) // Display Balance
        {
            printf("Current Balance: %.2f\n", balance);
        }
        else if (choice == 0) // Exit
        {
            printf("Exiting...\n");
            printf("Total deposits: %d, Total withdrawals: %d\n", numDeposits, numWithdrawals);
            return 0;
        }
        else // Invalid choice
        {
            printf("Error. Try again a valid option!\n");
        }
    }

    return 0;
}
