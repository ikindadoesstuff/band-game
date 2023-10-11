#include <iostream> 
#include <windows.h>
#include <string>
#include <cstdio> //printf()
#include <conio.h> //getch()
#include <cstdlib> //rand
#include "utility.h"

#pragma comment(lib, "User32.lib") 
#pragma comment(lib, "winmm.lib")

using namespace std;

void init();
void showTitle();
void playStory();
void displayStats(string bandName, float stats[]);
void handleFail(string message);

int main() {
	init(); 
	cout << "\nThanks for playing!";
}

void init() {
	showTitle();
	awaitInput();
	playStory();
	//PlaySoundA("C:\\Users\\devyo\\Development\\band-game\\resources\\Sound\\soundtrack1.mp3", NULL, SND_ASYNC);			
}

void showTitle() {
	centerString(" _______  __   __  _______    _______  _______  __   __  _______  __   __  _______ ",10);
	centerString("|       ||  | |  ||       |  |       ||       ||  |_|  ||       ||  | |  ||       |",10);
	centerString("|_     _||  |_|  ||    ___|  |    ___||   _   ||       ||    ___||  | |  ||    _  |",10);
	centerString("  |   |  |       ||   |___   |   |    |  | |  ||       ||   |___ |  |_|  ||   |_| |",10);
	centerString("  |   |  |       ||    ___|  |   |    |  |_|  ||       ||    ___||       ||    ___|",10);
	centerString("  |   |  |   _   ||   |___   |   |___ |       || ||_|| ||   |___ |       ||   |    ",10);
	centerString("  |___|  |__| |__||_______|  |_______||_______||_|   |_||_______||_______||___|    ",10);

	cout << endl << endl << endl;

	centerString("Press Any Key to Start...",50);
	clearScreen();
}

void playStory() {
	//Declare Player Variables
	string characterName;
	string bandName;
	char choice;
	//Declaring Player Stats
	float stats[] = {/*Money*/0, /*Plays*/0, /*Fans*/0, /*Multiplier*/1};
	
	//Initializing player variables
	slowType("Hello there!\n");
	slowType("Enter a name, young musician: ");
	getline(cin, characterName);
	slowType("And the name of your band: ");
	getline(cin, bandName);

	clearScreen();
	Sleep(500);

	//NARATTIVE BEGINS
	displayStats(bandName, stats);
	slowType(characterName + ": It's time " + bandName + " got off the ground.\n");

	//CHOICE: INITIAL INVESTMENT
	int _init_investment = (rand() * 10);
	slowType("(Your Aunt offers an investment of $" + to_string(_init_investment) + ". Do you accept? Y/N: ");
	choice = getch();
	switch (choice)
	{
	case 'y':
		slowType("\nYou accept her generous offer. " + bandName + " gets +$" + to_string(_init_investment) + " to start off.");
		stats[0] += _init_investment;
		break;
	
	case 'n':
		handleFail("\nYou decline. You have no money to start off. Without this, " + bandName + "'s dreams come to a halt.");
		return;
	}

	//Resetting Screen
	clearScreen(2000);
	displayStats(bandName, stats);

	//CHOICE: Purchasing Equipment
	slowType("A band needs good instruments and audio equipment. Time to use that investment you received wisely!\n");
	float _equipTotal = 0;
	float _instrTotal = 0;
	bool _choices1[] = {false,false,false,false};
	float _total  = 0;
	while(true){
		bool purchased = false;

		cout << "1. Purchase HIGH Quality Audio Equipment [+0.5x] ($200) " << (_choices1[0] ? "YES" : "NO") << endl;
		cout << "2. Purchase LOW Quality Audio Equipment  [+0.2x] ($75)  " << (_choices1[1] ? "YES" : "NO") << endl;
		cout << "3. Purchase HIGH Quality Instruments     [+0.5x] ($300) " << (_choices1[2] ? "YES" : "NO") << endl;
		cout << "4. Purchase LOW Quality Instruments      [+0.2x] ($100) " << (_choices1[3] ? "YES" : "NO") << endl;
		cout << "TOTAL: " << _total;

		choice = getch();
		switch (choice)
		{
		case '1':
			_choices1[0] = true;
			_choices1[1] = false;
			_equipTotal = 200;
			break;
		case '2':
			_choices1[0] = false;
			_choices1[1] = true;
			_equipTotal = 75;
			break;
		case '3':
			_choices1[2] = true;
			_choices1[3] = false;
			_instrTotal = 300;
			break;
		case '4':
			_choices1[2] = false;
			_choices1[3] = true;
			_instrTotal = 100;
			break;
		//Backspace is ASCII character 13
		case 13:
			_total  = _equipTotal + _instrTotal;
			if(_total > stats[0]){
				slowType("You can't afford that!", 35, 1000);
				break;
			}
			purchased = true;
			if(_choices1[0]) stats[3] += 0.5;
			if(_choices1[1]) stats[3] += 0.2;
			if(_choices1[2]) stats[3] += 0.5;
			if(_choices1[3]) stats[3] += 0.2;
			break;
		}
		_total  = _equipTotal + _instrTotal;
		clearScreen(50);
		displayStats(bandName, stats);
		cout << endl;

		if(purchased) {
			stats[0] -= _total;
			break;
		}
	}
	
	//Resetting Screen
	clearScreen(2000);
	displayStats(bandName, stats);

	//CHOICE: Record and publish first song
	slowType("Time to record and publish your first song!\n");
	float _recordTotal = 0;
	float _publishTotal = 0;
	bool _choices2[] = {false,false,false,false,false,false};
	_total  = 0;
	while(true){
		bool published = false;

		cout << "1. Spend 10 HOURS Perfecting Your Song [+0.5x] ($100) " << (_choices2[0] ? "YES" : "NO") << endl;
		cout << "2. Spend 5 HOURS Perfecting Your Song  [+0.2x] ($75)  " << (_choices2[1] ? "YES" : "NO") << endl;
		cout << "3. Publish On Spoopify                 [+0.25x] ($50) " << (_choices2[2] ? "YES" : "NO") << endl;
		cout << "4. Publish On Banana Music             [+0.25x] ($50) " << (_choices2[3] ? "YES" : "NO") << endl;
		cout << "5. Publish On SoundWave                [+0.25x] ($50) " << (_choices2[4] ? "YES" : "NO") << endl;
		cout << "6. Publish On SurroundAudio            [+0.25x] ($50) " << (_choices2[5] ? "YES" : "NO") << endl;
		cout << "TOTAL: " << _total;

		choice = getch();
		switch (choice)
		{
		case '1':
			_choices2[0] = true;
			_choices2[1] = false;
			_recordTotal = 100;
			break;
		case '2':
			_choices2[0] = false;
			_choices2[1] = true;
			_recordTotal = 75;
			break;
		case '3':
			if (_choices2[2]) {
				_choices2[2] = false;
				_publishTotal -= 50;
			} else {
				_choices2[2] = true;
				_publishTotal += 50;
			} 
			break;
		case '4':
			if (_choices2[3]) {
				_choices2[3] = false;
				_publishTotal -= 50;
			} else {
				_choices2[3] = true;
				_publishTotal += 50;
			}
			break;
		case '5':
			if (_choices2[4]) {
				_choices2[4] = false;
				_publishTotal -= 50;
			} else {
				_choices2[4] = true;
				_publishTotal += 50;
			}
			break;
		case '6':
			if (_choices2[5]) {
				_choices2[5] = false;
				_publishTotal -= 50;
			} else {
				_choices2[5] = true;
				_publishTotal += 50;
			}
			break;
		//Backspace is ASCII character 13
		case 13:
			_total  = _recordTotal + _publishTotal;
			if(_total > stats[0]){
				slowType("You can't afford that!", 35, 1000);
				break;
			}
			published = true;
			if(_choices2[0]) stats[3] += 0.50;
			if(_choices2[1]) stats[3] += 0.20;
			if(_choices2[2]) stats[3] += 0.25;
			if(_choices2[3]) stats[3] += 0.25;
			if(_choices2[4]) stats[3] += 0.25;
			if(_choices2[5]) stats[3] += 0.25;
			break;
		}
		_total  = _recordTotal + _publishTotal;
		clearScreen(50);
		displayStats(bandName, stats);
		cout << endl;

		if(published) {
			stats[0] -= _total;
			break;
		}
	}
	
	//Resetting Screen
	clearScreen(2000);
	displayStats(bandName, stats);

	//End
	slowType("Its been a month since you released your first song.\n");
	slowType("Let's see how you did.\n");
	stats[1] += trunc(2000 * stats[3]);
	stats[2] += trunc(500 * stats[3]);
	slowType("You garnered " + to_string(static_cast<int>(stats[1])) + " plays, and\n");
	slowType("you gained " + to_string(static_cast<int>(stats[2])) + " fans");

	//Resetting Screen
	clearScreen(2000);
	displayStats(bandName, stats);
		slowType("You're well on your way to becoing a worldwide sensation!\n");
		slowType("Unfortunately, continuing on from this point would require\nus to rebuild the game from scratch, so as to fit the scope.\n");
		slowType("Nevertheless, we appreciate you playing so far.\n");

	//displayStats(bandName, stats);
}

void displayStats(string bandName, float stats[]){
    cout << bandName << endl;
    cout << "Money: $" << stats[0] << endl;
    cout << "Plays:  "  << stats[1] << endl;
    cout << "Fans:   "   << stats[2] << endl;
    cout << "Band Ability : "   << stats[3] << "x" << endl;
    cout << "====================" << endl;
}

void handleFail(string message){
	slowType(message);
}