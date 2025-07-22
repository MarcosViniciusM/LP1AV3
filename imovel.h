#include <string>
#include <vector>
using namespace std;

class Imovel {
private:
	string tipo;
	int id;
	int proprietarioId;
	double lat;
	double lng;
	string endereco;
	double preco;
	
public:
	Imovel(string tipo, int pId, double lt, double lg, string e, double p);
	int getId();
	int getPropId();
	double getLat();
	double getLng();
	string getEndereco();
	double getPreco();
	void debugPrint();
};

void lerImovel(vector<Imovel>& Imovel);