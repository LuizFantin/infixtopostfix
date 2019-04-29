#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

//1) Inicializa��o e Libera��o de uma Pilha

// 1.a) fun��o que aloca mem�ria para uma Pilha, inicializando seus campos
//		Entrada: void
//		Sa�da: ponteiro para uma pilha
Stack *createStack()
{
    Stack *ptr;
    if(ptr=(Stack *)malloc(sizeof(Stack))){
        ptr->size=0;
        ptr->first=NULL;
        return ptr;
    }
    return NULL;
}

// 1.b) fun��o que aloca mem�ria para um no, inicializando seus campos
//		Entrada: void
//		Sa�da: ponteiro para uma Node
Node *createNode()
{
    Node *ptr;
    if(ptr=(Node *)malloc(sizeof(Node))){
        ptr->info=NULL;
        ptr->next=NULL;
        return ptr;
    }
    return NULL;
}
// 1.c) fun��o que aloca mem�ria para um elemento de informa��o Info, inicializando seus campos
//		Entrada: inteiro conte�do do elemento de informa��o
//		Sa�da: ponteiro para um Info
Info *createInfoChar(char i)
{
    Info *ptr;
    if(ptr=(Info *)malloc(sizeof(Info))){
        ptr->value=i;
        return ptr;
    }
    return NULL;
}

Info *createInfoFloat(float i)
{
    Info *ptr;
    if(ptr=(Info *)malloc(sizeof(Info))){
        ptr->number=i;
        return ptr;
    }
    return NULL;
}

//1.d) fun��o que libera todo o espa�o de mem�ria usado por uma Pilha
//		Entrada: ponteiro para uma Pilha
//		Sa�da: void
void freeStack(Stack *stack)
{
    Node *ptr;
    if (!stack) return;
    while(stack->first)
    {
        ptr=stack->first->next;
        free(stack->first->info);
        free(stack->first);
        stack->first=ptr;
    }
    free(stack);
}


//2) Informa��es sobre Pilha

// 2.a) Fun��o que verifica se uma Pilha � vazia
//		Entrada: ponteiro para uma Pilha
//		Sa�da: bool (TRUE se a Pilha � vazia, FALSE caso contr�rio
bool isEmptyStack(Stack * stack)
{
    return (!stack || stack->size==0);
}

// 2.b) Fun��o que Imprime o conteudo da Pilha
//		Entrada: ponteiro para uma Pilha
//		Sa�da: bool (TRUE se a Pilha � vazia, FALSE caso contr�rio
void printStack(Stack *stack)
{

    Node *ptr;

    if(isEmptyStack(stack)) return;
    printf("\n TOP[ ");
    ptr=stack->first;

    //inicia do primeiro elemento da lista
    while(ptr != NULL)
    {
      printf("(%d) ",ptr->info->value);
      ptr = ptr->next;
    }
	printf(" ]BOTTOM");
}

// 2.c) Fun��o que verifica o tamanho da Pilha
//		Entrada: ponteiro para uma Pilha
//		Sa�da: inteiro >=0 representando o tamanho da Pilha, -1 caso a Pilha seja nula
int lengthStack(Stack *stack)
{
	if (!stack) return -1;
	return stack->size;
}

//3) Opera��es sobre Pilha

// 3.a) Fun��o que insere um elemento da Pilha (na primeira posi��o)
//		Entrada: ponteiro para uma Pilha
//		Sa�da: bool (TRUE se o elemento foi inserido, FALSE caso contr�rio
bool push(Stack *stack, Info *inf)
{
	Node *ptr;
    if(!stack || !(ptr=createNode())) return false;
    ptr->info=inf;
    ptr->next=stack->first;
    stack->first=ptr;
    stack->size++;
    return true;
}

// 3.b) Fun��o que retira um elemento da Pilha (da primeira posi��o)
//		Entrada: ponteiro para uma Pilha
//		Sa�da: ponteiro para Info com o elemento retirado
Info *pop(Stack *stack)
{
	Node *ptr;
  	Info *inf;
	if (isEmptyStack(stack)) return NULL;
	ptr=stack->first;
	stack->first=ptr->next;
  	inf=ptr->info;
  	free(ptr);
  	stack->size--;
  	return inf;
}

