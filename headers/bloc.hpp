#include <iostream>
#include <string>

class Bloc
{
	private:
		char contenu;
		int height; 
		int width;
		int refHeight; 
		int refWidth;

	public:
		Bloc();
		Bloc(char const caractere);
		Bloc(char const caractere, int setHeight, int setWidth, int setRefHeight, int setRefWidth);
		~Bloc();
		void set( char const caractere);
		void print( void );


};


class Debug : public Bloc
{
	private:

	public:
		Debug();
		Debug(char const caractere);
		Debug(char const caractere, int setHeight, int setWidth, int setRefHeight, int setRefWidth);
};

