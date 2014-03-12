#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct baseballPlayer {
string nameFirst;
string nameLast;
int homerun;
int hits;

};

void getPlayerData(baseballPlayer roster[],const int RosterSize);
void printPlayerData(baseballPlayer roster[], const int RosterSize);
int searchRoster(baseballPlayer roster[], const int RosterSize); 
void updateRoster(baseballPlayer roster[]); 
void loadRosterFile(baseballPlayer roster[],const int RosterSize);
void closeRosterFile(baseballPlayer roster[],const int RosterSize);




int main(){

	const int RosterSize = 5;
	baseballPlayer roster[RosterSize];
	
	loadRosterFile(roster,RosterSize);
	
	
	int exit = 0;
	while(exit == 0){
	
	int menuChoice;

	cout << "Please make a selection(1-4): " << endl;
	cout << "1. Enter new roster data. " << endl;
	cout << "2. Print current roster data. " << endl;
	cout << "3. Search Roster." << endl;
	cout << "4. Update Roster." << endl;
	cout << "5. Save and Quit." << endl;
	
	cin >> menuChoice;
	
		if (menuChoice == 1){
			getPlayerData(roster,RosterSize);
		}

		if (menuChoice == 2){
			printPlayerData(roster,RosterSize);
		}

		else if(menuChoice == 3){
			cout << "The player you are searching for is located at index: " << searchRoster(roster,RosterSize) << endl << endl;

		}

		else if(menuChoice == 4){
			updateRoster(roster);
		}

		else if(menuChoice == 5){
			cout << "Saving and exiting..." << endl;
			closeRosterFile(roster,RosterSize);
			exit = 1;
		}

	}//end while



	system("pause");
return 0;
} //end main()


void getPlayerData(baseballPlayer roster[],const int RosterSize){
	
	for(int i = 0; i < RosterSize; i++){

	cout << "Please enter player number " << i+1 << "'s first name: ";
	cin >> roster[i].nameFirst;

	cout << "Please enter player number " << i+1 << "'s last name: ";
	cin >> roster[i].nameLast;


	cout << "Please enter player number " << i+1 << "'s homeruns: ";
	cin >> roster[i].homerun;

	cout << "Please enter player number " << i+1 << "'s hits: ";
	cin >> roster[i].hits;
	
	cout << endl;
	}
	cout << endl;
}


void printPlayerData(baseballPlayer roster[], const int RosterSize){

	for(int i = 0; i < RosterSize; i++){
	cout << "---Player " << i+1 << "---" << endl;
	cout << roster[i].nameFirst << " " << roster[i].nameLast << endl;

	cout << "Homeruns: " << roster[i].homerun << endl;
	
	cout << "Hits: " << roster[i].hits << endl << endl << endl;
	
	}


}

int searchRoster(baseballPlayer roster[], const int RosterSize){
	
	string searchName;
	int indexResult;

	cout << "Please enter the player's last name: ";
	cin >> searchName;

	for(int i=0; i < RosterSize;i++){
		if (roster[i].nameLast == searchName){
			indexResult = i;
		}
	}
	
	return indexResult;

}

void updateRoster(baseballPlayer roster[]){
	int indexNum;

	cout << "Please enter the index of the player you would like to update: ";
	cin >> indexNum;

	cout << "Current information on player: " << endl;
		cout << "First Name: " << roster[indexNum].nameFirst << endl;
		cout << "Last Name: " << roster[indexNum].nameLast << endl;
		cout << "Homeruns: " << roster[indexNum].homerun << endl;
		cout << "Hits: " << roster[indexNum].hits << endl;

	cout << "Please enter new information: " << endl; 
		cout << "First Name: ";
		cin >> roster[indexNum].nameFirst;

		cout << "Last Name: ";
		cin >> roster[indexNum].nameLast;

		cout << "Homeruns: ";
		cin >> roster[indexNum].homerun;

		cout << "Hits: ";
		cin >> roster[indexNum].hits;
}

void loadRosterFile(baseballPlayer roster[],const int RosterSize){
	
	ifstream inRoster("rosterdatafile.txt"); 
	
	if (inRoster.fail()){    //if there is no previous roster file creates blank values
		for(int i = 0; i < RosterSize; i++){
			roster[i].nameFirst = " ";
			roster[i].nameLast = " "; 
			roster[i].homerun = 0;
			roster[i].hits = 0;
		}
		
	}// end if
	else{
		int i = 0;
		while(!inRoster.eof() && i < RosterSize){
			inRoster >> roster[i].nameFirst;
			inRoster >> roster[i].nameLast; 
			inRoster >> roster[i].homerun;
			inRoster >> roster[i].hits;
	
			i++;
		}

	}//end else
	
}// end loadRosterFile

void closeRosterFile(baseballPlayer roster[],const int RosterSize){
	
	ofstream outRoster("rosterdatafile.txt"); 
	
	for(int i = 0; i < RosterSize; i++){
		outRoster << roster[i].nameFirst << " " << endl;
		outRoster << roster[i].nameLast << " " << endl; 
		outRoster << roster[i].homerun << " " << endl;
		outRoster << roster[i].hits << " " << endl;
		
	}
}