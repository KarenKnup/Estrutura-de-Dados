//Baseado em solução de Lucas Beriba
typedef struct no tNo;
typedef struct LSE tLSE;

/*
  Retorna TRUE (1) ou FALSE (0) dependendo se a lista
  simplesmente encadeada {pL} é classificada ou não,
  respectivamente.
*/
int lstSE_isClassif(tLSE *pL);

/*
  Retorna TRUE (1) ou FALSE (0) dependendo se a lista
  simplesmente encadeada {pL} permite ou não repetição,
  respectivamente.
*/
int lstSE_comRepet(tLSE *pL);

/*
  Retorna TRUE (<>0) ou FALSE (0) dependendo se a lista
  simplesmente encadeada {pL} está ou não vazia,
  respectivamente.
*/
int lstSE_isVazia(tLSE *pL);


/*
  Cria e retorna uma lista simplesmente encadeada.
  {isClassif, comRepet} determinam, respectivamente, se
  a lista é classificada e se pode haver repetição de
  elementos. (0 = Não; <>0 = Sim)
*/
tLSE *lstSE_criaLista(int isClassif, int comRepet);

/*
Tenta inserir o ID {id} na lista simplesmente encadeada
  {pL}, retornando TRUE (1) ou FALSE (0) dependendo se a
  operação foi bem-sucedida ou não, respectivamente.

  Possíveis impedidores: memória insuficiente; {id} já
  existe e {pL} não permite repetição; etc.
*/
int lstSE_inclui(tLSE *pL, int id);

/*
  Imprime no console os elementos de uma lista
  simplesmente encadeada {pL}.
*/
void lstSE_imprime(tLSE *pL);

/*
  Remove todas as ocorrências do ID {id} na lista
  simplesmente encadeada {pL}, retornando a quantidade
  de instâncias excluídas.
*/
int lstSE_exclui(tLSE *pL, int id);