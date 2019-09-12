#include <iostream>
#include<string.h>
#include<iomanip>
using namespace std;
class Graph
{
public:
	int adjMatrix[10][10];
	int v;
	string city[10];

Graph()
{
	for(int i=0;i<10;i++)
	{
		city[i]=" ";
	}
	v=0;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
			adjMatrix[i][j]=0;
	}
}

void getCity()
{
	int i;
	cout<<"Enter the number of Cities: ";
	cin>>v;
	for(i=0;i<v;i++)
	{
		cout<<"\nEnter name of city: ";
		cin>>city[i];
	}
}

int getC(string s)
{
	int i;
	for(i=0;i<v;i++)
	{
		if(s==city[i])
		{
			break;
		}
	}
	return i;
}

bool search(string s)
{
	int i;
	for(i=0;i<v;i++)
	{
		if(s==city[i])
		{
			return true;
		}
	}
	return false;
}

void createAdj()
{
	char ch;
	string dest,src;
	int w,s,d;
	dest=src=" ";
	do{
		cout<<"\nEnter Source: ";
		cin>>src;
		cout<<"\nEnter Destination: ";
		cin>>dest;
		cout<<"\nEnter Cost: ";
		cin>>w;
		if(search(src)&&search(dest))
		{
			s=getC(src);
			d=getC(dest);
			adjMatrix[s][d]=w;
			adjMatrix[d][s]=w;
		}
		else
			cout<<"\nEnter correct city name!\n";

		cout<<"\nEnter Another? (y/n): ";
		cin>>ch;
	}while(ch=='y');
}

void display()
{
	int i,j;
	cout<<"\nAdjacent Matrix:\n";
	cout<<setw(10)<<" ";
	for(i=0;i<v;i++)
	{
		cout<<setw(10)<<city[i];
	}
	cout<<endl;
	for(i=0;i<v;i++)
	{
		cout<<setw(10)<<city[i];
		for(j=0;j<v;j++)
		{
			cout<<setw(10)<<adjMatrix[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
}

/*int Graph:: vsize(int a[])
{
	int count;
	count=0;
	for(int i=0;i<v;i++)
	{
		if(a[i]==1)
			count++;
	}
	return count;
}


int Graph:: unvsize(int a[])
{
	int count;
	count=0;
	for(int i=0;i<v;i++)
	{
		if(a[i]==0)
			count++;
	}
	return count;
}*/

void prims()
{
	int visit[v],reach[v],m[v][v];
			int wt=0, count=1, rc=0, t1, t2, temp, min;
			int res[v][v];

			for(int i=0;i<v;i++){
				for(int j=0;j<v;j++){
					res[i][j]=0;
					m[i][j]=adjMatrix[i][j];
				}
				reach[i] = 0;
				visit[i] = 0;
			}
			reach[0]=0;
			visit[0] = 1;
			rc++;

			while(count<v){
				//find min
			min =9999;
			for(int i=0;i<rc;i++)
			{

				temp = reach[i];

				for(int j=0;j<v;j++)
				{
					if(min>m[temp][j] && m[temp][j]!=0)
					{
						min = m[temp][j];
						t1=temp; t2=j;
					}
				}
			}
			//remove edge
			temp = m[t1][t2];
			m[t1][t2] = 0;
			m[t2][t1] = 0;
			if(visit[t2]!=1 ){  //if no cycle add edge to res
				res[t1][t2] = temp;
				res[t2][t1] = temp;
				wt = wt + temp;		//add wt
				visit[t2] = 1;
				reach[rc] = t2;
				count++; rc++;
			}

			}

			cout<<"weight of min spanning tree is:  "<<wt<<endl;
			//display();
			//display resultant mat
			int i,j;
			cout<<"\nAdjacent Matrix:\n";
			cout<<setw(10)<<" ";
			for(i=0;i<v;i++)
			{
				cout<<setw(10)<<city[i];
			}
			cout<<endl;
			for(i=0;i<v;i++)
			{
				cout<<setw(10)<<city[i];
				for(j=0;j<v;j++)
				{
					cout<<setw(10)<<res[i][j];
				}
				cout<<endl;
			}
			cout<<endl;
			/*cout<<"\t";
			for(int i=0;i<v;i++)
				cout<<i<<"\t";
			cout<<endl;
			for(int i=0;i<v;i++)
			{
				cout<<i<<"\t";
				for(int j=0;j<v;j++)
				{
					cout<<res[i][j]<<"\t";
				}
				cout<<endl;
			}*/
}




void kruskals()
{
	int visit[v],reach[v];
	int wt=0, count=1, rc=0, t1, t2, temp, min;
	int k=0,a[v-1],b[v-1],m[v][v];
	int res[v][v];

	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			res[i][j]=0;
			m[i][j]=adjMatrix[i][j];
		}
		reach[i] = 0;
		visit[i] = 0;
	}
	reach[0]=0;
	visit[0] = 1;
	rc++;

	while(count<v)
	{
		min =9999;
		for(int i=0;i<v;i++)
		{
			for(int j=i;j<v;j++)
			{
				if(min>m[i][j] && m[i][j]!=0)
				{
					min = m[i][j];
					t1=i; t2=j;
				}
			}
		}
					//remove edge
		temp = m[t1][t2];
		m[t1][t2] = 0;
		m[t2][t1] = 0;
		if(visit[t2]!=1 || visit[t1]!=1)
		{  //if no cycle add edge to res
			res[t1][t2] = temp;
			res[t2][t1] = temp;
			wt = wt + temp;		//add wt
			visit[t2] = 1;
			reach[rc] = t2;
			count++; rc++;
		}

	}

	cout<<"Weight of minimum spanning tree is:  "<<wt<<endl;
					//display();
					//display resultant mat
	int i,j;
	cout<<"\nAdjacent Matrix:\n";
	cout<<setw(10)<<" ";
	for(i=0;i<v;i++)
	{
		cout<<setw(10)<<city[i];
	}
	cout<<endl;
	for(i=0;i<v;i++)
	{
		cout<<setw(10)<<city[i];
		for(j=0;j<v;j++)
		{
			cout<<setw(10)<<res[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
					/*cout<<"\t";
					for(int i=0;i<v;i++)
						cout<<i<<"\t";
					cout<<endl;
					for(int i=0;i<v;i++)
					{
						cout<<i<<"\t";
						for(int j=0;j<v;j++)
						{
							cout<<res[i][j]<<"\t";
						}
						cout<<endl;
					}*/
}

};
int main()
{
	int choice;
	Graph g;
	do{
	cout<<"\n\nMenu\n\n1.Enter Cities\n\n2.Enter Paths\n\n3.Display Adjacency Matrix\n\n4.Prims\n\n5.Kruskals\n\n0.Exit\n\nOption: ";
	cin>>choice;
		switch(choice)
		{
			case 1:
				g.getCity();
				break;

			case 2:
				g.createAdj();
				break;

			case 3:
				g.display();
				break;
			case 4:
				g.prims();
				break;
			case 5:
				g.kruskals();
				break;

			case 0:
				break;
		}
		}while(choice!=0);
	return 0;
}
