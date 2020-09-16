/* ******************************************************* 
 * Filename		:	Machine.h
 * Author		:	Esra Nur CENGÝZ		
 * Date			:	02/01/2020
 * Description	:	Machine Class Implementation
 * ******************************************************/
#ifndef MACHINE_H
#define MACHINE_H
#include<string>
using namespace std;

class Machine
{
	public:
		Machine();
		void setIdCode(string);
		void setHeight(string);
		void setLength(string);
		void setWidth(string);
		void setEnergyConsumption(string);
		void setEnginePower(string);
		void setEngineRotations(string);
		void setNumberInInventory(string);
		
	
		
	protected:   //Common properties
		string idCode;
		int height;
		int length;
		int width;
		string energyConsumption;
		double enginePower;
		int engineRotations;
		int number;
	
};

#endif
