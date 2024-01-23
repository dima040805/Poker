#include "page header.h"
using namespace std;


void all_in(person player[2], int& turn, int& bank){
	player[turn].bet = player[turn].bal;
	bank += player[turn].bet;
	player[turn].bal -= player[turn].bal;
	cout << endl << "Player " << turn + 1  << " choose All-in. And your bet is - " << player[turn].bet << endl << endl;
}


void pass(person player[2], int& turn, int& bank){
	player[abs(turn - 1)].bal += bank;
	bank = 0;
	player[turn].bet = -2;
	cout << endl << "You choose Pass"<< endl << endl;
}


void add(person player[2], int& turn, int& bank, int BetAi){
	cout << endl << "What is your bet?" << endl << endl;
	if(turn == 0)
		cin >> player[turn].bet;
	else
		player[turn].bet = BetAi;
	bank += player[turn].bet;
	player[turn].bal -= player[turn].bet;
	cout << endl << "Player " << turn + 1  << " choose Add. And your bet is - " << player[turn].bet << endl << endl;
}


void call(person player[2], int& turn, int& bank){
	int razn = 0;
	if(player[turn].bet < 0)
		player[turn].bet ++;
	if(player[abs(turn - 1)].bet <= player[turn].bal + player[turn].bet){
		razn = (player[abs(turn - 1)].bet - player[turn].bet);
		player[turn].bet += razn;
		}
	else
		player[turn].bet = player[turn].bal;
	player[turn].bal -= razn;
	bank += razn;
	cout << "Player " << turn + 1  << " choose Call. And your bet is - " << player[turn].bet << endl;
}


void check(person player[2], int& turn){
	player[turn % 2].bet = -1;
	cout << "Player " << turn + 1  << " Check." << endl;
}


int stavki(person player[2], int turn, int koloda[4][13], karts stol[5], int KolKart,int &BetAi){
	int i;
	if(turn == 0){
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
		else
			return ArtificialIntelligence(player, koloda, stol, KolKart, BetAi);
	cout << endl;
}


void stavki_osn(person player[2], int& turn, int& bank, int koloda[4][13], karts stol[5], int KolKart){
	bool flag = false;
	for(int i = 0; i < 2; i++)
		cout << i + 1 << " balanse = " << player[i].bal << "    " ;
	cout << endl << endl;
	player[0].type = 0;
	player[1].type = 0;	
	int BetAi;
	if (player[0].bet != -2 && player[1].bet != -2){
		player[0].bet = 0;
		player[1].bet = 0;	
	}
	if(player[0].bal != 0 && player[1].bal != 0  && player[0].bet != -2 && player[1].bet != -2)
	do{
		flag = false;
		switch (stavki(player, turn, koloda, stol, KolKart, BetAi))
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
				add(player, turn, bank, BetAi);
				break;
			default:
				flag = true;
				cout << "Repet please" << endl;
				break;
		}
		if(!flag){
		turn ++;
		turn %= 2;
		}
		}while((player[0].bet != player[1].bet && (player[0].bet != -2 && player[1].bet != -2) && (player[0].bal != 0 || player[1].bal != 0)) || flag);
	turn = 0;


}
