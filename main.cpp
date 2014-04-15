/****************************************************************************
* COSC2131 - Programming Using C++
* Semester 2013A Assignment #1
* Full Name        : Nguyen Quoc Trong Nghia
* Student Number   : s3343711
****************************************************************************/

#include "main.h"

int main(){
	menu();	
	return 0;
}

void menu(){   

	/*Init variables*/	
	R500 *mic_r500 ;
	PIC32F42 *mic_pic;
	Micro34HC22 *mic_34;
	bool exit=false;
	string input, command;
	char user_select;
	string chosen_mic;

	/*Checking user input*/
	while(exit==false){
		cout << '>';
		getline(cin, input);			
		if (input.length()!=1){                
			cout<<"Invalid Input\n";
		} else {				
			user_select =  input[0];

			switch(user_select){
			case 'c':
			case 'C':
				{
					/*choose micro controller*/
					cout<< "Input one microcontroller.\n";
					cout<< "R500\n";
					cout<< "34HC22\n";
					cout<< "PIC32F42\n";

					cout<< ">type? ";
					getline(cin, input);	

					std::istringstream iss(input);				
					iss >>command;

					/*Checking micro input*/
					if (command.compare(MIC_R500)==0){	
						chosen_mic = MIC_R500;
						mic_r500 = new R500();
					} else if (command.compare(MIC_PIC32F42)==0){
						chosen_mic = MIC_PIC32F42;
						mic_pic = new PIC32F42();
					} else if(command.compare(MIC_34HC22)==0){
						chosen_mic = MIC_34HC22;
						mic_34 =  new Micro34HC22();
					} else {
						cout<< "Invalid Type\n";
					}						 									
				}
				break;

			case 'd':
			case 'D':
				{				
					/*Display Microcontroller*/
					if (chosen_mic ==MIC_R500){
						mic_r500->displayMemory();
					}else if(chosen_mic == MIC_PIC32F42){
						mic_pic->displayMemory();
					} else if (chosen_mic == MIC_34HC22){
						mic_34->displayMemory();
					}
					else {
						cout<< "Not Connect to MicroController.\n";
					}
				}
				break;
			case 'e':
			case 'E':
				{
					/*Execute Microcontroller*/
					if (chosen_mic ==MIC_R500){
						mic_r500->opcodeFunction();			
					}else if(chosen_mic == MIC_PIC32F42){
						mic_pic->opcodeFunction();
					} else if (chosen_mic == MIC_34HC22){
						mic_34->opcodeFunction();
					}
					else {
						cout<< "Not Connect to MicroController.\n";
					}
				}
				break;

			case 'h':
			case 'H':
				{
					/*Help List*/
				cout<< "c : Connect to Microcontroller\n";
				cout<< "d : Display Memory\n";
				cout<< "e : Execute PC\n";
				cout<< "g : Execute PC from location\n";				
				cout<< "h : Display help\n";
				cout<< "l : Look at Memory\n";
				cout<< "m : Modify Memory\n";				
				cout<< "q : Quit the program\n";
				cout<< "r : Reset Microcontroller\n";
				cout<< "s : Display PC and registers\n";
				}
				break;
			case 'l':
			case 'L':
				{
					/*Look at address memory*/
					if (chosen_mic ==MIC_R500){
						mic_r500->lookMemory();
					}else if(chosen_mic == MIC_PIC32F42){
						mic_pic->lookMemory();
					} else if (chosen_mic == MIC_34HC22){
						mic_34->lookMemory();
					}
					else {
						cout<< "Not Connect to MicroController.\n";
					}
				}
				break;
			case 'm':
			case 'M':
				{
					/*Modify address memory */
					if (chosen_mic ==MIC_R500){
						mic_r500->modifyMemory();
					}else if(chosen_mic == MIC_PIC32F42){
						mic_pic->modifyMemory();
					} else if (chosen_mic == MIC_34HC22){
						mic_34->modifyMemory();
					}
					else {
						cout<< "Not Connect to MicroController.\n";
					}
				}
				break;
			case 'r':
			case 'R':
				{
					/*Reset Microcontroller*/
					if (chosen_mic ==MIC_R500){
						mic_r500->resetMemory();
					}else if(chosen_mic == MIC_PIC32F42){
						mic_pic->resetMemory();
					} else if (chosen_mic == MIC_34HC22){
						mic_34->resetMemory();
					}
					else {
						cout<< "Not Connect to MicroController.\n";
					}
				}
				break;
			case 's':
			case 'S':
				{
					/*Microcontroller status*/
					if (chosen_mic ==MIC_R500){
						mic_r500->displayPC();
					}else if(chosen_mic == MIC_PIC32F42){
						mic_pic->displayPC();
					} else if (chosen_mic == MIC_34HC22){
						mic_34->displayPC();
					}
					else {
						cout<< "Not Connect to MicroController.\n";
					}
				}
				break;
			case 'q':
			case 'Q':
				{
					/*Exit Program*/        
					cout<<"Bye bye\n";					
					exit = true;
				}
				break;
			default:                 
				cout<<"Invalid Input\n";
				break;
			}
		}
	}	
}

