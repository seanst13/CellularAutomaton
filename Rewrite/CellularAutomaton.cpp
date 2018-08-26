#include "CellularAutomaton.h"
#include <iostream> 
#include <string>
using namespace std;

CellularAutomaton::CellularAutomaton(int rules, int width, int lines ){
    setRule(rules);
    setWidth(width);
    setLine(lines);
}

void CellularAutomaton::setRule(int newrule){
  int binarynumber[8];
        for (int i = 7; i >= 0; i--) { 
            binarynumber[i] =  (newrule % 2) ; //Sets the remainder of each loop to the present value in the array
            newrule = newrule / 2 ; // Divides the number by two each time, As in 8 bit binary, each number is divisable by two
			rule[i] = binarynumber[i]; 
        }
}

 void CellularAutomaton::setLine(int newline){
    lines = newline;
}

void CellularAutomaton::setWidth(int newwidth){
    width = newwidth;
}

 int CellularAutomaton::getRule(int position){
    return rule[position]; 
}
int CellularAutomaton::displayRuleDecimal(){
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

 int CellularAutomaton::getLine(){
    return lines;
}

 int CellularAutomaton::getWidth(){
    return width;
}

void CellularAutomaton::generateValues(){
    int parent[getWidth()] = {0};
    int child[getWidth()] = {0};

    parent[getWidth()/2] = 1;

     for (int i = 0; i < getLine(); i++){
         for (int j = 0; j < getWidth(); j++){
             if (parent[j] == 1){
                 cout << "#"; 
             } else {
                 cout << " "; 
             }
             child[j] = determineChildValues(parent, j);
         }

        for (int x = 0; x < getWidth(); x++){
            parent[x] = child[x]; 
        }
        cout << endl; 
     }
     return;      
}

int CellularAutomaton::determineChildValues(int parent[], int position){
    int left; int middle; int right; 

    left = parent[position-1];
    middle = parent[position];
    right = parent[position+1];

    if (position == 0){
        left = parent[getWidth()-1];
    } else if (position == getWidth()-1){
        right = parent[0];
    }

    return calculateValues(left,middle,right);
}

int CellularAutomaton::calculateValues (int left, int middle, int right){

    if  	(left == 1 && middle == 1 && right == 1) { return getRule(0); }
    else if (left == 1 && middle == 1 && right == 0) { return getRule(1); }
    else if (left == 1 && middle == 0 && right == 1) { return getRule(2); }
    else if (left == 1 && middle == 0 && right == 0) { return getRule(3); }
    else if (left == 0 && middle == 1 && right == 1) { return getRule(4); }
    else if (left == 0 && middle == 1 && right == 0) { return getRule(5); }
    else if (left == 0 && middle == 0 && right == 1) { return getRule(6); }
    else if (left == 0 && middle == 0 && right == 0) { return getRule(7); }
}    