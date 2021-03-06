/* ******************************************************* 
 * Filename		:	Refrigerator.h
 * Author		:	Esra Nur CENG�Z		
 * Date			:	02/01/2020
 * Description	:	Refrigerator Class Implementation
 * ******************************************************/
 
#ifndef REFRIGERATOR_H
#define REFRIGERATOR_H
#include "Machine.h"
#include<string>
#include<vector>
using namespace std;

class Refrigerator : public Machine
{
	friend ostream &operator<<(ostream &,Refrigerator &);
	
	public:
		
		Refrigerator(string);
	
		void setTemperature(string);
		void setVolume(string);
		void setDoors(string);
		void setDefrost(string);
		void setCoolingCapacity(string);
		
		void addToRefrigate(vector<Refrigerator> &);  
		
	private:
		  // Different properties  (Refrigerator special properties)
		int temperature;
		int volume;
		int doors;
		string defrost;
		int coolingCap;
};

#endif
