#ifndef MY_BANK_H
#define MY_BANK_H
#define ACCOUNTS 50
#define FIRST_INDEX 901

void bankShowMenu();
void bankBalanceInquiry();
void bankDeposit();
void bankWithdrawal();
void bankCloseAccount();
void bankInterest();
void bankPrint();

enum bankAction{
    open,
    close,
    deposit,
    withdrawal,
    inquiry,
    interest,
};

#endif