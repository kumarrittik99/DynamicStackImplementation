#include<iostream>
using namespace std;
class StackInfo
{
	public:
	int capacity;
	int topIndex;
	int *stack;
};
class StackInfo *stackPointer=NULL;
class StackInfo* createStackInfo(int cap)
{
	class StackInfo *temp = new StackInfo;
	temp->capacity=cap;
	temp->topIndex=-1;
    temp->stack=new int[temp->capacity];
    return temp;
}
bool isFull(StackInfo *pointer)
{
	if(pointer->topIndex==pointer->capacity-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool isEmpty(class StackInfo *pointer)
{
	if(pointer->topIndex==-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void push(class StackInfo *pointer,int element)
{
	if(isFull(stackPointer))
	{
		cout<<"Stack is full. More elements cant be inserted.\n";
	}
	else
	{
		pointer->topIndex++;
		pointer->stack[pointer->topIndex]=element;
	}
}
void pop(class StackInfo *pointer)
{
	if(isEmpty(stackPointer))
	{
		cout<<"Elements cant be deleted as stack is already empty!!\n";
	}
	else
	{
		int element;
		element=pointer->stack[pointer->topIndex];
		pointer->topIndex--;
		cout<<element<<" is popped.\n";
	}
}
void traverse(class StackInfo *pointer)
{
	if(isEmpty(stackPointer))
	{
		cout<<"No elements to show as stack is empty!!\n";
	}
	else
	{
		for(int i=0;i<=pointer->topIndex;i++)
		{
			cout<<pointer->stack[i]<<endl;
		}
	}
}
int main()
{
	int choice,element,capacity;
	cout<<"Enter the capacity of the stack.\n";
	cin>>capacity;
	stackPointer=createStackInfo(capacity);
	cout<<"1 Push an element to stack.\n";
	cout<<"2 Pop an element from the stack.\n";
	cout<<"3 Traverse through the stack.\n";
	cout<<"4 Exit.\n";
	while(true)
	{
		cout<<"Enter your choice\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter the element you want to push\n";
				cin>>element;
				push(stackPointer,element);
				break;
			case 2:
				pop(stackPointer);
				break;
			case 3:
				traverse(stackPointer);
				break;
			default:
				cout<<"Invalid choice\n";
				break;
		}
	}
	return 0;
}
