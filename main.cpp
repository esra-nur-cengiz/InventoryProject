/* ******************************************************* 
 * Filename		:	main.cpp
 * Author		:	Esra Nur CENGÝZ		
 * Date			:	02/01/2020
 * Description	:	A Simple Inventory Program
 * ******************************************************/

#include "Refrigerator.h"
#include "Dishwasher.h"
#include "WashingMachine.h"

#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<string>
#include<stdio.h>

using namespace std;
vector<Refrigerator> RefArray;
vector<Dishwasher> DishArray;
vector<WashingMachine> WasArray;

int main() {	
	ifstream file;
	file.open("inputfile.txt");
	string line;
	
	while(getline(file,line))  // Reading line by line
	{
		if ( line[0] == 'R' )
		{
			Refrigerator Ref(line);   // Sent to constructure to separate strings using tokenizer structure.
			RefArray.push_back(Ref);
		}
		
		else if ( line[0] == 'D')
		{
			Dishwasher Dish(line);
			DishArray.push_back(Dish);
		}
		
		else if ( line[0] == 'W' )
		{
			WashingMachine Wash(line);
			WasArray.push_back(Wash);
		}
	}
	file.close();
	 
	for(vector<Refrigerator>:: iterator it=RefArray.begin() ; it != RefArray.end() ; it++)    //Read products are printed on the screen.
	{
		cout << *it;
		cout << endl;
	}
	for(vector<Dishwasher>:: iterator it=DishArray.begin() ; it != DishArray.end() ; it++)
	{
		cout << *it;
		cout << endl;
	}
	for(vector<WashingMachine>:: iterator it=WasArray.begin() ; it != WasArray.end() ; it++)
	{
		cout << *it;
		cout << endl;
	}	
	cout <<"\n" <<endl;
	cout << "-------------MENU----------" << endl;
	cout << "\n";
	cout << "Do you want to ADD a new product to the inventory? Press - 1" << endl;
	cout << "Do you want to CHANGE the number of products in the inventory? Press  - 2 " << endl;
	cout << "Do you want to EXIT the program? Press - 3" << endl;
	cout << "\n";
	cout << "---------------------------" << endl;
	int menuNumber;
	cin >> menuNumber;	
	
	switch (menuNumber)
	{
		case 1: 
		{
			cout << "\nPress the specified number according to the type of product you want to add." << endl;
			cout << "Refrigerator   -- 1"<< endl;
			cout << "Dishwasher     -- 2"<< endl;
			cout << "WashingMachine -- 3"<<endl;
			int typeNumber;
			cin>>typeNumber;
	
			string text;
			ofstream out;
			out.open("inputfile.txt",std::ios_base::app | std::ios_base::out);
			cout << "\nEnter the values : (Please enter '-' between the product parameters)" << endl;
			if( typeNumber == 1 )     //New product written to inventory.
			{
				cin >> text;     // The parameters of the new product were requested.
				cout << text;
				Refrigerator Ref1(text);   // Sent to constructure to separate strings using tokenizer structure.
				RefArray.push_back(Ref1);
				out << "\n" << text;  //write to text structure 
			}
			else if( typeNumber == 2 )
			{
				cin >> text;
				cout << text;
				Dishwasher Dish1(text);
				DishArray.push_back(Dish1);
				out << "\n" << text;
			}
			else if( typeNumber == 3 )
			{
				cin >> text;
				cout << text;
				WashingMachine Wash1(text);
				WasArray.push_back(Wash1);
				out << "\n" << text;
			}	
			out.close();	
			
		break;
		}
		case 2:
		{
			cout << "\nPress the number specified by the product type whose inventory number you want to change." << endl;
			cout << "Refrigerator   -- 1"<< endl;
			cout << "Dishwasher     -- 2"<< endl;
			cout << "WashingMachine -- 3"<<endl;
		
			int typeNumber;
			cin>>typeNumber;
	
			if (typeNumber ==1 )
			{
				RefArray[0].addToRefrigate(RefArray);  //The function called to change the number of products.
	 		}
	 
			else if(typeNumber == 2 )
			{
				DishArray[0].addDishWasher(DishArray);
			}
			else 
			{	
	  			WasArray[0].addWashingMachine(WasArray);
			}
		break;	
		}
				
		case 3:
		break;   // Exit
	}
	
		
	return 0;
}
