#ifndef System_Monitor
#define System_Monitor

#include <iostream>	// for standard input and output
#include <windows.h>	// for Windows API functions

class SystemMonitor
{
public:
	SystemMonitor(); // constructor
	~SystemMonitor(); // destructor

	//public member functions, aka methods

	void displaySystemInfo(); // method to display system information
	void getCPUUsage(); // method to get CPU usage
	DWORDLONG getTotalPhysicalMemory(); // method to get total physical memory
	DWORDLONG getfreePhysicalMemory(); // method to get free physical memory
	void getmeter(); // method to get system metrics




private:
	FILETIME lastidleTime, lastkernelTime, lastuserTime; // private member variables to store last CPU times
	//used for calculating CPU usage in getCPUUsage method.

	double CalcCPUUsage(const FILETIME& idleTime, const FILETIME& kernelTime, const FILETIME& userTime); // private method to calculate CPU usage
	// & indicates that the method takes references to FILETIME objects as parameters, allowing it to access the original objects without making copies. aka pass by reference.
	//const indicates that the method will not modify the passed variables, aka they are read-only within the method.

};
#endif // !System_Monitor_H
//to define header file only once during compilation

SystemMonitor::SystemMonitor()
{
}

SystemMonitor::~SystemMonitor()
{
}

