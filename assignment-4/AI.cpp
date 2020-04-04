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

		if(head->min_max_mode==0)
		{
			temp->min_max_mode=1;
		}
		else
		{
			temp->min_max_mode=0;
		}

		temp->utility = -100;

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

		if(head->min_max_mode == 0)
		{
			temp1->min_max_mode = 1;
		}
		else
		{
			temp1->min_max_mode = 0;
		}

		temp1->utility = -100;
		
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

		if(head->min_max_mode == 0)
		{
			temp2->min_max_mode = 1;
		}
		else
		{
			temp2->min_max_mode = 0;
		}

		temp2->utility = -100;

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
	head->utility = -100;

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
	cout<<"utility: "<<head->utility<<"\n";
	cout<<"Min Max Mode: "<<head->min_max_mode<<"\n\n";
}

void cleanup(node* head)
{
	if(head->one!=NULL)
	{
		if(head->one->arena.remaining_sticks==0)
		{
			free(head->one);
			head->one=NULL;
		}

		if(head->one!=NULL)
		{
			cleanup(head->one);
		}
	}

	if(head->two !=NULL)
	{
		if(head->two->arena.remaining_sticks == 0)
		{
			free(head->two);
			head->two = NULL;
		}

		if(head->two != NULL)
		{
			cleanup(head->two);
		}
	}

	if(head->three!=NULL)
	{
		if(head->three->arena.remaining_sticks == 0)
		{
			free(head->three);
			head->three = NULL;
		}

		if(head->three!=NULL)
		{
			cleanup(head->three);
		}
	}
}

void assign_leaf_utility(node* head)
{
	if(head->one!=NULL)
	{
		assign_leaf_utility(head->one);
	}

	if(head->two!=NULL)
	{
		assign_leaf_utility(head->two);
	}

	if(head->three!=NULL)
	{
		assign_leaf_utility(head->three);
	}

	if((head->arena.remaining_sticks == 1) && head->min_max_mode == 1)
	{
		head->utility = 1;
	}

	if((head->arena.remaining_sticks == 1) && head->min_max_mode == 0)
	{
		head->utility = -1;
	}
}


void evaluate_game_tree(node* head)
{
	if(head->one!=NULL)
	{
		evaluate_game_tree(head->one);
	}

	if(head->two!=NULL)
	{
		evaluate_game_tree(head->two);
	}

	if(head->three!=NULL)
	{
		evaluate_game_tree(head->three);
	}

	if(head->arena.remaining_sticks!=1)
	{
		if(head->min_max_mode == 0)
		{
			if(head->one!=NULL)
			{
				if(head->utility < head->one->utility)
				{
					head->utility = head->one->utility;
				}
			}

			if(head->two!=NULL)
			{
				if(head->utility < head->two->utility)
				{
					head->utility = head->two->utility;
				}
			}

			if(head->three!=NULL)
			{
				if(head->utility < head->three->utility)
				{
					head->utility = head->three->utility;
				}
			}
		}

		if(head->min_max_mode == 1)
		{
			if(head->one!=NULL)
			{
				if((head->utility > head->one->utility) || head->utility == -100)
				{
					head->utility = head->one->utility;
				}
			}

			if(head->two!=NULL)
			{
				if((head->utility > head->two->utility) || head->utility == -100)
				{
					head->utility = head->two->utility;
				}
			}

			if(head->three!=NULL)
			{
				if((head->utility > head->three->utility) || head->utility == -100)
				{
					head->utility = head->three->utility;
				}
			}
		}
	}
}

int sticks_to_be_removed(node* head)
{ 
	if(head->one!=NULL)
	{
		if(head->utility == head->one->utility)
		{
			return 1;
		}
	}

	if(head->two!=NULL)
	{
		if(head->utility == head->two->utility)
		{
			return 2;
		}
	}

	if(head->three!=NULL)
	{
		if(head->utility == head->three->utility)
		{
			return 3;
		}
	}
}

void evaluate_utility(node* head)
{
	cleanup(head);

	assign_leaf_utility(head);

	evaluate_game_tree(head);
}



void AI(game* platform)
{
	node* game_tree;

	game_tree = create_game_tree(platform);

	//display_game_tree(game_tree);

	evaluate_utility(game_tree);

	//display_game_tree(game_tree);

	int remove_sticks = sticks_to_be_removed(game_tree);

	cout<<"Number of sticks removed by AI: "<<remove_sticks<<"\n";

	platform->remaining_sticks -= remove_sticks;
}