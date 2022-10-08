//Project 2-Stacks
//Zechariah Delos Santos
//CIS-277-602HY

#include <iostream>
#include <iomanip>

using namespace std;

int stack[15];
int point = -1;

void newStack(int &point, int &select){
	cout << "Would you like to start a new stack?" << endl;
	cout <<"------------------------------------------------------------------" << endl;
	cout << "Enter 1 to create a new stack" << endl;
	cout << "Enter 6 to end program" << endl;
	cout <<"------------------------------------------------------------------" << endl;
	cin >> select;
	while(!(cin.fail()) && (select == 7 || select == 1)){
		cin.clear();
		cin.ignore();
		cout << "Please enter a valid input" << endl;
		cout <<"------------------------------------------------------------------" << endl;
		cout << "Enter 1 to create a new stack" << endl;
		cout << "Enter 6 to end program" << endl;
		cout <<"------------------------------------------------------------------" << endl;
		cin >> select;
	}
	if(select == 7){
		point = -1;
		select = 1;
	}
}
void display(int point){
	cout << "The Current Stack is :[ ";
	for (int i = 0; i <= point; i++){
		cout << stack[i] << ", ";
	}
	cout <<"]" << endl;
}
void full(){
		cout << "***********ERROR**********"<<endl;
		cout << "**** OVERFLOW STACK IS FULL ******" << endl;
}
void empty(){
		cout << "***********ERROR**********"<<endl;
		cout << "**** UNDERFLOW STACK IS EMPTY ******" << endl;
}
void push(int &point){
	int val;
	if(point == 14){
		full();
	}else{
		cout << "enter a value to push" << endl;
		cin >> val;
		point++;
		stack[point] = val;
	}
}
void pop(int &point){
	if(point == -1){
		empty();
	}else{
		cout << stack[point] << endl;
		point--;
	}
}
void top(int point){
	if(point == -1){
		empty();
	}else{
		cout << "The current top of the stack is : " << stack[point] << endl;
	}
}
void selection(int &select){
	cout <<"----------------Please Enter a Selection--------------------------" << endl;
	display(point);
	cout <<"Enter 1:Top" << endl;
	cout <<"Enter 2:Push"<< endl;
	cout <<"Enter 3:Pop" << endl;
	cout <<"Enter 4:Purge" << endl;
	cout <<"Enter 6 to end program" << endl;
	cout <<"------------------------------------------------------------------" << endl;
	cin >> select;
	while(cin.fail()){
		cout <<"Enter an integer" << endl;
		cin.clear();
		cin.ignore();
		cin >> select;
	}
}
void purge(int &point){
	if(point == -1){
		empty();
	}else{
		point = -1;
		cout << "The Stack has been emptied" << endl;
	}
}
void selVal(int &select){
	while(!(select >= 1 && select <= 6)){
		cout << "PLEASE ENTER A VALID SELECTION"<< endl;
		selection(select);
	}
}
int main() {
	int select;
	while(select !=6){
 	 while(select != 6){
			selection(select);
			selVal(select);
			switch(select){
				case 1: 
					top(point);
					break;
				case 2:
					push(point);
					break;
				case 3:
					pop(point);
					break;
				case 4:
					purge(point);
					break;
				case 6:
					cout << "Program will terminate" <<endl;
					select = 6;
					break;
			}
		}
	newStack(point,select);
	}
	cout << "Program ending...." << endl;
	return 0;
}