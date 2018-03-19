#include <iostream>
#include <string>
#include <algorithm>

#define BOURRAGE '.'

class Bloc
{
	protected:
		int height; 
		int width;
		int refHeight; 
		int refWidth;

	public:
		Bloc();
		Bloc(int setHeight, int setWidth, int setRefHeight, int setRefWidth);
		virtual ~Bloc();

		int getHeight(void);
		int getWidth(void);
		int getRefHeight(void);
		int getRefWidth(void);
		void printSpec(void);

		virtual void print(void) = 0;
		virtual void printLigne(int numLigne) = 0;
};


class Debug : public Bloc
{
	private:
		char contenu;

	public:
		Debug();
		Debug(char const caractere);
		Debug(char const caractere, int setHeight, int setWidth, int setRefHeight, int setRefWidth);
		virtual ~Debug();

		virtual void print(void);
		virtual void printLigne(int numLigne);
};



class Over : public Bloc
{
	private:
		Bloc* over;
		Bloc* under;

	public:
		Over();
		Over(Bloc* blocOver, Bloc* blocUnder);
		virtual ~Over();

		virtual void print(void);
		virtual void printLigne(int numLigne);

		void bourrage(int a, int b);
};


class Beside : public Bloc
{
	private:
		Bloc* left;
		Bloc* right;

	public:
		Beside();
		Beside(Bloc* blocLeft, Bloc* blocRight);
		virtual ~Beside();

		virtual void print(void);
		virtual void printLigne(int numLigne);

		void bourrage(int a, int b);
};
