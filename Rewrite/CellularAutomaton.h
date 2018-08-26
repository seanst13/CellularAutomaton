// Cellular Automaton Header File
//Written by Sean Stewart

#ifndef CELLULARAUTOMATON_H
#define CELLULARAUTOMATON_H

class CellularAutomaton{

        int rule[8];
        int width;
        int lines;

    public: 
    //Get & Set Methods
        CellularAutomaton(int rule, int width, int newline);
        void setRule(int newrule);
        int getRule(int position);
        int displayRuleDecimal(); 
        void setWidth(int newwidth);
        int getWidth();
        void setLine(int newline);
        int getLine(); 
    //Other Class Methods
        int determineChildValues(int parent[], int position);
        void generateValues();
        int calculateValues(int left, int middle, int right); 
};
#endif
