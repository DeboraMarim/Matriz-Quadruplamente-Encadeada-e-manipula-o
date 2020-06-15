#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main()
{
    Matriz* ma = cria_matriz();
    int d,  valor;
    char r;
    int resp =1;


    printf("\n informe a dimensao da matriz: ");
    scanf("%d", &d);

    int dim = d;
    int dime = d;
    int dimen = d;

    cria_celulas_matriz(ma, d);
    exibir_matriz(ma, d);




//menu

while(resp != 0){

       printf("\t INFORME O QUE DESEJA FAZER: ");
       printf("\n Digite 1 para inserir  um valor na matriz");
       printf("\n Digite 2 para retornar um valor da matriz");
       printf("\n Digite 3 para retornar a posicao de um valor na matriz");
       printf("\n Digite 4 para retornar vizinhos");
       printf("\n Digite 5 para visualizar a matriz");
       printf("\n Digite 0 para sair \n");

       scanf("%d", &resp);


       switch (resp){

        case 1:
             insere_posicao(ma, dime);
        break;

         case 2:
            consulta_posicao(ma, dim);
        break;

         case 3:
            consulta_valor(ma);
        break;

         case 4:
             retorna_vizinhos(ma, dimen);
        break;

        case 5:
             exibir_matriz(ma, dime);
        break;


         case 0:

        break;

       }

}

/*DESALOCANDO A MATRIZ */
    libera_matriz(ma);
    return 0;
}
