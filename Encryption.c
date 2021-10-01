#include<stdio.h>
#include<stdlib.h>
#include"header.h"
int Encrypt(char fname[]) {
    FILE *fpts, *fptt, *fptu; /*File datat type variables*/
    int rand_num, ch, nav;

    /*Opening the file */
    fpts = fopen(fname, "r"); 
    if(fpts = NULL) {
        (voud) printf("File does not exist or error in opening...!!");
        exit(EXIT_FAILURE);
    }
    fptt = fopen("temp.txt", "w"); 
    if(fptt == NULL) {
        (void)printf("Error in creation of file temp.txt ...!!");
        (void)fclose(fpts);
        exit(EXIT_FAILURE); 
    }
    fptu = fopen("code.txt", "r+"); 
    while ((nav = fgetc(fptu)) != EOF) {
        
    }

    while ((ch=fgetc(fptu)) != EOF){
        rand_num = printRandoms(20, 90);
        ch = ch + rand_num;
        (void)fputc(ch, fptt);
        (void)fprintf(fptu, "%d", rand_num);
    }
    (void)fclose(fpts);
    (void)fclose(fptt);
    fpts = fopen(fname, "w");

    if (fpts == NULL) {
        (void)printf("File does not exist or error in opening ..!!");
        exit(EXIT_FAILURE);
    }
    fptt = fopen("temp.txt", "r"); 
    if(fptt == NULL) {
        (void)printf("File does not exist or Error in opening ..!!");
        (void)printf("\n--------------------------");
        (void)fclose(fpts);
        exit(EXIT_FAILURE);
    }
    while ((ch=fgetc(fptt)) != EOF){
        (void)fputc(ch, fpts);
    }
    (void)fclose(fpts);
    (void)fclose(fptt);
    (void)fclose(fptu);
    return (EXIT_SUCCESS);
}