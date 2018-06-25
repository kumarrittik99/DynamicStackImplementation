#include<iostream>
using namespace std;
class Node
{
	public:
	int data;
	class Node *next;
};
class Node *start=NULL;
class Node* createNode()
{
	int element;
	class Node *temp=new Node;
	cout<<"Enter an integer\n";
	cin>>element;
	temp->data=element;
	temp->next=NULL;
	return temp;
}
void insertNodeFirst()
{
	class Node *temp;
	if(start==NULL)
	{
		start=createNode();
	}
	else
	{
		temp=createNode();
		temp->next=start;
		start=temp;
	}
}
void insertNodeLast()
{
	class Node *temp;
	temp=start;
	if(start==NULL)
	{
		start=createNode();
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=createNode();
	}
}
void insertNodePos(int position)
{
	class Node *temp=start;
	class Node *t;
	if(start==NULL)
	{
		start=createNode();
	}
	else
	{
		for(int i=0;i<position-1;i++)
		{
			temp=temp->next;
		}
		t=createNode();
		t->next=temp->next;
		temp->next=t;
	}
}
void deleteFirstNode()
{
	class Node *temp;
	if(start==NULL)
	{
		cout<<"List is already empty. Nothing to delete.\n";
	}
	else
	{
		temp=start;
		start=start->next;
		delete temp;
	}
}
void deleteLastNode()
{
	class Node *temp=start;
	class Node *t;
	if(start==NULL)
	{
		cout<<"List is already empty. Nothing to delete.\n";
	}
	else
	{
		while(temp->next!=NULL)
		{
			t=temp;
			temp=temp->next;
		}
		t->next=NULL;
		delete temp;
	}
}
void deleteNodePos(int position)
{
	class Node *temp=start;
	class Node *t;
	if(start==NULL)
	{
		cout<<"List is already empty. Nothing to delete.\n";
	}
	else
	{
		for(int i=0;i<position-2;i++)
		{
			temp=temp->next;
		}
		t=temp->next;
		temp->next=temp->next->next;
		delete t;
	}
}
void traverse()
{
	class Node *temp;
	temp=start;
	if(start==NULL)
	{
		cout<<"List is empty\n";
	}
	else
	{
		while(temp!=NULL)
		{
			cout<<temp->data<<endl;
			temp=temp->next;
		}
	}
}
int main()
{
	int choice,position;
	cout<<"1 Insert a node at first.\n";
	cout<<"2 Insert a node at last.\n";
	cout<<"3 Insert a node at a specific position.\n";
	cout<<"4 Delete a node at first.\n";
	cout<<"5 Delete a node at last.\n";
	cout<<"6 Delete a node at specific position.\n";
	cout<<"7 Print all the values of the list.\n";
	cout<<"8 Press to exit.\n";
	while(true)
	{
		cout<<"Enter your choice.\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
				insertNodeFirst();
				break;
			case 2:
				insertNodeLast();
				break;
			case 3:
				cout<<"Enter position\n";
				cin>>position;
				insertNodePos(position);
				break;
			case 4:
				deleteFirstNode();
				break;
			case 5:
				deleteLastNode();
				break;
			case 6:
				cout<<"Enter position\n";
				cin>>position;
				deleteNodePos(position);
				break;
			case 7:
				traverse();
				break;
			case 8:
				exit(false);
				break;
			default:
				cout<<"Invalid Choice\n";
				break;
		}
	}
}
