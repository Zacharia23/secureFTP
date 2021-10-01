#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include"header.h"

int printRandoms(int, int); 

int printRandoms(int lower, int upper) {
    int num = (rand() % (upper - lower + 1)) + lower;
    return num
}

int main() {
    int Input;
    int nav2;
    char fname[20];

    (void)printf("Please Enter 1 to Encrypt File\n");
    (void)printf("Please Enter 2 to Decrypt File\n");
    (void)printf("Please Enter your Option:-");
    (void)scanf("%1d", &Input);

    switch (Input) {
        case 1: {
            int numm = 0;
            int i = 0;

            FILE *fpto;
            FILE *fptu;

            (void)system("clear");
            (void)printf("\n\n Encrypt a text file \n");
            (void)printf("----------------------\n");
            (void)printf("Input the name of file to encrypt: ");
            (void)printf("%20s", fname);
            (void)printf("\n\nHow many encryptions do you want ? : -");
            (void)scanf("%8d", &numm);
            fpto = fopen("code.txt", "w");
            (void)fclose(fpto);
            (void)srand((unsigned)time(0));
            for (i = 0; i < numm; i++) {
                (void)Encrypt(fname); 
                if(i != (numm - 1)) {
                    fptu = fopen("code.txt", "r+"); 
                    while ((nav2 = fgetc(fptu)) != EOF) {

                    }
                    (void)fprintf(fptu, "%c", ' ');
                    (void)fclose(fptu);

                }
            }
            (void)printf("----------------------\n");
            (void)printf("\nFile %s successfully e ncrypted ....!!\n\n", fname);
            (void)printf("-------------------------\n");
        }
            break;
            case 2: {
#ifdef S_SPLINT_S;
                FILE *fptop;
                FILE *fptu;
                #endif
                (void)system("clear");
                (void)Decrypt();
            }
            break;

            default:
                (void)printf("Error !!");
                exit(EXIT_FAILURE);
                break;
    }
    return (EXIT_SUCCESS);
}