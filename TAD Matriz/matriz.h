/* TAD: Matriz m por n (m e n >= 1)*/
/* Tipo Exportado */
typedef struct matriz Matriz;
/* Funções Exportadas */
/* Função mat_cria - Aloca e retorna matriz m por n */
Matriz* mat_cria (int m, int n);
/* Função mat_libera - Libera a memória de uma matriz */
void mat_libera (Matriz* mat); 
/* Função mat_acessa - Retorna o valor do elemento [i][j] */
float mat_acessa (Matriz* mat, int i, int j);
/* Função mat_atribui - Atribui valor ao elemento [i][j] */
void mat_atribui (Matriz* mat, int i, int j, float v);
/* Função mat_linhas - Retorna o no. de linhas da matriz */
int mat_linhas (Matriz* mat);
/* Função mat_colunas - Retorna o no. de colunas da matriz */
int mat_colunas (Matriz* mat);
/* Função mat_exibe - Imprime a matriz */
void mat_exibe(Matriz* mat);
/* Função mat_multiplica - retorna a matriz resutante da multiplicação das 2 matrizes recebidas */
Matriz* mat_multiplica (Matriz* mA, Matriz* mB) ;
/* Função mat_soma - retorna a matriz resutante da soma das 2 matrizes recebidas */
Matriz* mat_soma (Matriz* mA, Matriz* mB) ;
/* Função mat_subtrai - retorna a matriz resutante da subtração das 2 matrizes recebidas */
Matriz* mat_subtrai (Matriz* mA, Matriz* mB) ;
/* Função mat_somaLinha - Retorna a soma dos elementos da linha recebida */
float mat_somaLin (Matriz* mat, int l);
/* Função mat_somaCol - Retorna a soma dos elementos da coluna recebida */
float mat_somaCol (Matriz* mat, int c);
