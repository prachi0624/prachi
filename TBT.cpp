#include <iostream>
using namespace std;
class node
{
public:
	int data,lbit,rbit;
	node *left;
	node *right;
	node()
	{
		lbit=rbit=0;
		left=right=NULL;
		data=0;
	}
	node(int ele)
	{
		lbit=rbit=0;
		data=ele;
		left=right=NULL;
	}
};

class tbt
{
public:
	node *root,*head;

	tbt()
	{
	    head=NULL;
		root=NULL;
	}

	void create(int id)
	{
		if(root==NULL)
		{
		    head=new node(-99);
		    head->lbit=head->rbit=0;
            head->left=head->right=head;

		    root=new node(id);
			head->left=root;
			head->lbit=1;
			root->lbit=root->rbit=0;
			root->left=root->right=head;
		}
		else
		{
			node *ptr=root;
			node *temp;
			while(1)
			{
				if(ptr->data > id)
				{
					if(ptr->lbit!=0)
						ptr=ptr->left;
					else
					{
						temp=new node(id);
						temp->left=ptr->left;
						temp->right=ptr;
						ptr->lbit=1;
						ptr->left=temp;
						return;
					}
				}
				else if(ptr->data < id)
				{
					if(ptr->rbit!=0)
						ptr=ptr->right;
					else
					{
					    temp=new node(id);
						temp->right=ptr->right;
						temp->left=ptr;
						ptr->rbit=1;
						ptr->right=temp;
						return;
					}
				}
			}

		}
	}

	void inorder()
	{
		node *ptr;
		ptr=root;
		while(ptr->lbit!=0)
		{
			ptr=ptr->left;
		}
		while(ptr!=head)
		{
			cout<<ptr->data;
			if(ptr->rbit==0)
				ptr=ptr->right;
			else
			{
				ptr=ptr->right;
				while(ptr->lbit!=0)
				{
					ptr=ptr->left;
				}
			}
		}
	}

	void preorder()
	{
		node *ptr=root;
		while(ptr->lbit!=0)
        {
            cout<<ptr->data;
            ptr=ptr->left;
        }
        cout<<ptr->data;
		while(ptr!=head)
		{
			if(ptr->rbit==0)
                ptr=ptr->right;
            else
            {
                ptr=ptr->right;
                cout<<ptr->data;
                while(ptr->lbit!=0)
                {
                    ptr=ptr->left;
                    cout<<ptr->data;
                }
            }
		}
	}
};

int main()
{
	tbt t;
	int x,c;
	do
	{
		cout<<"\n1.create\n2.inorder\n3.preorder\n0.exit"<<endl;
		cin>>c;
		switch(c)
		{
		case 1:
			cout<<"enter value"<<endl;
			cin>>x;
			t.create(x);
			break;
		case 2:
			t.inorder();
			break;
		case 3:
		    t.preorder();
		    break;
		}

	}while(c!=0);

	return 0;
}
