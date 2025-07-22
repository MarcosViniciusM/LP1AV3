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
	
	for(int i=0;i<vCorretor.size();i++){
		if(vCorretor[i].getAvaliador()==0){
			continue;
		}
		if(i){
			cout << endl;
		}
		vector<int> rota;
		criarRota(vImovel, vCorretor[i], rota, numAval);
		imprimirRota(vImovel, vCorretor[i], rota);
	}
	
	return 0;
}