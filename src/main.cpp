#include <iostream>
#include "../headers/bloc.hpp"

using namespace std;

int main(){

	cout << "Hello World!" << endl;

	Bloc bloc1;
	Debug* BlocDebug = new Debug('y',5,7,1,1);

	cout << "Affichage d'un Bloc" << endl;
	bloc1.set('x');
	bloc1.print();

	cout << "Affichage d'un Bloc Debug" << endl;
	BlocDebug->print();	

	return 0;
}
