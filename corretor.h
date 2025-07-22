#include <string>
#include <vector>
using namespace std;

class Corretor {
private:
	int id;
	string nome;
	string telefone;
	bool isAvaliador;
	double lat;
	double lng;
	
public:
	Corretor(string n, string t, bool a, double lt, double lg);
	int getId();
	string getNome();
	string getTelefone();
	bool getAvaliador();
	double getLat();
	double getLng();
	void debugPrint();
};

void lerCorretor(vector<Corretor>& Corretor);