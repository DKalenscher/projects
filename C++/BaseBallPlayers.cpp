#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;


struct fruitType{
string name;
string color;
int fat;
int sugar;
int carbohydrate;
};

struct baseballPlayer {
string nameFirst;
string nameLast;
int homerun;
int hits;

};


void getFruitInput(fruitType &fruit); 
void printFruitOutput(fruitType fruit); 
void getPlayerData(baseballPlayer roster[],const int RosterSize);
void printPlayerData(baseballPlayer roster[], const int RosterSize);



int main(){

	const int RosterSize = 5;
	baseballPlayer roster[RosterSize];
	fruitType fruit;

	cout << "-----PARTS 1 & 2-----" << endl;
	getFruitInput(fruit);
	cout << endl;
	printFruitOutput(fruit);
	cout << endl <<endl;
	
	cout << "-----PART 3-----" << endl;
	getPlayerData(roster,RosterSize);
	printPlayerData(roster,RosterSize);



	system("pause");
return 0;
} //end main()


void getFruitInput(fruitType &fruit){
cout << "Please enter the name of the fruit: ";
cin >> fruit.name;

cout << "Please enter the color of the fruit: ";
cin >> fruit.color;

cout << "Please enter the fat content of the fruit: ";
cin >> fruit.fat;

cout << "Please enter the sugar content of the fruit: ";
cin >> fruit.sugar;

cout << "Please enter the carbohydrate content of the fruit: ";
cin >> fruit.carbohydrate;

}

void printFruitOutput(fruitType fruit){

cout << "Fruit Name: " << fruit.name << endl;
cout << "Fruit Color: " << fruit.color << endl;
cout << "Fat Amount: " << fruit.fat << endl;
cout << "Sugar Amount: " << fruit.sugar << endl;
cout << "Carbohydrate Amount: " << fruit.carbohydrate << endl;

}

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