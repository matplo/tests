#include "useUtils.h"

#include <utils/MyUtils.h>

#include <iostream>
using namespace std;

void useUtils()
{
	cout << "[i] This is test1..." << endl;

	MyUtils ut("called_from_c_function");
	ut.Loop(10);

	cout << "[i] Done." << endl;
}

