#include <iostream>
#include <cmath>
#include <time.h>


struct karts{
	int suit, value;
};

struct playerHand{
	karts hand[5];
	int points, starshaya;
};

struct person{
	int bal, bet, type;
	karts PlayerKarts[2];
	playerHand five_kart, best_hand;
};


void karts_1(person player[2], int koloda[4][13], int& turn);
void first_cads(karts stol[5], int koloda[4][13], int& k);
void add_card(karts stol[5], int koloda[4][13], int& k);

void stavki_osn(person player[2], int& turn, int& bank);

void result(playerHand& hand);
void bestHand(person players[2], int& turn, karts stol[5]);


void winner(person players[2], int& bank);
