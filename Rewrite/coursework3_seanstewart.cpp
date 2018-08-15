// Cellular Autoamton Rewrite. 
// Written by Sean Stewart

#include <iostream>
#include <string> 
#include <fstream> 
using namespace std;


// Method Declaration
void menu();
void menuLoop(); 
void settingsMenu();
void setRule(int);
int convertToDecimal();
void displaySettingsMenu(); 
int calculateValues(int,int,int);
int determineChildValues(int[], int, int);
void generateValues(int,int);
void resetToDefault();
bool determineOptionOutcome(char); 


int rule[8] = {0, 1, 0, 1, 1, 0, 1, 0}; // -Array to hold the Rules. By default it is set to Rule 90. 
int numoflines = 24;
int width = 48;

// ----Main Method----
int main(){

	menuLoop();

return 0;

} // ---End of Main Method ---

void menuLoop(){
	// -- Varaibles for the width and the number of lines. By default they are set to 32. 

	
// Variables that relate to the menu
	int choice;
	char option;
	int rulenumber;
	bool loopcomplete = false;

// -- Do-While Loop to Display a Menu until the Program is exited.
	do {
		menu();
		cout << "Choice: " ;
		cin >> choice;
		
		switch (choice) {
		
			case 1:{
				cout << endl; 
				cout << "Rule: " << convertToDecimal() << "\t Number of Generations: " << numoflines << "\t Width of Automaton: " << width << endl;
				cout << endl; 
				generateValues(width, numoflines);
				break;
			}
				
			case 2:{
				setRule(rand() % 255);
				cout << endl; 
				cout << "Rule: " << convertToDecimal() << "\t Number of Generations: " << numoflines << "\t Width of Automaton: " << width << endl;
				cout << endl; 
				generateValues(width, numoflines);
				resetToDefault();
				break;
				}
			case 3: {
					displaySettingsMenu(); 
					break;
				}

//Statement to output to a file - Note this does not function. 

/*			case 6: { 
					ofstream outputfile;
  					outputfile.open ("cellular_automaton_output.txt");
					outputfile << "--------------------------------------------------------------- \n" ;
  					outputfile << "Rule: " << getRule() << "\t Number of Generations: " << numoflines << "\t Width of Automaton: " << width;
					
					outputfile << "\n" << generateValues(width, numoflines) << "\n";
  					outputfile.close();

					cout << endl;
					cout << "The output has been stored to the file." << endl;
					cout << endl;
					break;
				} */
			case 4: {
					cout << "Thank you for using the program." << endl;
					break;
				}
				
			default: {
				cout << endl;
				cout << "ERROR: Invalid Option. Please enter a value between 1 and 5!" << endl;
				cout << endl; 
				}
			}// - End of Switch Statement
 
	}while (choice != 4);

}


// ---- Menu Method ----
void menu() {
	cout << endl;
	cout << "===============================================================" << endl;
	cout << "-------------------------MAIN MENU-----------------------------" << endl;
	cout << "===============================================================" << endl;	
	cout << "Please choose from the following options" << endl; 
	cout << "---------------------------------------------------------------" << endl;
	cout << " 1.\tView Cellular Automaton" << endl;
	cout << " 2.\tView a Random Cellular Automaton Rule" << endl;	
	cout << " 3.\tChange Display Settings" << endl;		
	cout << " 4.\tExit The Program" << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << endl; 
	
return;
} // ---- End of Menu Method ---

void settingsMenu(){
	cout << endl; 
	cout << "===============================================================" << endl;
	cout << "------------------------- SETTINGS ----------------------------" << endl;
	cout << "===============================================================" << endl;	
	cout << "Please choose from the following options" << endl; 
	cout << "---------------------------------------------------------------" << endl;
	cout << " 1.\tView Current Settings" << endl;
	cout << " 2.\tChange Cellular Automaton Rule" << endl;
	cout << " 3.\tChange Number of Lines Generated" << endl;
	cout << " 4.\tChange Width of Cellular Automaton" << endl;
	cout << " 5.\tReset to Default Settings" << endl;
	cout << " 6.\tReturn to Main Menu" << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << endl; 	
}

void displaySettingsMenu(){
	int choice = 0 ;
	while (choice !=6){
		settingsMenu();
		cout << "OPTION: "; 
		cin >> choice;
		cout << endl;  
		switch (choice){

			case 1: {
				cout << "=====================================================" << endl;
				cout << "---------------- CURRENT SETTINGS -------------------" << endl;
				cout << "=====================================================" << endl;	
				cout << "\tRULE:\t" << convertToDecimal() << endl;
				cout << "\tWIDTH:\t" << width << endl;
				cout << "\tLINES:\t" << numoflines << endl;
				cout << "=====================================================" << endl;
				break;
			}
			
			case 2: {
				char input;
				cout << "The Current Rule is: RULE " << convertToDecimal() << endl;  
				cout << "Do you wish to change this? (Y/N)" << endl; 
				cin >> input; 
				if (determineOptionOutcome(input)){
					int newrule;
					bool incompleteloop = true; 
					while (incompleteloop){
						cout << "Please enter a new rule number that you wish to change" << endl;
						cout << "RULE: ";
						cin >> newrule; 
						if (newrule < 0 | newrule > 255) {
							cout << "Number is invalid. Please enter a valid number" << endl; 
						} else {
							incompleteloop = false; 
						}
					}
					setRule(newrule); 
				}
				break;
			}

			case 3: {
				char input;
				cout << "The Number of Lines displayed is:  " << numoflines << endl;  
				cout << "Do you wish to change this? (Y/N)" << endl; 
				cin >> input; 
				if (determineOptionOutcome(input)){
					int newlines;
					cout << "Please enter a new the new number of lines" << endl;
					cout << "NUMBER OF LINES: ";
					cin >> newlines; 
					numoflines = newlines; 
					}
				break; 	
				}

			case 4: {
				char input;
				cout << "The Current width of the cellular automaton is: " << width << endl;  
				cout << "Do you wish to change this? (Y/N)" << endl; 
				cin >> input; 
				if (determineOptionOutcome(input)){
					int newwidth;
					cout << "Please enter a new rule number that you wish to change" << endl;
					cout << "RULE: ";
					cin >> newwidth; 
					width = newwidth; 
				}
				break;
			}

			case 5: {
				char input;
				cout << "Do you wish to revert back to default settings? (Y/N)" << endl; 
				cin >> input; 
				if (determineOptionOutcome(input)){
					resetToDefault();
					width = 32;
					numoflines = 16; 
				}
				break; 
			}

			case 6: {
				break;
			}

			default: {
				cout << endl;
				cout << "ERROR: Invalid Option. Please enter a value between 1 and 6!" << endl;
				cout << endl; 
				break;
			}
		}
	}
}

bool determineOptionOutcome(char input){
	input = toupper(input);

	if (input == 'Y'){
		return true; 
	} else {
		return false; 
	}
}

void setRule(int numtoconvert){
    int binarynumber[8];
        for (int i  = 7; i >= 0; i--) { 
            binarynumber[i] =  (numtoconvert % 2) ; //Sets the remainder of each loop to the present value in the array
            numtoconvert = numtoconvert / 2 ; // Divides the number by two each time, As in 8 bit binary, each number is divisable by two
			rule[i] = binarynumber[i]; 
        }
}

int convertToDecimal(){
// Loops through the array and converts the value from binary into decimal.
	int binaryvalue = 128;
	int total = 0;

	for (int i = 0; i < 8; i++){
		if (rule[i] == 1){
			total += binaryvalue;
		} 
		binaryvalue = binaryvalue/2; 
	}

	return total; 

}

void resetToDefault(){
	int newrule[8] = { 0, 0, 0, 1, 1, 1, 1, 0 };
	for(int i = 0; i < 8; i++){
		rule[i] = newrule[i];
	}
}

void generateValues(int width, int generations){ //This code is based off the Nature of Code's sample code for Cellular Automaton -- See References below. 

	int parentgeneration[width];  // The array for the previous values of each generation
	int childgeneration[width];   // The array for the current values of each generation

	for (int i = 0; i < width; i++){
		parentgeneration[i] = 0;
		childgeneration[i] = 0;
	}
	parentgeneration[width/2] = 1; 

	for (int i = 0; i < generations;i++){
		for (int j = 0; j < width; j++){
			if (parentgeneration[j] == 1){
				cout << "#" ;
			} else {
				cout << " ";
			}

			childgeneration[j] = determineChildValues(parentgeneration, j, width);
		}
		//Loop to apply child generation values
		for (int s = 0; s < width; s++ ){
			parentgeneration[s] = childgeneration[s];
		} 			
	cout << endl;
	}
	return;  
} 

int determineChildValues(int parents[], int position, int width){

	int right; 
	int left; 
	int middle; 

	if (position == 0){
		left = parents[width-1];
		middle = parents[position];
		right = parents[position+1];
	} else if (position == width-1) {
		left = parents[position-1];
		middle = parents[position];
		right = parents[0];
	} else {
		left = parents[position-1];
		middle = parents[position];
		right = parents[position+1];
	}

	// cout << "Left: " << left << " Middle: " << middle << " Right: " << right << endl; 
	int newvalue = calculateValues(left,middle,right);
 	return newvalue; 
}

// ---- calculateValues Method ----
int calculateValues(int left, int middle, int right) { //This code is based off the Nature of Code's sample code for Cellular Automaton -- See References below. 

    if  	(left == 1 && middle == 1 && right == 1) { return rule[0]; }
    else if (left == 1 && middle == 1 && right == 0) { return rule[1]; }
    else if (left == 1 && middle == 0 && right == 1) { return rule[2]; }
    else if (left == 1 && middle == 0 && right == 0) { return rule[3]; }
    else if (left == 0 && middle == 1 && right == 1) { return rule[4]; }
    else if (left == 0 && middle == 1 && right == 0) { return rule[5]; }
    else if (left == 0 && middle == 0 && right == 1) { return rule[6]; }
    else if (left == 0 && middle == 0 && right == 0) { return rule[7]; }

} // ---- End of the calculateValues Method ---


/* ******* References ********

Shiffman, D. (2015). The Nature of Code. [online] Natureofcode.com. Available at: http://natureofcode.com/book/chapter-7-cellular-automata/ [Accessed 3rd November 2015].
Binary Converter Program: https://www.dropbox.com/s/ia7sjunz8ptn0h8/Binaryconverter.java?dl=0

*/