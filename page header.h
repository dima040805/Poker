

#include <iostream>
#include <cmath>
#include <time.h>

struct karts{
	int suit, value;
};

struct ruka_player{
	karts ruka[5];
	int points, starshaya;
};

struct person{
	int bal, bet, type;
	karts player[2];
	ruka_player five_kart, best_ruka;
};


void karts_1(person player[2], int koloda[4][13], int& k1);
void first_cads(karts stol[5], int koloda[4][13], int& k);
void add_card(karts stol[5], int koloda[4][13], int& k);

void stavki_osn(person player[2], int& k1, int& bank);

void result(ruka_player& ruka);
void luchaya_ruka(person players[2], int& k1, karts stol[5]);


void winner(person players[2], int& bank);
