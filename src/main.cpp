#include <iostream>
#include "../headers/bloc.hpp"

using namespace std;

int main(){

	cout << "Hello World!" << endl;

	Bloc bloc1;
	Debug* BlocDebug = new Debug('y',3,3,0,0);

	cout << "Affichage d'un Bloc" << endl;
	bloc1.set('x');
	bloc1.print();

	cout << "Affichage d'un Bloc" << endl;
//	BlocDebug->print();	

	return 0;
}
