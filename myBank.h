#ifndef MY_BANK_H
#define MY_BANK_H
#define ACCOUNTS 50
#define FIRST_INDEX 901

void bankShowMenu();
void bankBalanceInquiry();
void bankDeposit();
void bankWithdrawal();
void bankOpenAccount();
void bankCloseAccount();
void bankInterest();
void bankPrint();

typedef enum boolean{
    true = 1,
    false = 0,
} boolean;

typedef enum bankAction{
    open = 'O',
    close = 'C',
    deposit = 'D',
    withdrawal = 'W',
    inquiry = 'B',
    printAll = 'P',
    interest = 'I',
    exit = 'E',
} bankAction;
#endif