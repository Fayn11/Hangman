#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {

	string word = "kickboxer";
	char first_letter = word[0];
	char last_letter = word[word.length() - 1];
	string display_word = "";
	int attempts = 7;
	string used_letters = "";
	char talpa = '_';
	char try_letter;
	int letter_found = 0;

	used_letters += first_letter;
	used_letters += last_letter;
	for (int i = 0; i < word.length(); i++) {
		if (word[i] == first_letter || word[i] == last_letter) {
			display_word += word[i];
		}
		else {
			display_word += talpa;
		}
	}
	while (attempts != 0) {
		cout << display_word << "\n" << "Remaining attempts: " << attempts << "\n";
		cout << "Used letters: " << used_letters << "\n";
		if (display_word.find(talpa) != string::npos && attempts != 0) {
			letter_found = 0;
			cout << "Insert a letter!\n";
			cin >> try_letter;
			try_letter = tolower(try_letter);
			if (isalpha(try_letter)) {
				if (used_letters.find(try_letter) == string::npos) {
					for (int i = 0; i < word.length(); i++) {
						if (word[i] == try_letter) {
							display_word[i] = try_letter;
							letter_found += 1;
						}
					}
					if (letter_found != 0) {
						cout << "Letter (" << try_letter << ") found!\n";
					}
					else {
						cout << "Letter (" << try_letter << ") NOT found!\n";
						attempts -= 1;
					}
					used_letters += try_letter;
				}
				else {
					cout << "This letter is already revealed! Please try again!\n";
					attempts -= 1;
				}
			}
			else {
				cout << "That is not a letter! Try again!\n";
			}
		}
		else {
			cout << "Congratulations! You have found the word!\n";
			break;
		}
	}
	if (attempts == 0) {
		cout << "Out of attempts! The word was:\n" << word;
	}
}