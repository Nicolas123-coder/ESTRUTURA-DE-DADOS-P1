#include "P1_queue.h"
#include "P1_stack.h"
#include <string>

//NICOLAS DE BARROS
//32070837

using namespace std;

StaticQueue Create()
{
	StaticQueue queue =
	{
		Create_stack(), Create_stack()           //cria duas pilhas do tipo StaticStack
	};

	return queue;
}


bool Enqueue(StaticQueue& queue, string elem)    
{
	// Verifica se a fila está cheia.
	if (queue.pilha_A.count == Size(queue))    
	{
		return false;
	}

	push(queue.pilha_A, elem);						//empilhar na primeira pilha e depois empilhar, 								 
	return true;
	queue.pilha_A.count++;
}

string Dequeue(StaticQueue& queue)
{
	if (IsEmpty_queue(queue))
	{
		return "\0";
	} 
	while (!IsEmpty(queue.pilha_A))
	{
		push(queue.pilha_B, top(queue.pilha_A));
		pop(queue.pilha_A);
	}

	return pop(queue.pilha_B);
}


string Front(StaticQueue& queue) 
{
	if (IsEmpty_queue(queue))
	{
		return "\0";
	}
	else
	{
		top(queue.pilha_B);
	}
	return top(queue.pilha_B);
}


int Size(const StaticQueue& queue)
{
	return sizeof(queue.pilha_A.values) / sizeof(queue.pilha_A.values[0]); 
}


int Count(const StaticQueue& queue)
{
	int soma = queue.pilha_A.count + queue.pilha_B.count;

	return soma;
}


bool IsEmpty_queue(const StaticQueue& queue)
{
	return queue.pilha_A.count == 0 && queue.pilha_B.count == 0;
}


bool Clear(StaticQueue& queue)
{
	while (!IsEmpty_queue(queue))
	{
		Dequeue(queue);
	}

	return IsEmpty_queue(queue);
}