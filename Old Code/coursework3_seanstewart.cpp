// **** Computer Systems 2A: Architecture Fundamentals & Unix ********
// **** Coursework 3 - Cellular Automataton **************************
// **** Author: Sean Stewart *****************************************
// **** Marticulation Number: 140009213	******************************


#include <iostream>
#include <string> 
#include <fstream> 
using namespace std;


// Method Declaration
void menu();
void setRule(int);
int getRule();
int calculateValues(int,int,int);
char generateValues(int,int);


int rule[8] = { 0, 0, 0, 1, 1, 1, 1, 0 }; // -Array to hold the Rules. By default it is set to Rule 30. 

// ----Main Method----
int main(){

// -- Varaibles for the width and the number of lines. By default they are set to 16 and 32. 
	int numoflines = 16;
	int width = 32;
	
// Variables that relate to the menu
	int choice;
	char option;
	int rulenumber;
	bool loopcomplete = false;

// -- Do-While Loop to Display a Menu until the Program is exited.
	do{
		menu();
		cout << "Choice: " ;
		cin >> choice;
		
		switch (choice) {
		
			case 1:{
				loopcomplete = false;
					do {
						cout<< endl;
						cout << "The current rule that is set is: " << getRule() << endl;
						cout << "Do you wish to change this? (Y/N)" << endl;
						cin >> option;

						if (option == 'Y' || option == 'y'){

							while (loopcomplete == false){
									cout << endl;
									cout << "What number do you wish to set the rule to? Please choose a value between 0 and 255." << endl;
									cin >> rulenumber;

									if (rulenumber < 0 || rulenumber > 255) {
										cout << "That number is outside the range of values availiable. Please choose a value between 0 and 255." << endl;
									} else {
										setRule(rulenumber);
										cout << "The Automaton has been set to display Rule " << rulenumber << endl;
										loopcomplete = true;
									}
																
							} //End of While Loop
								break;
						} else if (option == 'N' || option == 'n') {
							break;
						} else {
							cout << option << " is an invalid option. Please choose either Y or N." << endl; 
					}	
											
					} while (option != 'Y' || option != 'y' || option != 'N' || option != 'n'); // end of outer while loop
					break;
					}
				
			case 2:{
				loopcomplete = false;
						while (loopcomplete == false) {
						cout << endl;
						cout << "The current number of lines that will generate is: " << numoflines << endl;
						cout << "Do you wish to change this? (Y/N)" << endl;
						cin >> option;

						if (option == 'Y' || option == 'y'){
							cout << "How many lines do you wish to generate?" << endl;
							cin >> numoflines;
							loopcomplete = true;
						} else if (option == 'N' || option == 'n') {
							loopcomplete = true;
						} else {
							cout << option << " is an invalid option. Please choose either Y or N." << endl; 
						}
					}
				break;
				}
			case 3: {
				 loopcomplete = false; 
					while (loopcomplete == false) {
						cout << endl;
						cout << "The current width of the automaton is " << width << " characters" << endl;
						cout << "Do you wish to change this? (Y/N)" << endl;
						cin >> option;

						if (option == 'Y' || option == 'y'){
							cout << "How many characters wide do you wish the automaton to be?" << endl;
							cin >> width;
							cout << "The width of the cellular automaton has been changed to " << width  << endl; 
							loopcomplete = true;
						} else if (option == 'N' || option == 'n') {
							loopcomplete = true;
						} else {
							cout << option << " is an invalid option. Please choose either Y or N." << endl; 
						}
					}
				break;
				}
			case 4: {
					cout << endl; 
					cout << "Rule: " << getRule() << "\t Number of Generations: " << numoflines << "\t Width of Automaton: " << width << endl;
					cout << endl; 
					generateValues(width, numoflines);
					break;
				}
			case 5: {
				loopcomplete = false;
					while (loopcomplete == false) {
						cout << endl;
						cout << "Are you sure you wish to reset the Cellular Automaton to it's default values? (Y/N)" << endl;
						cin >> option;
				
						if (option == 'Y' || option == 'y'){

						// - Resets the number of generations and the width of automaton
							numoflines = 16;
							width = 32;
					
						// - Two for loops and an assingment to reset the rule array back to Rule 30
							for(int i = 0; i < 3; i++){
								rule[i] = 0;
							}
				
							for (int i = 3; i < 7; i ++) {
								rule[i] = 1; 
							} 
							rule[7] = 0;
							cout << "The values have been reset." << endl;
							loopcomplete = true;
						} else if (option == 'N' || option == 'n') {
							loopcomplete = true;
						} else {
							cout << option << " is an invalid option. Please choose either Y or N." << endl; 
						}
					}
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
			case 6: {
					cout << "Thank you for using the program." << endl;
					break;
				}
				
			default:
				{
					cout << choice << " is an invalid option. Please choose a number between 1 and 6." << endl;
					break;
				}
			} // - End of Switch Statement

	}while (choice != 6);

return 0;

} // ---End of Main Method ---

// ---- Menu Method ----
void menu() {

	cout << "---------------------------------------------------------------" << endl;
	cout << "-------------------------MAIN MENU-----------------------------" << endl;
	cout << "---------------------------------------------------------------" << endl;	
	cout << "Please choose from the following options" << endl; 
	cout << "---------------------------------------------------------------" << endl;
	cout << " 1.\tSet Rule of the Cellular Automaton" << endl;
	cout << " 2.\tSet the Number of Lines to Generate" << endl;
	cout << " 3.\tSet the Number of Characters per Line" << endl;
	cout << " 4.\tDisplay The Cellular Automaton" << endl;
	cout << " 5.\tReset the Automaton to Default Values" << endl;
//	cout << " 6.\tOutput the Cellular Automaton to a file." << endl;
	cout << " 6.\tExit The Program" << endl;
	cout << "---------------------------------------------------------------" << endl;
	
return;
} // ---- End of Menu Method ---


//---- setRule Method ----
void setRule(int numtoconvert){

        int binarynumber[8];

/* This loop is taken from a binary converter program we were given to copy down as part of the 
   college section of the Applied Computing degree last year 
   when we were learning about methods and number conversions,
   A link to that code is provided in the references Section below */

           for (int i = 0; i < 8; i++) { 
                binarynumber[i] =  (numtoconvert % 2) ; //Sets the remainder of each loop to the present value in the array
                numtoconvert = numtoconvert / 2 ; // Divides the number by two each time, As in 8 bit binary, each number is divisable by two
            }

// -- For loop to set the ruleset to the converted binary number
	for (int i = 0,j = 7; (i < 8, j >=0); i++, j--){

		rule[i] = binarynumber[j];
	}

} // ---- End of setRule Method ----

// ---- getRule Method ----
int getRule(){

	int total = 0;

//Set of if statements to add to the total going through each element in the rule array

//	First Element	
	if (rule[0] == 1) {
		total = total + 128;
	} else if (rule[0] == 0) { 
		total = total + 0;
	} 

//	Second Element 
	if (rule[1] == 1) {
		total = total + 64;
	} else if (rule[1] == 0) { 
		total = total + 0;
	} 

//	Third Element
	if (rule[2] == 1) {
		total = total + 32;
	} else if (rule[2] == 0) { 
		total = total + 0;
	} 

//	Fourth Element
	if (rule[3] == 1) {
		total = total + 16;
	} else if (rule[3] == 0) { 
		total = total + 0;
	} 

// 	Fifth Element
	if (rule[4] == 1) {
		total = total + 8;
	} else if (rule[4] == 0) { 
		total = total + 0;
	} 

//	Sixth Element
	if (rule[5] == 1) {
		total = total + 4;
	} else if (rule[5] == 0) { 
		total = total + 0;
	} 

//	Seventh Element
	if (rule[6] == 1) {
		total = total + 2;
	} else if (rule[6] == 0) { 
		total = total + 0;
	} 

//	Eigth Element
	if (rule[7] == 1) {
		total = total + 1;
	} else if (rule[7] == 0) { 
		total = total + 0;
	}
		
	return total;
} // ---- End of getRule Method----


// ----- generateValues Method ----
char generateValues(int width, int generations){ //This code is based off the Nature of Code's sample code for Cellular Automaton -- See References below. 

// Arrays for the generation of each line.

	int parentgeneration[width];  // The array for the previous values of each generation
	int childgeneration[width];   // The array for the current values of each generation

// Variables for the positions of the values
	int leftvalue;
	int middlevalue;
	int rightvalue;

	char character;
	
// Initial for loop to set up the first row of values 

	for (int i = 0; i <width; i++){
		parentgeneration[i] = 0;
	}

	parentgeneration[width/2] = 1; // The center value of the first row will be set to 1. This is to start the top of the automaton. 


// Nested for loop to print the values of each line
// The outer for loop is for the number of lines that will be generated

	for (int numoflines = 0; numoflines < generations;){

// Inner for loop to display each indivdiual value per line
		for (int i = 0; i <width; i++){

// Display the previous generations' values
			if (parentgeneration[i] == 1){
				cout << "#" ;
				character = '#';
				 
			} else if (parentgeneration[i] == 0){
				cout << "-";
				character = '-';
			}	
		
// Calculate the new values for the next generation of the automaton.

// If statements to wrap around the ends of each array
		if (i == 0){  
			leftvalue = parentgeneration[width-1]; 
			middlevalue = parentgeneration[i];
			rightvalue = parentgeneration[i+1];
			}
			else if (i == width-1) {
			leftvalue = parentgeneration[i-1]; 
			middlevalue = parentgeneration[i];
			rightvalue = parentgeneration[0];
			}
			else {  
			leftvalue = parentgeneration[i-1]; 
			middlevalue = parentgeneration[i];
			rightvalue = parentgeneration[i+1];
			}
			int newvalues = calculateValues(leftvalue,middlevalue,rightvalue);

// Set the new values to the current value
			childgeneration[i] = newvalues;
			 
		} // End of Inner For Loop

// Set the previous values to the new current values
	for (int i = 0; i < width; i++){
		parentgeneration[i] = childgeneration[i]; 
	}
	
	numoflines++;
	cout << endl;

	} // End of Outer For Loop

return character;
} // ----- End of the generateValues Method ----- 


// ---- calculateValues Method ----
int calculateValues(int left, int middle, int right) { //This code is based off the Nature of Code's sample code for Cellular Automaton -- See References below. 


    if  (left == 1 && middle == 1 && right == 1) {
	return rule[0];
	}
    else if (left == 1 && middle == 1 && right == 0) {
	return rule[1];
	}
    else if (left == 1 && middle == 0 && right == 1) {
	return rule[2];
	}
    else if (left == 1 && middle == 0 && right == 0) {
	return rule[3]; 
	}
    else if (left == 0 && middle == 1 && right == 1) { 
	return rule[4];
	}
    else if (left == 0 && middle == 1 && right == 0) {
	return rule[5];
	}
    else if (left == 0 && middle == 0 && right == 1) {
	return rule[6];
	}
    else if (left == 0 && middle == 0 && right == 0) {
	return rule[7];
	}

} // ---- End of the calculateValues Method ---


/* ******* References ********

Shiffman, D. (2015). The Nature of Code. [online] Natureofcode.com. Available at: http://natureofcode.com/book/chapter-7-cellular-automata/ [Accessed 3rd November 2015].
Binary Converter Program: https://www.dropbox.com/s/ia7sjunz8ptn0h8/Binaryconverter.java?dl=0

*/