#include <iostream>
#include <cstdlib>
#include <ctime>
#include "unistd.h"
using namespace std;
int start(void){
    cout << "--------------------------------"
    sleep(1);
    cout << "...Game Start..." <<endl;
    sleep(1);
	unsigned int car_door = rand()%3;
	unsigned int user_choose;
	cout << "Choose the door(0~2): door ";
	cin >> user_choose;
	if(user_choose > 2){
		cout << "Maybe you should learn how to type 0/1/2\n\tGood Job!";
		return 0;
	}
	unsigned int hostess_open = rand()&3 - 1;
	for(int i=1; i>0; i++){
		if(hostess_open == user_choose)  hostess_open = rand()&3 - 1;
		else if(hostess_open == car_door)  hostess_open = rand()%3 - 1;
		else  break;
	}
	cout << "I will open a door now. door " << hostess_open << " is full of sheep" << endl;
	int user_open;
	cout << "Then it's your turn\nOpen a door: door ";
	cin >> user_open;
	if(user_open > 2){
		cout << "Maybe you should learn how to type 0/1/2\n\tGood Job!";
		return 0;
	}
	if(user_open == car_door)  cout << "\tYou Win!" << endl;
	else  cout << "\tYou Lose!" << endl;
} 
int main(){
	srand(int(time(0)));
	cout << "****************************************************************" << endl
	     << "*                                                              *" << endl
	     << "*                        Monty Hall                            *" << endl
	     << "*                                                              *" << endl
		 << "****************************************************************" << endl
	     << "by ";
	sleep(1);
	cout << "C.";
	sleep(1);
	cout << "Y.";
	sleep(1);
	cout << "张" << endl;
	sleep(1);
	cout << "There is a car behind one door, other is full of sheeps.\tFind the car.\n\tGood Luck!" << endl;
	start();
	for(char i; i != 'N'; ){
		cout << "Again?\t[Y]es\t[N]o" << endl;
		cin >> i;
		if(i == 'Y')  start();
	}
	return 0;
}
