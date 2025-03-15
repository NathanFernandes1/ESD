typedef struct conj Conjunto;

Conjunto * conj_cria(void); // cria um conjunto de numeros inteiros vazio

int conj_busca(Conjunto *c , int num);

void conj_exibe(Conjunto *c); //exibe um conjunto de numeros inteiros

Conjunto * conj_remove(Conjunto *c,int num); //remove um elemento de um conjunto de inteiros. Se o elemento nao existir, retornar o conjunto intacto

Conjunto *conj_uniao(Conjunto *c, Conjunto *c2); //cria o conjunto que e dado pela uniao dos dois conjuntos enviados como parametro

Conjunto *conj_intersecao(Conjunto *c, Conjunto *c2); 
//cria o conjunto que e dado pela intersecao dos dois conjuntos enviados como parametro

Conjunto * conj_insere(Conjunto *c,int num); //insere um novo elemento num conjunto ja criado