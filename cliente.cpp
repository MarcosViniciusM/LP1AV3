#include <iostream>
#include "cliente.h"
#include "id.h"
using namespace std;

Cliente::Cliente(string n, string t){
	id = getNextId();
	nome = n;
	telefone = t;
}

int Cliente::getId(){
	return id;
}

string Cliente::getNome(){
	return nome;
}

string Cliente::getTelefone(){
	return telefone;
}

void Cliente::debugPrint(){
	cout << "Cliente " << nome << ", ID " << id << ", " << telefone << endl;
	cout << endl;
}

void lerCliente(vector<Cliente>& Cliente){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		// ler telefone
		string telefone;
		cin >> telefone;
		string nome;
		getline(cin >> ws, nome); // lê o restante da linha como nome completo
		
		Cliente.emplace_back(nome, telefone);
	}
}