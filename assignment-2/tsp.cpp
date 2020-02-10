#include <bits/stdc++.h>

using namespace std;

//int number_of_nodes=0;

struct state{

	int starting_node;

	int cost;

	int heursitic_cost;

	vector <int> node_list;

	//int num_nodes;

	struct state* children;

};

typedef struct state state;

state* open_list;

state* closed_list;

void calc_heurisitics(state* s,vector <vector <int> > &ct,int no)
{
	if(s->node_list.size()>=1)
	{
		int start=s->starting_node;

		int num=no;

		int a[num];

		a[0]=1;

		for(int i=1;i<num;i++)
		{
			a[i]=0;
		}

		for(int i=0;i<s->node_list.size();i++)
		{
			a[s->node_list[i]]=1;
		}

		int curr_node=s->node_list[s->node_list.size()-1];

		if(curr_node==s->starting_node)
		{
			return ;
		}

		vector <vector <int> > b;

		while(1)
		{
			int count=0;
			int remain=no-s->node_list.size();

			for(int i=0;i<num;i++)
			{
				if(a[i]!=1)
				{
					count++;

					b.resize(count);

					b[count-1].push_back(ct[curr_node][i]);
					b[count-1].push_back(i);
				}
			}

			sort(b.begin(),b.end());

			s->heursitic_cost +=b[0][0];

			a[b[0][1]]=1;

			remain--;

			if(remain==0)
			{
				s->heursitic_cost +=ct[curr_node][0];

				break;
			}	

			curr_node=b[0][1];
		}

	}


}

state* state_init(vector <vector <int> > &ct,int no,int node)
{
	state* start=NULL;

	start=(state*) malloc(sizeof(state));

	start->starting_node=node;

	start->cost=0;

	start->node_list.push_back(node);

	calc_heurisitics(start,ct,no);

	start->children=NULL;

	return start;

}



int main()
{
	int number_nodes;

	cout<<"Enter the number of nodes\n";

	cin>>number_nodes;

	//number_of_nodes=number_nodes;

	vector <vector <int> > cost_table;

	cost_table.resize(number_nodes);

	for(int i=0;i<number_nodes;i++)
	{
		cost_table[i].resize(number_nodes);
	}

	cout<<"Enter the cost of each path between the tables with starting state being marked with number 0\nSelf distance will be assigned -1\n";

	for(int i=0;i<number_nodes;i++)
	{
		for(int j=0;j<number_nodes;j++)
		{
			cin>>cost_table[i][j];
		}
	}

	cout<<"\n";

	for(int i=0;i<number_nodes;i++)
	{
		for(int j=0;j<number_nodes;j++)
		{
			cout<<cost_table[i][j]<<" ";
		}
		cout<<"\n";
	}

	state* start=state_init(cost_table,number_nodes,0);

	cout<<start->heursitic_cost<<"\n";

	return 0;
}

		
