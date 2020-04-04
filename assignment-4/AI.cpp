#include "game_structure.h"
#include <bits/stdc++.h>
#include "AI.h"
using namespace std;	

struct node{
	game arena;
	node* one;
	node* two;
	node* three;
	int min_max_mode;  //0 for maximzer and 1 for minimizer.
	int utility;
};

typedef struct node node;

node* dfs(node* head)
{
	

	if(head->arena.remaining_sticks >= 1)
	{
		node* temp;

		temp = (node*) malloc(sizeof(node));

		temp->arena = head->arena;

		temp->one =NULL;
		temp->two = NULL;
		temp->three = NULL;

		head->one = temp;

		temp->arena.remaining_sticks--;

		head->one = dfs(head->one);
	}

	if(head->arena.remaining_sticks >= 2)
	{
		node* temp1;
		temp1 = (node*) malloc(sizeof(node));

		temp1->one = NULL;
		temp1->two = NULL;
		temp1->three = NULL;

		temp1->arena = head->arena;

		head->two = temp1;
		
		temp1->arena.remaining_sticks -= 2;

		head->two = dfs(head->two);
	}

	if(head->arena.remaining_sticks >= 3)
	{
		node* temp2;
		temp2 = (node*) malloc(sizeof(node));

		temp2->one = NULL;
		temp2->two = NULL;
		temp2->three = NULL;

		temp2->arena = head->arena;

		head->three = temp2;

		temp2->arena.remaining_sticks -= 3;

		head->three = dfs(head->three);
	}

	return head;
}


node* create_game_tree(game* platform)
{
	node* head;

	head = (node*) malloc(sizeof(node));

	head->arena = *(platform);

	head->min_max_mode=0;

	head->one=NULL;
	head->two=NULL;
	head->three=NULL;

	head = dfs(head);

	return head;
}

void display_game_state(game* arena)
{
	//cout<<"total sticks count: "<<arena->total_stick_count<<"\n";
	cout<<"Remaining Sticks: "<<arena->remaining_sticks<<"\n";
	//cout<<"Turn number: "<<arena->turn_number<<"\n";
}

void display_game_tree(node* head)
{
	if(head->one!=NULL)
	{
		display_game_tree(head->one);
	}

	if(head->two != NULL)
	{
		display_game_tree(head->two);
	}

	if(head->three != NULL)
	{
		display_game_tree(head->three);
	}

	display_game_state(&(head->arena));
}

void AI(game* platform)
{
	node* game_tree;

	game_tree = create_game_tree(platform);

	display_game_tree(game_tree);
}