#include <bits/stdc++.h>
using namespace std;

class node
{
	string keyword,meaning;
public:
	friend class hashtable;
};

class hashtable
{

	node bucket[10];
	int flag[10];

public:
	hashtable()
	{
		for(int i=0;i<10;i++)
		{
			bucket[i].keyword=bucket[i].meaning="";
			flag[i]=0;

		}
	}

int hashfunction(string s)
{
	int p;//=0;
	//for(int i=0;i<s.size();i++)
	//{
		int x=s[0];//+(31*x);
	//}
	p=x%10;
	cout<<"hash="<<p<<endl;

	return p;
}

void inserthash()
{
	string s,m;
	cout<<"Enter the keyword:  ";
	cin>>s;

	cout<<"Enter the meaning of keyword:  ";
	cin>>m;

	int x=hashfunction(s);
	if(flag[x]==0)
	{
		bucket[x].keyword=s;
		bucket[x].meaning=m;
		flag[x]=1;
		return;
	}
	int i=(x+1)%10;

	while(flag[i]!=0 && x!=i)
	{
		i=(i+1)%10;

	}
	if(i==x)
	{
		cout<<"Array is full\n";
		return;
	}
	else
	{
		bucket[i].keyword=s;
		bucket[i].meaning=m;
		flag[i]=1;

	}

}
void insert()
{
	string s,m;
		cout<<"Enter the keyword:  ";
		cin>>s;

		cout<<"Enter the meaning of keyword:  ";
		cin>>m;

		int x=hashfunction(s);

			if(flag[x]==0)
			{
				bucket[x].keyword=s;
				bucket[x].meaning=m;
				flag[x]=1;
				return;
			}
			int i=(x+1)%10;

			while(flag[i]!=0 && x!=i)
			{
				i=(i+1)%10;
			}
			if(i==x)
			{
				cout<<"Array is full\n";
				return;
			}
			if(hashfunction(bucket[x].keyword)!=x)
			{
				bucket[i].keyword=bucket[x].keyword;
				bucket[i].meaning=bucket[x].meaning;
				flag[i]=1;

				bucket[x].keyword=s;
				bucket[x].meaning=m;
				flag[x]=1;

			}
			else
			{
				bucket[i].keyword=s;
				bucket[i].meaning=m;
				flag[i]=1;

			}
}
void delhash()
{
	string s;
	cout<<"Enter the keyword to be deleted:  ";
	cin>>s;

	int x=hashfunction(s);
	if(bucket[x].keyword==s)
	{
		bucket[x].keyword="";
		bucket[x].meaning="";
		flag[x]=0;
		return;
	}
	int i=(x+1)%10;
	while(bucket[i].keyword!=s && x!=i)
	{
		i=(i+1)%10;
	}
	bucket[i].keyword="";
	bucket[i].meaning="";
	flag[i]=0;

}

void showbucket()
{
	for(int i=0;i<10;i++)
	{
		cout<<i<<" -> ";
		cout<<bucket[i].keyword<<"	"<<bucket[i].meaning<<"	"<<endl;
	}
}

void search()
{
	string s;
	cout<<"Enter the keyword to be searched:  ";
	cin>>s;

	int x=hashfunction(s);
	if(bucket[x].keyword==s)
	{
		cout<<bucket[x].keyword<<"	"<<bucket[x].meaning<<"	"<<"\n";//flag[x]<<"\n";
		return;
	}
	int i=(x+1)%10;
	while(bucket[i].keyword!=s && x!=i)
	{
		i=(i+1)%10;
	}
	if(i==x)
	{
		cout<<"Keyword not found\n";
		return;
	}
	cout<<bucket[i].keyword<<"	"<<bucket[i].meaning<<"	"<<"\n";//<<flag[i]<<"\n";

}
void modify()
{
	string s;
		cout<<"Enter the keyword to be modified:  ";
		cin>>s;

		int x=hashfunction(s);
		if(bucket[x].keyword==s)
		{
			cout<<"enter the new meaning"<<endl;
			cin>>bucket[x].meaning;
			cout<<bucket[x].keyword<<"	"<<bucket[x].meaning<<"	"<<"\n";//flag[x]<<"\n";
			return;
		}
		int i=(x+1)%10;
		while(bucket[i].keyword!=s && x!=i)
		{
			i=(i+1)%10;
		}
		if(i==x)
		{
			cout<<"Keyword not found\n";
			return;
		}
		cout<<"enter the new meaning"<<endl;
        cin>>bucket[i].meaning;
		cout<<bucket[i].keyword<<"	"<<bucket[i].meaning<<"	 "<<"\n";//flag[i]<<"\n";
}
};
int main()
{
	hashtable ht;
	int choice,ch;
	cout<<"1.Without Replacement\n2.With Replacement"<<endl;
	cin>>ch;
	if(ch==1)
	{
		do
		{
			cout<<"\n1.Add Keyword\n2.Delete keyword\n3.Show Hash Array\n4.Search\n5.Modify\n0.Exit\n";
			cout<<"Enter your choice:  ";
			cin>>choice;
			switch(choice)
			{
				case 1:ht.inserthash();
					break;
				case 2:ht.delhash();
					break;
				case 3:ht.showbucket();
					break;
				case 4:ht.search();
					break;
				case 5:ht.modify();
					break;
			}
		}while(choice!=0);
	}
	else if(ch==2)
	{
		do
		{
			cout<<"\n1.Add Keyword\n2.Delete keyword\n3.Show Hash Array\n4.Search\n5.Modify\n0.Exit\n";
			cout<<"Enter your choice:  ";
			cin>>choice;
			switch(choice)
			{
				case 1:ht.insert();
					break;
				case 2:ht.delhash();
					break;
				case 3:ht.showbucket();
					break;
				case 4:ht.search();
					break;
					case 5:ht.modify();
					break;

			}
		}while(choice!=0);
	}
	return 0;
}
