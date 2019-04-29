#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "stack.c"

#define SIZE 200

void infixToPostfix(char infix[], char postfix[])
{
	int count = 0;
	Stack *pilha = createStack();
	int i=0;

	push(pilha,createInfoChar('('));

	while(infix[i]!='\0')
	{

		if(infix[i]=='\n')
			infix[i] = ')';

		// Caso encontre um parenteses abrindo, empilha ele.
		if(infix[i] == '(')
			push(pilha,createInfoChar('('));


		//Caso seja um operando, já coloca ele na expressão pós fixa.
		else if((infix[i] != '+')&&(infix[i] != '/')&&(infix[i] != '*')&&(infix[i] != '-')&&(infix[i] != '%')&&(infix[i] != ')'))
		{
			postfix[count] = infix[i];
			count++;
		}
		else if(infix[i] != ')')
		{
			if(infix[i] == '+' || infix[i] == '-')
			{
				while(pilha->first->info->value != '(')
				{
					postfix[count] = pop(pilha)->value;
					count++;
				}
			}
			else
			{
				while(pilha->first->info->value != '+' && pilha->first->info->value != '-' && pilha->first->info->value != '(')
				{
					postfix[count] = pop(pilha)->value;
					count++;
				}
			}
			push(pilha,createInfoChar(infix[i]));

		}

		//Caso o caracter seja um parenteses fechando ou é a ultima posição da expressão infixa, vai desempilhando
		else
		{
			while(pilha->first->info->value != '(')
			{
				postfix[count]=pop(pilha)->value;
				count++;
			}
			free(pop(pilha));
		}
		postfix[count] = '\0';

        i++;
	}


}

float avaliarPosFixa(char *postfix)
{
    int i=0;
    Stack *pilha = createStack();
    while(postfix[i]!='\0')
    {


        if(postfix[i]!='+' && postfix[i]!='*' && postfix[i]!='%' && postfix[i]!='/' && postfix[i]!='-')
        {
            float valor;
            valor = (float)postfix[i] - 48;
            if(valor<0 || valor>9)
            {
                printf("Por favor, entre com o componente %c\n",postfix[i]);
                scanf("%f",&valor);
            }
            push(pilha,createInfoFloat(valor));
        }
        else
        {
            float termo1 = pop(pilha)->number;
            float termo2 = pop(pilha)->number;

            if(postfix[i] == '+')
            {
                termo1 = termo1+termo2;
            }
            else if(postfix[i] == '-')
            {
                termo1 = termo2-termo1;
            }
            else if(postfix[i] == '*')
            {
                termo1 = termo1*termo2;
            }
            else if(postfix[i] == '/')
            {
                termo1 = termo2/termo1;
            }
            else
            {
                termo1 = fmod(termo2,termo1);
            }
            push(pilha,createInfoFloat(termo1));
        }
        i++;
    }
    return pop(pilha)->number;
}

void main()
{
	char infix[SIZE], postfix[SIZE];
	float result;

	printf("Entre com a expressao infixa\n");
	fgets(infix,SIZE,stdin);

    printf("Expressao infixa: %s\n",infix);

	infixToPostfix(infix,postfix);

	printf("Expressao pos fixa: %s\n",postfix);
	result = avaliarPosFixa(postfix);

	printf("Resultado: %.2f\n",result);

	return;
}

