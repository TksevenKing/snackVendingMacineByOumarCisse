#include<iostream>
#include<cstdlib>
#include"DropCheck.h"


using namespace std;

DropCheck::DropCheck(){
	cout << "++ DropCheck"<< endl;
}

bool DropCheck::productReleased(){
	//Ici je genere un nombre aleatoire entre 0 et 9 inclus
	int randomNum = rand() % 10;


	// La probabilite de retourner vrai est de 90 % (0-8) et faux est de 10%  (9)
	return randomNum < 9;
}
