#include <iostream>
#include "../headers/bloc.hpp"

using namespace std;

int main(){

	cout << "Hello World!" << endl;

// test over
	Debug* BlocDebug = new Debug('a',5,7,1,1);
	Debug* BlocDebug2 = new Debug('b',4,3,0,2);
	Debug* BlocDebug3 = new Debug('c',3,6,2,3);

// test beside
	Debug* BlocDebug4 = new Debug('d',5,5,1,2);
	Debug* BlocDebug5 = new Debug('e',6,2,5,1);
	
	Over* BlocOver = new Over(BlocDebug, BlocDebug2);
	Over* BlocOver2 = new Over(BlocOver, BlocDebug3);

	Beside* BlocBeside = new Beside(BlocDebug4, BlocDebug5);
	Beside* BlocBeside2 = new Beside(BlocOver2, BlocBeside);

	//cout << endl << "Affichage d'un Bloc Over" << endl;
	//BlocOver2->print();		

	cout << endl << "Affichage d'un Bloc Beside (Spec)" << endl;
	BlocBeside2->printSpec();

	cout << endl << "Affichage d'un Bloc Beside" << endl;
	BlocBeside2->print();

	return 0;
}
