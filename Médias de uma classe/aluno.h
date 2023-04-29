//protótipos

typedef struct aluno Aluno;

//Média de um aluno
float aluno_media (float n1, float n2);

//Criar um aluno
Aluno* aluno_cria (char nome[], float n1, float n2);

//Exibir dados de aluno
void aluno_exibe (Aluno* a);

//Acessa os dados de um aluno
char* aluno_acessa (Aluno* a);

//Alterar os dados de um aluno
void aluno_altera (Aluno* a);

//Remover um aluno
void aluno_remove (Aluno* a);
