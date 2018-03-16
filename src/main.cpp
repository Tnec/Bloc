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

	cout << endl <<"Affichage d'un Bloc Debug" << endl;
	BlocDebug->print();	

	cout << endl << "Affichage d'une ligne Debug" << endl;
	BlocDebug->printLigne(0);	


	return 0;
}
