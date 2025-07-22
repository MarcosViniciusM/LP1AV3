#include <iostream>
#include <string>
#include "id.h"
#include "corretor.h"
#include "cliente.h"
#include "imovel.h"
#include "agendamento.h"
using namespace std;

int main(){
	
	vector<Cliente> vCliente;
	vector<Corretor> vCorretor;
	vector<Imovel> vImovel;
	
	lerCorretor(vCorretor);
	lerCliente(vCliente);
	lerImovel(vImovel);
	
	int numAval=numAvaliadores(vCorretor);

	// Avaliador 
	for(int i=0;i<vCorretor.size();i++){
		//Pula o processo de visitas, se o corretor não for um avaliador
		if(vCorretor[i].getAvaliador()==0){
			continue;
		}
		// Unicamente para encaixar perfeitamente com as saídas
		if(i){
			cout << endl;
		}
		vector<int> rota;
		// Coloca o trajeto a ser feito no vetor rota
		criarRota(vImovel, vCorretor[i], rota, numAval);
		
		// Imprime o trajeto, e o horário
		imprimirRota(vImovel, vCorretor[i], rota);
	}
	
	return 0;
}
