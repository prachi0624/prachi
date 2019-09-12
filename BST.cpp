#include <iostream>
using namespace std;

class node
{
	string keyword,meaning;
	node *left,*right;
public:
	node(string s)
	{
		keyword=s;
		cout<<"Enter the meaning of the keyword:  ";
		cin>>meaning;
		left=right=NULL;

	}
	friend class BST;
};

class BST
{
	node *root;
public:
	BST()
	{
		root=NULL;
	}

void add_keyword()
{
	node *p=root,*q;
	string s;
	cout<<"Enter the keyword:  ";
	cin>>s;

	if(root==NULL)
	{
		root=new node(s);
		return;
	}
	while(p!=NULL)
	{
		q=p;
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
			cout<<"Word already exists\n";
			return;
		}
	}
	if(s < q->keyword)
	{
		q->left=new node(s);
	}
	else
	{
		q->right=new node(s);
	}
	cout<<"Keyword added\n";

}
void delete_keyword()
{
	string s;
	cout<<"Enter the keyword to be deleted:   ";
	cin>>s;
	root=del(root,s);
}
node *del(node *p,string s)
{
	if(p==NULL)
	{
		cout<<"Keyword doesn't exist\n";
		return NULL;
	}
	if(s < p->keyword)
	{
		p->left=del(p->left,s);
		return p;
	}
	else if(s > p->keyword)
	{
		p->right=del(p->right,s);
		return p;
	}
	else if(s == p->keyword)
	{

		if(p->left==NULL && p->right==NULL)
		{
			delete p;
			return NULL;
		}
		else if(p->left!=NULL && p->right==NULL)
		{
			node *q=p->left;
			delete p;
			return q;
		}
		else if(p->left==NULL && p->right!=NULL)
		{
			node *q=p->right;
			delete p;
			return q;
		}
		else
		{
		    node *q=p->right;
				while(q->left!=NULL)
				{
					q=q->left;
				}
				p->keyword=q->keyword;
				p->right=del(p->right,q->keyword);

			return p;
		}

	}

}
/*node *find_min(node *p)
{
	if(p==NULL)
	{
		return NULL;
	}
	while(p->left!=NULL)
	{
		p=p->left;
	}
	return p;

}*/
void update_keyword()
{
	string s,m;
	cout<<"Enter the keyword to be updated:  ";
	cin>>s;
	node *p=root;
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
//void ascending_order()
//{
	//asc(root);
//}
void ascending_order(node *p)
{
	if(root==NULL)
	{
		cout<<"Empty Tree"<<endl;
		return;
	}
	if(p!=NULL)
    {
        ascending_order(p->left);
        cout<<p->keyword<<":	"<<p->meaning<<"\n";
        ascending_order(p->right);
    }

}
//void descending_order()
//{
	//desc(root);
//}
void descending_order(node *p)
{
	if(root==NULL)
	{
		cout<<"Empty Tree"<<endl;
		return;
	}
	if(p!=NULL)
    {
        descending_order(p->right);
        cout<<p->keyword<<":	"<<p->meaning<<"\n";
        descending_order(p->left);
    }
}

/*void BST::display()
{
	queue<node *>q;
	node *p=root;
	if(root==NULL)
	{
		cout<<"Tree is empty.\n";
		return;
	}
	q.push(p);
	while(!q.empty())
	{
		p=q.front();
		q.pop();
		if(p->left!=NULL)
		{
			q.push(p->left);
		}
		if(p->right!=NULL)
		{
			q.push(p->right);
		}

		cout<<p->keyword<<":	"<<p->meaning<<"\n";
	}

}*/
void search_keyword()
{
	int count=1;
	string s;
	cout<<"Enter the keyword to be searched:  ";
	cin>>s;
	node *p=root;
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

/*void copy(BST &d1)
{
	root=copy_tree(d1.root);
	ascending_order(d1.);
}*/

void operator =(BST &t2)
	{
		node *t=copy_tree(root);
		t2.root=t;
		cout<<" traversal of copied tree:"<<endl;
		ascending_order(t2.root);
	}
node *copy_tree(node *p)
{
	if(p==NULL)
	{
		return NULL;
	}                                        //refer binary tree's copy tree function
	p->left=copy_tree(p->left);
	p->right=copy_tree(p->right);

	return p;
}

node*returnRoot()
	{
		return root;
	}

};
int main()
{
	BST d,d1;
	char ch1;
	int choice;
	while(1)
	{
		cout<<"\n1.Add keyword\n2.Delete keyword\n3.Update keyword\n4.Ascending order\n5.Descending order\n6.Display\n7.Search a keyword\n8.Copy tree\n";
		cout<<"Enter your choice:  ";
		cin>>choice;
		switch(choice)
		{
			case 1:d.add_keyword();
				break;
			case 2:d.delete_keyword();
				break;
			case 3:d.update_keyword();
				break;
			case 4:d.ascending_order(d.returnRoot());
				break;
			case 5:d.descending_order(d.returnRoot());
				break;
			//case  6:d.display();
			//	break;
			case 7:d.search_keyword();
				break;
			case 8: cout<<"Copy tree?(y/n)"<<endl;
        			cin>>ch1;
        			if(ch1=='y')
        			{
        				d=d1;
        				cout<<endl;
        			}
				break;
			default:cout<<"Invalid choice !\n";
				break;
		}
	}
}
