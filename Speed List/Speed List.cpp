

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include "functions.h"

using namespace std;






int main()
{
	string pathIn = "TXTFiles/SpeedListL1_out.txt";
	string pathOut = "TXTFiles/LR1_coordsOnlyIdeal.txt";



	columnParser(pathIn,pathOut);
	//writeLinearSpeed(pathOut);
}










