#include<iostream>
#include"SmallSlot.h"

using namespace std;

SmallSlot::SmallSlot(int slotId, string productName,int price,int motor1Id):Slot(slotId,productName,price){
	cout << "++ SmallSlot"<< endl;
	motor1 = new Motor(motor1Id);


};
SmallSlot::~SmallSlot(){
	cout << "-- SmallSlot"<< endl;
	delete motor1;
}
// Fonction drop()
void SmallSlot::drop() {
    if (getNumProduct() == 0) {
        cout << "Aucun produit a ejecter dans le slot " << getId() << "." << std::endl;
        return;
    }

    if (motor1) {
        motor1->trigger();
    }


    cout <<"Livraison de << "<< getProductName() << " >> a partir du logement " << getId()<< " en cours..." << std::endl;

    int num = getNumProduct();
    num--;
    setNumProduct(num);

   // cout << "Il reste " << getNumProduct() << " produit(s) dans le slot " << getId() << "." << endl;
}
