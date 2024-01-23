#include "page header.h"
using namespace std;


bool flash(int res1[4]){
	for(int i = 0; i < 4; i ++)
		if (res1[i] == 5)
			return true;
		else
			return false;
}


void result(playerHand &ruka){
	int points = 0;
	ruka.starshaya = 0;
	int res[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int res1[4] = {0, 0, 0, 0}; 
	for(int i = 0; i < 5; i++)
		res[ruka.hand[i].suit] ++;
	for(int i = 0; i < 5; i++)
		res1[ruka.hand[i].value] ++;
	for(int i = 0; i < 13; i++){
		if(res[i] == 2){
			points ++;
			for(int q = i + 1; q < 13; q ++){
				if(res[q] == 2){
					points ++;
					ruka.starshaya = ruka.hand[q].suit;
					break;}
				if(res[q] == 3){
					points += 5;
					ruka.starshaya = ruka.hand[q].suit;
					break;
				}
			}
			ruka.starshaya = ruka.hand[i].suit;
			break;
		}
		if(res[i] == 3){
			points = 3;
			for(int q = i + 1; q < 13; q ++){
				if(res[q] == 2){
					points = 6;
					ruka.starshaya = ruka.hand[q].suit;
					break;}
			}
			ruka.starshaya = ruka.hand[i].suit;
			break;
		}
		if(res[i] == 4){
			points = 7;
			ruka.starshaya = ruka.hand[i].suit;
			break;}
		if(i <= 7){
			if((res[i] == 1 && res[i + 1] == 1 && res[i + 2] == 1 && res[i + 3] == 1 && res[i + 4] == 1) ||
				(res[12] == 1 && res[0] == 1 && res[1] == 1 && res[2] == 1 && res[3] == 1)){
				points = 4;
				ruka.starshaya = i + 4;
				break;
			}
		}
		for(int q = 0; q < 5; q ++)
			if (ruka.hand[q].suit > ruka.starshaya)
				ruka.starshaya = ruka.hand[q].suit;
	}
	if(flash(res1))
		if(points == 4)
			if(ruka.starshaya == 12)
				points = 9;
			else
				points = 8;
		else
			points = 5;
	ruka.points = points;
}




void bestHand(person players[2], int& turn, karts stol[5]){
		char* c[4] = {"Diamonds", "Hearts", "Spades", "Clubs"};
		char* c1[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
		playerHand best_ruka[2];
		int max = 0, maxs = 0;
		for(int i = 0; i < 5; i++){
			players[turn].five_kart.points = 0;
			for(int q = 0; q < 5; q++){
				for(int j = 0; j < 5; j++)
					players[turn].five_kart.hand[j] = stol[j];
				players[turn].five_kart.hand[i] = players[turn].PlayerKarts[0];
				if( q != i)
					players[turn].five_kart.hand[q] = players[turn].PlayerKarts[1];
				result(players[turn].five_kart);
				if(players[turn].five_kart.points > max){
					max = players[turn].five_kart.points;
					best_ruka[turn] = players[turn].five_kart;
				}
				else if(players[turn].five_kart.points == max)
					if(players[turn].five_kart.starshaya >= maxs){
						maxs = players[turn].five_kart.points;
						best_ruka[turn] = players[turn].five_kart;
				
					}
			}
		}
		players[turn].best_hand = best_ruka[turn];
	cout << "palyer " << turn + 1 << ": ";
	for(int q = 0; q < 5; q ++)
		cout << c1[best_ruka[turn].hand[q].suit] << ' ' << c[best_ruka[turn].hand[q].value] << "    ";
	cout << best_ruka[turn].points << endl;
		turn ++;
}



void winner(person players[2], int& bank){
	char* c[4] = {"Diamonds", "Hearts", "Spades", "Clubs"};
	char* c1[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
	if(players[0].best_hand.points > players[1].best_hand.points){
		for(int q = 0; q < 5; q ++)
			cout << c1[players[0].best_hand.hand[q].suit] << ' ' << c[players[0].best_hand.hand[q].value] << "    ";
		cout << players[0].best_hand.points << endl;
		players[0].bal += bank;
		bank = 0;
	}
	else if(players[0].best_hand.points < players[1].best_hand.points) {
		for(int q = 0; q < 5; q ++)
			cout << c1[players[1].best_hand.hand[q].suit] << ' ' << c[players[1].best_hand.hand[q].value] << "    ";
		cout << players[1].best_hand.points << endl;
		players[1].bal += bank;
		bank = 0;	
	}
	else if(players[0].best_hand.starshaya > players[1].best_hand.starshaya){
				for(int q = 0; q < 5; q ++)
			cout << c1[players[0].best_hand.hand[q].suit] << ' ' << c[players[0].best_hand.hand[q].value] << "    ";
		cout << players[0].best_hand.points << endl;
		players[0].bal += bank;
		bank = 0;	
	}
	else {
		for(int q = 0; q < 5; q ++)
			cout << c1[players[1].best_hand.hand[q].suit] << ' ' << c[players[1].best_hand.hand[q].value] << "    ";
		cout << players[1].best_hand.points << endl;
		players[1].bal += bank;
		bank = 0;	
	}
	cout << players[0].bal << "   " << players[1].bal << endl;


}
