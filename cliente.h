#include <string>
#include <vector>
using namespace std;

class Cliente {
protected:
	int id;
	string nome;
	string telefone;
	
public:
	Cliente(string n, string t);
	int getId();
	string getNome();
	string getTelefone();
	void debugPrint();
};

void lerCliente(vector<Cliente>& Cliente);