#pragma once
#include <string>
#ifndef STACK_2_H
#define STACK_1_H
#define TAMANHO 8

using namespace std;

//NICOLAS DE BARROS
//32070837

struct  StaticStack
{
	int count;
	string values[TAMANHO];               //usando string para refazer a lista 3.
};

StaticStack Create_stack();

bool IsEmpty(const StaticStack &stack);

bool push(StaticStack &stack, string elem);

string pop(StaticStack &stack);

string top(const StaticStack &stack);

int size(const StaticStack& stack);

int count(const StaticStack& stack);

bool clear(StaticStack& stack);


#endif // !STACK_2_H


