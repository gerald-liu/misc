#include <iostream>
#include "state.h"

using namespace std;

State::State(): husband{'3'}, wife{'3'}, boat{'1'}, tripNum{0}, prev{nullptr}, next{nullptr} {}

State::State(char h, char w, char b, int t, State* p, State** n): husband{h}, wife{w}, boat{b}, tripNum{t}, prev{p}, next{n} {}

State::~State() {
    if (next != nullptr) {
        for (int i=0; i<NUM_MOVES; i++) if (next[i] != nullptr) delete next[i];
        delete[] next;
    }
}

void State::print() const {
    if (prev != nullptr) prev->print();

    if (tripNum == 0) cout << "\nSolution:\n";
    cout << tripNum << "\t< "  << husband << ", " << wife << ", " << boat << " >\n";
}

void State::move(bool forth) {
    State** next = new State* [NUM_MOVES];

    for (int i=0; i<NUM_MOVES; i++) {
        char husband, wife, boat;
        if (forth) {
            husband = this->husband + MOVES[i][0];
            wife = this->wife + MOVES[i][1];
            boat = this->boat + '1';
        }
        else {
            husband = this->husband - MOVES[i][0];
            wife = this->wife - MOVES[i][1];
            boat = this->boat - '1';
        }
        
        if (!(husband == '0' || husband == '3' || husband == wife)) {
            next[i] = nullptr;
            continue;
        }
        
        next[i] = new State(husband, wife, boat, this->tripNum + 1, this, nullptr);
        if (husband == '0' && wife == '0' && boat == '0') {
            next[i]->print();
            continue;
        }
    }

    bool deadEnd = true;
    int i = 0;
    for (; i<NUM_MOVES; i++) {
        if (next[i] != nullptr) {
            deadEnd = false;
            break;
        }
    }
    if (deadEnd) {
        delete[] next;
        next = nullptr;
        return;
    }
    else {
        this->next = next;
        for (; i<NUM_MOVES; i++) if (next[i] != nullptr) next[i]->move(!forth);
    }
}
