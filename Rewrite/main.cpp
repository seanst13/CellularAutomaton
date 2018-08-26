// Cellular Autoamton Rewrite. 
// Written by Sean Stewart

#include <iostream>
#include <string> 
#include <fstream> 
#include "CellularAutomaton.cpp"
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
CellularAutomaton cell(30,32,16); 


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
				cout << "Rule: " << cell.displayRuleDecimal() << "\t Number of Generations: " << cell.getLine() << "\t Width of Automaton: " << cell.getWidth() << endl;
				cout << endl; 
				cell.generateValues(); 
				break;
			}
				
			case 2:{
				cell.setRule(rand() % 255);
				cout << endl; 
				cout << "Rule: " << cell.displayRuleDecimal() << "\t Number of Generations: " << cell.getLine() << "\t Width of Automaton: " << cell.getWidth() << endl;
				cout << endl; 
				cell.generateValues();
				cell.setRule(30); 
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
				cout << "\tRULE:\t" << cell.displayRuleDecimal() << endl;
				cout << "\tWIDTH:\t" << cell.getWidth() << endl;
				cout << "\tLINES:\t" << cell.getLine() << endl;
				cout << "=====================================================" << endl;
				break;
			}
			
			case 2: {
				char input;
				cout << "The Current Rule is: RULE " << cell.displayRuleDecimal() << endl;  
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
					cell.setRule(newrule); 
				}
				break;
			}

			case 3: {
				char input;
				cout << "The Number of Lines displayed is:  " << cell.getLine() << endl;  
				cout << "Do you wish to change this? (Y/N)" << endl; 
				cin >> input; 
				if (determineOptionOutcome(input)){
					int newlines;
					cout << "Please enter a new the new number of lines" << endl;
					cout << "NUMBER OF LINES: ";
					cin >> newlines; 
					cell.setLine(newlines); 
					}
				break; 	
				}

			case 4: {
				char input;
				cout << "The Current width of the cellular automaton is: " << cell.getWidth() << endl;  
				cout << "Do you wish to change this? (Y/N)" << endl; 
				cin >> input; 
				if (determineOptionOutcome(input)){
					int newwidth;
					cout << "Please enter a new width for the Cellular Automaton" << endl;
					cout << "RULE: ";
					cin >> newwidth; 
					cell.setWidth(newwidth); 
				}
				break;
			}

			case 5: {
				char input;
				cout << "Do you wish to revert back to default settings? (Y/N)" << endl; 
				cin >> input; 
				if (determineOptionOutcome(input)){
					cell.setRule(30);
					cell.setWidth(32);
					cell.setLine(16); 
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

void resetToDefault(){
	int newrule[8] = { 0, 0, 0, 1, 1, 1, 1, 0 };
	for(int i = 0; i < 8; i++){
		rule[i] = newrule[i];
	}
}