#ifndef __STACK_H__
#define __STACK_H__

// Defini��o da Estrutura de Dados PILHA

typedef struct
{
	char value;
	float number;
}Info;
typedef struct tnode
{
	struct tnode *next;
	Info *info;
}Node;
typedef struct
{
	int size;
	Node *first;
}Stack;

// Defini��o das assinaturas das fun��es sobre o TAD PILHA

//1) Inicializa��o e Libera��o de uma Pilha

// 1.a) fun��o que aloca mem�ria para uma Pilha, inicializando seus campos
//		Entrada: void
//		Sa�da: ponteiro para uma pilha
Stack *createStack();

// 1.b) fun��o que aloca mem�ria para um no, inicializando seus campos
//		Entrada: void
//		Sa�da: ponteiro para uma Node
Node *createNode();

// 1.c) fun��o que aloca mem�ria para um elemento de informa��o Info, inicializando seus campos
//		Entrada: inteiro conte�do do elemento de informa��o
//		Sa�da: ponteiro para um Info
Info *createInfoChar(char i);

Info *createInfoInt(int i);

//1.d) fun��o que libera todo o espa�o de mem�ria usado por uma Pilha
//		Entrada: ponteiro para uma Pilha
//		Sa�da: void
void freeStack(Stack *stack);

//2) Informa��es sobre Pilha

// 2.a) Fun��o que verifica se uma Pilha � vazia
//		Entrada: ponteiro para uma Pilha
//		Sa�da: bool (TRUE se a Pilha � vazia, FALSE caso contr�rio
bool isEmptyStack(Stack * stack);

// 2.b) Fun��o que Imprime o conteudo da Pilha
//		Entrada: ponteiro para uma Pilha
//		Sa�da: bool (TRUE se a Pilha � vazia, FALSE caso contr�rio
void printStack(Stack *stack);

// 2.c) Fun��o que verifica o tamanho da Pilha
//		Entrada: ponteiro para uma Pilha
//		Sa�da: inteiro >=0 representando o tamanho da Pilha, -1 caso a Pilha seja nula
int lengthStack(Stack *stack);

//3) Opera��es sobre Pilha

// 3.c) Fun��o que insere um elemento da Pilha (na primeira posi��o)
//		Entrada: ponteiro para uma Pilha
//		Sa�da: bool (TRUE se o elemento foi inserido, FALSE caso contr�rio
bool push(Stack *stack, Info *inf);

// 3.c) Fun��o que retira um elemento da Pilha (da primeira posi��o)
//		Entrada: ponteiro para uma Pilha
//		Sa�da: ponteiro para Info com o elemento retirado
Info *pop(Stack *stack);


#endif // __STACK_H__
