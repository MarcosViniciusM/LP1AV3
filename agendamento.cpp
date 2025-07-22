#include <iostream>
#include <vector>
#include <iomanip>
#include "corretor.h"
#include "imovel.h"
#include "leitura.h"
#include "haversine.h"
using namespace std;

int numAvaliadores(vector<Corretor>& corretor){
	int n=0;
	for(int i=0;i<corretor.size();i++){
		if(corretor[i].getAvaliador()){
			n++;
		}
	}
	return n;
}

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

void criarRota(vector<Imovel>& imovel, Corretor corretor, vector<int>& rota, int numAval){
	vector<int> selecao;
	
	int size=imovel.size()/numAval;
	
	for(int i=0;i<=size;i++){
		int x;
		int y=corretor.getId();
		
		if(y>numAval){
			y-=(corretor.getId()%numAval);
		}
		
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

void debugPrintVector(vector<int> vetor){
	for(int i=0;i<vetor.size()-1;i++){
		cout << vetor[i] << " ";
	}
	cout << endl;
}