/****************************************************************************
* COSC2131 - Programming Using C++
* Semester 2013A Assignment #1
* Full Name        : Nguyen Quoc Trong Nghia
* Student Number   : s3343711
****************************************************************************/

#include "R500.h"

void R500::resetMemory() {
    PC = 0;
    for (int i = 0; i < size; i++) {
        memory[i] = '0';
    }
	cout<<"Reset Successful.\n";
}

void R500::opcodeFunction() {
    int opcodeValue, address;
    string hexStr;
    opcodeValue = hexToInt('0', '0', memory[PC], memory[PC + 1]);

    switch (opcodeValue) {

            //Add Value to Memory
        case 10:
        {
            hasOpcode = true;
            int value, addTo, result;
            string hex_value;
            value = hexToInt('0', '0', memory[PC + 2], memory[PC + 3]);
            address = hexToInt(memory[PC + 4], memory[PC + 5], memory[PC + 6], memory[PC + 7])*2;
            addTo = hexToInt('0', '0', memory[address], memory[address + 1]);
            result = value + addTo;
            hex_value = intToHex(result);
            memory[address] = hex_value[hex_value.size() - 2];
            memory[address + 1] = hex_value[hex_value.size() - 1];
            PC = PC + 8;
            opcodeFunction();
        }
            break;

            //Subtract Value from Memory
        case 19:
        {
            hasOpcode = true;
            int value, subTo, result;
            string hex_value;
            value = hexToInt('0', '0', memory[PC + 2], memory[PC + 3]);
            address = hexToInt(memory[PC + 4], memory[PC + 5], memory[PC + 6], memory[PC + 7])*2;
            subTo = hexToInt('0', '0', memory[address], memory[address + 1]);
            result = subTo - value;
            hex_value = intToHex(result);
            memory[address] = hex_value[hex_value.size() - 2];
            memory[address + 1] = hex_value[hex_value.size() - 1];
            PC = PC + 8;
            opcodeFunction();
        }
            break;

            //Go to address
        case 22:
            hasOpcode = true;
            int temp;
            address = hexToInt(memory[PC + 2], memory[PC + 3], memory[PC + 4], memory[PC + 5]);
            temp = PC;
            PC = address * 2;
            if (PC > (size - 1)) {
                cout << "SIGWEED. Program executed past top of memory\n";
                PC = temp;
                break;
            }
            opcodeFunction();
            break;

            //Branch relative
        case 23:
            hasOpcode = true;
            int value;
            value = hexToInt('0', '0', memory[PC + 2], memory[PC + 3]);
            PC = PC + (value * 2);
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
