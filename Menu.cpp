/*
// Menu.cpp
// Project 3: CS-210
// Zachary Grimm
// 8/8/23
*/

#include "Menu.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <stdexcept>
#include <cctype>  // For fixing invalid data due to case of letters

using namespace std;


/**
 * Prints Menu 
 */
void Menu::printMenu() {
        cout << "----------------------------------------" << endl;
        cout << "MENU" << endl;
        cout << "----------------------------------------" << endl;
        cout << "1. Search Item Frequency" << endl;
        cout << "2. Print All Item Frequencies" << endl;
        cout << "3. Print All Item Frequencie Histogram" << endl;
        cout << "4. Exit" << endl;
}

/**
 * Performs selected options function
 *
 * @param menuOption user selected option number from menu
 *
 */
void Menu::runOption(int menuOption, map<string, int> itemMap) {
    switch (menuOption) {
    case 1:
        cout << endl;
        printItemFrequency(itemMap);
        break;
    case 2:
        cout << endl;
        printFrequencyAllItems(itemMap);
        break;
    case 3:
        cout << endl;
        printHistogram(itemMap);
        break;
    case 4:
        cout << endl;
        exitProgram();
        break;
    default:
        cout << "Something went wrong" << endl;
        //throw runtime_error("There was a problem with your input");
    }
}

/**
* Prompt user for and get the option selected from the menu
*
* @return menu option selected by user
**/
int Menu::getUserSelection() {
    //cin.clear();    // Clear the error state
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore the invalid input
    int optionNumber = 0;
    while (true) {
        cout << "Enter a Menu Option (1-4): ";
        if (cin >> optionNumber && optionNumber >= 1 && optionNumber <= 4) {
            break;  // Input is valid, exit the loop
        }
        else {
            cout << "Please enter a valid option number (1-4)." << endl;
            cin.clear();    // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore the invalid input
        }
    }
    return optionNumber;
}



/**
 * Checks if entered item is in list. attempts to fix Plural and capitilization issues
 *
 * @param itemName name of item to search
 *
 * @return correct name if found or throws error
 */
string Menu::validateItemEntered(string itemName, map<string, int> itemData) {
    try {
        if (!itemName.empty()) {
            // for trying and fix capitalization errors
            string itemNameCaseFix = itemName;
            itemNameCaseFix[0] = toupper(itemNameCaseFix[0]);
            for (int i = 1; i < itemNameCaseFix.length(); ++i) {
                itemNameCaseFix[i] = tolower(itemNameCaseFix[i]);  // Convert remaining characters to lowercase
            }

            // for trying and fix errors due to plurilzation
            string itemNamePluralFix = itemNameCaseFix;
            char lastLetter = itemNamePluralFix.back();
            if (lastLetter == 's') {
                itemNamePluralFix.pop_back();
            }
            else {
                itemNamePluralFix.push_back('s');
            }

            if (itemData.count(itemName) == 1) {
                return itemName;
            }
            else if (itemData.count(itemNameCaseFix) == 1) {
                return itemNameCaseFix;
            }
            else if (itemData.count(itemNamePluralFix) == 1) {
                return itemNamePluralFix;
            }
            else {
                throw runtime_error("Could not find requested item");
            }
        }
        else {
            throw runtime_error("An error occured: No item entered");
        }  
    }
    catch (runtime_error& excpt) {
        cout << excpt.what() << endl;
        cin.clear();    // Clear the error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore the invalid input
        return "Error";
    }
    catch (...) {
        cout << "Something went wrong" << endl;
        cin.clear();    // Clear the error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore the invalid input
        return "Error";
    }
}
    
    


/**
 * prints frequency of user entered item after validating input
 *
 * @param itemData 
 *
 * @return number of instances of item
 */
void Menu::printItemFrequency(map<string, int> itemData) {
    string itemName;
    string validatedName;
    while (true) {
        cout << "What item are you inquiring about?" << endl;
        cin >> itemName;
        // run validation
        try {
            validatedName = validateItemEntered(itemName, itemData);
            if (validatedName == "Error") {
                throw runtime_error(" Press any key to continue");
            }
            else {
                if (validatedName != itemName) { // inform user of input fix
                    cout << "Did you mean " << validatedName << "? If so ";
                }
                cout << "There have been " << itemData.at(validatedName) << " purchases of " << validatedName << endl;
                break;
            }
        }
        catch (runtime_error& excpt) {
            cout << excpt.what() << endl;
            cin.clear();    // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore the invalid input
        }
    }
    
   
    
}

/**
 * Prints a list of each item with the number of occurences
 */
void Menu::printFrequencyAllItems(map<string, int> itemData) {
    for (auto& pair : itemData) {
        cout << pair.first << " " << pair.second << endl;
    }
}

/**
 * Returns length of longest item name in list, for formatting
 */
int Menu::getMaxSize(map<string, int> itemData) {
    string longestWord = "";
    for (auto& pair : itemData) {
        if (int(pair.second) > int(longestWord.length())) {
            longestWord = pair.first;
        }
    }
    return int (longestWord.length());
}


/**
 * Displays histogram showing the number of occurences for each item
 */ 
void Menu::printHistogram(map<string, int> itemData) {
    int labelLength = getMaxSize(itemData);
    for (auto& pair : itemData) {
        cout << pair.first << " "; 
        int spaceCounter = 0;
        while (int(pair.first.length()) + spaceCounter < labelLength) {
            cout << " ";
            spaceCounter++;
        }
        cout << "|";
        for (int i = 0; i < pair.second; ++i) {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;
}

/**
 * Exit
 */
void Menu::exitProgram() {
    cout << "Goodbye!" << endl;
}











