#include <iostream>
#include <string>
using namespace std;

int suma(int a, int b)
{
	return a + b;
}
void main() {
	//Pointeri la Functii
	int(*pf)(int x, int y);
	pf = suma;
	cout << pf(7, 8);

}