#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10485760 //10MB = 10 * 1024 * 1024 bytes


int main(void){

    //variavel utilizada para escrever os numeros
    unsigned char num;
    
    
    printf("*** INICIO ***\n");

    //-------------------------------------------------------------------------------------------------------------------------
        
    //PRIMEIRO ARQUIVO - modo aleatorios
    
    //abertura do arquivo e verificacao
    FILE *f1;
    
    f1 = fopen("arq1.bin", "wb");
    
    if(f1 == NULL){
        
        printf("ERRO! Falha na abertura do arquivo 1\n");
        return 1;
    }

    //escreve os numeros no arquivo
    for(int i = 0; i < TAMANHO; i++){

        num = rand() % 256; //numero aleatorio (0 - 255)
        fwrite(&num, sizeof(unsigned char), 1, f1);
    }

    printf("Arquivo1 criado com sucesso\n");

    //fechamento do arquivo
    fclose(f1);

    //-------------------------------------------------------------------------------------------------------------------------
        
    //SEGUNDO ARQUIVO - modo aleatorio restrito

        //abertura do arquivo e verificacao
    FILE *f2;
    
    f2 = fopen("arq2.bin", "wb");
    
    if(f2 == NULL){
        
        printf("ERRO! Falha na abertura do arquivo 2\n");
        return 1;
    }

    //escreve os numeros no arquivo

    for(int i = 0; i < TAMANHO; i++){

        num = rand() % 26; //numero aleatorio (0 - 25)
        fwrite(&num, sizeof(unsigned char), 1, f2);
    }

    printf("Arquivo2 criado com sucesso\n");

    //fechamento do arquivo
    fclose(f2);

    //-------------------------------------------------------------------------------------------------------------------------

    //TERCEIRO ARQUIVO - modo nao aleatorio

        //abertura do arquivo e verificacao
    FILE *f3;
    
    f3 = fopen("arq3.bin", "wb");
    
    if(f3 == NULL){
        
        printf("ERRO! Falha na abertura do arquivo 3\n");
        return 1;
    }

    //escreve os numeros no arquivo
    //padrao: escreve 128 numeros iguais por vez
    num = 0;
    for(int i = 0; i < TAMANHO/128; i++){

        for(int j=0; j < 128; j++){
            fwrite(&num, sizeof(unsigned char), 1, f3);
        }
        
        num++;
    }

    printf("Arquivo3 criado com sucesso\n");

    //fechamento do arquivo
    fclose(f3);

    printf("*** FIM ***\n");
    return 0;
}