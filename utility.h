#include <iostream>
#include <windows.h> //Sleep()

using namespace std;

void centerString(const string &str, const int padding) {
	for (int i = 0; i < padding; ++i) cout << " ";
	cout << str;
	for (int i = 0; i < padding; ++i) cout << " ";
    cout << endl;
}

void slowType(string stringToType, int typeDelay = 35, int sleepTime = 500) {
	for (int i = 0; i < stringToType.size(); i++) {
		cout << stringToType[i];
		Sleep(typeDelay);
	}
	Sleep(sleepTime);
}

void clearScreen(int time = 1500){
	Sleep(time);
	system("cls");
}

void awaitInput(){
	getch();
}