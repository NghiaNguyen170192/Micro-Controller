/****************************************************************************
* COSC2131 - Programming Using C++
* Semester 2013A Assignment #1
* Full Name        : Nguyen Quoc Trong Nghia
* Student Number   : s3343711
****************************************************************************/

#include "Microcontroller.h"

using namespace std;

void Microcontroller::displayMemory() {
    cout << "      00 01 02 03 04 05 06 07  08 09 0a 0b 0c 0d 0e 0f\n\n";
    for (int i = 0; i < size; i++) {
        if ((i % 32) == 0) {
            cout.fill('0');
            cout << hex << setw(4) << i / 2;
            cout << "  ";
        }
        cout << memory[i];
        if ((i + 1) % 16 == 0) {
            cout << "  ";
        } else {
            if ((i + 1) % 2 == 0) {
                cout << " ";
            }
        }
        if ((i + 1) % 32 == 0) {
            cout << "\n";
        }
    }
}


//Check if a value is hexadecimal

bool Microcontroller::checkHex(string check) {
    if (check.find_first_not_of("0123456789abcdefABCDEF") != string::npos) {
        return false;
    } else {
        return true;
    }
}


//Convert a string hexadecimal to integer

int Microcontroller::hexToInt(char first, char second, char third, char fourth) {
    int converted_value;
    string convert_string, str1, str2, str3, str4;
    str1 = first;
    str2 = second;
    str3 = third;
    str4 = fourth;
    convert_string = str1 + str2 + str3 + str4;
    stringstream stream;
    stream << hex << convert_string;
    stream >> converted_value;
    return converted_value;
}


//Convert an integer number to hexadecimal

string Microcontroller::intToHex(int value) {
    string hex_value;
    stringstream stream;
    stream << hex << value;
    hex_value = stream.str();
    if (hex_value.size() == 1) {
        hex_value = "0" + hex_value;
    }
    return hex_value;
}


//Modify memory

void Microcontroller::modifyMemory() {
    string location, new_value;
    int locationValue;
    bool run = true, input_again = true;

    while (run == true) {
        cout << "> location? ";
		getline(cin, location);
        stringstream stream;
        stream << hex << location;
        stream >> locationValue;

        if ((checkHex(location) == false) || (locationValue > ((size / 2) - 1))) {
            cout << "Invalid address\n";
        } else {
            run = false;
            cout << "Old value: 0x" << memory[locationValue * 2] << memory[(locationValue * 2) + 1] << "\n";
            while (input_again == true) {
                cout << "> New? ";
				getline(cin, new_value);
                if (checkHex(new_value) == false) {
                    cout << "Invalid hex value\n";
                } else {
                    input_again = false;
                    if (new_value.size() == 1) {
                        memory[locationValue * 2] = '0';
                        memory[(locationValue * 2) + 1] = new_value[0];
                    } else {
                        memory[locationValue * 2] = new_value[new_value.size() - 2];
                        memory[(locationValue * 2) + 1] = new_value[new_value.size() - 1];
                    }
                }
            }
        }
    }
}


//Look at memory

void Microcontroller::lookMemory() {
    string location;
    int locationValue;
    bool run = true;

    while (run == true) {
        cout << "> location? ";
		getline(cin, location);
        stringstream stream;
        stream << hex << location;
        stream >> locationValue;

        if ((checkHex(location) == false) || (locationValue > ((size / 2) - 1))) {
            cout << "Invalid address\n";
        } else {
            run = false;
            cout << "The value is 0x" << memory[locationValue * 2] << memory[(locationValue * 2) + 1] << "\n";
        }
    }
}


//Display PC and registers

void Microcontroller::displayPC() {
    string hex_value;
    hex_value = intToHex(*PC / 2);
    cout << "PC = 0x" << hex_value << "\n";
    cout << "Opcode = 0x" << memory[*PC] << memory[*PC + 1] << "\n";
}


//Execution from a specific location

void Microcontroller::executeMemory() {
    string location;
    int value;
    bool run = true;
    while (run == true) {
        cout << "> location? ";
		getline(cin, location);
        stringstream stream;
        stream << hex << location;
        stream >> value;
        if ((checkHex(location) == false) || (value > ((size / 2) - 1))) {
            cout << "Invalid address\n";
        } else {
            run = false;
            *PC = value * 2;
        }
    }
}


