#include <iostream>
#include <vector>
#include "Utilities.h"
#include "Users.h"
using namespace std;

void demoSimpleHash();
void demoParseString();
void demoCSVToObject();

int main()
{
	cout << endl << "demoSimpleHash()..........." << endl;
	demoSimpleHash();

	cout << endl << "demoParseString()..........." << endl;
	demoParseString();

	cout << endl << "demoCSVToObject()..........." << endl;
	demoCSVToObject();

	return 0;
}

void demoSimpleHash() {
	//hasher for ints
	hash<int> hasherInt;
	int rank = 70;
	cout << "hash[" << rank << "]: " << hasherInt(rank) << endl;

	//hasher for strings
	hash<string> hasherStr;
	string fName = "Colby";
	cout << "hash[" << fName << "]: " << hasherStr(fName) << endl;

	//hasher for doubles
	hash<double> hasherDbl;
	double lastLogTime = 03.23;
	cout << "hash[" << lastLogTime << "]: " << hasherDbl(lastLogTime) << endl;

	//we can store the hash value using size_t (basically an unasigned int)
	size_t myHash = hasherStr("this is a hash value store in a uint");
	cout << myHash << endl;
}

//useful - fails when a row of data contains a field (e.g., address) which contains commas
void demoParseString()
{
	//string str = "WBC88XPE6LP, 70, Colby, Burks, M, rutrum.non@aol.org, 1-704-685-7028, 6723 EV, 460-8248 Tempor Rd, Peru, 03.23, 121.31";
	string str = "70, Colby, rutrum.non@aol.org";
	string delimiter = ",";

	vector<string> rowFromCSV = splitString(str, delimiter);

	if (rowFromCSV.size() == 3)
	{
		int rank = stoi(rowFromCSV[0]);
		string fName = rowFromCSV[1];
		string email = rowFromCSV[2];
		vector<string> dateWords = splitString(rowFromCSV[3], "/");
	}
}

void demoCSVToObject()
{
	string fileName = "data/data_3.csv";
	vector<vector<string>> allData = readDelimitedRows(fileName);

	for (vector<string> row : allData) {
		for (string field : row) {
			cout << field << ",";
		}
		cout << endl;
	}
}