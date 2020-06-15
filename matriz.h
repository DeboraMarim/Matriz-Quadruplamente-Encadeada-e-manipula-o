
typedef struct celula* Matriz;

Matriz* cria_matriz();
int cria_celulas_matriz(Matriz* ma, int d);
void libera_matriz(Matriz* ma);
int exibir_matriz(Matriz *ma, int dim);
void insere_posicao(Matriz* ma, int d);
void consulta_posicao(Matriz* ma, int d);
void consulta_valor(Matriz* ma);
void retorna_vizinhos(Matriz* ma, int d);
