#include <bits/stdc++.h>
#include <time.h>
#include <unistd.h>
#include "game_structure.h"
#include "AI.h"
using namespace std;



int toss()
{
	srand(time(NULL));

	int l = rand() % 53;

	if(l%2 == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void call_player(int turn_number,game* platform)
{
	turn_number = turn_number % 2;

	switch(turn_number)
	{
		case 1: {

			
		}

		break;

		case 0: {

		} 
	}
}

int main()
{
	int toss_result;

	game platform;

	cout<<"Enter the total number of sticks: ";
	cin>>platform.total_stick_count;
	cout<<"\n";

	platform.remaining_sticks=platform.total_stick_count;

	cout<<"Player 1 is the AI\n";

	cout<<"Select the game mode:\n";

	cout<<"1. AI vs AI\n";
	cout<<"2. AI vs Human\n";

	cout<<"Enter the game mode: ";
	cin>>platform.game_mode;
	cout<<"\n";

	int temp;
	cout<<"TOSS....\n";
	if(platform.game_mode==2)
	{
		cout<<"HEADS or TAILS: Enter 0 for HEADS and 1 for TAILS: ";
		cin>>temp;
	}

	if(platform.game_mode==1)
	{
		srand(time(NULL));
		temp=rand() % 2;

		if(temp==0)
		{
			cout<<"Player 2 (AI) chooses HEAD\n";
		}
		else
		{
			cout<<"Player 2 (AI) chooses TAIL\n";
		}
	}

	cout<<"Flipping the coin.....\n";

	sleep(3);

	toss_result=toss();

	if(toss_result==0)
	{
		cout<<"It's HEADS\n";
		if(temp==0)
		{
			cout<<"You won the toss\nYou will play the first turn\n";
			platform.first_turn_taken_by=2;
		}
		else
		{
			cout<<"You lose the toss\nAI (Player 1) will play the first turn\n";
			platform.first_turn_taken_by=1;
		}
	}
	else
	{
		cout<<"It's TAILS\n";

		if(temp==1)
		{
			cout<<"You won the toss\nYou will play the first turn\n";
			platform.first_turn_taken_by=2;
		}
		else
		{
			cout<<"You lose the toss\nAI (Player 1) will play the first turn\n";
			platform.first_turn_taken_by=1;
		}
	}

	platform.turn_number=1;

	//while(platform.remaining_sticks!=0)
	{
		AI(&platform);
	}

	return 0;
}