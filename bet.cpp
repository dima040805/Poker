

#include "page header.h"
using namespace std;


void all_in(person player[2], int& k1, int& bank){
	player[k1%2].bet = player[k1%2].bal;
	bank += player[k1%2].bet;
	player[k1%2].bal -= player[k1%2].bal;
	k1 ++;

}

void pass(person player[2], int& k1, int& bank){
	player[abs(k1 % 2 - 1)].bal += bank;
	bank = 0;
	player[k1 % 2].bet = -2;
	k1 ++;
}


void add(person player[2], int& k1, int& bank){
	cin >> player[k1%2].bet;
	bank += player[k1%2].bet;
	player[k1%2].bal -= player[k1%2].bet;
	k1 ++;

}


void call(person player[2], int& k1, int& bank){
	int razn = 0;
	if(player[abs(k1 - 1)].bet <= player[k1].bal + player[k1].bet){
		razn = (player[abs(k1 - 1)].bet - player[k1].bet);
		player[k1].bet += razn;
	}
	else
		player[k1].bet = player[k1].bal;
	player[k1].bal -= razn;
	bank += razn;
	k1 ++;
}

void check(person player[2], int& k1){
	player[k1 % 2].bet = -1;
	k1 ++;
}


int stavki(person player[2], int k1){
	int i;
	for(int i = 0; i < 2; i++)
		cout << i + 1 << " balanse = " << player[i].bal << "    ";
	cout << endl;
	if(player[abs(k1 - 1)].type == 0){
		cout << "1 - pass" << endl;
		cout << "2 - check" << endl; 
		cout << "4 - add" << endl;
		cout << "5 - all_in" << endl;}
	else if(player[abs(k1 - 1)].type == 5){
		cout << "1 - pass" << endl;
		cout << "3 - call" << endl; }
	else if(player[abs(k1 - 1)].type == 3){
		cout << "1 - pass" << endl;
		cout << "3 - call" << endl; 
		cout << "5 - all_in" << endl;}
	else if(player[abs(k1 - 1)].type == 2){
		cout << "1 - pass" << endl;
		cout << "2 - check" << endl;
		cout << "3 - call" << endl; 
		cout << "4 - add" << endl;
		cout << "5 - all_in" << endl;}
	else if(player[abs(k1 - 1)].type == 4){
		cout << "1 - pass" << endl;
		cout << "3 - call" << endl; 
		cout << "4 - add" << endl;
		cout << "5 - all_in" << endl;}
	cin >> i;
	return i;
}


void stavki_osn(person player[2], int& k1, int& bank){
	player[0].type = 0;
	player[1].type = 0;	
	if (player[0].bet != -2 && player[1].bet != -2){
	player[0].bet = 0;
	player[1].bet = 0;	
	}
	if(player[0].bal != 0 && player[1].bal != 0  && player[0].bet != -2 && player[1].bet != -2)
	do{
		switch (stavki(player, k1))
		{
			case(5):
				player[k1].type = 5;
				all_in(player, k1, bank);
				break;
			case(1):
				player[k1].type = 1;
				pass(player, k1, bank);
				break;
			case(2):
				player[k1].type = 2;
				check(player, k1);
				break;
			case(3):
				player[k1].type = 3;
				call(player, k1, bank);
				break;
			case(4):
				player[k1].type = 4;
				add(player, k1, bank);
				break;
		}
		k1 %= 2;
		}while(player[0].bet != player[1].bet && (player[0].bet != -2 && player[1].bet != -2) && (player[0].bal != 0 || player[1].bal != 0));
	k1 = 0;


}
