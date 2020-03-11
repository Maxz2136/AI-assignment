#include <bits/stdc++.h>
using namespace std;

struct population
{
	int population_size;

	vector <vector <int> > cluster_list;

	vector <int> fitness_value;
};

typedef struct population population;

void initial_population(population* populi,int n,int m,int k,int size)
{
	srand(time(NULL));
	
	populi->population_size=size;

	populi->cluster_list.resize(populi->population_size);

	for(int i=0;i<populi->population_size;i++)
	{
		populi->cluster_list[i].resize(n);	
	}

	for(int i=0;i<populi->population_size;i++)
	{



		vector <int> check;

		check.resize(k,0);

		for(int j=0;j<n;j++)
		{
			

			populi->cluster_list[i][j]=rand() % k;

		}

		int count=0;

		for(int l=0;l<n;l++)
		{
			check[populi->cluster_list[i][l]]++;
		}

		for(int l=0;l<k;l++)
		{
			if(check[l]==0)
			{
				populi->cluster_list[i][count]=l;
				count++;
			}
		}

	}


}


void show_population(population* populi)
{
	for(int i=0;i<populi->population_size;i++)
	{
		for(int j=0;j<populi->cluster_list[i].size();j++)
		{
			cout<<populi->cluster_list[i][j]<<" ";
		}
		cout<<"\n";
	}
}



int main()
{

	int n,m,k;

	cout<<"Enter the number of students\n";

	cin>>n;

	cout<<"Enter the number of subjects\n";

	cin>>m;

	cout<<"Enter the number of groups you want to have\n";

	cin>>k;

	int arr[n][m];

	for(int i=0;i<n;i++)
	{
		cout<<"Enter the marks of "<<i+1<<"th student\n";

		for(int j=0;j<m;j++)
		{
			cin>>arr[i][j];
		}
	}

	population populi;

	initial_population(&populi,n,m,k,5);

	show_population(&populi);



	return 0;
}
