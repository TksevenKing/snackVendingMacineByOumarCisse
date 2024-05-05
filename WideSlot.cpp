#include<iostream>
#include"WideSlot.h"



using namespace std;


WideSlot::WideSlot(int slotId,string productName,int price,int motor1Id,int motor2Id):Slot(slotId,productName,price){
	cout <<" ++ WideSLot"<< endl;
	motor1 = new Motor(motor1Id);
//	if(motor2Id != 0){
		motor2 = new Motor(motor2Id);
//	}
};
WideSlot::~WideSlot(){
	cout << "-- Wide Slot"<< endl;
	delete motor1;
	delete motor2;
};
void WideSlot::drop(){
	    if (getNumProduct() == 0) {
        cout << "Aucun produit a ejecter dans le slot " << getId() << "." << std::endl;
        //drop = 1;
		return;
    }

    if (motor1) {
        motor1->trigger();
    }
    if (motor2) {
        motor2->trigger();
    }

        cout <<"Livraison de << "<< getProductName() << " >> a partir du logement " << getId()<< " en cours..." << std::endl;

    int num = getNumProduct();
    num--;
    setNumProduct(num);

   // cout << "Il reste " << getNumProduct() << " produit(s) dans le slot " << getId() << "." << std::endl;

}
