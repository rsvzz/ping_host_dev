
main : main.cpp HeaderBar.o WinApp.o
	g++ -o main $(pkg-config --cflags --libs gtk4) main.cpp HeaderBar.o WinApp.o

HeaderBar.o: HeaderBar.c HeaderBar.hpp
gcc -g -Wall -c HeaderBar.o HeaderBar.cpp

WinApp.o: WinApp.cpp WinApp.hpp
gcc -g -Wall -c WinApp.o WinApp.cpp

clean : 
	rm *.o

