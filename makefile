SOURCES=sources/*.cpp
HEADERS=headers/*.hpp

all : bloc

bloc : main.o bloc.o
	g++ -o bloc build/main.o build/bloc.o	

main.o : src/main.cpp headers/bloc.hpp buildDir
	g++ -o build/main.o -c src/main.cpp -W -Wall -ansi -pedantic

bloc.o : src/bloc.cpp
	g++ -o build/bloc.o -c src/bloc.cpp -W -Wall -ansi -pedantic

buildDir : 
	if [ -d "./build" ]; 				\
	then 						\
		echo "BUILD DIR ALREADY EXISTS";	\
	else 						\
		mkdir build; 				\
	fi

clear :
	rm -rf *.o
	rm -rf bloc
	rm -rf build/
