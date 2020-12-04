#include <stdio.h>
#include "myBank.h"

int main(){
    int run = true;
    char command = 0;
    while (run)
    {
        bankShowMenu();
        // scanf would always work with chars.
        scanf(" %c", command);
        switch (command)
        {
        case exit:
            run = false;
            break;
        case open: 
            bankOpenAccount();
            break;
        case close:
            bankCloseAccount();
            break;
        case withdrawal:
            bankWithdrawal();
            break;
        case deposit:
            bankDeposit();
            break;
        case printAll:
            bankPrint();
            break;
        case interest:
            bankInterest();
            break;
        case inquiry:
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


