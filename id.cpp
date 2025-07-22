#include <string>
#include "id.h"
using namespace std;


int getNextId(){
	static int nextId=0;
	nextId++;
	return nextId;
}