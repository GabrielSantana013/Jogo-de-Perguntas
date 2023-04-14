#include "stdio.h"
#include "ctype.h"
#include "locale.h"
#include "string.h"
#include "windows.h"

int main(){
    setlocale(LC_ALL, "");
    char Questions[][100] = { 
    "1. Qual é a capital do Brasil?: ",
    "2. Como se chama o primeiro presidente do Brasil?: ",
    "3. Qual é o nome do maior animal terrestre vivo atualmente?: "};

    char Alternativas[][100] = {
    "A. Rio de Janeiro", "B. São Paulo","C. Brasilia","D. Santos",
    "A. Dom Pedro Primeiro","B. Marechal Deodoro da Fonseca","C. Lula","D. Bolsonaro",
    "A. Elefante", "B. Girafa","C. Jubarte","D. Rinoceronte"};

    char Corretas [3] = {'C', 'B', 'A'};

    int ndquestoes = sizeof(Questions)/sizeof(Questions[0]);

    char resposta[100];
    int pontuacao = 0;

    printf("Quiz Game!\n");

    for(int i=0; i < ndquestoes; i++){
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("%s\n", Questions[i]);
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

        for(int j = (i*4); j < (i*4)+4 ; j++){
            printf("%s\n", Alternativas[j]);
        }

        printf("Resposta: ");
        scanf("%s", &resposta);
        resposta[0] = toupper(resposta[0]);
        fflush(stdin);
        if(strlen(resposta) != 1)
        {
            printf("Resposta inválida, por favor pressione qualquer tecla para continuar\n");
            getchar();
            i--;
            system("cls");
            continue;
            
        }
        
        while (resposta[0] != 'A' && resposta[0] != 'B' && resposta[0] != 'C' && resposta[0] != 'D')
        {

            printf("Resposta inválida, por favor digite (A),(B),(C) ou (D)\n");
            scanf("%s", &resposta);
            resposta[0] = toupper(resposta[0]);
            fflush(stdin);
            
            
        }

        if(resposta[0] == Corretas[i])
        {
            printf("Correto!\n");
            pontuacao++;
        }
        else
        {
            printf("Errado :( \n");
        }
    }

    printf("Você acertou %d questões de %d.\n", pontuacao, ndquestoes);
    fflush(stdin);
    printf("Pressione enter para finalizar...");
    getchar();

return 0;
}