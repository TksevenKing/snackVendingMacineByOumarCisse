#include<iostream>
#include"Slot.h"
#include"Motor.h"


using namespace std;

class WideSlot: public Slot{
	Motor* motor1;
	Motor* motor2;
	public:
		WideSlot(int slotId = 0, string productName = "",int price = 0, int motor1Id = 0, int motor2Id = 0);
		~WideSlot();
		void drop() override;
};
