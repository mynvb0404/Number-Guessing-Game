#pragma once
#include <iostream>
#include <random>
#include <ctime>
#include <fstream>

using namespace std;

class NumberGuessingGame
{
public:
	NumberGuessingGame() {
		srand(time(0));
		this->result = 0;
		this->score = 0;
		loadHighScoreFromFile();
	}

	~NumberGuessingGame() {
		saveHighScoreToFile();
	}
	
	void startGame() {
		srand(time(0));
		this->result = generateRandomNumber();
		this->score = 0;
	}
	//generate a random number
	int generateRandomNumber() {
		return rand() % 101;
	}

	//player select level
	int selectLevel(int playerOption) {
		return this->chances[playerOption - 1];
	}


	bool playGame(int chance) {
		int attempt = 0;
		while (attempt < chance) {
			int ans;
			cout << "\nEnter your guess: ";
			cin >> ans;
			if (ans == this->result) {
				cout << "\nCongratulations!You guessed the correct number in " << attempt << " attempts.\n";
				this->score = (chance - attempt) * 10;
				return true;
			}
			else {
				if (ans > this->result) {
					cout << "Incorrect! The number is less than " << ans << endl;
				}
				else {
					if (ans < this->result) {
						cout << "Incorrect! The number is greater than " << ans << endl;
					}
				}
			}
			attempt++;
			cout << "\nYour attempt is " << attempt + 1 << endl;
		}
		cout << "\nGame over! The correct number was " << this->result << endl;
		return false;
	}

	void saveHighScore() {
		if (this->highScore < this->score) {
			this->highScore = this->score;
			saveHighScoreToFile();
		}
	}

	void saveHighScoreToFile() {
		ofstream outFile("highscore.txt");
		if (outFile.is_open()) {
			outFile << this->highScore;
			outFile.close();
		}
		else {
			cout << "Error: Could not save high score to file.\n";
		}
	}

	void loadHighScoreFromFile() {
		ifstream inFile("highscore.txt");
		if (inFile.is_open()) {
			inFile >> this->highScore;
			inFile.close();
		}
		else {
			this->highScore = 0;
		}
	}

	void displayHighScore() {
		cout << "Your high score: " << this->highScore << endl;
	}

	void resetHighScore() {
		this->highScore = 0;
	}
private:
	int result;
	int chance;
	int attempt;
	int score;
	int playerChoice;
	int chances[3] = { 10, 5, 3 };
	int highScore = 0;

};

