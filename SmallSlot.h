#include<iostream>
#include"Motor.h"
#include"Slot.h"

using namespace std;

class SmallSlot: public Slot{
	Motor* motor1;
	public:
		SmallSlot(int slotId, string productName,int price, int motor1Id);
		~SmallSlot();
		void drop() override;
};
