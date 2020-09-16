/* ******************************************************* 
 * Filename		:	Machine.cpp
 * Author		:	Esra Nur CENGÝZ		
 * Date			:	02/01/2020
 * Description	:	Machine Class Interface
 * ******************************************************/

#include "Machine.h"
#include<stdio.h>
#include<string.h>
#include<sstream>
#include<iostream>

using namespace std;

Machine::Machine()
{

}
void Machine::setIdCode(string idcode)
{
	idCode=idcode;
}
void Machine::setHeight(string height1)
{
	stringstream ss(height1);     // string to int convertion
	ss >> height;
}
void Machine::setLength(string length1)
{
	stringstream ss(length1);
	ss >> length;
}
void Machine::setWidth(string width1)
{
	stringstream ss(width1);
	ss >> width;
}
void Machine::setEnergyConsumption(string energy)
{
	energyConsumption=energy;
}
void Machine::setEnginePower(string enginep)
{
	stringstream ss;
	ss << enginep;
	ss >> enginePower;
}
void Machine::setEngineRotations(string enginer)
{
	stringstream ss(enginer);
	ss >> engineRotations;
}
void Machine::setNumberInInventory(string numIn)
{
	stringstream ss(numIn);
	ss >> number;
}
