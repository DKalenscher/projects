//Daniel Kalenscher
//10-10-2013
//Accepts user input for the dimensions of a rectangle.  Allows for choice to calculate area or perimeter.  
// Stores results in external .txt file, error checks all inputs, allows for multiple reptitions.
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main(){
	double width, length, area, perimeter;
	ifstream inData;
	ofstream outData;
	char apchoice, rerun;

	outData.open("C:\\Users\\Dan\\Desktop\\Programming\\C++\\Rectangle\\Results.txt");

	int i=0;
	while (i == 0){  // control loop for multiple reptitions

		int widthcheck = 0;
		while(widthcheck == 0){  // width error check loop

			cout << "Please enter the width of the rectangle: ";
			cin >> width;

				if (width > 0){
					outData << "The width you chose was: " << width << endl;
					widthcheck = 1;
				}

				else{
						cout << endl << "*** You must enter a value greater than 0. ***" << endl << endl;
				}
		}

		int lengthcheck = 0;
		while (lengthcheck == 0){ // length error check loop

			cout << endl << "Please enter the length of the rectangle: ";
			cin >> length;

				if(length > 0){
					outData << "The length you chose was: " << length << endl;
					lengthcheck = 1;
				}

				else{
					cout << endl << "*** You must enter a value greater than 0. ***" << endl;
				}
		}
		
		int aploop = 0;
		while(aploop == 0){  // area/perimeter selection choice error loop
			
			cout << endl << "Would you like to calculate Area or Perimeter? (A/P)";
			cin >> apchoice;

			if(apchoice == 'A' || apchoice == 'a'){ //Area Selected
				area = (width) * (length);
				cout << endl << "The area of this rectangle is: " << area << endl;
				outData << endl << "You selected to calculate Area." << endl;
				outData << endl << "The area of this rectangle is: " << area << endl;
				aploop = 1;
			}

			else if(apchoice == 'P' || apchoice == 'p'){  //Perimeter Selected
				perimeter = (width * 2) + (length * 2);
				cout << endl << "The perimeter of this rectangle is: " << perimeter << endl;
				outData << endl << "You selected to calculate Perimeter." << endl;
				outData << endl << "The perimeter of this rectangle is: " << perimeter << endl;
				aploop = 1;
			}

			else{
				cout << endl << "*** Please make a selection of A or P ***" << endl;
			}
		}

		int rerunloop = 0;
		while (rerunloop == 0){ // checks input of Yes/No to rerun the program
			cout << endl << "Would you like to run this program again? (Y/N)";
			cin >> rerun;
			cout << endl << "================================================" << endl << endl;
			outData << endl << "================================================" << endl << endl;

			if(rerun == 'Y' || rerun =='y'){
				rerunloop = 1;
			}
			else if (rerun == 'N' || rerun =='n'){
				i = 1;
				rerunloop = 1;
				cout << "Thank you for using this program, your results are located in \"recangle.txt\"." << endl << endl;
				outData.close();
				system("pause");
			}

			else{
				cout << " ***Please make a selection of Y or N" << endl;
			}
		}
	
	}
	
}