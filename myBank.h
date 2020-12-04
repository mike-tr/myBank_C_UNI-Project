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

typedef enum boolean {
    true = 1,
    false = 0,
} boolean;

typedef enum bankAction {
    bank_open = 'O',
    bank_close = 'C',
    bank_deposit = 'D',
    bank_withdrawal = 'W',
    bank_inquiry = 'B',
    bank_printAll = 'P',
    bank_interest = 'I',
    bank_exit = 'E',
} bankAction;
#endif