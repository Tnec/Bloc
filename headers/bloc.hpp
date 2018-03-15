#include <iostream>
#include <string>

class Bloc
{
	private:
		int height;
		int width;
		char contenu;

	public:
		Bloc();
		Bloc(char const caractere);
		~Bloc();
		void set( char const caractere);
		void print( void );


};

/*
class Debug : public Bloc
{

};
*/
