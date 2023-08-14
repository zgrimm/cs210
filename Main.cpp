/*
// Main.cpp
// Project 3: CS-210
// Zachary Grimm
// 8/8/23
*/

#include <map>
#include "Menu.h"
#include "Data.h"

using namespace std;

int main() {
	int userMenuChoice = 0;
	// for storing file data parsed into key value pairs (itemName:Quantity)
	map<string, int> itemMap;

	// Data object used to read file, manipulate and backup data
	Data storeData;

	// Menu object for printing menu and performing user selection
	Menu storeMenu;
	
	// Retrieve, parse, backup and store parsed file data into variable 
	itemMap = storeData.prepData("CS210_Project_Three_Input_File.txt");

	// Print Menu, perform indicated user selection
	while (userMenuChoice != 4) {
		storeMenu.printMenu();
		userMenuChoice = storeMenu.getUserSelection();
		storeMenu.runOption(userMenuChoice, itemMap);
	}
	
	
	return 0;
}