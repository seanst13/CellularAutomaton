#include CellularAutomaton.h
#include <string> 
using namespace std; 

CellularAutomaton::CellularAutomaton(int rules, int width, int lines ){
    setRules(rules);
    setWidth(width);
    setLines(lines);
}

CellularAutomaton::setRules(int newrule){
  int binarynumber[8];
        for (int i = 0; i < 8; i++) { 
            binarynumber[i] =  (newrule % 2) ; //Sets the remainder of each loop to the present value in the array
            newrule = newrule / 2 ; // Divides the number by two each time, As in 8 bit binary, each number is divisable by two
			this.rule[i] = binarynumber[i]; 
        }
}

CellularAutomaton::setLines(int newline){
    this.lines = newline
}

CellularAutomaton::setWdith(int newwidth){
    this.width = newwidth;
}

CellularAutomaton::getRule(){
    return this.rule; 
}

CellularAutomaton::getLine(){
    return this.lines;
}

CellularAutomaton::getWidth(){
    return this.width;
}