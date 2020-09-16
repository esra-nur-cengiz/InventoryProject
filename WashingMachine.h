/* ******************************************************* 
 * Filename		:	WashingMachine.h
 * Author		:	Esra Nur CENGÝZ		
 * Date			:	02/01/2020
 * Description	:	WashingMachine Class Implementation
 * ******************************************************/
 
#ifndef WASHINGMACHINE_H
#define WASHINGMACHINE_H
#include "Machine.h"
#include<string>
#include<vector>
using namespace std;

class WashingMachine : public Machine
{
	friend ostream &operator<<(ostream &,WashingMachine &);
	public:
		
		WashingMachine(string);
		
		void setLiters(string);
		void setPrograms(string);
		void setCapacity(string);
		void setSpeed(string);
		void setHeadingCapacity(string);
		
		void addWashingMachine(vector<WashingMachine> &);
	private:
		
		int liters;
		int programs;
		int capacity;
		int speed;
		int heating;
};

#endif
