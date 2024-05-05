#include<iostream>
#include"Keypad.h"

using namespace std;

int Keypad::getSelection(){
	int choix ;
	//cout << "Saisir le numero d'emplacement du produit (-1) pour annuler..."<< endl;
	cin >> choix;
	return choix;
}
