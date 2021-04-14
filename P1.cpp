#include "P1_queue.h"
#include <iostream>
#include <ctime>
#include <stdio.h>

//NICOLAS DE BARROS
//32070837

#pragma warning (disable : 4996)

using namespace std; 

int main()
{
	setlocale(LC_ALL, "pt_BR");

	//inicialização de variaveis
	int opcao = 0;
	int estante, prateleira, gaveta;
	string unidade_de_agua;                 //será adicionado na lista A ou B, dependendo da marca 
	string elemento_removido;
	string VENDA_marca_da_agua;
	char ADD_marca_da_agua;
	char dataaux[110];					   //vetor de char auxiliar p/ colocar na queue 


	//Criação das filas, do tipo StaticQueue
	StaticQueue queue_A = Create();
	StaticQueue queue_B = Create();

	//MENU 
	while (opcao != 3)
	{
		cout << "\n-------------------------------------------\n";
		cout << "Digite a opcao desejada : \n";
		cout << "   1-)	Realizar venda \n";
		cout << "   2-)	Cadastrar um produto no estoque \n";
		cout << "   3-)	Sair \n";
		cout << "-------------------------------------------\n";
		cout << "\n";

		cin >> opcao;
		if (opcao != 1 && opcao != 2 && opcao != 3)
		{
			cout << "Digite a opcao correta de acordo com o MENU ! \n";
			cin >> opcao;
		}

		switch (opcao)
		{
			// faz a venda e remove do estoque 
		case 1:

			cout << "\nDigite a marca de preferencia (A / B) : ";
			cin >> VENDA_marca_da_agua;
			cout << "\n";

			//Mostra as informações e remove do estoque
			//VENDA DA MARCA --> A <--	
			if (VENDA_marca_da_agua == "a" || VENDA_marca_da_agua == "A")
			{
				if (IsEmpty_queue(queue_A) == true)
				{
					cout << "\nO estoque de A está vazio !";
					continue;
				}
				elemento_removido = Dequeue(queue_A);
				cout << "*** INFORMAÇÕES DA AGUA VENDIDA : ***\n" << elemento_removido;
				continue;
			}

			//Mostra as informações e remove do estoque
			//VENDA DA MARCA --> B <--
			else if (VENDA_marca_da_agua == "b" || VENDA_marca_da_agua == "B")
			{
				if (IsEmpty_queue(queue_B) == true)
				{
					cout << "\nO estoque de B está vazio !";
					continue;
				}
				elemento_removido = Dequeue(queue_B);
				cout << "*** INFORMAÇÕES DA AGUA VENDIDA : ***\n" << elemento_removido;
				continue;
			}

		case 2:

			cout << "\nDigite a marca da agua que deseja adicionar no estoque : ";
			cin >> ADD_marca_da_agua;

			// ADD MARCA --> A <--
			if (ADD_marca_da_agua == 'A' || ADD_marca_da_agua == 'a')
			{
				time_t t = time(nullptr);
				tm timeinfo;
				localtime_s(&timeinfo, &t);

				cout << "\nDigite a estante onde será armazenado : ";
				cin >> estante;
				cout << "\nDigite a prateleira onde será armazenado : ";
				cin >> prateleira;
				cout << "\nDigite a gaveta onde será armazenado : ";
				cin >> gaveta;
				cout << "\n *** INFORMAÇÕES DO PRODUTO CADASTRADO : *** \n";
				sprintf(dataaux, "%02d/%02d/%04d %02d:%02d:%02d estante:%02d prateleira:%02d  gaveta:%02d", timeinfo.tm_mday, timeinfo.tm_mon + 1, timeinfo.tm_year + 1900, timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec, estante, prateleira, gaveta);
				unidade_de_agua = (string)(dataaux);

				cout << dataaux << "\n";

				Enqueue(queue_A, unidade_de_agua);
				cout << "\nCOUNT : " << Count(queue_A);
			}

			// ADD MARCA --> B <--
			else if (ADD_marca_da_agua == 'B' || ADD_marca_da_agua == 'b')
			{
				time_t t = time(nullptr);
				tm timeinfo;
				localtime_s(&timeinfo, &t);

				cout << "\nDigite a estante onde será armazenado : ";
				cin >> estante;
				cout << "\nDigite a prateleira onde será armazenado : ";
				cin >> prateleira;
				cout << "\nDigite a gavete onde será armazenado : ";
				cin >> gaveta;

				cout << "INFORMAÇÕES DO PRODUTO CADASTRADO : \n";
				sprintf(dataaux, "%02d/%02d/%04d %02d:%02d:%2d estante:%02d prateleira:%02d  gaveta:%02d", timeinfo.tm_mday, timeinfo.tm_mon + 1, timeinfo.tm_year + 1900, timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec, estante, prateleira, gaveta);
				unidade_de_agua = (string)(dataaux);

				cout << dataaux << "\n";

				Enqueue(queue_B, unidade_de_agua);
				cout << "\nCOUNT : " << Count(queue_B);
			}

			//ERRO
			else
			{
				cout << "Digite apenas aguas da marca A ou B !!\n";
			}
			continue;
		}
	}
}
