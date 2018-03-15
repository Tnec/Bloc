#include "../headers/bloc.hpp"

using namespace std;

Bloc::Bloc() : height(1), width(1), contenu(' '){}

Bloc::Bloc(char const caractere) : height(1), width(1), contenu(caractere){}

Bloc::~Bloc(){}


void Bloc::set(char const caractere)
{
	contenu = caractere;
}

void Bloc::print(void)
{
	cout << contenu << endl;
}
