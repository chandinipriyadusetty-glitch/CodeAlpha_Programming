#include <stdio.h>
#include <stdlib.h>

struct Account {
    int accountNumber;
    char name[50];
    float balance;
};

void createAccount();
void deposit();
void withdraw();
void checkBalance();

int main() {
    int choice;

    while (1) {
        printf("\n===== BANK ACCOUNT MANAGEMENT SYSTEM =====\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Balance Enquiry\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                printf("Thank You!\n");
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    }
}

void createAccount() {
    FILE *fp = fopen("bank.dat", "wb");
    struct Account a;

    printf("Enter Account Number: ");
    scanf("%d", &a.accountNumber);

    printf("Enter Account Holder Name: ");
    scanf(" %[^\n]", a.name);

    printf("Enter Initial Balance: ");
    scanf("%f", &a.balance);

    fwrite(&a, sizeof(a), 1, fp);
    fclose(fp);

    printf("Account Created Successfully!\n");
}

void deposit() {
    FILE *fp = fopen("bank.dat", "rb+");
    struct Account a;
    float amount;

    fread(&a, sizeof(a), 1, fp);

    printf("Enter Deposit Amount: ");
    scanf("%f", &amount);

    a.balance += amount;

    rewind(fp);
    fwrite(&a, sizeof(a), 1, fp);
    fclose(fp);

    printf("Deposit Successful!\n");
}

void withdraw() {
    FILE *fp = fopen("bank.dat", "rb+");
    struct Account a;
    float amount;

    fread(&a, sizeof(a), 1, fp);

    printf("Enter Withdrawal Amount: ");
    scanf("%f", &amount);

    if (amount > a.balance) {
        printf("Insufficient Balance!\n");
    } else {
        a.balance -= amount;
        rewind(fp);
        fwrite(&a, sizeof(a), 1, fp);
        printf("Withdrawal Successful!\n");
    }

    fclose(fp);
}

void checkBalance() {
    FILE *fp = fopen("bank.dat", "rb");
    struct Account a;

    if (fp == NULL) {
        printf("No Account Found!\n");
        return;
    }

    fread(&a, sizeof(a), 1, fp);

    printf("\nAccount Number : %d\n", a.accountNumber);
    printf("Account Holder : %s\n", a.name);
    printf("Current Balance: %.2f\n", a.balance);

    fclose(fp);
}