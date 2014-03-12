//Daniel Kalenscher
//2-26-2014
//Ch 8 - HW [Flight Capacity]

#include <iostream>
#include <fstream>
using namespace std;

void fillSeatInfo(int passCapacity[],int passTickets[], int FlightArraySZ,int &flightNum);  //populates two parallel arrays and counts the number of entries in the loaded file.
int deniedBoarding(int passCapacity[], int passTickets[], int FlightArraySZ, int flightNum); //compares tickets sold to seats available
void flightSales(int passCapacity[], int passTickets[], int FlightArraySZ, int flightNum); //categorizes the % of flight fullness



int main(){
	const int FlightArraySZ = 100;
	int passCapacity[FlightArraySZ];
	int passTickets[FlightArraySZ];
	
	int flightNum = 0; //used as a counter to determine how many values get put into the arrays from file. 

	fillSeatInfo(passCapacity,passTickets,FlightArraySZ, flightNum);   //populates two parallel arrays for tickets sold and number of seats available
	
	cout << "There were "<< deniedBoarding(passCapacity,passTickets,FlightArraySZ, flightNum) << " people denied boarding." << endl << endl;  
	
	flightSales(passCapacity,passTickets,FlightArraySZ,flightNum);

	system("pause");
	return 0;
}




void fillSeatInfo(int passCapacity[],int passTickets[],int FlightArraySZ,int &flightNum){


	ifstream getseatData("FlightData.txt");
	if (getseatData.fail()){   //check that file is opened correctly
		cerr << "Opening Flight Data file failed." << endl;
		cerr << "Program exiting." << endl;
		system("pause");
		exit(1);

	}

	
	while(!getseatData.eof() && flightNum < FlightArraySZ){
		getseatData >> passCapacity[flightNum];
		getseatData >> passTickets[flightNum];
		flightNum++;
	}
	


}//endfillSeatInfo()


int deniedBoarding(int passCapacity[], int passTickets[], int FlightArraySZ, int flightNum){
	int numDenied = 0;
	int oversold = 0;
	
	for(int i = 0; i < flightNum; i++){ 
		oversold = passTickets[i] - passCapacity[i]; 

		if(oversold > 0){  //only adds the positive numbers of 3rd array, aka only when tickets > seats
			numDenied += oversold;
		}

	}// end for

	return numDenied;
}//end deniedBoarding()


void flightSales(int passCapacity[], int passTickets[], int FlightArraySZ, int flightNum){
	double percentSold = 0.0;
	int a = 0, b = 0, c = 0, d= 0;   //counters for percentage categories


	for(int i = 0; i < flightNum; i++){
		percentSold = (static_cast<double>(passTickets[i])/static_cast<double>(passCapacity[i]))*100;
		
		if(percentSold < 70.0){
			a++;
		}

		else if (percentSold >= 70.0 && percentSold < 90.0){
			b++;
		}

		else if (percentSold >= 90.0 && percentSold <= 100.0){
			c++;
		}

		else{
			d++;
		}

	}//end for

		cout << a << " flights were less than 70% full." << endl << endl;
	cout << b << " flights were between 70% and 90% full." << endl << endl;
	cout << c << " flights were between 90% and 100% full." << endl << endl;
	cout << d << " flights were oversold." << endl << endl;


}//end flightSales()



















////1. # of people denied boarding  =  tickets > capacity    So do tickets - capacity to find and add only positive numbers.
//
//
////2.  number of flights  < 70% full
//						between 70 and 90% full 
//							90% to 100% full 
//		> 100% full