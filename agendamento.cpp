#include <iostream>
#include <vector>
#include <iomanip>
#include "corretor.h"
#include "imovel.h"
#include "leitura.h"
#include "haversine.h"
using namespace std;

// Retorna o número de avaliadores em um vetor de corretores
int numAvaliadores(vector<Corretor>& corretor){
	int n=0;
	for(int i=0;i<corretor.size();i++){
		if(corretor[i].getAvaliador()){
			n++;
		}
	}
	return n;
}

// Retorna a posição do vizinho mais próximo, dado um vetor de possivel endereços, e o endereço inicial
int vizinhoMaisProximo(vector<Imovel>& imovel, vector<int>& selecao, double lat2, double lng2){
	double menorDist=9999999;
	int menorSelecao;
	for(int i=0;i<selecao.size();i++){
		double lat1=imovel[selecao[i]-1].getLat();
		double lng1=imovel[selecao[i]-1].getLng();
		double distAtual(haversine(lat1, lng1, lat2, lng2));
		if(distAtual<menorDist){
			menorDist=distAtual;
			menorSelecao=i;
		}
	}
	return menorSelecao;
}

// Preenche um vetor com a rota que um corredor deve fazer, obedecendo as regras de sempre ir para o imóvel mais próximo.
// É aqui que os imóveis são assinalados para seus respectivos corretores
void criarRota(vector<Imovel>& imovel, Corretor corretor, vector<int>& rota, int numAval){
	vector<int> selecao;
	
	int size=imovel.size()/numAval;

	// Preenche o vetor seleção com todos os imóveis que o corretor deve visitar
	// Divide o número de imóveis pelo número de avaliadores, e assinala os imóveis baseado nessa divisão
	for(int i=0;i<=size;i++){
		int x;
		int y=corretor.getId();

		// Se o ID for maior que o número de avaliadores (quer dizer que houve um corretor que não é avaliador),
		// ajusta o valor para não criar um furo na equação
		if(y>numAval){
			y-=(corretor.getId()%numAval);
		}

		// Enquanto o vetor é percorrido, vai assinalando os imóveis seguindo a equação de x
		// Então, se o sistema precisa assinalar uma seleção entre 15 imóveis, para o corretor 1, enquanto tem 5 avaliadores entre eles,
		// ele retornaria o imóvel 1, 6, 11 para o vetor de seleção
		x=(i*numAval)+y;
		if(x > imovel.size()){
			break;
		}
		selecao.push_back(x);
	}

	
	int numViagens=selecao.size();
	double latIni = corretor.getLat();
	double lngIni = corretor.getLng();
	
	for(int i=0;i<numViagens;i++){
		int posicao;
		
		posicao = vizinhoMaisProximo(imovel, selecao, latIni, lngIni);
		rota.push_back(selecao[posicao]);
		
		selecao.erase(selecao.begin() + posicao);
	}
}

// Segue o cronograma armazenado no vetor rota, calcula a distância entre os pontos, e imprime o resultado.
void imprimirRota(vector<Imovel>& imovel, Corretor corretor, vector<int> rota){
	int minutoTotal=540;
	double lat1=corretor.getLat();
	double lng1=corretor.getLng();
	
	cout << "Corretor " << corretor.getId() << endl;
	for(int i=0;i<rota.size();i++){
		double lat2=imovel[rota[i]-1].getLat();
		double lng2=imovel[rota[i]-1].getLng();
		
		double trajeto=haversine(lat1, lng1, lat2, lng2);
		
		minutoTotal += trajeto*2;
		
		cout << setfill('0') << setw(2) << static_cast<int>(minutoTotal/60) << ":"
			 << std::setw(2) << static_cast<int>(minutoTotal%60) << " Imóvel " << rota[i] << endl;
			 
		minutoTotal+=60;
		
		lat1=imovel[rota[i]-1].getLat();
		lng1=imovel[rota[i]-1].getLng();
	}
}

// Função debug para certificar os valores armazenados em um vetor, mantida para casos de debug.
void debugPrintVector(vector<int> vetor){
	for(int i=0;i<vetor.size()-1;i++){
		cout << vetor[i] << " ";
	}
	cout << endl;
}
