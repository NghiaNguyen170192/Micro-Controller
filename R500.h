/****************************************************************************
* COSC2131 - Programming Using C++
* Semester 2013A Assignment #1
* Full Name        : Nguyen Quoc Trong Nghia
* Student Number   : s3343711
****************************************************************************/

#ifndef R500_H
#define	R500_H

#include "Microcontroller.h"

class R500 : public Microcontroller {
private:
	bool hasOpcode;

	static const int size = 2048;
	unsigned char memory[size];
	int PC;

public:

	R500() : Microcontroller(memory, size, &PC){
		cout<<"R500 Created\n";
		resetMemory();
	}

	void resetMemory();
	void opcodeFunction();

	virtual ~R500() {}
};

#endif

