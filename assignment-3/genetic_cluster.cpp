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


void fitness_function(population* populi,int n,int m,int k,vector <vector <int> > arr)
{
	populi->fitness_value.resize(populi->population_size,0);

	for(int i=0;i<populi->population_size;i++)
	{
		for(int j=0;j<k;j++)
		{
			vector <int> temp;

			for(int l=0;l<n;l++)
			{
				if(populi->cluster_list[i][l]==j)
				{
					temp.push_back(l);
				}
			}

			int sum=0;

			for(int l=0;l<temp.size();l+=2)
			{
				int add=0;

				if(l<temp.size())
				{
					for(int t=0;t<m;t++)
					{
						add=add + (arr[temp[l+1]][t] -arr[temp[l]][t]);
					}

					sum=sum+add;
				}
				else
				{
					break;
				}
			}

			populi->fitness_value[i]=populi->fitness_value[i]+sum;
		}
	}
}


void show_fitness(population* populi)
{
	for(int i=0;i<populi->fitness_value.size();i++)
	{
		cout<<populi->fitness_value[i]<<" ";
	}

	cout<<"\n";
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

	vector <vector <int> > arr;

	arr.resize(n);

	for(int i=0;i<n;i++)
	{
		arr[i].resize(m);
	}

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

	fitness_function(&populi,n,m,k,arr);

	show_fitness(&populi);

	return 0;
}
