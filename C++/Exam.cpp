// Daniel Kalenscher
// 11/15/2013
// Reads in any number of names and weights(kg) from a .txt. 
// Converts weight to lb, averages total weight, and creates an output file.  Weights msut be displayed to 2 decimal places.  

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){
	
	string fname, lname;
	double weight_kg, weight_lb, weight_avg;
	
	int i = 0; // init counter for total number of entries
	double weight_sum = 0; //init for running total of weights

	ifstream inData;
	ofstream outData;

	inData.open("C:\\Users\\Dan\\Desktop\\Programming\\C++\\Exam\\ExamData.txt");
	outData.open("C:\\Users\\Dan\\Desktop\\Programming\\C++\\Exam\\Results.txt");

		while(inData.eof()!=true){

			i++; //counts number of lines/entries in .txt file

			inData >> fname >> lname >> weight_kg;

			weight_lb = weight_kg *2.2;

			outData << "===========Entry " << i << "===========" << endl;
			outData << "First Name: " << fname << endl;
			outData << "Last Name : " << lname << endl;
			outData << setprecision(2) << fixed << "Weight(kg): " << weight_kg << endl;
			outData << setprecision(2) << fixed << "Weight(lb): " << weight_lb << endl << endl;

			weight_sum += weight_lb;
		}

		weight_avg = weight_sum / i;

		outData << "=============================" << endl;
		outData << setprecision(2) << fixed << "Average weight(lb) for all " << i << " entries is: " << weight_avg << endl;

		inData.close();
		outData.close();
		cout << "Run Completed.  Please see Results.txt." << endl;
		system("pause");
}