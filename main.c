#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BankAccount {
    int accNo;
    char name[100];
    float balance;
};

struct BankAccount accounts[100];
int totalAccounts = 0;

void createAccount() {
    printf("\n--- Create Account ---\n");
    printf("Enter Account Number: ");
    scanf("%d", &accounts[totalAccounts].accNo);
    printf("Enter Name: ");
    scanf(" %[^\n]", accounts[totalAccounts].name);  // accepts full name with spaces
    printf("Enter Initial Deposit: ");
    scanf("%f", &accounts[totalAccounts].balance);
    printf("Account Created Successfully!\n");
    totalAccounts++;
}

void showAllAccounts() {
    printf("\n--- All Accounts ---\n");
    for (int i = 0; i < totalAccounts; i++) {
        printf("Acc No: %d | Name: %s | Balance: ₹%.2f\n",
               accounts[i].accNo,
               accounts[i].name,
               accounts[i].balance);
    }
}

void deposit() {
    int acc;
    float amount;
    printf("\nEnter Account Number: ");
    scanf("%d", &acc);

    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].accNo == acc) {
            printf("Enter Amount to Deposit: ");
            scanf("%f", &amount);
            accounts[i].balance += amount;
            printf("Deposit Successful! New Balance: ₹%.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account Not Found!\n");
}

void withdraw() {
    int acc;
    float amount;
    printf("\nEnter Account Number: ");
    scanf("%d", &acc);

    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].accNo == acc) {
            printf("Enter Amount to Withdraw: ");
            scanf("%f", &amount);
            if (amount > accounts[i].balance) {
                printf("Insufficient Balance!\n");
            } else {
                accounts[i].balance -= amount;
                printf("Withdrawal Successful! New Balance: ₹%.2f\n", accounts[i].balance);
            }
            return;
        }
    }
    printf("Account Not Found!\n");
}

void menu() {
    int choice;
    do {
        printf("\n\n------ BANK MENU ------\n");
        printf("1. Create Account\n");
        printf("2. Show All Accounts\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: showAllAccounts(); break;
            case 3: deposit(); break;
            case 4: withdraw(); break;
            case 5: printf("Exiting... Thank you!\n"); break;
            default: printf("Invalid Choice!\n");
        }

    } while (choice != 5);
}

int main() {
    menu();
    return 0;
}
