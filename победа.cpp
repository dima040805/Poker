#include "Верхний колонтитул.h"
using namespace std;


bool flash(int res1[4]){
	for(int i = 0; i < 4; i ++)
		if (res1[i] == 5)
			return true;
		else
			return false;
}


void result(ruka_player& ruka){
	int points = 0;
	ruka.starshaya = 0;
	int res[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int res1[4] = {0, 0, 0, 0}; 
	for(int i = 0; i < 5; i++)
		res[ruka.ruka[i].suit] ++;
	for(int i = 0; i < 5; i++)
		res1[ruka.ruka[i].value] ++;
	for(int i = 0; i < 13; i++){
		if(res[i] == 2){
			points ++;
			for(int q = i + 1; q < 13; q ++){
				if(res[q] == 2){
					points ++;
					ruka.starshaya = ruka.ruka[q].suit;
					break;}
				if(res[q] == 3){
					points += 5;
					ruka.starshaya = ruka.ruka[q].suit;
					break;
				}
			}
			ruka.starshaya = ruka.ruka[i].suit;
			break;
		}
		if(res[i] == 3){
			points = 3;
			for(int q = i + 1; q < 13; q ++){
				if(res[q] == 2){
					points = 6;
					ruka.starshaya = ruka.ruka[q].suit;
					break;}
			}
			ruka.starshaya = ruka.ruka[i].suit;
			break;
		}
		if(res[i] == 4){
			points = 7;
			ruka.starshaya = ruka.ruka[i].suit;
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
			if (ruka.ruka[q].suit > ruka.starshaya)
				ruka.starshaya = ruka.ruka[q].suit;
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




void luchaya_ruka(person players[2], int& k1, karts stol[5]){
		char* c[4] = {"Diamonds", "Hearts", "Spades", "Clubs"};
		char* c1[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
		ruka_player best_ruka[2];
		int max = 0, maxs = 0;
		for(int i = 0; i < 5; i++){
			players[k1].five_kart.points = 0;
			for(int q = 0; q < 5; q++){
				for(int j = 0; j < 5; j++)
					players[k1].five_kart.ruka[j] = stol[j];
				players[k1].five_kart.ruka[i] = players[k1].player[0];
				if( q != i)
					players[k1].five_kart.ruka[q] = players[k1].player[1];
				result(players[k1].five_kart);
				if(players[k1].five_kart.points > max){
					max = players[k1].five_kart.points;
					best_ruka[k1] = players[k1].five_kart;
				}
				else if(players[k1].five_kart.points == max)
					if(players[k1].five_kart.starshaya >= maxs){
						maxs = players[k1].five_kart.points;
						best_ruka[k1] = players[k1].five_kart;
				
					}
			}
		}
		players[k1].best_ruka = best_ruka[k1];
	cout << "palyer " << k1 + 1 << ": ";
	for(int q = 0; q < 5; q ++)
		cout << c1[best_ruka[k1].ruka[q].suit] << ' ' << c[best_ruka[k1].ruka[q].value] << "    ";
	cout << best_ruka[k1].points << endl;
		k1 ++;
}



void winner(person players[2], int& bank){
	char* c[4] = {"Diamonds", "Hearts", "Spades", "Clubs"};
	char* c1[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
	if(players[0].best_ruka.points > players[1].best_ruka.points){
		for(int q = 0; q < 5; q ++)
			cout << c1[players[0].best_ruka.ruka[q].suit] << ' ' << c[players[0].best_ruka.ruka[q].value] << "    ";
		cout << players[0].best_ruka.points << endl;
		players[0].bal += bank;
		bank = 0;
	}
	else if(players[0].best_ruka.points < players[1].best_ruka.points) {
		for(int q = 0; q < 5; q ++)
			cout << c1[players[1].best_ruka.ruka[q].suit] << ' ' << c[players[1].best_ruka.ruka[q].value] << "    ";
		cout << players[1].best_ruka.points << endl;
		players[1].bal += bank;
		bank = 0;	
	}
	else if(players[0].best_ruka.starshaya > players[1].best_ruka.starshaya){
				for(int q = 0; q < 5; q ++)
			cout << c1[players[0].best_ruka.ruka[q].suit] << ' ' << c[players[0].best_ruka.ruka[q].value] << "    ";
		cout << players[0].best_ruka.points << endl;
		players[0].bal += bank;
		bank = 0;	
	}
	else {
		for(int q = 0; q < 5; q ++)
			cout << c1[players[1].best_ruka.ruka[q].suit] << ' ' << c[players[1].best_ruka.ruka[q].value] << "    ";
		cout << players[1].best_ruka.points << endl;
		players[1].bal += bank;
		bank = 0;	
	}
	cout << players[0].bal << "   " << players[1].bal << endl;


}