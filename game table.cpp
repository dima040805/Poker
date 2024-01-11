#include "page header.h"
using namespace std;

void karts_1(person player[2], int koloda[4][13], int& k1){
	char* c[4] = {"Diamonds", "Hearts", "Spades", "Clubs"};
	char* c1[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
	int s, v;
	for(int i = 0; i < 2; i++){
		s = rand() % 13;
		v = rand() % 4;
		player[k1].player[i].suit = -1;
		while(player[k1].player[i].suit == -1){
			if(koloda[v][s] != 0){
				player[k1].player[i].suit = s;
				player[k1].player[i].value = v;
				koloda[v][s] = 0;
				break;
			}
			s = rand() % 13;
			v = rand() % 4;}
	}
	cout << "player: ";
	for(int i = 0; i < 2; i ++)
		cout << c1[player[k1].player[i].suit] << ' ' << c[player[k1].player[i].value] << "      ";
	cout << endl;
	k1++;
	k1 %= 2;
}


void first_cads(karts stol[5], int koloda[4][13], int& k){
	char* c[4] = {"Diamonds", "Hearts", "Spades", "Clubs"};
	char* c1[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
	int s, v;
	while(k < 3){
		s = rand() % 13;
		v = rand() % 4;
		stol[k].suit = -1;
	while(stol[k].suit == -1){
		if(koloda[v][s] != 0){
			stol[k].suit = s;
			stol[k].value = v;
			koloda[v][s] = 0;
			break;}
		s = rand() % 13;
		v = rand() % 4;
	}
	k++;
	}
	for (int i = 0; i < 20; i++)
	{
		cout << "- ";
	}
	cout << endl;
	for(int i = 0; i < k; i ++)
		cout << c1[stol[i].suit] << ' ' << c[stol[i].value] << "    ";
	cout << endl;
	for (int i = 0; i < 20; i++)
	{
		cout << "- ";
	}
	cout << endl;
}


void add_card(karts stol[5], int koloda[4][13], int& k){
	char* c[4] = {"Diamonds", "Hearts", "Spades", "Clubs"};
	char* c1[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
	int s, v;
		s = rand() % 13;
		v = rand() % 4;
		stol[k].suit = -1;
	while(stol[k].suit == -1){
		if(koloda[v][s] != 0){
			stol[k].suit = s;
			stol[k].value = v;
			koloda[v][s] = 0;
			break;}
		s = rand() % 13;
		v = rand() % 4;
	}
	k ++;
	for (int i = 0; i < 20; i++)
	{
		cout << "- ";
	}
	cout << endl;
	for(int i = 0; i < k; i ++)
		cout << c1[stol[i].suit] << ' ' << c[stol[i].value] << "    ";
	cout << endl;
	for (int i = 0; i < 20; i++)
	{
		cout << "- ";
	}
	cout << endl;
}
