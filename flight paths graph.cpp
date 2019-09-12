#include<iostream>
using namespace std;

class node
{
	string cityname;
	int distance;
	node *next;
public:
	node(string c,int d)
	{
		cityname=c;
		distance=d;
		next=NULL;
	}
	friend class flight;
};
class flight
{
	node* head[20];
	int nc;
	char dir;
public:
	flight()
	{
		nc=0;
		cout<<"Is the graph directed ?[y/n]";
		cin>>dir;
		for(int i=0;i<20;i++)
		{
			node *p = new node("x",0);
			head[i]=p;
			p->next=NULL;
		}
	}
	void addcity();
	void deletecity();
	void addflight();
	void deleteflight();
	void display();
	void degree();
	void indegree();
	void outdegree();
};
void flight::addcity()
{
	string city;
	cout<<"Enter the city name to be added:  ";
	cin>>ws;
	getline(cin,city);
	int i=0;
	while(head[i]->cityname!="x")
	{
		if(head[i]->cityname==city)
		{
			cout<<"City already exists\n";
			return;
		}
		i++;
	}
	head[i]->cityname=city;
	nc++;
}
void flight::deletecity()
{
	string d;
	cout<<"Enter the city to be deleted:  ";
	cin>>ws;
	getline(cin,d);
	int i=0,j;
	while(head[i]->cityname!=d)
	{
		i++;
	}
	node *p=new node("x",0);
	head[i]=p;

	for(j=i;j<nc-1;j++)
	{
		head[j]=head[j+1];
	}
	head[j]=p;
	nc--;

	i=0;
	while(i<nc)
	{
		node *q=head[i];
		while(q->next!=NULL)
		{
			if(q->next->cityname==d)
			{
				break;
			}
			q=q->next;
		}
		node *p=q->next;
		q->next=q->next->next;
		delete p;
		i++;
	}


}
void flight::addflight()
{
	string s,d;
	int dist;
	cout<<"Enter the source node:  ";
	cin>>ws;
	getline(cin,s);
	cout<<"Enter the destination node:  ";
	cin>>ws;
	getline(cin,d);
	cout<<"Enter the distance between the 2 nodes:  ";
	cin>>dist;

	int i=0;
	while(head[i]->cityname!=s)
	{
		i++;
	}
	if(head[i]->next==NULL)
	{
		head[i]->next=new node(d,dist);
	}
	else
	{
		node *p=head[i]->next;
		while(p->next !=NULL)
		{
			p=p->next;
		}
		p->next=new node(d,dist);
	}

	if(dir!='y' && dir!='Y')
	{
		int i=0;
		while(head[i]->cityname!=d)
		{
			i++;
		}
		if(head[i]->next==NULL)
		{
			head[i]->next=new node(s,dist);
		}
		else
		{
			node *p=head[i]->next;
			while(p->next !=NULL)
			{
				p=p->next;
			}
			p->next=new node(s,dist);
		}

	}
}
void flight::deleteflight()
{
	string s,d;
	cout<<"Enter the source node:  ";
	cin>>ws;
	getline(cin,s);
	cout<<"Enter the destination node:  ";
	cin>>ws;
	getline(cin,d);

	int i=0;
	while(head[i]->cityname!=s)
	{
		i++;
	}
	node *q=head[i];
	while(q->next!=NULL)
	{
		if(q->next->cityname==d)
		{
			break;
		}
		q=q->next;
	}
	node *p=q->next;
	q->next=q->next->next;
	delete p;

	if(dir!='y' && dir!='Y')
	{
		int i=0;
		while(head[i]->cityname!=d)
		{
			i++;
		}
		node *q=head[i];
		while(q->next!=NULL)
		{
			if(q->next->cityname==s)
			{
				break;
			}
			q=q->next;
		}
		q->next=q->next->next;
		delete q->next;
	}
}
void flight::display()
{
	for(int i=0;i<nc;i++)
	{
		cout<<head[i]->cityname<<" ==>> ";
		node *p=head[i];
		while(p!=NULL)
		{
			if(p->next!=NULL)
			{
				cout<<p->cityname<<" -> ";
			}
			else
			{
				cout<<p->cityname;
			}
			p=p->next;
		}
		cout<<"\n";
	}
}
void flight::degree()
{
	if(dir=='y' || dir=='Y')
	{
		indegree();
		outdegree();
	}
	else
	{
		int deg;
		node *p;
		for(int i=0;i<nc;i++)
		{
			p=head[i];
			deg=0;
			while(p!=NULL)
			{
				deg++;
				p=p->next;
			}
			cout<<"Degree of "<<head[i]->cityname<<" vertex is "<<deg-1<<"\n";
		}
	}
}
void flight::indegree()
{
	int deg;
	for(int i=0;i<nc;i++)
	{

		deg=0;
		for(int j=0;j<nc;j++)
		{
			node *p=head[j];
			while(p!=NULL)
			{
				if(p->cityname==head[i]->cityname)
				{
					deg++;
				}
				p=p->next;
			}
		}
		cout<<"Indegree of "<<head[i]->cityname<<" vertex is "<<deg-1<<"\n";
	}
}
void flight::outdegree()
{
	int deg;
	node *p;
	for(int i=0;i<nc;i++)
	{
		p=head[i];
		deg=0;
		while(p!=NULL)
		{
			deg++;
			p=p->next;
		}
		cout<<"Outdegree of "<<head[i]->cityname<<" vertex is "<<deg-1<<"\n";
	}
}





int main()
{
	flight f;
	int choice;
	do
	{
		cout<<"\n1.Add city\n2.Add Flight\n3.Display\n4.Degree\n5.Delete flight\n6.Delete city\n";
		cout<<"Enter your choice:  ";
		cin>>choice;
		switch(choice)
		{
			case 1:f.addcity();
				break;
			case 2:f.addflight();
				break;
			case 3:f.display();
				break;
			case 4:f.degree();
				break;
			case 5:f.deleteflight();
				break;
			case 6:f.deletecity();
				break;
		}
	}while(choice!=0);
}
