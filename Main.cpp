#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {

	double totalWinnings = 0;
	double averageWinnings = 0;
	int menuInput;
	double slotNum;
	int bounceNum;
	const int RANDOM_SEED = 42;
	srand(RANDOM_SEED);
	double chipNum;
	int origSlotNum;
	cout << fixed;

	cout << "Welcome to The Plinko simulator! Enter 3 to see options. " <<
		endl << endl << "Enter your selection now:";
	cin >> menuInput;

	while (menuInput != 4) {
		if ((menuInput > 4) || (menuInput < 1)) {
			cout << endl << "Invalid selection. Enter 3 to see options." << endl;
		}

		if (menuInput == 3) {
			cout << "Menu: Please select one of the following options:" << endl
				<< endl << "1 - Drop a single chip into one slot" << endl
				<< "2 - Drop multiple chips into one slot" << endl << "3 - Show the options menu" <<
				endl << "4 - Quit the program" << endl;
		}

		if (menuInput == 1) {
			slotNum = 0;
			cout << endl << "*** Drop a single chip ***" << endl << endl;
			cout << "Which slot do you want to drop the chip in (0-8)?" << endl;
			cin >> slotNum;
			if (slotNum < 0 || slotNum > 8) {
				cout << "Invalid slot." << endl << endl;
			}
			else {
				cout << "*** Dropping chip into slot " << setprecision(0) << slotNum << " ***" << endl;
				cout << "Path: [ ";
				for (int i = 0; i < 12; ++i) {
					cout << setprecision(1) << slotNum << ", ";

					if (slotNum == 0) {
						slotNum = slotNum + .5;
					}
					else if (slotNum == 8) {
						slotNum = slotNum - .5;
					}
					else {
						bounceNum = rand() % 2;
						if (bounceNum == 1) {
							slotNum = slotNum + .5;
						}
						else {
							slotNum = slotNum - .5;
						}
					}
				}
				cout << slotNum;
				if (slotNum  <  0.5 || slotNum > 7.5) {
					totalWinnings = 100.00;
				}
				else if (slotNum < 1.5 || slotNum > 6.5) {
					totalWinnings = 500.00;
				}
				else if (slotNum < 2.5 || slotNum > 5.5) {
					totalWinnings = 1000.00;
				}
				else if (slotNum < 3.5 || slotNum > 4.5) {
					totalWinnings = 0.00;
				}
				else {
					totalWinnings = 10000.00;
				}
				cout << "]";
				cout << endl << setprecision(2) << "Winnings: $" << totalWinnings << endl << endl;
				totalWinnings = 0;
			}
		}

		if (menuInput == 2) {
			cout << endl << "*** Drop multiple chips ***" << endl << endl << "How many chips do you want to drop(> 0) ? ";
			cin >> chipNum;
			cout << endl << endl;
			if (chipNum < 0) {
				cout << "Invalid number of chips." << endl;
			}
			else {
				cout << "Which slot do you want to drop the chip in (0-8)?";
				cin >> origSlotNum;
				if (origSlotNum < 0 || origSlotNum > 8) {
					cout << "Invalid slot." << endl;
				}
				else {
					cout << endl;
					for (int j = 0; j < chipNum; j++) {
						slotNum = origSlotNum;
						for (int i = 0; i < 12; ++i) {
							if (slotNum == 0) {
								slotNum = slotNum + .5;
							}
							else if (slotNum == 8) {
								slotNum = slotNum - .5;
							}
							else {
								bounceNum = rand() % 2;
								if (bounceNum == 1) {
									slotNum = slotNum + .5;
								}
								else {
									slotNum = slotNum - .5;
								}
							}

						}
						if (slotNum < 0.5 || slotNum > 7.5) {
							totalWinnings = totalWinnings + 100;
						}
						else if (slotNum < 1.5 || slotNum > 6.5) {
							totalWinnings = totalWinnings + 500;
						}
						else if (slotNum < 2.5 || slotNum > 5.5) {
							totalWinnings = totalWinnings + 1000;
						}
						else if (slotNum < 3.5 || slotNum > 4.5) {
							totalWinnings = totalWinnings + 0;
						}
						else {
							totalWinnings = totalWinnings + 10000;
						}

					}
					cout << "Total winnings on " << setprecision(0) << chipNum << setprecision(2) << " chips: $" << totalWinnings << endl;
					averageWinnings = totalWinnings / chipNum;
					cout << "Average winnings per chip: $" << averageWinnings << endl << endl;
					totalWinnings = 0;
				}
			}
		}
		cout << "Enter your selection now:" << endl;
		cin >> menuInput;
	}
	cout << endl << "Goodbye! ";
	return 0;
}