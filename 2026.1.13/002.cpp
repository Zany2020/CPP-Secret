#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>

class Log
{
public:
	const int LogLevelError = 0;
	const int LogLevelWarning = 1;
	const int LogLevelInfo = 2;
private: 
	int m_LogLevel = LogLevelInfo;//意思是所有的东西都打印出来
public:
	void SetLevel(int level)
	{
		m_LogLevel = level;
	}

	void Warn(const char* massage)
	{
		if (m_LogLevel >= LogLevelWarning)
			cout << "[WARNING]" << massage << endl;
	}
	
	void Info(const char* massage)
	{
		if (m_LogLevel >= LogLevelInfo)
			cout << "[INFO]" << massage << endl;
	}

	void Error(const char* massage)
	{
		if (m_LogLevel >= LogLevelError)
			cout <<	"[ERROR]" << massage << endl;
	}

};

int main()
{
	Log log;
	log.SetLevel(log.LogLevelWarning);
	log.Warn("hello!");
	log.Error("hello!");
	log.Info("hello!");
	return 0;
}
