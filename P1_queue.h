#ifndef __STATIC_QUEUE_H__
#define __STATIC_QUEUE_H__
#include <ctime>
#include <string>
#include "P1_stack.h"

//NICOLAS DE BARROS
//32070837

using namespace std;

// Estrutura de dados do tipo Fila.
const int STATIC_QUEUE_CAPACITY = 8;

struct StaticQueue
{

	StaticStack pilha_A;			//depois será usado Create_stack() para cada uma ads pilhas.
	StaticStack pilha_B;

};

StaticQueue Create();

bool Enqueue(StaticQueue& queue_A, string elem);

string Dequeue(StaticQueue& queue);

int Front(const StaticQueue& queue);

int Size(const StaticQueue& queue);

int Count(const StaticQueue& queue);

bool IsEmpty_queue(const StaticQueue& queue);

bool Clear(StaticQueue& queue);

#endif 