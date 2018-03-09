#include "../headers/bloc.hpp"

using namespace std;

Bloc::Bloc() : height(0), width(0), contenu(""){}
Bloc::Bloc(std::string contenuInput) : height(0), width(0), contenu(contenuInput){}
Bloc::~Bloc(){}


void Bloc::set(string const equation)
{
	contenu = equation;
}

void Bloc::print(void)
{
	cout << contenu << endl;
}
