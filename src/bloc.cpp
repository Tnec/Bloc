#include "../headers/bloc.hpp"

using namespace std;

/**************/
/* class Bloc */
/**************/

Bloc::Bloc() 
	: contenu(' '), height(1), width(1), refHeight(0), refWidth(0){}

Bloc::Bloc(char const caractere) 
	: contenu(caractere), height(1), width(1), refHeight(0), refWidth(0){}

Bloc::Bloc(char const caractere, int setHeight, int setWidth, int setRefHeight, int setRefWidth)
	: contenu(caractere), height(setHeight), width(setWidth), refHeight(setRefHeight), refWidth(setRefWidth){}

	Bloc::~Bloc(){}


void Bloc::set(char const caractere)
{
	contenu = caractere;
}

void Bloc::print(void)
{
	cout << contenu << endl;
}


/***************/
/* class Debug */
/***************/

Debug::Debug() : Bloc(' ',1,1,0,0){}

Debug::Debug(char const caractere) : Bloc(caractere,1,1,0,0){}

Debug::Debug(char const caractere, int setHeight, int setWidth, int setRefHeight, int setRefWidth)
	: Bloc( caractere, setHeight, setWidth, setRefHeight, setRefWidth){}


void Debug::print(void)
{
	for(int i = -this->refHeight; i < (this->height - refHeight); i++){
		for(int j =  -this->refWidth; j < (this->width -this->refWidth); j++){
			if ( !i && !j)
			{
				cout << '+';
			} else {			
				cout << this->contenu;
			}
		}
		cout << endl;
	}
}




