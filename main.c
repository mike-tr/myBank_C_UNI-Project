#include "myBank.h"
#include <stdio.h>

int main() {
    int run = true;
    char command = 0;
    while (run) {
        bankShowMenu();
        // scanf would always work with chars.
        scanf(" %c", &command);
        switch (command) {
        case bank_exit:
            run = false;
            break;
        case bank_open:
            bankOpenAccount();
            break;
        case bank_close:
            bankCloseAccount();
            break;
        case bank_withdrawal:
            bankWithdrawal();
            break;
        case bank_deposit:
            bankDeposit();
            break;
        case bank_printAll:
            bankPrint();
            break;
        case bank_interest:
            bankInterest();
            break;
        case bank_inquiry:
            bankBalanceInquiry();
            break;
        default:
            printf("Invalid transaction type\n");
            break;
        }

        printf("\n");
    }
    return 0;
}
