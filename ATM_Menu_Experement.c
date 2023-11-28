#include <stdio.h>

void displayMenu();
void printSeparator();

void processChoice(int choice, float *balance, int *numDeposits, int *numWithdrawals);

void performDeposit(float *balance, int *numDeposits);
void performWithdrawal(float *balance, int *numWithdrawals);
void displayBalance(float balance);
void displaySummary(int numDeposits, int numWithdrawals);
void displayError();


int main()
{
    int choice, numDeposits = 0, numWithdrawals = 0;
    float balance = 0.0;

    while (1)
    {
        displayMenu();

        printf("Choose an option: ");
        scanf("%d", &choice);

        printSeparator();
        processChoice(choice, &balance, &numDeposits, &numWithdrawals);

        if (choice == 0) break;
    }

    return 0;
}

void processChoice(int choice, float *balance, int *numDeposits, int *numWithdrawals)
{
    switch (choice)
    {
        case 1: 
            performDeposit(balance, numDeposits);
            break;

        case 2: 
            performWithdrawal(balance, numWithdrawals);
            break;

        case 3: 
            displayBalance(*balance);
            break;

        case 0: 
            displaySummary(*numDeposits, *numWithdrawals);
            break;

        default: 
            displayError();
    }
}

void displayMenu()
{
    printf("\n\033[1;36mATM Menu:\033[0m\n");
    printSeparator();
    printf("| 1. Deposit        |\n");
    printf("| 2. Withdrawal     |\n");
    printf("| 3. Display Balance|\n");
    printf("| 0. Exit           |\n");
    printSeparator();
}

void performDeposit(float *balance, int *numDeposits)
{
    float amount;

    printf("| Enter deposit amount: ");
    scanf("%f", &amount);

    *balance += amount;
    (*numDeposits)++;

    printf("| Deposited: \033[1;32m%.2f\033[0m\n", amount);
    printSeparator();
}

void performWithdrawal(float *balance, int *numWithdrawals)
{
    float amount;

    printf("| Enter withdrawal amount: ");
    scanf("%f", &amount);

    printSeparator();
    if (amount > *balance)
    {
        printf("| \033[1;31mInsufficient balance.\033[0m\n");
    }
    else
    {
        *balance -= amount;
        (*numWithdrawals)++;
        printf("| Withdrawn: \033[1;32m%.2f\033[0m\n", amount);
    }
    printSeparator();
}

void displayBalance(float balance)
{
    printf("| Current Balance: ");

    if (balance <= 0)
    {
        printf("\033[1;31m%.2f\033[0m\n", balance);
    }
    else
    {
        printf("\033[1;32m%.2f\033[0m\n", balance);
    }
    printSeparator();
}

void displaySummary(int numDeposits, int numWithdrawals)
{
    printf("Exiting...\n");
    printSeparator();
    printf("| Total deposits: %d, Total withdrawals: %d |\n", numDeposits, numWithdrawals);
    printSeparator();
}

void displayError()
{
    printf("| \033[1;31mError. Try again a valid option!\033[0m\n");
    printSeparator();
}

void printSeparator()
{
    printf("+--------------------+\n");
}
