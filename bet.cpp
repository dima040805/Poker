#include "page header.h"
using namespace std;


void all_in(person player[2], int& turn, int& bank){
	player[turn].bet = player[turn].bal;
	bank += player[turn].bet;
	player[turn].bal -= player[turn].bal;
}

void pass(person player[2], int& turn, int& bank){
	player[abs(turn - 1)].bal += bank;
	bank = 0;
	player[turn].bet = -2;
}


void add(person player[2], int& turn, int& bank){
	cin >> player[turn].bet;
	bank += player[turn].bet;
	player[turn].bal -= player[turn].bet;
}


void call(person player[2], int& turn, int& bank){
	int razn = 0;
	if(player[abs(turn - 1)].bet <= player[turn].bal + player[turn].bet){
		razn = (player[abs(turn - 1)].bet - player[turn].bet);
		player[turn].bet += razn;
	}
	else
		player[turn].bet = player[turn].bal;
	player[turn].bal -= razn;
	bank += razn;
}

void check(person player[2], int& turn){
	player[turn % 2].bet = -1;
}


int stavki(person player[2], int turn){
	int i;
	for(int i = 0; i < 2; i++)
		cout << i + 1 << " balanse = " << player[i].bal << "    ";
	cout << endl;
	if(player[abs(turn - 1)].type == 0){
		cout << "1 - pass" << endl;
		cout << "2 - check" << endl; 
		cout << "4 - add" << endl;
		cout << "5 - all_in" << endl;}
	else if(player[abs(turn - 1)].type == 5){
		cout << "1 - pass" << endl;
		cout << "3 - call" << endl; }
	else if(player[abs(turn - 1)].type == 3){
		cout << "1 - pass" << endl;
		cout << "3 - call" << endl; 
		cout << "5 - all_in" << endl;}
	else if(player[abs(turn - 1)].type == 2){
		cout << "1 - pass" << endl;
		cout << "2 - check" << endl;
		cout << "3 - call" << endl; 
		cout << "4 - add" << endl;
		cout << "5 - all_in" << endl;}
	else if(player[abs(turn - 1)].type == 4){
		cout << "1 - pass" << endl;
		cout << "3 - call" << endl; 
		cout << "4 - add" << endl;
		cout << "5 - all_in" << endl;}
	cin >> i;
	return i;
}


void stavki_osn(person player[2], int& turn, int& bank){
	player[0].type = 0;
	player[1].type = 0;	
	if (player[0].bet != -2 && player[1].bet != -2){
		player[0].bet = 0;
		player[1].bet = 0;	
	}
	if(player[0].bal != 0 && player[1].bal != 0  && player[0].bet != -2 && player[1].bet != -2)
	do{
		switch (stavki(player, turn))
		{
			case(5):
				player[turn].type = 5;
				all_in(player, turn, bank);
				break;
			case(1):
				player[turn].type = 1;
				pass(player, turn, bank);
				break;
			case(2):
				player[turn].type = 2;
				check(player, turn);
				break;
			case(3):
				player[turn].type = 3;
				call(player, turn, bank);
				break;
			case(4):
				player[turn].type = 4;
				add(player, turn, bank);
				break;
		}
		turn %= 2;
		turn ++;
		}while(player[0].bet != player[1].bet && (player[0].bet != -2 && player[1].bet != -2) && (player[0].bal != 0 || player[1].bal != 0));
	turn = 0;


}
