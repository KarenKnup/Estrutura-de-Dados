typedef struct no tNo;
typedef struct LDE tLDE;

/*
  Retorna TRUE (1) ou FALSE (0) dependendo se a lista
  simplesmente encadeada {pL} é classificada ou não,
  respectivamente.
*/
int lstDE_isClassif(tLDE *pL);

/*
  Retorna TRUE (1) ou FALSE (0) dependendo se a lista
  simplesmente encadeada {pL} permite ou não repetição,
  respectivamente.
*/
int lstDE_comRepet(tLDE *pL);

/*
  Retorna TRUE (<>0) ou FALSE (0) dependendo se a lista
  simplesmente encadeada {pL} está ou não vazia,
  respectivamente.
*/
int lstDE_isVazia(tLDE *pL);


/*
  Cria e retorna uma lista simplesmente encadeada.
  {isClassif, comRepet} determinam, respectivamente, se
  a lista é classificada e se pode haver repetição de
  elementos. (0 = Não; <>0 = Sim)
*/
tLDE *lstDE_criaLista(int isClassif, int comRepet);

/*
Tenta inserir o ID {id} na lista simplesmente encadeada
  {pL}, retornando TRUE (1) ou FALSE (0) dependendo se a
  operação foi bem-sucedida ou não, respectivamente.

  Possíveis impedidores: memória insuficiente; {id} já
  existe e {pL} não permite repetição; etc.
*/
int lstDE_inclui(tLDE* pL, int id) ;

/*
  Imprime no console os elementos de uma lista
  simplesmente encadeada {pL}.
*/
void lstDE_imprime(tLDE *pL);

/*
  Remove todas as ocorrências do ID {id} na lista
  simplesmente encadeada {pL}, retornando a quantidade
  de instâncias excluídas.
*/
int lstDE_exclui(tLDE *pL, int id);

//Deleta uma lista
void lstDE_destroi(tLDE* pL);