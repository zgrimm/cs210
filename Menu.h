#ifndef MENU_H
#define MENU_H
#include <string>
#include <map>
using namespace std;
class Menu
{
public:
	// Menu(); *constructor not needed currently
	void runOption(int menuOption, map<string, int> itemMap);
	void printMenu();
	int getUserSelection();
private:
	//void printDetails(int year, double yearEndBalance, double interestEarned);
	void  printItemFrequency(map<string, int> itemData);
	void printFrequencyAllItems(map<string, int> itemData);
	void printHistogram(map<string, int> itemData);
	void exitProgram();
	int getMaxSize(map<string, int> itemData);
	string validateItemEntered(string itemName, map<string, int> itemData);
	
};

#endif

