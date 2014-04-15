/****************************************************************************
* COSC2131 - Programming Using C++
* Semester 2013A Assignment #1
* Full Name        : Nguyen Quoc Trong Nghia
* Student Number   : s3343711
****************************************************************************/

#include "PIC32F42.h"

void PIC32F42::resetMemory() {
    PC = 0;
    W = "00";
	for (int i = 0; i < size; i++) {
        memory[i] = '0';
    }
	cout<<"Reset Successful.\n";
}

void PIC32F42::displayPC() {
    Microcontroller::displayPC();
    cout << "W = 0x" << W << "\n";
}

void PIC32F42::opcodeFunction() {
    int opcodeValue, address;
    string hexStr;
    opcodeValue = hexToInt('0', '0', memory[PC], memory[PC + 1]);

    switch (opcodeValue) {

            //Move Value to W
        case 80:
            hasOpcode = true;
            W[0] = memory[PC + 2];
            W[1] = memory[PC + 3];
            PC = PC + 4;
            opcodeFunction();
            break;

            //Move W to memory
        case 81:
            hasOpcode = true;
            address = hexToInt(memory[PC + 2], memory[PC + 3], memory[PC + 4], memory[PC + 5])*2;
            memory[address] = W[0];
            memory[address + 1] = W[1];
            PC = PC + 6;
            opcodeFunction();
            break;

            //Add Value to W
        case 90:
        {
            int value;
            string hex_value;
            hasOpcode = true;
            value = hexToInt('0', '0', memory[PC + 2], memory[PC + 3]);
            value = value + hexToInt('0', '0', W[0], W[1]);
            hex_value = intToHex(value);
            W[0] = hex_value[hex_value.size() - 2];
            W[1] = hex_value[hex_value.size() - 1];
            PC = PC + 4;
            opcodeFunction();
        }
            break;

            //Subtract Value from W
        case 91:
        {
            int value;
            string hex_value;
            hasOpcode = true;
            value = hexToInt('0', '0', memory[PC + 2], memory[PC + 3]);
            value = hexToInt('0', '0', W[0], W[1]) - value;
            hex_value = intToHex(value);
            W[0] = hex_value[hex_value.size() - 2];
            W[1] = hex_value[hex_value.size() - 1];
            PC = PC + 4;
            opcodeFunction();
        }
            break;

            //Goto address
        case 110:
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

            //Branch if not equal
        case 112:
            hasOpcode = true;
            int comparision, value;
            comparision = hexToInt('0', '0', memory[PC + 2], memory[PC + 3]);
            value = hexToInt('0', '0', W[0], W[1]);
            if (comparision == value) {
                PC = PC + 8;
            } else {
                PC = hexToInt(memory[PC + 4], memory[PC + 5], memory[PC + 6], memory[PC + 7])*2;
            }
            opcodeFunction();
            break;

            //Halt opcode
        case 255:
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
