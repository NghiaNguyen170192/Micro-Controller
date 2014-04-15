/****************************************************************************
* COSC2131 - Programming Using C++
* Semester 2013A Assignment #1
* Full Name        : Nguyen Quoc Trong Nghia
* Student Number   : s3343711
****************************************************************************/

#ifndef PIC32F42_H
#define	PIC32F42_H

#include "Microcontroller.h"

class PIC32F42 : public Microcontroller {
private:	
	string W;
	bool hasOpcode;
	static const int size = 3072;
	unsigned char memory[size];	
	int PC;
public:

	PIC32F42() : Microcontroller(memory, size, &PC) {
		cout<<"PIC32F42 Created\n";
		resetMemory();
	}

	void resetMemory();
	void opcodeFunction();
	void displayPC();

	virtual ~PIC32F42() {}
};

#endif

