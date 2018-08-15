#include "CellularAutomaton.h"
#include <string> 
using namespace std; 

CellularAutomaton::CellularAutomaton(int rules, int width, int lines ){
    setRule(rules);
    setWidth(width);
    setLine(lines);
}

 void CellularAutomaton::setRule(int newrule){
  int binarynumber[8];
        for (int i = 7; i >= 0; i++) { 
            binarynumber[i] =  (newrule % 2) ; //Sets the remainder of each loop to the present value in the array
            newrule = newrule / 2 ; // Divides the number by two each time, As in 8 bit binary, each number is divisable by two
			rule[i] = binarynumber[i]; 
        }
}

 void CellularAutomaton::setLine(int newline){
    lines = newline
}

void CellularAutomaton::setWidth(int newwidth){
    width = newwidth;
}

 CellularAutomaton::getRule(){
    return rule; 
}

 int CellularAutomaton::getLine(){
    return lines;
}

 int CellularAutomaton::getWidth(){
    return width;
}