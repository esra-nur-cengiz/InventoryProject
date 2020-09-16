/* ******************************************************* 
 * Filename		:	Dishwasher.cpp
 * Author		:	Esra Nur CENGÝZ		
 * Date			:	02/01/2020
 * Description	:	Dishwasher Class Interface
 * ******************************************************/
 
#include "Dishwasher.h"
#include<stdio.h>
#include<string.h>
#include<vector>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

vector<string> line;
ostream &operator<<(ostream &output,Dishwasher &dish)
{
	output << dish.idCode;
	output << " ";
	output << dish.height;
	output << " ";
	output << dish.length;
	output << " ";
	output << dish.width;
	output << " ";
	output << dish.energyConsumption;
	output << " ";
	output << dish.liters ;
	output << " ";
	output << dish.programs;
	output << " ";
	output << dish.capacity;
	output << " ";
	output << dish.racks;
	output << " ";
	output << dish.enginePower;
	output << " ";
	output << dish.engineRotations;
	output << " ";
	output << dish.waterSpray;
	output << " ";
	output << dish.number;

	return output;
}
Dishwasher::Dishwasher(string line)
	:Machine()
{
	vector<string> tokens;
	stringstream ss(line); // Used for breaking words(lines)
	
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
	setRacks(tokens[8]);
	Machine::setEnginePower(tokens[9]);
	Machine::setEngineRotations(tokens[10]);
	setWaterSprayCapacity(tokens[11]);
	Machine::setNumberInInventory(tokens[12]);	
}
void Dishwasher::setLiters(string liter)
{
	stringstream ss(liter);
	ss >> liters;
}
void Dishwasher::setPrograms(string program)
{
	stringstream ss(program);
	ss>>programs;
}
void Dishwasher::setCapacity(string capacit)
{
	stringstream ss(capacit);
	ss>> capacity;	
}
void Dishwasher::setRacks(string rack)
{
	stringstream ss(rack);
	ss >> racks;
}
void Dishwasher::setWaterSprayCapacity(string spray)
{
	stringstream ss(spray);
	ss >> waterSpray;
}
void Dishwasher::addDishWasher(vector<Dishwasher> &DishArray)
{
	ifstream file;
	file.open("inputfile.txt");
	ofstream tempt;
	tempt.open("tempt.txt");
	string line, newtext, changeid;
	while(getline(file,line)) 
	{
		if(line[0] == 'R' || line[0] =='W')
			tempt << line << endl;
	}
	cout << "\nEnter the id code of the Dishwasher you want to change:" << endl;
	cin >> changeid;
	int i=0;	
	for(vector<Dishwasher>:: iterator it=DishArray.begin() ; it != DishArray.end() ; it++)
	{
		if(DishArray[i].idCode != changeid )
		{
			tempt << DishArray[i].idCode << "-" << DishArray[i].height << "-" << DishArray[i].length << "-" << DishArray[i].width << "-" << DishArray[i].energyConsumption << "-" << DishArray[i].liters << "-" << DishArray[i].programs << "-" <<  DishArray[i].capacity << "-" <<  DishArray[i].racks << "-" <<  DishArray[i].enginePower << "-" << DishArray[i].engineRotations << "-" <<  DishArray[i].waterSpray << "-" << DishArray[i].number << "-" << endl;
			
		}
		else 
		{
			cout << "Enter the  whole parameter of the Dishwasher: (Please enter '-' between the product parameters) " << endl;
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
	Dishwasher Dish1(newtext);
	DishArray.push_back(Dish1);
	mfile << newtext;
	mfile.close();
}
