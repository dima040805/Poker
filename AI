#include "page header.h"
using namespace std;

void sort(int* a){
	for(int i = 0; i < 5; i++)
		for(int q = i; q < 4; q++)
			if(a[q] > a[q + 1])
				swap(a[q], a[q+1]);
}


int RandBet(int a[5]){
	int a1[5];
	for(int i = 0; i < 5; i ++)
		a1[i] = a[i];
	sort(a1);
	int k = rand() % 100;
	for(int i = 0; i < 5; i ++)
		for(int q = 4; q > 0; q--)
			if(a[i] > a1[q])
				a[i] += a1[q];
	for(int i = k; i <= 100; i++){
		if(i == a[0])
			return 1;
		if(i == a[1])
			return 2;
		if(i == a[2])
			return 3;
		if(i == a[3])
			return 4;
		if(i == a[4])
			return 5;
	}
}


int check(person player[2], int koloda[4][13], karts stol[5], int KolKart, int& BetAi){
	int a[5] = {0, 0, 0, 0, 0};
	int a1[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int a2[4] = {0, 0, 0, 0};
	int turn = 1, max = 0, max1 = 0;
	BetAi = (rand() % 400 + 100) / 100 * 100;
	if(KolKart == 0){
		if(player[1].PlayerKarts[0].suit + player[1].PlayerKarts[1].suit >= 16){
			if(player[1].PlayerKarts[0].suit == player[1].PlayerKarts[1].suit){
				a[4] += 60;
				a[3] += 20;
				a[1] += 20;
				return RandBet(a);
			}
			else{
				a[3] += 55;
				a[1] += 45;
				return RandBet(a);
			}
		}
		else if(player[1].PlayerKarts[0].suit == player[1].PlayerKarts[1].suit){
			a[3] = 40;
			a[1] = 60;
			return RandBet(a);
		}
		else if(player[1].PlayerKarts[0].suit + player[1].PlayerKarts[1].suit < 6 && player[1].PlayerKarts[0].suit != player[1].PlayerKarts[1].suit && player[1].PlayerKarts[0].value != player[1].PlayerKarts[1].value){
			a[0] = 70;
			a[1] = 30;
			return RandBet(a);
		}
		else if(player[1].PlayerKarts[0].suit + player[1].PlayerKarts[1].suit < 16 &&  player[1].PlayerKarts[0].suit + player[1].PlayerKarts[1].suit > 8){
			a[3] = 60;
			a[1] = 40;
			return RandBet(a);
		}
		else 
			return 2;
	}
	else if(KolKart == 3){
		for(int i = 0; i < 3; i ++){
			a1[stol[i].suit] ++;
			a2[stol[i].value] ++;
		}
		a1[player[1].PlayerKarts[0].suit] ++;
		a1[player[1].PlayerKarts[1].suit] ++;
		a2[player[1].PlayerKarts[0].value] ++;
		a2[player[1].PlayerKarts[1].value] ++;
		for(int i = 0; i < 13; i++)
			if (a1[i] > max)
				max = a1[i];
		for(int i = 0; i < 4; i++)
			if (a2[i] > max1)
				max1 = a2[i];
		if(max == 2){
			a[3] = 60;
			a[1] = 40;
			return RandBet(a);
		}
		else if(max == 3 || max == 4 || max1 == 1){
			a[3] = 70;
			a[1] = 30;
			BetAi *= (rand() % 2 + 1);
			return RandBet(a);
		}
		else if(max == 2){
			a[3] = 20;
			a[1] = 80;
			return RandBet(a);
		}
		else
			return 2;
	}
	else if(KolKart == 4){
		int a1[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		int a2[4] = {0, 0, 0, 0};
		for(int i = 0; i < 4; i ++){
			a1[stol[i].suit] ++;
			a2[stol[i].value] ++;
		}
		a1[player[1].PlayerKarts[0].suit] ++;
		a1[player[1].PlayerKarts[1].suit] ++;
		a2[player[1].PlayerKarts[0].value] ++;
		a2[player[1].PlayerKarts[1].value] ++;
		for(int i = 0; i < 13; i++)
			if (a1[i] > max)
				max = a1[i];
		for(int i = 0; i < 4; i++)
			if (a2[i] > max1)
				max1 = a2[i];
		if(max == 2){
			a[3] = 60;
			a[1] = 40;
			return RandBet(a);
		}
		else if(max == 3 || max == 4 || max1 == 1){
			a[3] = 70;
			a[1] = 30;
			return RandBet(a);
		}
		else if(max == 2){
			a[3] = 20;
			a[1] = 80;
			return RandBet(a);
		}
		else
			return 2;
	}
	else if(KolKart == 5){
		bestHand(player, turn, stol);
		if (player[1].best_hand.points == 0)
			return 2;
		else if(player[1].best_hand.points >= 4){
			a[4] = 70;
			a[3] = 30;
			return RandBet(a);
		}
		else if(player[1].best_hand.points <= 3 && player[1].best_hand.points >= 2){
			a[3] = 80;
			a[1] = 20;
			BetAi *= (rand() % 2 + 1);
			return RandBet(a);
		}
		else if(player[1].best_hand.points == 1){
			a[3] = 40;
			a[1] = 60;
			BetAi *= (rand() % 1 + 1);
			return RandBet(a);
		}
	}
	else
		return 2;
}


int add(person player[2], int koloda[4][13], karts stol[5], int KolKart, int& BetAi){
	int a[5] = {0, 0, 0, 0, 0};
	int a1[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int a2[4] = {0, 0, 0, 0};
	int turn = 1, max = 0, max1 = 0;
	BetAi = player[0].bet + ((rand() % 200 + 100) / 100 * 100);
	if(KolKart == 0){
		if(player[1].PlayerKarts[0].suit + player[1].PlayerKarts[1].suit >= 16){
			if(player[1].PlayerKarts[0].suit == player[1].PlayerKarts[1].suit){
				a[4] += 60;
				a[3] += 40;
				a[2] += 20;
				return RandBet(a);
			}
			else{
				a[3] += 45;
				a[2] += 55;
				return RandBet(a);
			}
		}
		else if(player[1].PlayerKarts[0].suit == player[1].PlayerKarts[1].suit){
			a[3] = 40;
			a[2] = 60;
			return RandBet(a);
		}
		else if(player[1].PlayerKarts[0].suit + player[1].PlayerKarts[1].suit < 6 && player[1].PlayerKarts[0].suit != player[1].PlayerKarts[1].suit && player[1].PlayerKarts[0].value != player[1].PlayerKarts[1].value){
			a[0] = 70;
			a[2] = 30;
			return RandBet(a);
		}
		else if(player[1].PlayerKarts[0].suit + player[1].PlayerKarts[1].suit < 16 &&  player[1].PlayerKarts[0].suit + player[1].PlayerKarts[1].suit > 8){
			a[3] = 30;
			a[2] = 30;
			a[0] = 40;
			return RandBet(a);
		}
		else 
			return 3;
	}
	else if(KolKart == 3){
		for(int i = 0; i < 3; i ++){
			a1[stol[i].suit] ++;
			a2[stol[i].value] ++;
		}
		a1[player[1].PlayerKarts[0].suit] ++;
		a1[player[1].PlayerKarts[1].suit] ++;
		a2[player[1].PlayerKarts[0].value] ++;
		a2[player[1].PlayerKarts[1].value] ++;
		for(int i = 0; i < 13; i++)
			if (a1[i] > max)
				max = a1[i];
		for(int i = 0; i < 4; i++)
			if (a2[i] > max1)
				max1 = a2[i];
		if(max == 2){
			a[3] = 30;
			a[2] = 70;
			return RandBet(a);
		}
		else if(max == 3 || max == 4 || max1 == 1){
			a[3] = 50;
			a[2] = 50;
			BetAi *= 3;
			return RandBet(a);
		}
		else if(max1 == 2){
			a[3] = 10;
			a[2] = 45;
			a[0] = 45;
			BetAi *= (rand() % 2 + 1);
			return RandBet(a);
		}
		else
			return 3;
	}
	else if(KolKart == 4){
		int a1[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		int a2[4] = {0, 0, 0, 0};
		for(int i = 0; i < 4; i ++){
			a1[stol[i].suit] ++;
			a2[stol[i].value] ++;
		}
		a1[player[1].PlayerKarts[0].suit] ++;
		a1[player[1].PlayerKarts[1].suit] ++;
		a2[player[1].PlayerKarts[0].value] ++;
		a2[player[1].PlayerKarts[1].value] ++;
		for(int i = 0; i < 13; i++)
			if (a1[i] > max)
				max = a1[i];
		for(int i = 0; i < 4; i++)
			if (a2[i] > max1)
				max1 = a2[i];
		if(max == 2){
			a[3] = 60;
			a[2] = 40;
			return RandBet(a);
		}
		else if(max == 3 || max1 == 4 || max1 == 3){
			a[3] = 70;
			a[2] = 30;
			return RandBet(a);
		}
		else if(max1 == 1){
			a[3] = 10;
			a[2] = 30;
			a[0] = 60;
			return RandBet(a);
		}
		else
			return 3;
	}
	else if(KolKart == 5){
		bestHand(player, turn, stol);
		if (player[1].best_hand.points == 0)
			return 2;
		else if(player[1].best_hand.points >= 4){
			a[4] = 70;
			a[3] = 30;
			return RandBet(a);
		}
		else if(player[1].best_hand.points < 4 && player[1].best_hand.points >= 2) {
			a[3] = 50;
			a[2] = 40;
			a[0] = 10;
			return RandBet(a);
		}
	}
	else
		return 3;
}


int ArtificialIntelligence(person player[2], int koloda[4][13], karts stol[5], int KolKart, int& BetAi){
	switch (player[0].type)
	{
		case(1):
			break;
		case(2):
			return check(player, koloda, stol, KolKart, BetAi);
			break;
		case(3):
			break;
		case(4):
			return add(player, koloda, stol, KolKart, BetAi);;
			break;
		case(5):
			break;
	}
}
