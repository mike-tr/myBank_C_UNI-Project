#include "myBank.h"
#include <stdio.h>

typedef enum accountState {
    closed,
    open,
} accountState;

double accounts_deposit[ACCOUNTS] = {0};
accountState accounts_state[ACCOUNTS] = {closed};
int size = 0;
int account_index = -1;
int current_id = -1;

void printAccountBalance(int index) {
    printf("The balance of account number %d is: %.2lf\n", index + FIRST_INDEX, accounts_deposit[index]);
}

boolean getAccount() {
    printf("Please enter account number: ");
    if (scanf(" %d", &current_id) != 1) {
        printf("Failed to read the account number\n");
        current_id = -1;
        account_index = -1;
        return false;
    } else {
        account_index = current_id - FIRST_INDEX;
        if (account_index >= ACCOUNTS || current_id < 0) {
            printf("Invalid account number\n");
            return false;
        }
        if (accounts_state[account_index] == closed) {
            printf("This account is closed\n");
            return false;
        }
    }
    return true;
}

boolean getAmount(int *amount, char *message) {
    printf("%s", message);
    if (scanf(" %d", amount) != 1) {
        printf("Failed to read the amount\n");
        return false;
    }
    return true;
}

void bankShowMenu() {
    printf("Please choose a transaction type:\n");
    printf(" O-Open Account\n");
    printf(" B-Balance Inquiry\n");
    printf(" D-Deposit\n");
    printf(" W-Withdrawal\n");
    printf(" C-Close Account\n");
    printf(" I-Interest\n");
    printf(" P-Print\n");
    printf(" E-Exit\n");
}

void bankBalanceInquiry() {
    if (getAccount()) {
        printAccountBalance(account_index);
    }
}

void bankDeposit() {
    int amount = 0;
    if (getAccount() && getAmount(&amount, "Please enter amount for deposit: ")) {
        if (amount < 0) {
            printf("Cannot deposit a negative amount\n");
            return;
        }
        accounts_deposit[account_index] += amount;
        printf("The new balance is: %.2lf\n", accounts_deposit[account_index]);
    }
}

void bankWithdrawal() {
    int amount = 0;
    if (getAccount() && getAmount(&amount, "Please enter the amount to withdraw: ")) {
        if (amount < 0) {
            printf("Cannot withdraw a negative amount\n");
            return;
        }
        if (amount > accounts_deposit[account_index]) {
            printf("Cannot withdraw more than the balance\n");
            return;
        }
        accounts_deposit[account_index] -= amount;
        printf("The new balance is: %.2lf\n", accounts_deposit[account_index]);
    }
}

void bankOpenAccount() {
    if (size < ACCOUNTS) {
        int amount = 0;
        if (getAmount(&amount, "Please enter amount for deposit: ")) {
            if (amount < 0) {
                printf("Invalid Amount\n");
                return;
            }
            for (int i = 0; i < ACCOUNTS; i++) {
                if (accounts_state[i] == closed) {
                    account_index = i;
                    current_id = account_index + FIRST_INDEX;
                    break;
                }
            }
            accounts_state[account_index] = open;
            accounts_deposit[account_index] = amount;
            printf("New account number is: %d\n", current_id);
            size++;
        }
    } else {
        printf("Bank is full, cannot open new accounts\n");
    }
}

void bankCloseAccount() {
    printf("Please enter account number: ");
    if (scanf(" %d", &current_id) != 1) {
        printf("Failed to read the account number\n");
        current_id = -1;
        account_index = -1;
        return;
    } else {
        account_index = current_id - FIRST_INDEX;
        if (account_index >= ACCOUNTS || current_id < 0) {
            printf("Invalid account number\n");
            return;
        }
        if (accounts_state[account_index] == closed) {
            printf("This account is already closed\n");
            return;
        }
        accounts_state[account_index] = closed;
        accounts_deposit[account_index] = 0;
        size--;
        printf("Closed account number %d\n", current_id);
    }
    return;
}

void bankInterest() {
    int intrest = 0;
    printf("Please enter interest rate: ");
    if (scanf(" %d", &intrest)) {
        if (intrest < 0) {
            printf("Invalid interest rate\n");
            return;
        }
        for (int i = 0; i < ACCOUNTS; i++) {
            if (accounts_state[i] == open) {
                accounts_deposit[i] *= (1 + (intrest / 100.0));
            }
        }
    } else {
        printf("Failed to read the interest rate\n");
    }
}

void bankPrint() {
    for (int i = 0; i < ACCOUNTS; i++) {
        if (accounts_state[i] == open) {
            printAccountBalance(i);
        }
    }
}
