#include<iostream>
#include"Slot.h"
#include"motor.h"

using namespace std;

Slot::Slot() : id(0), productName(""), price(0),numProducts(0) {
    cout << "++ Construction du slot par defaut"<< id << endl;
}


Slot::Slot(int slotId = 0, string prodName = "", int prix = 0): id(slotId), productName(prodName), price(prix){ // : motor(motor1Id) car car lorsque je cree des objets Motor dynamiquement dans la classe Slot, le compilateur essaie d'appeler un constructeur sans parametre, mais il ny en pas
    cout<<"++ Construction du slot "<<id<<endl;


};
Slot::~Slot(){
	//cout<< "-- Destruction d'un slot"<< endl;

};

// ----------------- Fonction drop()


// ----------------- Getter && Setter
string Slot::getProductName(){
	return productName;
}
void Slot::setProductName(string prodName){
	productName = prodName;
}
int Slot::getNumProduct(){
	return numProducts;
}
void Slot::setNumProduct(int numProd){
	numProducts = numProd;
}
int Slot::getPrice(){
	return price;
}
void Slot::setPrice(int  prix){
	price = prix;
}
int Slot::getId(){
	return id;
}
void Slot::afficheSlot(){
	cout << productName<< " "<< numProducts<< " "<< price<<endl;
}
