#include <iostream>
#include "imovel.h"
#include "id.h"
using namespace std;

Imovel::Imovel(string t, int pId, double lt, double lg, string e, double p){
	tipo = t;
	id = getNextId();
	proprietarioId = pId;
	lat = lt;
	lng = lg;
	endereco = e;
	preco = p;
}

int Imovel::getId(){
	return id;
}

int Imovel::getPropId(){
	return proprietarioId;
}

double Imovel::getLat(){
	return lat;
}

double Imovel::getLng(){
	return lng;
}

string Imovel::getEndereco(){
	return endereco;
}

double Imovel::getPreco(){
	return preco;
}

void Imovel::debugPrint(){
	cout << id << ", propID " << proprietarioId << ", " << endereco << lat << " " << lng << endl;
	cout << preco << endl;
	cout << tipo << endl << endl;
}

void lerImovel(vector<Imovel>& Imovel){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		// ler tipo, proprietarioId, lat, lon, preco
		string tipo; int propId; double lat, lon, preco;
		cin >> tipo >> propId >> lat >> lon >> preco;
		string endereco;
		getline(std::cin >> std::ws, endereco); // lê o restante da linha como endereco completo
		
		Imovel.emplace_back(tipo, propId, lat, lon, endereco, preco);
	}
}