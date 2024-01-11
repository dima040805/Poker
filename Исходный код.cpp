#include "Âåðõíèé êîëîíòèòóë.h"
using namespace std;

int main(){
	srand(time(NULL));
	int koloda[4][13], k, bal[2] = {1000, 1000}, k1,  bank, bet[2];
	person players[2];
	karts stol[5], stol_1[5];
	for(int i = 0; i < 4; i++)
		for(int q = 0; q < 13; q++)
			koloda[i][q] = 1;
	players[0].bal = 5000;
	players[1].bal = 5000;
	while (players[0].bal != 0 && players[1].bal != 0){
		players[0].bet = 0;
		players[1].bet = 0;
		players[0].type = 0;
		players[1].type = 0;
		k1 = 0;
		k = 0;
		bank = 0;
		karts_1(players, koloda, k1);
		karts_1(players, koloda, k1);
		k1 = 0;
	
		stavki_osn(players, k1, bank);
		first_cads(stol, koloda, k);

	
		stavki_osn(players, k1, bank);
		add_card(stol, koloda, k);
	

		stavki_osn(players, k1, bank);
		add_card(stol, koloda, k);


		stavki_osn(players, k1, bank);	


		k1 = 0;
		luchaya_ruka(players, k1, stol);
		luchaya_ruka(players, k1, stol);

		winner(players, bank);}
	system("pause");
	return 0;
}
