// VLNString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;

class VLNString
{
	public:
		string makeAcronym(string longName);
};

string VLNString::makeAcronym(string longName)
{
	vector<string> tokens;
	istringstream iss(longName);
	ostringstream result;

	// Split the string into tokens by whitespace
	copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         back_inserter<vector<string> >(tokens));

	// Iterate through the vector, check for the exceptions, add to result 
	for(vector<string>::iterator it = tokens.begin(); it != tokens.end(); ++it)
	{
		if(*it != "and" && *it != "the" && *it != "of")
			result << (char)toupper((*it)[0]);
	}
	return result.str();
}

int _tmain(int argc, _TCHAR* argv[])
{
	VLNString vlnString;
	
	// Test 1
	string string1 = "dance dance revolution";
	cout << string1 << endl;
	cout << vlnString.makeAcronym(string1) << endl << endl;

	// Test 2
	string string2 = " return of the king ";
	cout << string2 << endl;
	cout << vlnString.makeAcronym(string2) << endl << endl;
	
	// Test 3
	string string3 = "the united states of america";
	cout << string3 << endl;
	cout << vlnString.makeAcronym(string3) << endl << endl;
	
	// Test 4
	string string4 = " of the and  ";
	cout << string4 << endl;
	cout << vlnString.makeAcronym(string4) << endl << endl;

	// Test 5
	string string5 = "";
	cout << string5 << endl;
	cout << vlnString.makeAcronym(string5) << endl << endl;

	// Test 6
	string string6 = "Louis Dewei Wong";
	cout << string6 << endl;
	cout << vlnString.makeAcronym(string6) << endl << endl;
	system("pause");
	return 0;
}

