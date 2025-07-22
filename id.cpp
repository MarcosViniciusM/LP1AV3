#include <string>
#include "id.h"
using namespace std;

// Quando essa função é chamada, é assinalado um ID crescente, independente da classe que invocou
// Feita desta maneira para criar uma lista de IDs uniforme, já que as classes tem seus respectivos vetores
int getNextId(){
	static int nextId=0;
	nextId++;
	return nextId;
}
