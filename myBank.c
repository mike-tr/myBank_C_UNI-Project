#include "myBank.h"
#include <stdio.h>

typedef enum accountState{
    closed,
    open,
} accountState;

double accounts_deposit[ACCOUNTS] = {0};
accountState accounts_state[ACCOUNTS] = { closed };
int size = 0;
int index = -1;
int current_id = -1;

void printAccountBalance(int index){
    printf("The balance of account number %d is: %.2lf\n", index + FIRST_INDEX, accounts_deposit[index]);
}

boolean getAccount(){
    if(scanf(" %d", current_id) != 1){
        printf("Failed to read the account number\n");
        current_id = -1;
        index = -1;
        return false;
    }else{
        index = current_id - FIRST_INDEX;
        if(index >= ACCOUNTS || current_id < 0){
            printf("Invalid account number\n");
            return false;
        }
        if(accounts_state[index] == closed){
            printf("This account is closed\n");
            return false;
        }
    }
    return true;
}

boolean getAmount(int *amount){
    if(scanf(" %d", amount) != 1){
        printf("Failed to read the amount\n");
        return false;
    }
    return true;
}

void bankShowMenu(){
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

void bankBalanceInquiry(){
    if(getAccount()){
        printAccountBalance(index);
    }
}

void bankDeposit(){
    int amount = 0;
    if(getAccount() && getAmount(&amount)){
        if(amount < 0){
            printf("Cannot deposit a negative amount\n");
            return;
        }
        accounts_deposit[index] += amount;
        printf("The new balance is: %.2lf", accounts_deposit[index]);
    }
}

void bankWithdrawal(){
    int amount = 0;
    if(getAccount() && getAmount(&amount)){
        if(amount < 0){
            printf("Cannot withdraw a negative amount\n");
            return;
        }
        if(amount > accounts_deposit[index]){
            printf("Cannot withdraw more than the balance\n");
            return;
        }
        accounts_deposit[index] -= amount;
        printf("The new balance is: %.2lf", accounts_deposit[index]);
    }
}

void bankOpenAccount(){
    if(size < ACCOUNTS){
        int amount = 0;
        if(getAmount(&amount)){
            if(amount < 0){
                printf("Invalid Amount\n");
                return;
            }
            for(int i = 0; i < ACCOUNTS; i++){
                if(accounts_state[i] == closed){
                    index = i;
                    current_id = index + FIRST_INDEX;
                }
            }
            accounts_state[index] = open;
            accounts_deposit[index] = amount;
            printf("New account number is: %d\n", current_id);
            size++;
        }
    }else{
        printf("Bank is full, cannot open new accounts\n");
    }
}

void bankCloseAccount(){
    if(scanf(" %d", current_id) != 1){
        printf("Failed to read the account number\n");
        current_id = -1;
        index = -1;
        return;
    }else{
        index = current_id - FIRST_INDEX;
        if(index >= ACCOUNTS || current_id < 0){
            printf("Invalid account number\n");
            return;
        }
        if(accounts_state[index] == closed){
            printf("This account is already closed\n");
            return;
        }
        accounts_state[index] = closed;
        accounts_deposit[index] = 0;
        size--;
    }
    return;
}

void bankInterest(){
    int intrest = 0;
    if(scanf(" %d", &intrest)){
        if(intrest < 0){
            printf("Invalid interest rate\n");
            return;
        }
        for(int i = 0; i < ACCOUNTS; i++){
            if(accounts_state[i] == open){
                accounts_deposit[i] *= (1 + (interest / 100.0));
            }
        }
    }else{
        printf("Failed to read the interest rate\n");
    }
}

void bankPrint(){
    for(int i = 0; i < ACCOUNTS; i++){
        if(accounts_state[i] == open){
            printAccountBalance(i);
        }
    }
}
