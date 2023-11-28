#include <stdio.h>

// Функция для установки цвета текста
void setColor(char* color) {
    printf("%s", color);
}

int main()
{
    int choice, numDeposits = 0, numWithdrawals = 0;
    float balance = 0.0, amount;

    // Определение цветов для различных элементов интерфейса
    char* blue = "\033[0;34m";   // Синий для "ATM Menu"
    char* green = "\033[0;32m";  // Зелёный для успешных операций
    char* red = "\033[0;31m";    // Красный для неудачных операций
    char* yellow = "\033[0;33m"; // Жёлтый для ввода пользователя
    char* reset = "\033[0m";     // Сброс цвета

    while (1)
    {
        // Вывод меню
        setColor(blue);
        printf("\nATM Menu:\n");
        setColor(yellow);
        printf("1. Deposit\n");
        printf("2. Withdrawal\n");
        printf("3. Display Balance\n");
        printf("0. Exit\n");
        setColor(reset);
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: // Deposit
                printf("Enter deposit amount: ");
                scanf("%f", &amount);

                balance += amount;
                numDeposits++;

                setColor(green);
                printf("Successfully deposited: %.2f\n", amount);
                setColor(reset);
                break;

            case 2: // Withdrawal
                printf("Enter withdrawal amount: ");
                scanf("%f", &amount);

                if (amount > balance)
                {
                    setColor(red);
                    printf("Insufficient balance.\n");
                    setColor(reset);
                }
                else
                {
                    balance -= amount;
                    numWithdrawals++;
                    setColor(green);
                    printf("Successfully withdrawn: %.2f\n", amount);
                    setColor(reset);
                }
                break;

            case 3: // Display Balance
                setColor(green);
                printf("Current Balance: %.2f\n", balance);
                setColor(reset);
                break;

            case 0: // Exit
                setColor(red);
                printf("\nExiting...\n");
                setColor(green);
                printf("Total deposits: %d, Total withdrawals: %d\n", numDeposits, numWithdrawals);
                setColor(reset);
                return 0;

            default: // Invalid choice
                setColor(red);
                printf("Error: Invalid option. Please try again!\n");
                setColor(reset);
        }
    }
    return 0;
}