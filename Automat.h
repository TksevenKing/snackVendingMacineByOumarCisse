#include<iostream>
#include"Slot.h"
#include<vector>
#include"WideSlot.h"
#include "SmallSlot.h"
#include"CoinSlot.h"
#include"Keypad.h"
#include"DropCheck.h"


using namespace std;

class Automat{
	vector<Slot*> slots; // Tab des emplacements des prdouits
	int numSlots;        // nbre d'emplacement
	Slot* cached;
	int numProductsPerSlot;
	//int insertPos;
	CoinSlot coinSlot;
	Keypad keypad;
	DropCheck dropCheck;
	public:

		Automat(int numSlots,int numProductsPerSlot);
		~Automat();
		bool addSlot(string productName,int price, int slotId, int motor1Id, int motor2Id);
		bool addSlot(string productName,int price, int slotId, int motor1Id);
		//bool addSlot(Slot);
	    Slot* searchSlot(int slotId);
	    void changeSlot(int slotId, string name, int price);
	    int getPieces(int slotId);
	    int getPrice(int slotId);
	    bool isAvailable(int slotId);
	    bool dropSlot(int slotId);
	    void fillAll();
	    void remplir(int slotId, int numProducts);
	    int getNumSlot();
};


