#include<iostream>
#include<string>
//#include"Keypad.h"

using namespace std;

class CoinSlot{
	int coinAmount;
	int coinValues[7] = {200,100,50,20,10,5,1}; // 2 euros = 200 cents (NB: Les pieces sont en cents et vont de 200 cents  a 1 cent)
	public:
		CoinSlot();
		~CoinSlot();
		int updateCoinAmount();
		int getCoinAmount();
		void clear();
		void returnCoins(int price);
};
