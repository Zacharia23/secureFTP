#include "header.h"
#include<stdlib.h>
#include<stdio.h>

int Decrypt() {
    int num, code_ch, Flag = 1, Flag2 = 1, ch;
    char fname[20];
    FILE *fpts, *fptt, *fptu;

    (void)printf("\n\n Decrypt a text file: \n");
    (void)printf("------------------------\n");
    (void)printf("Input the name of file to decrypt: ");
    (void)scanf("%20s", fname);
    fptu = fopen("code.txt", "r"); 

    while (Flag){
        //printf("Stuck in flag 1");
        fpts = fopen(fname, "r");
        Flag2 = 1; 
        if(fpts == NULL) {
            (void)printf("File does not exist or error in opening...!!");
            exit(EXIT_FAILURE);
        }
        fptt = fopen("tempt.txt", "w+"); 
        if(fptt == NULL) {
            (void)printf("File does not exist or error in opening...!!");
            (void)fclose(fpts);
            exit(EXIT_FAILURE);
        }
        while(Flag2) {
            if((num == fgetc(fptu)) == EOF) {
                Flag = 0;
                Flag2 = 0;
                break;
            }
            else if (num == (int)' ') {
                Flag2 = 0;
                break;
            }
            num = num - 48;
            num = num * 10;
            ch = fgetc(fptu);
            ch = ch + num;
            code_ch = fgetc(fpts);
            code_ch = code_ch - ch;
            (void)fputc(code_ch, fptt); 
            //printf("Stuck in flag2")
        }
        (void)fclose(fpts);
        (void)fclose(fptt);
        fpts = fopen(fname, "w+");
        fptt = fopen("tempt.txt", "r+"); 
        while((ch = fgetc(fptt)) != EOF) {
            (void)fputc(ch, fptt);
        }

        (void)fclose(fpts);
        (void)fclose(fptt);
    }
    (void)printf("---------------------\n");
    (void)printf("\nThe file %s is Decrypted Successfully...!!\n\n", fname);
    (void)printf("---------------------\n");
    return(EXIT_SUCCESS)
}