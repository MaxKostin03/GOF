#include <iostream>
#include <string>
#include <fstream>
#include <chrono>

#include "FileLogger.h"

using namespace std;

FileLogger::FileLogger(const string& FN)
{
    logOut.open(FN, ios_base::out);
}
FileLogger::~FileLogger()
{
    if (logOut.is_open())
    {
        logOut.close();
    }
}

void FileLogger::WriteToLog(const string& str)
{
    if (logOut.is_open())
    {
        logOut << GetCurDateTime() << " - " << str << endl;
    }
}

void FileLogger::WriteToLog(const string& str, int n)
{
    if (logOut.is_open())
    {
        logOut << GetCurDateTime() << " - " << str << n << endl;
    }
}

void FileLogger::WriteToLog(const string& str, double d)
{
    if (logOut.is_open())
    {
        logOut << GetCurDateTime() << " - " << str << d << endl;
    }
}

string FileLogger::GetCurDateTime()
{
    auto cur = chrono::system_clock::now();
    time_t time = chrono::system_clock::to_time_t(cur);
    char buf[64] = { 0 };
    ctime_s(buf, 64, &time);
    buf[strlen(buf) - 1] = '\0';
    return string(buf);
}