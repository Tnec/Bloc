#include "../headers/bloc.hpp"

using namespace std;

/**************/
/* class Bloc */
/**************/

Bloc::Bloc() 
	: height(1), width(1), refHeight(0), refWidth(0){}

Bloc::Bloc(int setHeight, int setWidth, int setRefHeight, int setRefWidth)
	: height(setHeight), width(setWidth), refHeight(setRefHeight), refWidth(setRefWidth){}

	Bloc::~Bloc(){}

	int Bloc::getHeight(void) {return height;}
	int Bloc::getWidth(void) {return width;}
	int Bloc::getRefHeight(void) {return refHeight;}
	int Bloc::getRefWidth(void) {return refWidth;}

void Bloc::printSpec(void)
{
	cout << "height :" << height << endl;
	cout << "width :" << width << endl;
	cout << "refHeight :" << refHeight << endl;
	cout << "refWidth :" << refWidth << endl;
}


void Bloc::printLigne(int numLigne)
{
	
}


/***************/
/* class Debug */
/***************/

Debug::Debug() : Bloc(1,1,0,0), contenu('.'){}

Debug::Debug(char const caractere) : Bloc(1,1,0,0), contenu(caractere){}

Debug::Debug(char const caractere, int setHeight, int setWidth, int setRefHeight, int setRefWidth)
	: Bloc( setHeight, setWidth, setRefHeight, setRefWidth), contenu(caractere){}

	Debug::~Debug(){}

void Debug::print(void)
{
	for(int i = -this->getRefHeight(); i < (this->getHeight() - this->getRefHeight()); i++){
		this->printLigne(i);		
		cout << endl;
	}
}

void Debug::printLigne(int numLigne)
{
	if(numLigne <= (getHeight()-getRefHeight()-1)  && numLigne >= -getRefHeight())
	{
		for(int j =  -this->getRefWidth(); j < (this->getWidth() -this->getRefWidth()); j++){
			if ( !numLigne && !j)
			{
				cout << '+';
			} else {			
				cout << this->contenu;
			}
		}
	}	
}


/**************/
/* class Over */
/**************/


Over::Over() 
	: Bloc(1,1,0,0), over(NULL), under(NULL){}



Over::Over(Bloc* debugOver, Bloc* debugUnder)
	: Bloc(
			//			'.',

			debugOver->getHeight() + debugUnder->getHeight(), 				//height

			max( 								//width
				max (debugUnder->getWidth() , debugOver->getWidth()), 
				max(debugUnder->getRefWidth() + debugOver->getWidth() - debugOver->getRefWidth() , 
					debugOver->getRefWidth() + debugUnder->getWidth() - debugUnder->getRefWidth())),
			// cas1 		//debugUnder->getWidth()
			// cas2 		//debugOver->getWidth()
			// cas3 		//debugUnder->getRefWidth() + debugOver->getWidth() - debugOver->getRefWidth()
			// cas4 		//debugOver->getRefWidth() + blocunder->getWidth() - debugUnder->getRefWidth()

			(int)(debugOver->getHeight() - debugOver->getRefHeight() + debugUnder->getRefHeight())/2 + debugOver->getRefHeight(),		//refheight

			max(debugOver->getRefWidth(),	debugUnder->getRefWidth())),			//refwidth
	// cas1 		//debugUnder->getRefWidth()
	// cas2 		//debugOver->getRefWidth()
	over(debugOver),
	under(debugUnder){}

	Over::~Over(){}


void Over::print(void)
{
	for(int i = -this->getRefHeight(); i < this->getHeight() - this->getRefHeight(); i++)
	{
		cout << i << ". ";
		this->printLigne(i);
		cout << endl;
	}
}

void Over::printLigne(int numLigne)
{


	int borneOverInf, borneOverSup, borneUnderInf, borneUnderSup;

	borneOverInf = -this->getRefHeight();
	borneOverSup = this->getHeight()- under->getHeight()- (this->getRefHeight()+1);
	borneUnderInf = this->getHeight() - under->getHeight() - this->getRefHeight();
	borneUnderSup = this->getHeight() - this->getRefHeight() - 1;

	// Si je suis dans le bloc Over
	if( numLigne >= borneOverInf	&& numLigne <= borneOverSup )
	{
		//Bourrage avant bloc	
		if(this->getRefWidth() > over->getRefWidth()){
			bourrage(this->getRefWidth(),over->getRefWidth());
		}

		//affichage ligne
		over->printLigne( numLigne + this->getRefHeight() - over->getRefHeight());

		//Bourrage après bloc
		if(this->getWidth() - this->getRefWidth() > over->getWidth() - over->getRefWidth()){
			bourrage(this->getWidth() - this->getRefWidth(),over->getWidth() - over->getRefWidth());		
		}
	}
	else if ( numLigne >= borneUnderInf && numLigne<= borneUnderSup)
	{
		//Bourrage avant bloc	
		if(this->getRefWidth() > under->getRefWidth()){
			bourrage(this->getRefWidth(),under->getRefWidth());
		}

		//Affichage ligne
		under->printLigne( numLigne -(-this->getRefHeight()+over->getHeight()+under->getRefHeight() ));

		//Bourrage après bloc
		if(this->getWidth() - this->getRefWidth() > under->getWidth() - under->getRefWidth()){
			bourrage(this->getWidth() - this->getRefWidth(),under->getWidth() - under->getRefWidth());		
		}
	}
}

void Over::bourrage(int a, int b)
{
	for(int i = 0; i < max(a,b) - min(a,b); i++) { cout << BOURRAGE; }
}

