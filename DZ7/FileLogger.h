#pragma once

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class FileLogger
{
public:
	FileLogger(const string& FN);
	~FileLogger();
	void WriteToLog(const string& str);
	void WriteToLog(const string& str, int n);
	void WriteToLog(const string& str, double d);
	string GetCurDateTime();
private:
	ofstream logOut;
};
