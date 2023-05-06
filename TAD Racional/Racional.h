typedef  struct rac   Racional;

// funções exportadas
// cria um número Racional
Racional* rac_cria(int x, int y);
// Destrói um número Racional criado
void rac_libera(Racional* x);
// soma dois racionais
Racional*  rac_add(Racional* x, Racional* y);
// subtrai dois racionais
Racional*  rac_sub(Racional* x, Racional* y);
// Multiplica dois racionais
Racional* rac_mul(Racional* x, Racional* y);
// divide dois racionais
Racional* rac_divide(Racional* x, Racional *y);
//retorna uma string que representa o Racional
char * rac_exibe(Racional* x);
//verifica se dois numeros racionais são iguais
int   rac_iguais(Racional* x, Racional* y);
