#include<stdio.h>
#include<math.h>

int main(){
    int decision;
    long long num;

    printf("This program converts decimals to binary and vice-versa\n");
    printf("what type of number would you like to conver?\n");
    printf("type 1 for decimal or 2 for binary:\n");
    scanf("%d", &decision);

    switch(decision){
        case 1:
            printf("please enter Decimal number to convert to Binary:\n");
            scanf("%lld", &num);

            int binRemainder;
            int place = 1;
            long long binNum = 0;
            long long tempDec = num;
            while (tempDec >0){
                binRemainder = tempDec % 2;
                tempDec /= 2;
                binNum += (binRemainder * place);
                place *= 10;
            }

            printf("%lld in binary is: %lld\n", num, binNum);
            break;
        case 2:
            printf("please enter Binary number to convert to Decimal:\n");
            scanf("%lld", &num);

            int decNum = 0;
            int exp = 0;
            int decRemainder;
            long long tempBin = num;

            while (tempBin > 0){
                decRemainder = tempBin % 10;
                decNum += decRemainder * (pow(2, exp));
                exp += 1;
                tempBin /= 10;
            }

            printf("%lld in Decimal is: %d\n", num, decNum);
    }
    return 0;
}