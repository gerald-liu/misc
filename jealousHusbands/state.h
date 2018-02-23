#ifndef STATE_H
#define STATE_H

const char MOVES[][2] = {{'1', '0'}, {'0', '1'}, {'2', '0'}, {'0', '2'}, {'1', '1'}};
const int NUM_MOVES = 5;

class State {
public:
    char husband, wife, boat; // number on the wrong side
    int tripNum; // trip number
    const State *prev; // parent nodes
    State **next; // children nodes

    State();
    State(char h, char w, char b, int t, State* p, State** n);
    ~State();
    void print() const;
    void move(bool forth);
};

#endif
