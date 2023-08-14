#ifndef DATA_H
#define DATA_H
#include <string>
#include <map>
using namespace std;
class Data
{
public:
	map<string, int> prepData(string fileName);
private:
	map<string, int> formatFileData(string fileName);
	void backupData(map<string, int> itemData);

};

#endif

