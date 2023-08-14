/*
// Menu.cpp
// Project 3: CS-210
// Zachary Grimm
// 8/8/23
*/
#include "Data.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

/**
* read file and return map of items with their quantities
 *
 * @param fileName name of file to read
 *
 * @return map of each item and its number of occurences
 */
map<string, int> Data::formatFileData(string fileName) {

	ifstream purchasedItemsFS; // input filestream
	string item; // for temp storage of different item names 
	map<string, int> itemQts; // key:value pairs for items and their quantaties

	// CS210_Project_Three_Input_File.txt
	purchasedItemsFS.open(fileName);
	if (!purchasedItemsFS.is_open()) {
		cout << "Could not open file " << fileName << endl;
	}
	else {
		getline(purchasedItemsFS, item);
		// TRIM OFF non letters (fixing weird chars before a spinich entry)
		//string trimmedItem =  item;
		/*for (char c : item) {
			if (isalpha(c)) {
				trimmedItem += c;
			}
		}*/
		while (!purchasedItemsFS.fail()) {
			// if item exists as key in itemWts, increment its val if not, add new key with val of 1
			if (itemQts.count(item) == 1) {
				itemQts.at(item) = itemQts.at(item) + 1;
				getline(purchasedItemsFS, item);
			}
			else {
				itemQts.emplace(item, 1);
				getline(purchasedItemsFS, item);
			}

		}
		// close file
		purchasedItemsFS.close();
	}
	return itemQts;
}

/**
 * Saves a copy of parsed file data to frequency.dat
 *
 * @param itemData parsed data from external file
 *
 */
void Data::backupData(map<string, int> itemData) {

	ofstream backupFS; //output file stream
	backupFS.open("frequency.dat");

	if (!backupFS.is_open()) {
		cout << "Could not open file myoutfile.txt." << endl;
		return;
	}

	// Write to file using range based for loop
	for (auto& pair : itemData) {
		backupFS << pair.first << " " << pair.second << endl;
	}

	// close file
	backupFS.close();

}

/**
* reads file, formats contents and returns result as key:value pairs
 *
 * @param fileName name of file to read
 *
 */
map<string, int> Data::prepData(string fileName) {
	map<string, int> itemMap;
	// Read File and Parse Data
	itemMap = formatFileData(fileName);
	// Backup Data File Creation
	backupData(itemMap);
	return itemMap;
}
