#include <bits/stdc++.h>
using namespace std;

class node
{
	string name,attribute;
	int chain;
public:
	friend class hashtable;
};

class hashtable
{
	node bucket[10];
	int flag[10];
	char rep;
public:
	hashtable()
	{
		cout<<"Enter y for replacement and n for non-replacement:  ";
		cin>>rep;
		for(int i=0;i<10;i++)
		{
			bucket[i].name=bucket[i].attribute="";
			flag[i]=0;
			bucket[i].chain=-1;
		}
	}
	int hashfunction(string);
	void addname();
	void deletename();
	void searchname();
	void modifyattribute();
	void show();
};

int hashtable::hashfunction(string s)
{
	int x=0;
	for(int i=0;i<s.size();i++)
	{
		x=s[i]+(31*x);
	}
	x=x%10;
	return x;
}

void hashtable::addname()
{
	string s,a;
	cout<<"Enter the name to be added:  ";
	cin>>ws;
	getline(cin,s);
	cout<<"Enter the attribute of the name:  ";
	cin>>ws;
	getline(cin,a);
	int x=hashfunction(s);

	if(flag[x]==0)
	{
		bucket[x].name=s;
		bucket[x].attribute=a;
		flag[x]=1;
		return;
	}
	int i=(x+1)%10;
	while(flag[i]!=0 && i!=x)
	{
		i=(i+1)%10;
	}
	if(i==x)
	{
		cout<<"Table is full\n";
		return;
	}

	int t,j=0;
	if(hashfunction(bucket[x].name)==x)
	{
		bucket[i].name=s;
		bucket[i].attribute=a;
		flag[i]=1;

		t=x;
		while(bucket[t].chain!=-1)
		{
			t=bucket[t].chain;
		}
		bucket[t].chain=i;
	}
	else
	{
		if(rep=='y' || rep=='Y')
		{
			for(j=0;j<10;j++)
			{
				if(bucket[j].chain==x)
				{
					break;
				}
			}
			bucket[j].chain=i;
			bucket[i].name=bucket[x].name;
			bucket[i].attribute=bucket[x].attribute;
			bucket[i].chain=bucket[x].chain;
			flag[i]=1;

			bucket[x].name=s;
			bucket[x].attribute=a;
			bucket[x].chain=-1;

			return;
		}

		bucket[i].name=s;
		bucket[i].attribute=a;
		flag[i]=1;

		t=(x+1)%10;
		while(hashfunction(bucket[t].name)!=x)
		{
			t++;
		}
		while(bucket[t].chain!=-1)
		{
			t=bucket[t].chain;
		}
		if(i!=t)
		{
			bucket[t].chain=i;
		}

	}

}
void hashtable::deletename()
{
	string s;
	cout<<"Enter the name to be deleted:  ";
	cin>>ws;
	getline(cin,s);
	int x=hashfunction(s);
	if(bucket[x].name==s)
	{
		bucket[x].name="";
		bucket[x].attribute="";
		flag[x]=0;
		bucket[x].chain=-1;
		return;


	}
	int i=(x+1)%10;
	while(bucket[i].name!=s && i!=x)
	{
		i++;
	}
	int j=0;
	for(j=0;j<10;j++)
	{
		if(bucket[j].chain==i)
		{
			break;
		}
	}
	bucket[j].chain=bucket[i].chain;
	bucket[i].name="";
	bucket[i].attribute="";
	bucket[i].chain=-1;
	flag[i]=0;

}


void hashtable::show()
{
	for(int i=0;i<10;i++)
	{
		cout<<i<<" -> ";
		cout<<bucket[i].name<<"	"<<bucket[i].attribute<<"	"<<bucket[i].chain<<"	"<<flag[i]<<"\n";
	}
}



int main()
{
	hashtable h;
	int choice;
	while(1)
	{
		cout<<"\n1.Add name\n2.Delete name\n3.Search name\n4.Modify name\n5.Show\n";
		cout<<"Enter your choice:  ";
		cin>>choice;
		switch(choice)
		{
			case 1:h.addname();
				break;
			case 2:h.deletename();
				break;
			case 5:h.show();
				break;
		}
	}
}
