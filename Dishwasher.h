/* ******************************************************* 
 * Filename		:	Dishwasher.h
 * Author		:	Esra Nur CENGÝZ		
 * Date			:	02/01/2020
 * Description	:	Dishwasher Class Implementation
 * ******************************************************/
 
#ifndef DISHWASHER_H
#define DISHWASHER_H
#include<string>
#include "Machine.h"
#include<vector>
using namespace std;

class Dishwasher : public Machine
{
	friend ostream &operator<<(ostream &,Dishwasher &);
	public:
		
		Dishwasher(string);
		
		void setLiters(string);
		void setPrograms(string);
		void setCapacity(string);
		void setRacks(string);
		void setWaterSprayCapacity(string);
		
		void addDishWasher(vector<Dishwasher> &);
		
	private:
		
		int liters;
		int programs;
		int capacity;
		int racks;
		int waterSpray;
};

#endif
