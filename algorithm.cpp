#include <iostream>

using namespace std;

// T13 sustav bodovanja na kraju igre
// T14 određivanje težine zadataka

class Player {
public:
	int points;
	int lives;
	int modifier;
	int answers;
	int highscore;
	
	// Poziva se prilikom nove igre, stavlja varijable na svoje inicijalne vrijednosti
	
	void newGame() {
		points = 0;
		lives = 3;
		modifier = 1;
		answers = 0;
	};
	
	// Dobivanje bodova, poziva se prilikom tocnog odgovora, prima preostalo vrijeme u sekundama
	
	void GainPoints(int time) {
		points += time * modifier;
		answers++;
	};
	
	void GameOver() {
		if (points > highscore) {
			highscore = points;
		}
	}
	
	// Ažurira modifikator kojim se određuje težina zadataka te se igrača dodatno nagrađuje za točan odgovor
	
	void newModifier() {
		if (answers >= 5 & answers < 10) {
			modifier = 2;
		}
		
		if (answers >= 10 & answers < 15) {
			modifier = 3;
		}
		
		if (answers >= 15 & answers < 20) {
			modifier = 4;
		}
		
		if (answers >= 20) {
			modifier = 5;
		}
	};
};

int main() {
	
}


