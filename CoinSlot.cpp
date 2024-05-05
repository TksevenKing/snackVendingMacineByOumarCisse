#include<iostream>
#include<string>
#include"CoinSlot.h"

using namespace std;

CoinSlot::CoinSlot(){
	cout << "++ CoinSlot"<< endl;
	coinAmount = 0;
}
CoinSlot::~CoinSlot(){
	cout << "-- CoinSlot"<< endl;
}
int CoinSlot::updateCoinAmount(){
	int coin ;
	cout << "Inserer une piece entre [200,100,50,20,10,5,1] euro(s) (ou -1 pour annuler) "<< endl;
	cin >> coin;
    if(coin == -1){
    	cout << "Annulation de l'achat." << endl;
    //	return 0;
        return -1;
	}

	for(int i = 0;i< 7; ++i){
		if(coin == coinValues[i]){
			coinAmount += coin;
			return coin;
		}
	}
	//coinAmount += coin;
	cout << "Piece non valide."<< endl;
	return 0;
}
int CoinSlot::getCoinAmount(){
	return coinAmount;
}
void CoinSlot::clear(){
	coinAmount = 0;
}
// ================= Fonction returnCoins() by me
//void CoinSlot::returnCoins(int price){
//	cout << "Rendu de monnaie : "<< endl;
//	int temp = price;
//	temp *= 100;
//	int slotId = getSelection();
//	int currentPrice = getPrice(slotId);
//	if(price > currentPrice){
//		int monnaie;              // si le prod = 2 euros, et l'argent entere est 5 euros
//		monnaie = price - currentPrice;    // monnaie = 500 - 200 = 300
//		for(int i = 0; i< 7;i++){
//			if(monnaie > coinValues[i]){
//				monnaie - coinValues[i];
//			}
//		}
//	}
//}

// ================= returnCoins()
void CoinSlot::returnCoins(int price){
	cout<< "Rendu de monnaie : "<< endl;
	int remaining = coinAmount = price;

	for(int i = 0; i < 7; ++i){
		int numCoins = remaining / coinValues[i];
		remaining %= coinValues[i];
//		if(numCoins > 0){
//			cout << numCoins << " x " << coinValues[i] / 100.0 << " euros "<< endl;
//		}
			if(numCoins > 0){
			cout << numCoins << " x " << coinValues[i]  << " euros "<< endl;
		}
	}

	coinAmount = 0; // Reinitialiser le montant de la monnaie
}
