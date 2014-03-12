//Daniel Kalenscher
//2-19-2014
//Shapes HW
#include <iostream>
using namespace std;

void userInputs(int &height, char &symbol); 
void triangle(int height, char symbol);
void square(int height, char symbol);
void circle(int height, char symbol);
void figure8(int height, char symbol);
void rhombus(int height, char symbol);
bool isOnPerimeter(int row, int column, int radius);

int main(){
    //init values
	int height = 0;
    char symbol = ' ';
    char userSelection;

    cout << "Welcome to the Shape Drawing Program!" << endl << endl; 

    bool repeatProgram = true;
    while(repeatProgram == true){ 
        cout << "Please make a selection: " << endl << endl;
        cout << "(T)riangle" << endl << "(S)quare" << endl << "(C)ircle" << endl << "(F)igure 8" << endl << "(R)hombus" << endl << "(Q)uit" << endl << endl << ">";
        cin >> userSelection;
        cin.clear();  
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  //stops cin from readying multiple char inputs to be used for the next cin instance



        bool selectionCheck = true;
        while(selectionCheck == true){
            if(userSelection == 'T' || userSelection == 't'){
            triangle(height,symbol);
            selectionCheck = false;
            }

            else if (userSelection == 'S' || userSelection == 's'){
            square(height,symbol);
            selectionCheck = false;
            }

            else if (userSelection == 'C' || userSelection == 'c'){
            circle(height,symbol);
            selectionCheck = false;
            }

            else if (userSelection == 'F' || userSelection == 'f'){
            figure8(height,symbol);
            selectionCheck = false;
            }

            else if (userSelection == 'R'|| userSelection == 'r'){
            rhombus(height,symbol);
            selectionCheck = false;
            }

            else if (userSelection == 'Q'|| userSelection == 'q'){
            selectionCheck = false;
            repeatProgram = false;
            }
            else{
            cout << "Invalid selection, please try again." << endl << "> ";
            cin >> userSelection;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
            selectionCheck = true;
            }
        }//end while(selectionCheck)

    }// end while(repeatProgram)


    cout << "Thanks for using the Shape Drawing Program.  Have a nice day!" << endl;
    
	system("pause");
    return 0;
} //end main()

void userInputs(int &height, char &symbol){
    
	bool checkHeight = true;
    while(checkHeight){
		cout << "Please enter a height for your shape." << endl << ">";
		cin >> height;
   
        if(cin.fail()){                          //error checking for cin type, should only be int
            cout << "Integers Only!" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<int>::max(),'\n'); //cin has to be cleared after we check cin.fail
		}
        else{
            checkHeight = false;
        }
    }// end while(checkHeight)



    cout << "Please enter a character to draw the shape." << endl << ">";
    cin >> symbol;
    cout << endl;

}//end userInputs()


bool isOnPerimeter(int row, int column, int radius){

       if (pow(static_cast<double>(row),2.0)+pow(static_cast<double>(column),2.0)<=pow(static_cast<double>(radius),2.0) &&
              pow(static_cast<double>(row),2.0)+pow(static_cast<double>(abs(column)+1),2.0) > pow(static_cast<double>(radius),2.0))

              return true;

       else
              return false;
}// end isonPerimeter()


void triangle(int height, char symbol){
    userInputs(height,symbol);
    int width = 2*height -1; //character width of bottom of triangle = 2(height)-1
    int leftSide = height; //determines how many blank spaces are added on the left side of the triangle
    int heightCounter = 1; // determines which line of the triangle is currently being drawn (top to bottom)
    
    for(int i = 0; i < height -1; i++){
    
        for(int w = 0; w < leftSide -1 ;w++){    //adds spaces before the left side
            cout << ' ';
        }
     
        cout << symbol;  // left side symbol

        for(int w = 0; w < (2*heightCounter)-1;w++){// adds spaces in the middle
            cout << ' ';
        }

        cout << symbol << endl;  //right side symbol

        leftSide -=1;            //decreases the size of the left side space by 1 per line
        heightCounter +=1;        // increases height so middle spaces can be incremented
    }

    for(int w = 0; w < width+2; w++){         //makes bottom line
        cout << symbol;
    }

    cout << endl << endl;
}// end triangle()


void square(int height, char symbol){
    userInputs(height,symbol);

    for(int i = 0; i < height; i++){                //makes top line of square
        cout << symbol;
    }

    cout << endl;

    for(int i = 0; i < (height-2); i++){            //does a single row per iteration 
        cout << symbol;
        
        for(int w = 0; w < (height -2); w++){       // symbol on first and last spot spaces in between
            cout << ' ';
        }

        cout << symbol;
        cout << endl;

    }//for row iterations

    for(int i = 0; i < height; i++){               //makes bottom line of square
        cout << symbol;
    }

    cout << endl;
}//end square()


void circle(int height, char symbol){
    userInputs(height,symbol);
    int radius = height * 0.5; 
// using -radius to +radius so that the center is (0,0) (makes computation easier)

       for (int row = radius;row >= -radius;--row) {

              for (int column = -radius;column <= radius;++column)

                     if (isOnPerimeter(row,column,radius)){
                         cout << symbol;
                     }
                     else{
                         cout <<" ";
                     }
            cout << endl;
       }// end for
}// end circle()


void figure8(int height, char symbol){  //Couldn't call circle() twice because circle() calls userInputs() each time, resetting the heights and styles
        userInputs(height,symbol);
        int radius = height * 0.25; 

        for (int row = radius;row >= -radius;--row) {

            for (int column = -radius;column <= radius;++column)

                if (isOnPerimeter(row,column,radius)){
                        cout << symbol;
                }
                else{
                    cout <<" ";
                }

        cout << endl;
        }// end for

        for (int row = radius;row >= -radius;--row) {

            for (int column = -radius;column <= radius;++column)

                if (isOnPerimeter(row,column,radius)){
                    cout << symbol;
                }
                    else{
                        cout <<" ";
                    }
            cout << endl;
        }// end for

        cout << endl;
}//end figure8()


void rhombus(int height, char symbol){
        userInputs(height,symbol);
    //same as doing the left side from the triangle function and building a square normally afterwards.

    
    int leftSide = height;
    int heightCounter = 1;
    
    for(int i = 0; i < height -1; i++){
    
        for(int w = 0; w < leftSide -1 ;w++){    //adds spaces before the left side
            cout << ' ';
        }
            if(heightCounter ==1){ //add a full line if on the top, otherwise add only one
                    for(int w = 0; w < height; w++){         //makes top line
                        cout << symbol;
                    }
            }
            else{
                cout << symbol;  // left side symbol
            }

        for(int w = 0; w < height-2 ;w++){// add a set amount of space in between middle = width -2
            cout << ' ';
        }
            if(heightCounter != 1){         //only add right side symbol if not on the top line        
                cout << symbol;
            }
            cout << endl;

        leftSide -=1;            //decreases the size of the left side space by 1 per line
        heightCounter +=1;
    }

    for(int w = 0; w < height; w++){         //makes bottom line
        cout << symbol;
    }

    cout << endl << endl;
}//end rhombus()