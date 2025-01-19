#include "NumberGuessingGame.h"
int main() {
	int option;
	NumberGuessingGame game;
	cout <<"Hello, World!\n";
	cout <<"Welcome to Number Guessing Game - made by mynvb0404\n";
	cout <<"=============================================\n";
	cout <<"In this game, you need to guess a number between 1 and 100.\n";
	cout <<"You will have a limited number of chances based on the difficulty level you choose.\n";
	cout <<"   - Easy (10 chances)\n";
	cout <<"   - Medium (5 chances)\n";
	cout <<"   - Hard (3 chances)\n";
	cout <<"\nGame Rules:\n";
	cout <<"1. The game will generate a random number between 1 and 100.\n";
	cout <<"2. You have to guess the number within the given chances.\n";
	cout <<"3. After each guess, the game will tell you whether your guess is too high or too low.\n";
	cout <<"4. If you guess correctly within the allowed chances, you win the game!\n";
	cout <<"5. If you run out of chances, the game will be over and the number will be revealed.\n";
	cout << "\nHow to Calculate Your Score:\n";
	cout << "1. Start by checking your remaining chances:\n";
	cout << "   - Each level has a set number of chances (Easy - 10, Medium - 5, Hard - 3).\n";
	cout << "2. Formula for calculating score:\n";
	cout << "\n";
	cout << "       *------------------------------------------------*\n";
	cout << "       | Score = (Max Chances - Remaining Chances) * 10 |\n";
	cout << "       *------------------------------------------------*\n";
	cout << "\n   - The more chances you use up, the more your score increases.\n";

	cout <<"\nGood luck, and let's have fun!\n";
	do
	{
		cout << "Choose a level:\n";
		cout << "1 - Easy (10 chances)\n";
		cout << "2 - Medium (5 chances)\n";
		cout << "3 - Hard (3 chances)\n";
		cout << "4 - High score\n";
		cout << "5 - Reset your high score\n";
		cout << "0 - Quit\n";
		cin >> option;
		int level = game.selectLevel(option);
		system("cls");
		game.startGame();

		if (option == 1 || option == 2 || option == 3) {
			cout << "You have " << level << " chances to guess the correct number.\nGame started!\n";
		}
		switch (option) {
		case 1:
			game.playGame(level);
			game.saveHighScore();
			break;
		case 2:
			game.playGame(level);
			game.saveHighScore();
			break;
		case 3:
			game.playGame(level);
			game.saveHighScore();
			break;
		case 4:
			game.displayHighScore();
			break;
		case 5:
			game.resetHighScore();
			break;
		case 0:
			break;
		default:
			cout << "Invalid option\n";
			break;
		}
	} while (option != 0);
	return 0;
}
