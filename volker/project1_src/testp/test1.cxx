#include "test1.h"

#include <utils/MyUtils.h>

#include <iostream>
using namespace std;

void test1 ( int argc, char *argv[] )
{
	cout << "[i] This is test1..." << endl;

	MyUtils ut("called_from_test1_Volker_exec");
	ut.Loop(100);

	cout << "[i] Done." << endl;
}
