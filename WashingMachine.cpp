/* ******************************************************* 
 * Filename		:	WashingMachine.cpp
 * Author		:	Esra Nur CENGÝZ		
 * Date			:	02/01/2020
 * Description	:	WashingMachine Class Interface
 * ******************************************************/
 
#include "WashingMachine.h"
#include<stdio.h>
#include<string.h>
#include<vector>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

vector<string> line1;

WashingMachine::WashingMachine(string line1)
 	:Machine()
{
	vector<string> tokens;
	stringstream ss(line1); // Used for breaking words(lines)
	
	string token;
	
	while(getline(ss, token, '-'))
	{
		tokens.push_back(token);
	}
	Machine::setIdCode(tokens[0]);
	Machine::setHeight(tokens[1]);
	Machine::setLength(tokens[2]);
	Machine::setWidth(tokens[3]);
	Machine::setEnergyConsumption(tokens[4]);
	setLiters(tokens[5]);
	setPrograms(tokens[6]);
	setCapacity(tokens[7]);
	setSpeed(tokens[8]);
	Machine::setEnginePower(tokens[9]);
	Machine::setEngineRotations(tokens[10]);
	setHeadingCapacity(tokens[11]);
	Machine::setNumberInInventory(tokens[12]);
}
void WashingMachine::setLiters(string liter)
{
	stringstream ss(liter);
	ss >> liters;
}
void WashingMachine::setPrograms(string program)
{
	stringstream ss(program);
	ss>>programs;
}
void WashingMachine::setCapacity(string capacit)
{
	stringstream ss(capacit);
	ss>> capacity;	
}
void WashingMachine::setSpeed(string speeds)
{
	stringstream ss(speeds);
	ss >> speed;
}
void WashingMachine::setHeadingCapacity(string heat)
{
	stringstream ss(heat);
	ss >> heating;
}
void WashingMachine::addWashingMachine(vector<WashingMachine> &WasArray)
{
	ifstream file;
	file.open("inputfile.txt");
	ofstream tempt;
	tempt.open("tempt.txt");
	string line, newtext, changeid;
	while(getline(file,line)) 
	{
		if(line[0] == 'R' || line[0] =='D')
			tempt << line << endl;
	}
	cout << "\nEnter the id code of the WashingMachine you want to change:" << endl;
	cin >> changeid;
	int i=0;	
	for(vector<WashingMachine>:: iterator it=WasArray.begin() ; it != WasArray.end() ; it++)
	{
		if(WasArray[i].idCode != changeid )
		{
			tempt << WasArray[i].idCode  << "-" << WasArray[i].height << "-" << WasArray[i].length << "-" << WasArray[i].width << "-" <<WasArray[i].energyConsumption << "-" << WasArray[i].liters << "-" << WasArray[i].programs << "-" << WasArray[i].capacity << "-" << WasArray[i].speed << "-" << WasArray[i].enginePower << "-" << WasArray[i].engineRotations << "-" << WasArray[i].heating << "-" << WasArray[i].number << "-" << endl;
		}
		else 
		{
			cout << "Enter the  whole parameter of the WashingMachine: (Please enter '-' between the product parameters)" << endl;
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
	WashingMachine Wash(newtext);
	WasArray.push_back(Wash);
	mfile << newtext;
	mfile.close();
}
	
ostream &operator<<(ostream &output,WashingMachine &wasmac)
{
	output << wasmac.idCode;
	output << " ";
	output << wasmac.height;
	output << " ";
	output << wasmac.length;
	output << " ";
	output << wasmac.width;
	output << " ";
	output << wasmac.energyConsumption;
	output << " ";
	output << wasmac.liters ;
	output << " ";
	output << wasmac.programs;
	output << " ";
	output << wasmac.capacity;
	output << " ";
	output << wasmac.speed;
	output << " ";
	output << wasmac.enginePower;
	output << " ";
	output << wasmac.engineRotations;
	output << " ";
	output << wasmac.heating;
	output << " ";
	output << wasmac.number;

	return output;
}		
