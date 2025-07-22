#include <iostream>
#include <vector>
using namespace std;

int numAvaliadores(vector<Corretor>& corretor);

int vizinhoMaisProximo(vector<Imovel>& imovel, vector<int>& selecao, double lat2, double lng2);

void criarRota(vector<Imovel>& imovel, Corretor corretor, vector<int>& rota, int numAval);

void imprimirRota(vector<Imovel>& imovel, Corretor corretor, vector<int> rota);

void debugPrintVector(vector<int> vetor);