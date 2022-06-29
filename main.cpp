#include "list.h"
int main() {
	list<comande> l;
	l.create(l);
	//l.raggruppa();
	//l.cerca("Sciortino");
	l.elimina();
	cout << "--------------------" << endl;
	cout << l;

}