/****************************************************************************
* COSC2131 - Programming Using C++
* Semester 2013A Assignment #1
* Full Name        : Nguyen Quoc Trong Nghia
* Student Number   : s3343711
****************************************************************************/

#include "Micro34HC22.h"

//Reset the microcontroller

void Micro34HC22::resetMemory() {
    PC = 1018;    
	A = "00";
    B = "00";
	for (int i = 0; i < size; i++) {
        memory[i] = '0';
    }
	cout<<"Reset Successful.\n";
}

//Display PC and registers

void Micro34HC22::displayPC() {
    Microcontroller::displayPC();
    cout << "A = 0x" << A << "\n";
    cout << "B = 0x" << B << "\n";
}


//This method contain all the opcode and the way it execute

void Micro34HC22::opcodeFunction() {
    int opcodeValue, address;
    string hexStr;
    opcodeValue = hexToInt('0', '0', memory[PC], memory[PC + 1]);

    switch (opcodeValue) {

            //Move A to memory
        case 12:
            hasOpcode = true;
            address = hexToInt(memory[PC + 2], memory[PC + 3], memory[PC + 4], memory[PC + 5])*2;
            memory[address] = A[0];
            memory[address + 1] = A[1];
            PC = PC + 6;
            opcodeFunction();
            break;

            //Load A with Value
        case 55:
            hasOpcode = true;
            A[0] = memory[PC + 2];
            A[1] = memory[PC + 3];
            PC = PC + 4;
            opcodeFunction();
            break;

            //Load B with Value
        case 56:
            hasOpcode = true;
            B[0] = memory[PC + 2];
            B[1] = memory[PC + 3];
            PC = PC + 4;
            opcodeFunction();
            break;

            //Increment Register A
        case 83:
        {
            int value;
            string hex_value;
            hasOpcode = true;
            value = hexToInt('0', '0', A[0], A[1]);
            value = value + 1;
            hex_value = intToHex(value);
            A[0] = hex_value[hex_value.size() - 2];
            A[1] = hex_value[hex_value.size() - 1];
            PC = PC + 2;
            opcodeFunction();
        }
            break;

            //Branch Always
        case 90:
            hasOpcode = true;
            int tmp;
            address = hexToInt(memory[PC + 2], memory[PC + 3], memory[PC + 4], memory[PC + 5]);
            PC = address * 2;
            if (PC > (size - 1)) {
                cout << "SIGWEED. Program executed past top of memory\n";
                PC = tmp;
                break;
            }
            opcodeFunction();
            break;

            //Branch if A < B
        case 91:
            int aValue, bValue;
            aValue = hexToInt('0', '0', A[0], A[1]);
            bValue = hexToInt('0', '0', B[0], B[1]);
            if (aValue < bValue) {
                address = hexToInt(memory[PC + 2], memory[PC + 3], memory[PC + 4], memory[PC + 5]);
                PC = address * 2;
            } else {
                PC = PC + 6;
            }
            opcodeFunction();
            break;

            //Branch if Less than A
        case 93:
            hasOpcode = true;
            int comparision, value;
            comparision = hexToInt('0', '0', memory[PC + 2], memory[PC + 3]);
            value = hexToInt('0', '0', A[0], A[1]);
            if (comparision < value) {
                PC = hexToInt(memory[PC + 4], memory[PC + 5], memory[PC + 6], memory[PC + 7])*2;
            } else {
                PC = PC + 8;
            }
            opcodeFunction();
            break;

            //Halt opcode
        case 100:
            cout << "Program halted\n";
            break;

        default:
            if (hasOpcode == true) {
                hexStr = intToHex(PC / 2);
                cout << "Program Counter = 0x" << hexStr << "\n";
                hasOpcode = false;
            } else {
                hexStr = intToHex(PC / 2);
                cout << "SIGOP. Invalid opcode. Program Counter = 0x" << hexStr << "\n";
            }
            break;
    }
}
