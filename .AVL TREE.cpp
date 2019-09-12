#include <iostream>
#include<string.h>
using namespace std;
class Node
{
public:
	string keyword;
	string meaning;
	Node *left;
	Node *right;
	Node(string s1,string s2)
	{
		keyword=s1;
		meaning=s2;
		left=NULL;
		right=NULL;
	}
};
class AvlTree
{
	Node *root;
public:
	AvlTree()
	{
		root=NULL;
	}
	int balanceFactori(Node *t)
	{
		int hl=0,hr=0;
		if(t==NULL)
		{
			return 0;
		}
		if(t->left!=NULL)
		{
			hl=1+height(t->left);
		}
		if(t->right!=NULL)
		{
			hr=1+height(t->right);
		}
		if((hl-hr)<0)
			return (-1)*(hl-hr);
		return (hl-hr);
	}
	int height(Node *t)
	{
		int hl=0,hr=0;
		if(t==NULL)
		{
			return 0;
		}
		if(t->left==NULL&&t->right==NULL)
		{
			return 0;
		}
		if(t->left!=NULL)
		{
			hl=1+height(t->left);
		}
		if(t->right!=NULL)
		{
			hr=1+height(t->right);
		}
		if(hl<hr)
			return hr;
		return hl;
	}
	int balanceFactord(Node *t)
		{
			int hl=0,hr=0;
			if(t==NULL)
			{
				return 0;
			}
			if(t->left!=NULL)
			{
				hl=1+height(t->left);
			}
			if(t->right!=NULL)
			{
				hr=1+height(t->right);
			}
			return (hl-hr);
		}
	void create()
	{
		string temp1,temp2;
				cout<<" Enter keyword "<<endl;
				cin>>temp1;
				cout<<"Enter meaning of "<<temp1<<endl;
				cin>>temp2;
				root=insert(root,temp1,temp2);
				inorder(getroot());
	}
	Node *ll(Node *t)
	{
	    cout<<"LL rotation"<<endl;
		Node *y=t->left;
		t->left=y->right;
		y->right=t;
		return y;
	}
	Node *rr(Node *t)
	{
	    cout<<"RR rotation"<<endl;
		Node *y=t->right;
		t->right=y->left;
		y->left=t;
		return y;
	}
	Node *lr(Node *t)
	{
	    cout<<"LR rotation"<<endl;
		Node *y=t->left;
		Node *p=y->right;
		y->right=p->left;
		p->left=y;
		t->left=p;
		t=ll(t);
		return t;
	}
	Node *rl(Node *t)
	{
	    cout<<"RL rotation"<<endl;
		Node *y=t->right;
		Node *p=y->left;
		y->left=p->right;
		p->right=y;
		t->right=p;
		t=rr(t);
		return t;
	}

	Node *insert(Node *t,string s1,string s2)
	{
		if(t==NULL)
		{
			return new Node(s1,s2);
		}
		if(s1<t->keyword)
		{
			t->left=insert(t->left,s1,s2);
			if(balanceFactori(t)==2)
			{
				if(t->left->keyword>s1)
				{
					t=ll(t);
				}
				else
				{
					t=lr(t);
				}
			}
		}
		if(s1>t->keyword)
		{
			t->right=insert(t->right,s1,s2);
			if(balanceFactori(t)==2)
			{
				if(t->right->keyword>s1)
				{
					t=rl(t);
				}
				else
				{
					t=rr(t);
				}
			}
		}
		return t;
	}
	Node *getroot()
	{
		return root;
	}
	void inorder(Node *t)
	{
		if(t!=NULL)
		{
			inorder(t->left);
			//cout<<"Keyword = "<<t->keyword<<endl;
			//cout<<"Balance factor of "<<t->keyword<<" = "<<balanceFactord(t)<<endl;
			cout<<"Meaning of "<<t->keyword<<" = "<<t->meaning<<endl;
			inorder(t->right);
		}
	}
	void deleteNode()
	{
		string s;
		cout<<" Enter Keyword to be deleted "<<endl;
		cin>>s;
		root=deleteNode_rec(root,s);
	}
void search_keyword()
{
	int count=1;
	string s;
	cout<<"Enter the keyword to be searched:  ";
	cin>>s;
	Node *p=root;
	while(p!=NULL)
	{
		if(s < p->keyword)
		{
			p=p->left;
			count++;
		}
		else if(s > p->keyword)
		{
			p=p->right;
			count++;
		}
		else if(s == p->keyword)
		{
			cout<<"keyword found\n";
			cout<<p->keyword<<":	"<<p->meaning<<"\n";
			cout<<"Total no. of comparisons made:  "<<count<<endl;
			return;
		}

	}
	if(p==NULL)
	{
		cout<<"Keyword not found\n";
	}
}

	/*void compare()
	{
		string s;
		cout<<"Enter keyword "<<endl;
		cin>>s;
		Node *p=searchNode(root,s);
		int x=height(p);
		cout<<" Number of comparison = "<<x<<endl;
	}*/
	void update_keyword()
{
	string s,m;
	cout<<"Enter the keyword to be updated:  ";
	cin>>s;
	Node *p=root;
	while(p!=NULL)
	{
		if(s < p->keyword)
		{
			p=p->left;
		}
		else if(s > p->keyword)
		{
			p=p->right;
		}
		else if(s == p->keyword)
		{
			cout<<"Enter the meaning of the keyword:  ";
			cin>>ws;
			getline(cin,m);
			p->meaning=m;
			cout<<"Keyword updated\n";
			cout<<p->keyword<<":	"<<p->meaning<<"\n";
			break;
		}
	}
	if(p==NULL)
	{
		cout<<"Keyword doesn't exist\n";
	}

}
	Node *deleteNode_rec(Node *t,string s)
	{
		Node *p;
		if(t==NULL)
		{
			return NULL;
		}
		if(t->keyword>s)
		{
			t->left=deleteNode_rec(t->left,s);
			if(balanceFactord(t)==-2)
			{
				if(balanceFactord(t->right)<=0)
				{
					t=rr(t);
				}
				else
				{
					t=rl(t);
				}
			}
		}
		if(t->keyword<s)
		{
			t->right=deleteNode_rec(t->right,s);
			if(balanceFactord(t)==2)
			{
				if(balanceFactord(t->left)>=0)
				{
					t=ll(t);
				}
				else
				{
					t=lr(t);
				}
			}
		}
		if(t->keyword==s)
		{
			if(t->left==NULL&&t->right==NULL)
			{
				delete t;
				t=NULL;
				return t;
			}
			if(t->left!=NULL&&t->right==NULL)
			{
				p=t->left;
				delete t;
				return p;
			}
			if(t->right!=NULL&&t->left==NULL)
			{
				p=t->right;
				delete t;
				return p;
			}
			else
			{
				p=t->right;
				while(p->left!=NULL)
				{
					p=p->left;
				}
				t->keyword=p->keyword;
				t->right=deleteNode_rec(t->right,p->keyword);
				if(balanceFactord(t)==2)
				{
					if(balanceFactord(t->left)>=0)
					{
						t=ll(t);
					}
					else
					{
						t=lr(t);
					}
				}
				return t;
			}
		}
		return t;
	}
};
int main()
{
	int x;
	AvlTree t1;
	do
	{
		cout<<"1.add element "<<endl
				<<"\n2.display"<<endl
				<<"\n3.delete node "<<endl
				<<"\n4.update"<<endl
				<<"\n5.search "<<endl
				<<"\n6.exit"<<endl;
		cin>>x;
		switch(x)
		{
			case 1: t1.create();
					break;
			case 2: t1.inorder(t1.getroot());
					break;
			case 3: t1.deleteNode();
					break;
			case 4: t1.update_keyword();
					break;
			case 5: t1.search_keyword();
					break;
			case 6:return 0;
		}
	}while(1);
	return 0;
}

