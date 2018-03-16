#include "../headers/bloc.hpp"

using namespace std;

Bloc::Bloc() : contenu(' '), height(1), width(1){}

Bloc::Bloc(char const caractere) : contenu(caractere), height(1), width(1){}

Bloc::Bloc(char const caractere, int setHeight, int setWidth, int setRefHeight, int setRefWidth)
: contenu(caractere), height(setHeight), width(setWidth), refHeight(setRefHeight), refWidth(setRefWidth)
{}

Bloc::~Bloc(){}


void Bloc::set(char const caractere)
{
	contenu = caractere;
}

void Bloc::print(void)
{
	cout << contenu << endl;
}
