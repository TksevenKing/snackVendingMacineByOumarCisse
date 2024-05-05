#include<iostream>
#include"Motor.h"

using namespace std;

Motor::Motor(int Id){
	cout<< "++ Motor "<< Id<< " created usuel"<< endl;
	idmot = Id;
}
Motor::~Motor(){
	cout<< "-- Motor "<< idmot<< " deleted"<< endl;
}

void Motor::trigger(){
	cout<<"Motor " <<idmot<<" activeted !!"<<endl;
}
