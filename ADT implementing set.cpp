#include <iostream>
using namespace std;
class Node
{
	int ele;
	Node *next;
public:
	Node(int e)
	{
		ele=e;
		next=NULL;
	}
	friend class Set;
};

class Set
{
	Node *head;
	int size;
public:
	Set()
	{
		head=NULL;
		size=0;
	}
	void insert(int ele)
	{
		if(search(ele)==0)
		{
		Node *t;
		Node *temp=new Node(ele);
		if(head==NULL)
			head=temp;
		else
		{
			t=head;
			while(t->next!=NULL)
			{
				t=t->next;
			}
			t->next=temp;
		}
			size++;
		}
	}

	int search(int ele)
	{
		Node *t=head;
		while(t!=NULL)
		{
			if(t->ele==ele)
				return 1;
			t=t->next;
		}
		return 0;
	}

	void display()
	{
		Node *t=head;
		cout<<"{";
		while(t!=NULL)
		{
			cout<<t->ele<<",";
			t=t->next;
		}
		cout<<"}"<<endl;
	}

	void remove(int ele)
	{
		Node *t=head;
		if(search(ele)==1)
		{
			while(t!=NULL && t->ele!=ele)
			{
				if(t->next->ele==ele)
				{
					t->next=t->next->next;
				}
				t=t->next;
			}
			size--;
		}
		else
			cout<<"Element not present!"<<endl;
	}

	int getSize()
	{
		return size;
	}

	void intersection( Set &b)
	{
		Set c;
		Node *t=head;
		while(t!=NULL)
		{
			if(b.search(t->ele)==1)
			{
				c.insert(t->ele);
			}
			t=t->next;
		}
		cout<<"Intersection of sets : ";
		c.display();
	}

	void create()
	{
	    int ele;
		char ch;
		do
		{
			cout<<"Enter set element."<<endl;
			cin>>ele;
			insert(ele);
			cout<<"Do Another?(y/n)"<<endl;
			cin>>ch;
		}while(ch=='y');
	}

	void unionSet(Set &b)
	{
		Set c;
		Node *t1=head,*t2=b.head;
		while(t1!=NULL && t2!=NULL)
		{
			if(t1->ele < t2->ele)
			{
				c.insert(t1->ele);
				t1=t1->next;
			}
			else
			if(t2->ele < t1->ele)
			{
				c.insert(t2->ele);
				t2=t2->next;
			}
			else
			{
				c.insert(t2->ele);
				t1=t1->next;
				t2=t2->next;
			}
		}
		while(t1!=NULL)
		{
			c.insert(t1->ele);
			t1=t1->next;
		}
		while(t2!=NULL)
		{
			c.insert(t2->ele);
			t2=t2->next;
		}
		cout<<"Union of sets : ";
		c.display();
	}

	void diff(Set &b)
	{
		Set c;
		Node *t=head;
		while(t!=NULL)
		{
			if(b.search(t->ele)!=1)
			{
				c.insert(t->ele);
			}
			t=t->next;
		}
		cout<<"Difference of sets a-b :";
		c.display();
	}

	void subset(Set &b)
	{
		Node *t=b.head;
		int flag=0;
		while(t!=NULL)
		{
			if(search(t->ele)!=1)
			{
				cout<<"b is not subset of a"<<endl;
				flag=1;
				break;
			}
			t=t->next;
		}

		if(flag!=1)
		cout<<"b is subset of a"<<endl;
	}
};
int main()
{
	Set a,b;
	int s;
	a.create();
	cout<<"Set a : ";
	a.display();
	int ele,ch;
	do
	{
		cout<<"1.Insert element"<<endl;
		cout<<"2.Remove element"<<endl;
		cout<<"3.Search element"<<endl;
		cout<<"4.Size of set"<<endl;
		cout<<"5.Intersection of sets"<<endl;
		cout<<"6.Union of sets"<<endl;
		cout<<"7.Difference of sets"<<endl;
		cout<<"8.Subset of set"<<endl;
		cout<<"9.Exit"<<endl;
		cout<<"Enter choice:"<<endl;
		cin>>ch;

		switch(ch)
		{
		case 1:	cout<<"Enter set element."<<endl;
				cin>>ele;
				a.insert(ele);
				cout<<"Set a : ";
				a.display();
				break;

		case 2: cout<<"Enter element to remove"<<endl;
				cin>>ele;
				a.remove(ele);
				cout<<"Set a : ";
				a.display();
				break;

		case 3: cout<<"Enter element of search"<<endl;
				cin>>ele;
				if(a.search(ele)==1)
					cout<<"Element present"<<endl;
				else
					cout<<"Element not present."<<endl;
				break;

		case 4: cout<<"Size of set : ";
				s=a.getSize();
				cout<<s<<endl;
				break;

		case 5:	{
				Set b;
				cout<<"Enter elements for set b"<<endl;
				b.create();
				cout<<"Set b : ";
				b.display();
				cout<<"Set a : ";
				a.display();
				a.intersection(b);
				}
				break;

		case 6: {
				Set b;
				cout<<"Enter elements for set b"<<endl;
				b.create();
				cout<<"Set b : ";
				b.display();
				cout<<"Set a : ";
				a.display();
				a.unionSet(b);
			}
				break;

		case 7:{
				Set b;
				cout<<"Enter elements for set b"<<endl;
				b.create();
				cout<<"Set b : ";
				b.display();
				cout<<"Set a : ";
				a.display();
				a.diff(b);
			}
				 break;

		case 8: {
				Set b;
				cout<<"Enter elements for set b"<<endl;
				b.create();
				cout<<"Set b : ";
				b.display();
				cout<<"Set a : ";
				a.display();
				a.subset(b);
			}
				break;

		case 9: break;

		default:cout<<"Wrong choice.Try again!"<<endl;
		}
	}while(ch!=9);
	return 0;
}
