
#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

struct celula
{
    int valor;
    int linha;
    int coluna;
    struct celula *atras;
    struct celula *frente;
    struct celula *cima;
    struct celula *baixo;
};
typedef struct celula Celula;
/***/

Matriz* cria_matriz()
{
    Matriz* ma = (Matriz*) malloc(sizeof(Matriz));
    if(ma != NULL)
        *ma = NULL;
    printf("\n Matriz criada com sucesso!!\n");
    return ma;
}

/***/
void libera_matriz(Matriz* ma)
{
    if(ma != NULL)
    {
        Celula* no;
        while((*ma) != NULL)
        {
            no = *ma;
            *ma = (*ma)->frente;
            free(no);
        }
        free(ma);
        printf("\n \n  A Matriz foi desalocada com sucesso!! \n \n ");

    }


}
/***/
int cria_celulas_matriz(Matriz* ma, int dim)
{
    if(ma==NULL)
        return 0;

    int i = 0, j = 0, cont = 0;

    Celula *auxl;
    Celula *auxc;

    for(i=0; i<dim; i++)
    {
        cont++;
        Celula* nova = (Celula*) malloc(sizeof(Celula));
        nova->linha = i+1;
        nova->coluna = j+1;
        nova->valor = NULL;
        nova->atras = NULL;
        nova->baixo = NULL;
        nova->cima = NULL;
        nova->frente = NULL;

        if(*ma == NULL)
        {
            *ma = nova;
            auxc = nova;
            auxl = nova;
        }
        else
        {
            nova->cima = auxc;
            auxc->baixo = nova;
            auxc = nova;
            auxl = auxc;
        }

        for(j=1; j<dim; j++)
        {
            cont++;
            Celula* nova = (Celula*) malloc(sizeof(Celula));
            nova->linha = i+1;
            nova->coluna = j+1;
            nova->valor = NULL;

            nova->baixo = NULL;
            nova->cima = NULL;
            nova->frente = NULL;

            nova->atras = auxl;
            auxl->frente = nova;
            auxl = nova;
        }
        j = 0;
    }

    Celula* pf1; //ponteiro fixo na linha 1
    Celula* pf2; //ponteiro fixo na linha 2
    Celula* pm1;    //ponteiro pra percorrer a linha 1
    Celula* pm2;    //ponteiro pra percorrer a linha 2

    pf1 = (*ma);
    pf2 = (*ma)->baixo;
    pm1 = pf1->frente;
    pm2 = pf2->frente;

    for(i=0; i<dim-1; i++)
    {
        for(j=0; j< dim-1; j++)
        {
            pm1->baixo = pm2;
            pm2->cima = pm1;

            pm1 = pm1->frente;
            pm2 = pm2->frente;
        }

        pf1 = pf2;
        if(pf2->baixo != NULL)
            pf2 = pf2->baixo;

        pm1 = pf1->frente;
        pm2 = pf2->frente;
    }

    return 1;
}
/***/
int exibir_matriz(Matriz *ma, int dim)
{
    if(ma == NULL || *ma == NULL)
    {
        return 0;
    }

    Celula *auxL = *ma;
    Celula *auxC = *ma;

    while(auxL->linha <= dim)
    {
        while(auxC->coluna <= dim)
        {
            printf("[%d][%d] = %d\t", auxC->linha, auxC->coluna, auxC->valor);
            if(auxC->frente == NULL)
                break;
            auxC = auxC->frente;
        }

        printf("\n\n");

        if(auxL->baixo == NULL)
            break;
        auxL = auxL->baixo;
        auxC = auxL;
    }

    return 1;
}
/***/
void insere_posicao(Matriz* ma, int d)
{
        int c=0; int l=0;
        printf("\n \n Infome a posicao do valor que deseja armazenar ");
         printf("\n Coluna: ");
        scanf("%d", &c);
         printf("\n Linha: ");
        scanf("%d", &l);

        if((c)>(d)){
            printf(" informe um valor valido para coluna");
            return 0;
        }else
        if((l)>(d)){
            printf(" informe um valor valido para linha");
            return 0;
        }


        Celula* percorre = *ma;

        while(percorre->coluna!=c){
            percorre=percorre->frente;
        }

        while(percorre->linha!=l){
            percorre=percorre->baixo;
        }

        int valorArmazena;
        printf("qual valor deseja armazenar ?");
        scanf("%d", &valorArmazena);
        percorre->valor = valorArmazena;

        //printf("\n \n valor armazenado  com sucesso!! :  %d");
         exibir_matriz(ma, d);

         printf("\n \n ");
}
/***/

void consulta_posicao(Matriz* ma, int d)
{
        int c=0; int l=0;
        printf("\n \n Qual posição deseja verificar ? ");
         printf("\n Coluna: ");
        scanf("%d", &c);
         printf("\n Linha: ");
        scanf("%d", &l);

        if((c)>(d)){
            printf(" informe um valor valido para coluna");
            return 0;
        }else
        if((l)>(d)){
            printf(" informe um valor valido para linha");
            return 0;
        }

       Celula* percorre = *ma;

        while(percorre->coluna!=c){
            percorre=percorre->frente;
        }

        while(percorre->linha!=l){
            percorre=percorre->baixo;}

        printf("\n \n valor eh: %d", percorre->valor);


         printf("\n \n ");
}
/***/

void consulta_valor(Matriz* ma){

    Celula *auxl = *ma;
    Celula *auxc = *ma;
    int cont = 0;
    int valor = 0;

     printf("\n \n informe o valor que deseja procurar ");
     scanf("%d", &valor);

    while(auxl != NULL){
        while(auxc !=NULL){
            if(auxc->valor ==  valor){
                printf("\n [%d][%d] tem o valor %d", auxc->linha, auxc->coluna, valor);
                cont++;
            }

            auxc = auxc->frente;

        }

         auxl = auxl->baixo;
         auxc = auxl;



            }
                if(cont == 0){
                printf(" \n \n NENHUM VALOR ENCONTRADO");
    }
}

/***/
void retorna_vizinhos(Matriz* ma, int d)
{
        int c=0; int l=0;
        printf("\n \n Qual posição deseja verificar a vizinhanca ? ");
         printf("\n Coluna: ");
        scanf("%d", &c);
         printf("\n Linha: ");
        scanf("%d", &l);

        if((c)>(d)){
            printf(" informe um valor valido para coluna");
            return 0;
        }else
        if((l)>(d)){
            printf(" informe um valor valido para linha");
            return 0;
        }

       Celula* percorre = *ma;

        while(percorre->coluna!=c){
            percorre=percorre->frente;
        }

        while(percorre->linha!=l){
            percorre=percorre->baixo;}

        printf("\n \n  a cima do nó: [%d][%d] com o valor : %d ", percorre->cima->linha, percorre->cima->coluna, percorre->cima->valor );
        printf("\n \n  a baixo do nó: [%d][%d] com o valor : %d ", percorre->baixo->linha, percorre->baixo->coluna, percorre->baixo->valor);
        printf("\n \n  a traz do nó: [%d][%d] com o valor : %d ", percorre->atras->linha, percorre->atras->coluna, percorre->atras->valor);
        printf("\n \n  a frente do nó: [%d][%d] com o valor : %d ", percorre->frente->linha, percorre->frente->coluna, percorre->frente->valor);
         printf("\n \n ");

         printf(" passouuuuu aqui");
}
