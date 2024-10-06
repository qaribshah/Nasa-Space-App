#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

// Function declarations
void displayWelcomeMessage();
void showGalaxyMap();
void chooseMission(int &astronautsRescued);
void encounterObstacle(int &fuel);
bool gameOver(int astronautsRescued, int fuel);

int main() {
	srand(static_cast<unsigned int>(time(0)));

	int astronautsRescued = 0; // Counter for rescued astronauts
	int fuel = 100; // Starting fuel

	displayWelcomeMessage();

	// Main game loop
	while (true) {
		showGalaxyMap();
		chooseMission(astronautsRescued);
		encounterObstacle(fuel);

		if (gameOver(astronautsRescued, fuel)) {
			break; // Exit the game if conditions are met
		}
	}

	return 0;
}

// Function to display the welcome message
void displayWelcomeMessage() {
	cout << "========================================" << endl;
	cout << "       Welcome to Galactic Rescue!     " << endl;
	cout << "========================================" << endl;
	cout << "Your mission: Rescue stranded astronauts!" << endl;
}

// Function to show the galaxy map
void showGalaxyMap() {
	cout << "\n** Galaxy Map **" << endl;
	cout << "1. Alpha Sector" << endl;
	cout << "2. Beta Sector" << endl;
	cout << "3. Gamma Sector" << endl;
	cout << "Choose a sector to explore (1-3): ";
}

// Function to choose a mission
void chooseMission(int &astronautsRescued) {
	int choice;
	cin >> choice;

	switch (choice) {
	case 1:
		cout << "You are exploring Alpha Sector. Mission: Rescue 2 astronauts!" << endl;
		astronautsRescued += 2;
		break;
	case 2:
		cout << "You are exploring Beta Sector. Mission: Rescue 3 astronauts!" << endl;
		astronautsRescued += 3;
		break;
	case 3:
		cout << "You are exploring Gamma Sector. Mission: Rescue 1 astronaut!" << endl;
		astronautsRescued += 1;
		break;
	default:
		cout << "Invalid choice! Please select a valid sector." << endl;
		chooseMission(astronautsRescued); // Retry
	}
	cout << "Total astronauts rescued: " << astronautsRescued << endl;
}

// Function to encounter an obstacle
void encounterObstacle(int &fuel) {
	// Randomly determine if an obstacle occurs
	int obstacle = rand() % 2; // 0: no obstacle, 1: obstacle
	if (obstacle) {
		cout << "You've encountered an asteroid field!" << endl;
		int fuelLoss = rand() % 20 + 10; // Random fuel loss between 10 and 29
		fuel -= fuelLoss;
		cout << "You lost " << fuelLoss << " fuel. Remaining fuel: " << fuel << endl;
	}
	else {
		cout << "No obstacles encountered. Fuel remains stable." << endl;
	}
}

// Function to check if the game is over
bool gameOver(int astronautsRescued, int fuel) {
	if (fuel <= 0) {
		cout << "Game Over! You ran out of fuel!" << endl;
		return true; // Game over due to fuel loss
	}
	if (astronautsRescued >= 10) {
		cout << "Congratulations! You successfully rescued all astronauts!" << endl;
		return true; // Game over, player wins
	}
	return false; // Game continues
}
