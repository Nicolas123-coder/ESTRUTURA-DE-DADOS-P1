#include "P1_stack.h"
#include <string.h>

//NICOLAS DE BARROS
//32070837

StaticStack Create_stack()
{
	StaticStack stack =
	{
		0,
		{ " " }							//inicializando a pilha como string vazia
	};
	return stack;
}

bool IsEmpty(const StaticStack& stack)
{
	return stack.count == 0;
}

bool push(StaticStack& stack, string elem)
{
	if (stack.count == TAMANHO)
	{
		return false;
	}

	stack.values[stack.count] = elem;
	++stack.count;

	return true;
}

string pop(StaticStack& stack)
{
	if (IsEmpty(stack))
	{
		return "";
	}

	string temp = stack.values[stack.count - 1];
	stack.values[stack.count - 1] = '\0';
	--stack.count;

	return temp;
}

string top(const StaticStack& stack)
{
	if (IsEmpty(stack))
	{
		return "\0";
	}

	return stack.values[stack.count - 1];
}

int size(const StaticStack& stack)
{
	return sizeof(stack.values) / sizeof(stack.values[0]);
}

int count(const StaticStack& stack)
{
	return stack.count;
}

bool clear(StaticStack& stack)
{
	while (!IsEmpty(stack))
	{
		pop(stack);
	}

	return IsEmpty(stack);
}