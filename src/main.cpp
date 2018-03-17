#include <iostream>
#include "../headers/bloc.hpp"

using namespace std;

int main(){

	cout << "Hello World!" << endl;

	Debug* BlocDebug = new Debug('a',5,7,1,1);
	Debug* BlocDebug2 = new Debug('b',4,3,0,2);
	Debug* BlocDebug3 = new Debug('c',3,6,2,3);

//	Over* BlocOver = new Over(BlocDebug, BlocDebug2);
//	Over* BlocOver2 = new Over(BlocOver, BlocDebug3);

/*
	cout << endl <<"Affichage d'un Bloc Debug" << endl;
	BlocDebug->print();	

	cout << endl << "Affichage d'une ligne Debug" << endl;
	BlocDebug->printLigne(0);	
*/

	BlocDebug->print();
	BlocDebug2->print();
	BlocDebug3->print();
	
	cout << endl << "Affichage d'un Bloc Over (Spec)" << endl;
//	BlocOver2->printSpec();		

	cout << endl << "Affichage d'un Bloc Over" << endl;
//	BlocOver2->print();		


	return 0;
}
