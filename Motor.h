#include<iostream>

#ifndef MOTOR_H
#define MOTOR_H

using namespace std;


class Motor{
	int idmot;

	public:
		Motor(int idmot = 0);
		~Motor();
		void trigger();
};

#endif


