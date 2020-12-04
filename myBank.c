#include "myBank.h"
#include <stdio.h>

typedef enum boolean{
    true = 1,
    false = 0,
} boolean;

typedef enum accountState{
    closed,
    open,
} accountState;

double accounts[ACCOUNTS] = {0};
accountState states[ACCOUNTS] = { closed };
int size = 0;
int current = -1;


boolean getAccount(){
    if(scanf(" %d", &current) != 1){
        printf("Failed to read the account number");
        current = -1;
        return false;
    }
    return true;
}

boolean getAmount(int *amount){
    if(scanf(" %d", amount) != 1){
        
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
        int index = current - FIRST_INDEX;
        if(index >= ACCOUNTS || current < 0){
            printf("Invalid account number\n");
            return;
        }
        if(states[current] == open){
            printf("The balance of account number %d is: %.2lf", current, accounts[index]);
            current = -1;
        }else
        {
            printf("This account is closed");
        }
    }
}

void bankDeposit(){

}

void bankWithdrawal(){

}

void bankCloseAccount(){

}

void bankInterest(){

}

void bankPrint(){

}
