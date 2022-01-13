#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool loggedIn() {
	string username;
	string password;
	string userInput;
	string userPassword;

	cout << "Enter username: "; cin >> username;
	cout << "Enter password: "; cin >> password;


	ifstream read("data\\" + username + ".txt");
	getline(read, userInput);
	getline(read, userPassword);

	if (userInput == username && userPassword == password) {

		return true;

	}
	else {
		return false;
	}
}

void printList(string userName) {
	string fileLine;

	ifstream currentFile;

	currentFile.open(userName + ".txt");
	if (currentFile.is_open()) {
		while (!currentFile.eof()) {
			getline(currentFile, fileLine);
			cout << fileLine << "\n";

		}
	}
	else {
		cout << "\nunable to open file\n\n";
	}


	return;
}


bool uniqueUserName(string userName) {
	ifstream uniqueFile;

	uniqueFile.open(userName + ".txt");


	if (uniqueFile.is_open()) {
		uniqueFile.close();
		cout << "\nUser Name has already been taken, please try a different one\n";
		return false;
	}
	else {
		uniqueFile.close();
		return true;
	}
	
}


bool pwValidate() {
	
}
void deleteUsername() {
	
	return;
}



int main() {
	int select = 0;
	bool uniqueID = false;



	while (select != 4) {
		cout << "1: Register\n";
		cout << "2: Login\n";
		cout << "3: Print\n";
		cout << "4: Exit\n";
		cout << "Selection:";

		cin >> select;

		string input_username;
		string password;

		if (select == 1) {
	
			while ( uniqueID == false) {
				uniqueID = uniqueUserName(input_username);
				cout << "select a username: ";
				cin >> input_username;
			}
			 
			
			cout << "select a password: ";
			cin >> password;

			ofstream file;
			file.open(input_username + ".txt");
			file << input_username << endl << password;
			file.close();
		}
		else if (select == 3) {
			cout << "search username:\n";
			cin >> input_username;
			printList(input_username);

		}
		else if(select == 4) {
			cout << "EXITING";
		}
		else {
			cout << "Incorrect input, try again... 1-4\n";
		}
	}

}