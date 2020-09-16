/* ******************************************************* 
 * Filename		:	Refrigerator.cpp
 * Author		:	Esra Nur CENGÝZ		
 * Date			:	02/01/2020
 * Description	:	Refrigerator Class Interface
 * ******************************************************/
 
#include "Refrigerator.h"
#include<stdio.h>
#include<string.h>
#include<vector>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

vector<string> lines;

Refrigerator::Refrigerator(string lines)
	:Machine()
{
	vector<string> tokens;
	stringstream ss(lines); // Used for breaking words(lines)
	
	string token;
	
	while(getline(ss, token, '-'))
	{
		tokens.push_back(token);  //strings separated  using the 'tokenizer' structure. 
	}
	
	Machine::setIdCode(tokens[0]);   // assigned by the set function to string
	Machine::setHeight(tokens[1]);
	Machine::setLength(tokens[2]);
	Machine::setWidth(tokens[3]);
	Machine::setEnergyConsumption(tokens[4]);
	setTemperature(tokens[5]);
	setVolume(tokens[6]);
	setDoors(tokens[7]);
	setDefrost(tokens[8]);
	Machine::setEnginePower(tokens[9]);
	Machine::setEngineRotations(tokens[10]);
	setCoolingCapacity(tokens[11]);
	Machine::setNumberInInventory(tokens[12]);
}

void Refrigerator::setTemperature(string temm)
{
	stringstream ss(temm);
	ss>>temperature;
	
}
void Refrigerator::setVolume(string voll)
{
	stringstream ss(voll);
	ss >> volume;
}
void Refrigerator::setDoors(string door)
{
	stringstream ss(door);
	ss >> doors;
}

void Refrigerator::setDefrost(string def)
{
	defrost=def;
}
void Refrigerator::setCoolingCapacity(string cooling)
{
	stringstream ss(cooling);
	ss >> coolingCap;
}
void Refrigerator::addToRefrigate(vector<Refrigerator> &RefArray)  // change the number of Refrigerator in the inventory
{
	ifstream file;
	file.open("inputfile.txt");
	ofstream tempt;
	tempt.open("tempt.txt");
	string line, newtext, changeid;
	
	while(getline(file,line)) 
	{
		if(line[0] == 'D' || line[0] =='W')    // Write other products to file
			tempt << line << endl;
	}
	cout << "\nEnter the id code of the Refrigerator you want to change:" << endl;
	cin >> changeid;
	int i=0;
	
	for(vector<Refrigerator>:: iterator it=RefArray.begin() ; it != RefArray.end() ; it++)
	{
		if(RefArray[i].idCode != changeid )   // The ID number to be changed is compared with the other ID codes in the inventory. 
		{
			// If they are not the same, these strings are writing on the tex.
			tempt << RefArray[i].idCode << "-" << RefArray[i].height << "-" << RefArray[i].length << "-" << RefArray[i].width << "-" << RefArray[i].energyConsumption << "-" << RefArray[i].temperature << "-" << RefArray[i].volume << "-" << RefArray[i].doors <<
			"-" << RefArray[i].defrost << "-" << RefArray[i].enginePower << "-" << RefArray[i].engineRotations << "-" << RefArray[i].coolingCap << "-" << RefArray[i].number << "-" << endl;	
		}
		else 
		{
			cout << "Enter the  whole parameter of the Refrigerator: (Please enter '-' between the product parameters)" << endl;
			cin >> newtext;
		}
		i++;
	}
	file.close();
	tempt.close();
	remove("inputfile.txt");
	rename("tempt.txt","inputfile.txt");
			
	ofstream mfile;
	mfile.open("inputfile.txt",std::ios_base::app | std::ios_base::out);		
	Refrigerator Reff(newtext);
	RefArray.push_back(Reff);   //New product written to inventory.
	mfile << newtext;
	mfile.close();
}
ostream &operator<<(ostream &output,Refrigerator &reff)
{
	output << reff.idCode;
	output << " ";
	output << reff.height;
	output << " ";
	output << reff.length;
	output << " ";
	output << reff.width;
	output << " ";
	output << reff.energyConsumption;
	output << " ";
	output << reff.temperature ;
	output << " ";
	output << reff.volume;
	output << " ";
	output << reff.doors;
	output << " ";
	output << reff.defrost;
	output << " ";
	output << reff.enginePower;
	output << " ";
	output << reff.engineRotations;
	output << " ";
	output << reff.coolingCap;
	output << " ";
	output << reff.number;

	return output;
}

