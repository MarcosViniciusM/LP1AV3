#include <iostream>
#include "corretor.h"
#include "id.h"
using namespace std;

Corretor::Corretor(string n, string t, bool a, double lt, double lg){
	id = getNextId();
	nome = n;
	telefone = t;
	isAvaliador = a;
	lat = lt;
	lng = lg;
}
int Corretor::getId(){
	return id;
}

string Corretor::getNome(){
	return nome;
}

string Corretor::getTelefone(){
	return telefone;
}

bool Corretor::getAvaliador(){
	return isAvaliador;
}

double Corretor::getLat(){
	return lat;
}

double Corretor::getLng(){
	return lng;
}

void Corretor::debugPrint(){
	cout << "Corretor " << nome << ", ID " << id << ", " << telefone << endl;
	cout << "Avaliador: " << isAvaliador << ", " << lat << " " << lng << endl;
	cout << endl;
}

void lerCorretor(vector<Corretor>& Corretor){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		// ler telefone, avaliador, lat, lon
		string telefone; int avaliador; double lat, lon;
		cin >> telefone >> avaliador >> lat >> lon;
		string nome;
		getline(cin >> ws, nome); // lê o restante da linha como nome completo
		
		Corretor.emplace_back(nome, telefone, avaliador, lat, lon);
	}
}