/* TAD: Triangulo (x1,y1) (x2,y2) (x3,y3)*/
/* Tipo exportado */
typedef struct tri Triangulo;

/* Funções exportadas */
/* Função cria - Aloca e retorna um ponto com coordenadas (x,y) */
Triangulo* tri_cria(float x1, float y1,float x2, float y2,float x3, float y3);

/* Função libera - Libera a memória de um triangulo previamente criado */
void tri_libera(Triangulo* p);

/* Função acessa - Retorna os valores das coordenadas ds pontos do triângulo */
void tri_acessa(Triangulo* p, float* x1, float* y1,float* x2, float* y2,float* x3, float* y3);

/* Função atribui - Atribui novos valores às coordenadas ds pontos do triângulo */
void tri_atribui(Triangulo* p, float x1, float y1,float x2, float y2,float x3, float y3);


/* Função getTriangulo - Retorna uma string com os valores do triângulo formato(x,y)*/
char* tri_getTriangulo(Triangulo* p);

/* Função exibe -Escreve na tela o triangulo */
void tri_exibe(Triangulo* p);

/* Função clona -recebe um tri e retorna um novo tri com os mesmos valores do tri recebido*/
Triangulo* tri_clona(Triangulo* p);
/* Função perimetro -recebe um tri e retorna o perimetro*/
float tri_perimetro(Triangulo* p);
/* Função area -recebe um tri e retorna a area*/
float tri_area(Triangulo* p);