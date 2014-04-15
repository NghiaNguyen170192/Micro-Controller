/****************************************************************************
* COSC2131 - Programming Using C++
* Semester 2013A Assignment #1
* Full Name        : Nguyen Quoc Trong Nghia
* Student Number   : s3343711
****************************************************************************/

#ifndef MICROCONTROLLER_H
#define	MICROCONTROLLER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class Microcontroller {
private:
    unsigned char *memory;
    int size;
    int *PC;

public:

    Microcontroller(unsigned char *_memory, int _size, int *_PC) : memory(_memory), size(_size), PC(_PC) {
    }

    void displayMemory();
    void modifyMemory();
    bool checkHex(string);
    void lookMemory();
    void displayPC();
    int hexToInt(char, char, char, char);
    string intToHex(int);
    void executeMemory();
	virtual void resetMemory()=0;
	virtual void opcodeFunction()=0;
    virtual ~Microcontroller() {}

};

#endif

