// Cellular Automaton Header File
//Written by Sean Stewart

#ifndef CELLULARAUTOMATON_H
#define CELLULARAUTOMATON_H
#include<string>
using namespace std;

Class CellularAutomaton{

    private:
        int rule[8];
        int width;
        int lines;

    public: 
    //Get & Set Methods
        CellularAutomaton(string rule, int width, int newline);
        void setRule(int newrule);
        int getRule();
        void setWidth(int newwidth);
        int getWidth();
        void setLine(int newline);
        int getLine(); 
};
#endif
