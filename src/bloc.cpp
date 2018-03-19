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

void Bloc::print(void){}

void Bloc::printLigne(int numLigne){}


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

Over::Over(Bloc* blocOver, Bloc* blocUnder)
	: Bloc(
			blocOver->getHeight() + blocUnder->getHeight(), 				//height

			max( 								//width
				max (blocUnder->getWidth() , blocOver->getWidth()), 
				max(blocUnder->getRefWidth() + blocOver->getWidth() - blocOver->getRefWidth() , 
					blocOver->getRefWidth() + blocUnder->getWidth() - blocUnder->getRefWidth())),
			// cas1 		//blocUnder->getWidth()
			// cas2 		//blocOver->getWidth()
			// cas3 		//blocUnder->getRefWidth() + blocOver->getWidth() - blocOver->getRefWidth()
			// cas4 		//blocOver->getRefWidth() + blocunder->getWidth() - blocUnder->getRefWidth()

			(int)(blocOver->getHeight() - blocOver->getRefHeight() + blocUnder->getRefHeight())/2 + blocOver->getRefHeight(),		//refheight

			max(blocOver->getRefWidth(),	blocUnder->getRefWidth())			//refwidth
			// cas1 		//blocUnder->getRefWidth()
			// cas2 		//blocOver->getRefWidth()
	      ),
	over(blocOver),
	under(blocUnder){}

Over::~Over()
{
	delete(over);
	delete(under);
}


void Over::print(void)
{
	for(int i = -this->getRefHeight(); i < this->getHeight() - this->getRefHeight(); i++)
	{
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


/****************/
/* class Beside */
/****************/


Beside::Beside() 
	: Bloc(1,1,0,0), left(NULL), right(NULL){}

Beside::Beside(Bloc* blocLeft, Bloc* blocRight)
	: Bloc(
			// height
			max( 								
				max(blocLeft->getHeight() , blocRight->getHeight()), 
				max(blocLeft->getRefHeight() + blocRight->getHeight() - blocRight->getRefHeight(),
					blocRight->getRefHeight() + blocLeft->getHeight() - blocLeft->getRefHeight())
			   ),


			// width
			blocLeft->getWidth()+blocRight->getWidth(),	

			// refHeight
			max(blocLeft->getRefHeight(), blocRight->getRefHeight()),

			// refWidth
			(int)((blocLeft->getWidth() + blocRight->getRefWidth() - blocLeft->getRefWidth())/2 + blocLeft->getRefWidth() ) 	
	      ),
	left(blocLeft),
	right(blocRight){}

Beside::~Beside()
{
	delete(left);
	delete(right);
}


void Beside::print(void)
{

	for(int i = -this->getRefHeight(); i < this->getHeight() - this->getRefHeight(); i++)
	{
		this->printLigne(i);
		cout << endl;
	}

}

void Beside::printLigne(int numLigne)
{

	int borneLeftInf, borneLeftSup, borneRightInf, borneRightSup;

	borneLeftInf = - left->getRefHeight();
	borneLeftSup =  - left->getRefHeight() + left->getHeight() -1 ;
	borneRightInf = - right->getRefHeight();
	borneRightSup = - right->getRefHeight() + right->getHeight() -1 ;

/*
	cout << "Bornes ";
	cout << " ";
	cout << borneLeftInf;
	cout << " ";
	cout << borneLeftSup;
	cout << " ";
	cout << borneRightInf;
	cout << " ";
	cout << borneRightSup;
	cout << " ";
*/

	if (numLigne >= borneLeftInf && numLigne <= borneLeftSup )
	{
		left->printLigne(numLigne);		
	} else {
		this->bourrage(left->getWidth(),0);
	}

	if (numLigne >= borneRightInf && numLigne <= borneRightSup )
	{
		right->printLigne(numLigne);		
	} else {
		this->bourrage(right->getWidth(),0);
	}

}

void Beside::bourrage(int a, int b)
{
		for(int i = 0; i < max(a,b) - min(a,b); i++) { cout << BOURRAGE; }
}

