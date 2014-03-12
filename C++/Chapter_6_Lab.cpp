#include <iostream>
using namespace std;

int reverseDigit(int inputNum);

int iveBeenCalled();

void initialize(int &x, int &y, char &z); 

void getHoursRate(double &hours, double &rate);

double paycheck(double hours, double rate, double &amount);

void printCheck(double hours, double rate, double amount);

void funcOne(int &x, int y);

void nextChar(char &z);

int main(){
	//------------------------ REVESE DIGIT ------------------------------------------
	cout << endl << "------------------------ REVESE DIGIT ------------------------------------------" << endl;
	int inputNum = 0;

	cout << "Please enter your number to be reversed: ";
	cin >> inputNum;
	cout << endl << reverseDigit(inputNum) << endl;

	//------------------------ IVE BEEN CALLED ----------------------------------------
	cout << endl << endl << "------------------------ IVE BEEN CALLED ---------------------------------------" << endl;
	iveBeenCalled();
	iveBeenCalled(); //calling the function a few times to run up the counter.
	cout << "You have called 'iveBeenCalled' " << iveBeenCalled() << " times (including in this cout command)." << endl;

	//------------------------ RATE & HOURS -------------------------------------------
	cout << endl << endl << "------------------------ RATE & HOURS ------------------------------------------" << endl;
	
	int x, y;
	char z;
	double hours, rate;
	double amount;

	//part a.
	initialize(x,y,z);
	cout << "---Part a.---" << endl;
	cout << "Initialization Complete... " << endl;
	cout << "x is: " << x << endl;
	cout << "y is: " << y << endl;
	cout << "z is: " << z << endl;
	cout << endl << endl;

	//part b.
	cout << "---Part b.---" << endl;
	getHoursRate(hours,rate); 
	cout << "Initialization Complete... " << endl;
	cout << "hours is: " << hours << endl;
	cout << "rate is: " << rate << endl;
	cout << endl;


	//part c.
	cout << "---Part c.---" << endl;
	cout << "The amount earned is: " << paycheck(hours,rate,amount) << endl << endl;


	//part d.
	cout << "---Part d.---" << endl;
	printCheck(hours, rate, amount);

	//part e.
	cout << endl << "---Part e.---" << endl;
	funcOne(x,y);
	cout << "The new value of x is: " << x << endl << endl;

	//part f
	cout << "---Part f.---" << endl;
	nextChar(z);
	cout << "The new value of z is: " << z << endl << endl;




	system("pause");
	return 0;
}


//-------------------------------NON-MAIN FUNCTIONS---------------------------------


//-------------Part 1: reverseDigit Function
int reverseDigit(int inputNum){
	int outputNum = 0;

	while (inputNum != 0){
	int LSD = inputNum % 10;  //  get the LSD    %10

	outputNum = outputNum + LSD;//  Put LSD into output  add LSD to output

	outputNum = outputNum * 10;//  Shift output left   x10
	inputNum = inputNum / 10;  // Shift input right  /10


	}  // end while(inputNum !=0)

	outputNum = outputNum / 10;
	return outputNum;
}


//-------------Part 2: iveBeenCalled Function
int iveBeenCalled(){
	static int callcounter;
	callcounter++;
	return callcounter;
}//end iveBeenCalled()

//-------------Part 3--------------------------
void initialize(int &x, int &y, char &z){
	x = 0;
	y = 0;
	z = ' ';
} //end initialize()


void getHoursRate(double &hours, double &rate){

	cout << "Please input the number of hours worked: ";
	cin >> hours;

	cout << "Please input the rate per hour: ";
	cin >> rate;
	cout << endl;
} //end getHoursRate()

double paycheck(double hours, double rate, double &amount){
	
	if(hours <= 40){   
	amount = hours * rate;
	}

	else{
	amount = ((40 * rate) + (hours-40)*(rate*1.5));  
	}

	return amount; 
} //end paycheck()


void printCheck(double hours, double rate, double amount){
cout << "Printing your check now..." << endl;
cout << "The number of hours worked is: " << hours << endl;
cout << "The base rate per hour is: " << rate << endl; 
cout << "The salary earned for this period is: " << paycheck(hours,rate,amount) << endl;
} //end printCheck()


void funcOne(int &x, int y){
	int inputNum;
	cout << "Please enter a number: ";
	cin >> inputNum;

	x = 2*x + y - inputNum;
}//end funcOne


void nextChar(char &z){
	z = z+1;
}//end nextChar()
