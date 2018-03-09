#include <iostream>
#include <string>

class Bloc
{
	private:
		int height;
		int width;
		std::string contenu;

	public:
		Bloc();
		Bloc(std::string contenuInput);
		~Bloc();
		void set( std::string const equation);
		void print( void );


};
