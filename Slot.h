#include<iostream>
#include<string>


#ifndef SLOT_H
#define SLOT_H
using namespace std;

class Slot{
	protected:
	string productName;
	int id;                           // Id de l'emplacement
	int numProducts ;                  // Le nombre de produit actuellement stockee dans la fente
	int price;

	public:
		Slot();
		Slot(int slotId, string prodName, int prix);
		virtual ~Slot();
		// Fonction
		virtual void drop() = 0; // Pour la rendre Slot une classe Abstraite destinee uniquement a etre derivee
	    string getProductName();
	    void setProductName(string prodName);
	    int getNumProduct();
	    void setNumProduct(int numProd);
	    int getPrice();
	    void setPrice(int prix);
	    int getId();                  // Id du slot !!
	    void afficheSlot();


};
#endif
