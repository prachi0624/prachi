#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class Node
{
	private:
		int data;
		Node*right;
		Node*left;
	friend class BinaryTree;
	friend class Queue;
	friend class stack;
	public:
		Node()
		{
			data=0;
			left=right=NULL;
		}
		Node(int ele)
		{
			data=ele;
			right=left=NULL;
		}
};
class BinaryTree
{
	public:
		Node*root;
		int size;
		queue<Node*> q;
		stack<Node*> s;
	BinaryTree()
	{
		root=NULL;
		size=0;
	}

	BinaryTree(int s)
	{
		size=s;
	}

	void creation()
	{
		char op;
		int ele;
		if(root==NULL)
		{
			cout<<"\nEnter root value: ";
			cin>>ele;
			root=new Node(ele);
		}
		q.push(root);
		while(!q.empty())
		{
			Node*temp=q.front();
			q.pop();
			cout<<"Insert a left child for: "<<temp->data<<" ?\nOption(y/n): ";
			cin>>op;
			if(op=='y')
			{
				cout<<"\nEnter value for left child: ";
				cin>>ele;
				temp->left=new Node(ele);
				q.push(temp->left);
			}
			cout<<"Insert a right child for: "<<temp->data<<" ?\nOption(y/n): ";
			cin>>op;
			if(op=='y')
			{
				cout<<"\nEnter value for right child: ";
				cin>>ele;
				temp->right=new Node(ele);
				q.push(temp->right);
			}
		}
	}

	void inorder(Node*temp)
	{
		if(root==NULL)
		{
				cout<<"\nEmpty Tree!\n";
				return;
		}
		if(temp!=NULL)
		{
			inorder(temp->left);
			cout<<temp->data<<"\t";
			inorder(temp->right);
		}
	}

	void preorder(Node*temp)
	{
		if(root==NULL)
		{
				cout<<"\nEmpty Tree!\n";
				return;
		}
		if(temp!=NULL)
		{
			cout<<temp->data<<"\t";
			preorder(temp->left);
			preorder(temp->right);
		}
	}


	void postorder(Node*temp)
	{
		if(root==NULL)
		{
				cout<<"\nEmpty Tree!\n";
				return;
		}
		if(temp!=NULL)
		{
			postorder(temp->left);
			postorder(temp->right);
			cout<<temp->data<<"\t";
		}
	}

	Node*returnRoot()
	{
		return root;
	}

	Node *create()
	{
		int x;

		cout<<"\nenter data or -1 to stop"<<endl;
		cin>>x;

		if(x==-1)
		{
			return NULL;
		}
		else
		{
			Node *p=new Node(x);
			cout<<"Insert a left child for: "<<p->data;

				p->left = create();

			cout<<"Insert a right child for: "<<p->data;

				p->right = create();

			return p;
		}
	}

	void inorder1()
	{
		Node *curr=root;
		Node *temp;

		l:
			while(curr!=NULL)
			{
				s.push(curr);
				curr=curr->left;
			}

		if(!s.empty() && curr==NULL)
		{
			temp=s.top();
			s.pop();
			cout<<temp->data<<"\t";
			curr=temp->right;
			goto l;
		}
		if(s.empty() && curr==NULL)
		{
			return;
		}
	}

	void postorder1()
	{
		stack<Node*> s1;
		Node *curr=root;
		s.push(curr);
		while( !s.empty() )
		{
			Node *temp=s.top();
			s.pop();
			if(temp!=NULL)
			{
				s1.push(temp);
			}
			if(temp->left!=NULL)
				s.push(temp->left);
			if(temp->right!=NULL)
				s.push(temp->right);
		}
		while(!s1.empty())
		{
			curr=s1.top();
			s1.pop();
			cout<<curr->data<<"\t";
		}
	}

	void preorder1()
	{
		Node *curr=root;
		s.push(root);
		while(!s.empty())
		{
			Node *temp=s.top();
			s.pop();
			cout<<temp->data<<"\t";

			if(temp->right!=NULL)
			s.push(temp->right);

			if(temp->left!=NULL)
			s.push(temp->left);
		}
	}

	Node *mirror(Node*t)
    {
        if(t!=NULL)
        {
            Node*temp=t->left;
            t->left=mirror(t->right);
            t->right=mirror(temp);
        }
        return t;

    }
int display_internal(Node*t)
{
	if(t==NULL)
	        return 0;
	    if(t->left==NULL && t->right==NULL)
	    {

	        return 0;
	    }
	    else
        {
            cout<<t->data<<"\t";
            return(1+display_internal(t->left)+display_internal(t->right));
	    }

}

int display_leaves(Node*t)
{
    if(t==NULL)
        return 0;
    if(t->left==NULL && t->right==NULL)
    {
        cout<<t->data<<"\t";
        return 1;
    }
    return(display_leaves(t->left)+display_leaves(t->right));

}

int getheight(Node*t)
{
    if(t==NULL)
    {
        return 0;
    }
    int lh=getheight(t->left);
    int rh=getheight(t->right);
    if(lh>rh)
    {
        return (lh+1);
    }
    else
        return (rh+1);
}

int height()
{
	if(root==NULL)
	return 0;
	q.push(root);
	int ht=0;
	while(1)
	{
		int nc=q.size();
		if(nc==0)
			return ht;
		 ht++;

		while(nc>0)
		{
			Node *t=q.front();
			q.pop();
			if(t->left!=NULL)
                q.push(t->left);
			if(t->right!=NULL)
                q.push(t->right);
			nc--;
		}
	}
}

void delete1(Node *ptr)
{
	if(ptr!=NULL)
	{
		delete1(ptr->left);
		delete1(ptr->right);
		delete ptr;
		root=NULL;
	}
	else return;
}

Node* copy(Node *temp)
	{
		Node *p=NULL;
		if(temp!=NULL)
		{
			p=new Node(temp->data);
			p->left=copy(temp->left);
			p->right=copy(temp->right);
		}
		return p;
	}

	void operator =(BinaryTree &t2)
	{
		Node *t=copy(root);
		t2.root=t;
		cout<<"Preorder traversal of copied tree:"<<endl;
		t2.preorder(t2.root);
	}

};
int main()
{
	BinaryTree b,t,t1;
	char ch1;
	int choice,c,x;
	do{
	cout<<"\n1.non-recursive\n\n2.recursive\n\n0.Exit\n\nOption:"<<endl;
	cin>>c;
	if(c==1)
	{
		do{
		cout<<"\n1.Creation\n\n0.Exit\n\nOption: "<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				b.creation();
				cout<<"inorder traversal : ";
				b.inorder1();
				cout<<endl;
				cout<<"postorder traversal : ";
				b.postorder1();
				cout<<endl;
				cout<<"preorder traversal : ";
				b.preorder1();
				cout<<endl;
				int x=b.height();
				cout<<"height is : "<<x;

				break;
		}
		}while(choice!=0);

	}

	else if(c==2)
	{
	do{
		cout<<"\n1.Creation\n\n2.no. of leaves\n\n3.height of tree\n\n4.internal nodes\n\n5.mirror image\n\n6.delete nodes\n\n0.Exit\n\nOption: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				t.root=t.create();
				cout<<"inorder traversal : ";
				t.inorder(t.returnRoot());
				cout<<endl;
				cout<<"postorder traversal : ";
				t.postorder(t.returnRoot());
				cout<<endl;
				cout<<"preorder traversal : ";
				t.preorder(t.returnRoot());
				break;

			case 2:
			    cout<<"leaves are : ";
			    x=t.display_leaves(t.returnRoot());
			    cout<<"\nno. of leaves are : "<<x;
			    break;
			case 3:
			    cout<<"\nheight is : ";
                cout<<t.getheight(t.returnRoot());
                break;
			case 4:
                cout<<"\ninternal nodes are : ";
                x=t.display_internal(t.returnRoot());
                cout<<"\nno. of internal nodes are : "<<x;
                break;
			case 5:
                cout<<"\nmirror image : ";
                t.mirror(t.returnRoot());
                t.inorder(t.returnRoot());

                break;
			case 6:
                t.delete1(t.returnRoot());
                t.inorder(t.returnRoot());
				break;
            case 7:
            	 cout<<"Copy tree?(y/n)"<<endl;
            	cin>>ch1;
            	 if(ch1=='y')
            	 {
					 t=t1;
					 cout<<endl;
            	 }
		}
	}while(choice!=0);
	}
	}while(c!=0);
	return 0;
}



/*
class Queue
{
	private:
		int front,rear,size;
		Node*q[20];

	public:
	Queue()
	{
		front=rear=-1;
		size=20;
	}

	bool isEmpty()
	{
		if((rear==-1&&front==-1)||(front>rear))
			return true;
		else
			return false;
	}

	bool isFull()
	{
		if(rear==size-1)
			return true;
		else
			return false;
	}

	void push(Node*temp)
	{
		if(isFull())
			cout<<"\nQueue is Full!\n";
		else if(isEmpty())
			{
				front=rear=0;
				q[rear]=temp;
			}
		else
			{
				rear++;
				q[rear]=temp;
            }
	}

	Node*pop()
	{
		Node*temp;
		if(isEmpty())
		{
			cout<<"\nQueue is Empty!\n";
			return NULL;
		}
		else
		{
			temp=q[front];
			front++;
			return temp;
		}

	}

	int size1()
	{
	    if(rear==-1 && front==-1)
			return 0;
		return (rear-front+1);
	}

	void displayQ()
	{
		int i;
		for(i=front;i<rear+1;i++)
		{
			cout<<q[i]->data;
		}
	}
};
class stack
{
	private:
		int top;
		Node *s[20];

	public:
	stack()
	{
		top=-1;

	}

	bool isEmpty()
	{
		if(top==-1)
			return true;
		else
			return false;
	}

	bool isFull()
	{
		if(top==19)
			return true;
		else
			return false;
	}

	void push(Node*temp)
	{
		if(isFull())
			cout<<"\nStack is Full!\n";

		else
		{
			s[++top]=temp;

		}
	}

	Node* pop()
	{
		Node* temp;
		if(isEmpty())
		{
			cout<<"\nQueue is Empty!\n";
			return NULL;
		}
		else
		{
			return s[top--];
		}

	}


};
*/
