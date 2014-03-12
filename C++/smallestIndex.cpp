#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int smallestIndex(int a[], int size);
int lastlargestIndex(int a[], int size);
void testscores();


int main(){
	
	const int Arraysize = 6;
	int a[Arraysize] = { 1, 3, 5, -10, -10, 5};
	
	cout << "The index of the first instance of the smallest number in this array is: " << smallestIndex(a,Arraysize) << endl << endl;

	cout << "The index of the last instance largest number in this array is: " << lastlargestIndex(a, Arraysize) << endl << endl << endl;
	
	testscores();

	system("pause");
	return 0;

}// end main()



int smallestIndex(int a[], int size){
	int valueofsmallest = 0;
	int indexofsmallest = 0;

	for (int i = 0; i < size; i++){

		if (a[i] < valueofsmallest){
			valueofsmallest = a[i];
			indexofsmallest = i;
		}// end if

	}//end for
	
	return indexofsmallest;
}// end smallestIndex()


int lastlargestIndex(int a[], int size){
	int valueoflargest = 0;
	int indexoflargest = 0;

	for (int i = 0; i < size; i++){

		if (a[i] >= valueoflargest){
			valueoflargest = a[i];
			indexoflargest = i;
		}// end if

	}//end for
return indexoflargest;
}// end largestIndex()


void testscores(){

	//get the data
	ifstream scoreData;
	scoreData.open("testscores.txt");  // needs to be adjsuted for the appropriate directory
	
	if (scoreData.fail()){   //check that file is opened correctly
		cerr << "Opening file scoreData failed." << endl;
		cerr << "Program exiting." << endl;
		system("pause");
		exit(1);

	}
	//put the data into an array
	const int ScoreSize = 26;
	int scoreArray[ScoreSize];

	int i = 0; //counter for incrementing index of scoreArray
	while(!scoreData.eof()){ //put values of scoreData into the array
		scoreData >> scoreArray[i];
		i++;
	}

	int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0;  //range counters

	for(int i = 0; i < ScoreSize; i++){ //cycle through each index in the array and add a counter to the appropriate range
		if(scoreArray[i] < 25){
			a++;
		}

		else if(scoreArray[i] < 50){
			b++;
		}
		else if(scoreArray[i] < 75){
			c++;
		}
		else if(scoreArray[i] < 100){
			d++;
		}
		else if(scoreArray[i] < 125){
			e++;
		}
		else if(scoreArray[i] < 150){
			f++;
		}
		else if(scoreArray[i] < 175){
			g++;
		}
		else if(scoreArray[i] <= 200){
			h++;
		}
		else{
			cout << "Score is outside of normal range." << endl;
		}

	}//end for loop
		cout << "Test Score Ranges and Quantities for Each:" << endl << endl; 
		cout << " 0-24:      " << a << endl;
		cout << " 25-49:     " << b << endl;
		cout << " 50-74:     " << c << endl;
		cout << " 75-99:     " << d << endl;
		cout << " 100-124:   " << e << endl;
		cout << " 125-149:   " << f << endl;
		cout << " 150-174:   " << g << endl;
		cout << " 175-200:   " << h << endl << endl;
	
	scoreData.close();
	
}// end testscores()