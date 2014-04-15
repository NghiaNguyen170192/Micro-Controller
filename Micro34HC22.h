/****************************************************************************
* COSC2131 - Programming Using C++
* Semester 2013A Assignment #1
* Full Name        : Nguyen Quoc Trong Nghia
* Student Number   : s3343711
****************************************************************************/

#ifndef MICRO34HC22_H
#define	MICRO34HC22_H

#include "Microcontroller.h"

class Micro34HC22 : public Microcontroller {
private:
    int PC;
    bool hasOpcode;
    string A, B;
    static const int size = 1024;
    unsigned char memory[size];

public:

    Micro34HC22() : Microcontroller(memory, size, &PC) {
		cout<<"34HC22 Created\n";
        resetMemory();
    };

    void resetMemory();
    void displayPC();
    void opcodeFunction();

    virtual ~Micro34HC22() {}
};

#endif

