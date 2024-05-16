#include<iostream>
using namespace std;

// implementation of Queue with array
typedef int ElementType_Array;
typedef int Position_Array;

class Queue_Array
{
private:
	int Capacity;
	Position_Array Front, Rear;
	int Counter;
	ElementType_Array* Elements;
public:
	Queue_Array(int Size = 10)
	{
		Elements = new ElementType_Array[Size];
		Capacity = Size;
		Front = 0;
		Rear = Capacity - 1;
		Counter = 0;
	}
	bool IsEmpty_Array()
	{
		return Counter == 0;
	}
	bool IsFull_Array()
	{
		return Counter == Capacity;
	}
	ElementType_Array Fisrt_Array()
	{
		if (IsEmpty_Array())
		{
			cout << "Error: The Queue Is Empty \n";
			return -999;
		}
		else
		{
			return Elements[Front];
		}
	}
	void Enqueue_Array(ElementType_Array x)//Insert Element in The Last.
	{
		if (IsFull_Array())
		{
			cout << "Error: The Queue Is Full \n";

		}
		else
		{
			Rear = (Rear + 1) % Capacity;
			Elements[Rear] = x;
			Counter++;
		}
	}
	ElementType_Array Dequeue_Array()//Delete Element in The Fisrt And Return The Element.
	{
		if (IsEmpty_Array())
		{
			cout << "Error: The Queue Is Empty \n";
			return -999;
		}
		else
		{
			Front = (Front + 1) % Capacity;
			Counter--;
			return Elements[Front];
		}
	}
	void Print_Array()
	{
		if (IsEmpty_Array())
		{
			cout << "Error: The Queue Is Empty \n";
		}
		for (Position_Array i = Front; i != Rear; i = (i + 1) % Capacity)
		{
			cout << Elements[i] << " ";
		}
		cout << Elements[Rear] << endl;
	}
};
//=================================================
// implementation of Queue with Linked-List
typedef int ElementType_LL;
struct Node
{
	ElementType_LL Element;
	Node* Next;
};
typedef Node* Position_LL;
class Queue_LL
{
private:
	Position_LL Front, Rear;
	int Counter;
public:
	Queue_LL()
	{
		MakeNull();
	}
	void MakeNull()
	{
		Front = NULL;
		Rear = NULL;
		Counter = 0;
	}
	bool IsEmpty_LL()
	{
		return Front == NULL;
	}
	ElementType_LL First_LL()
	{
		if (IsEmpty_LL())
		{
			cout << "Error: The Queue Is Empty \n";
			return NULL;
		}
		return Front->Element;
	}
	void Enqueue_LL(ElementType_LL x)//Insert Element in The Last.
	{
		Position_LL NewNode = new Node();
		NewNode->Element = x;
		NewNode->Next = NULL;
		if (Counter == 0)
		{
			Rear = NewNode;
			Front = Rear;
		}
		else
		{
			Rear->Next = NewNode;
			Rear = NewNode;
		}
		Counter++;
	}
	ElementType_LL Dequeue_LL()//Delete Element in The Fisrt And Return The Element.
	{
		if (IsEmpty_LL())
		{
			cout << "Error: The Queue Is Empty \n";
			return NULL;
		}
		else
		{
			ElementType_LL x = Front->Element;
			Position_LL Temp = Front;
			Front = Front->Next;
			delete Temp;
			Counter--;
			if (Counter == 0)
			{
				Rear = NULL;
			}
			return x;
		}
	}
	void Print_LL()
	{
		if (IsEmpty_LL())
		{
			cout << "Error: The Queue Is Empty \n";
			return;
		}
		cout << "Queue Is ==>";
		Position_LL q = Front;
		while (q != NULL)
		{
			cout << q->Element << " ";
			q = q->Next;
		}
		cout << endl;
	}
};
//=====================================================
//Linked-List Bassed Stack implementation
typedef int ElementType;

struct node {
	ElementType data;
	node* Next;
};

typedef node* position_LL;

class stack_ll
{
private:
	int counter_ll;
	position_LL top_ll;
public:
	stack_ll()
	{
		makenull();
	}
	void makenull()
	{
		top_ll = NULL;
		counter_ll = 0;
	}
	bool isEmpty_ll()
	{
		return top_ll == NULL;
	}
	void push_ll(ElementType x)
	{
		position_LL newNode = new node();
		newNode->data = x;
		newNode->Next = top_ll;
		top_ll = newNode;
		counter_ll++;
	}
	ElementType pop_ll()
	{
		if (isEmpty_ll())
		{
			cout << "Error : The Stack Is Empty" << endl;
			return NULL;
		}
		else
		{
			ElementType x = top_ll->data;
			position_LL temp = top_ll;
			top_ll = top_ll->Next;
			delete temp;
			counter_ll--;
			return x;
		}
	}
	ElementType topp_ll()
	{
		if (isEmpty_ll())
		{
			cout << "Error : The Stack Is Empty" << endl;
			return NULL;
		}
		return top_ll->data;
	}
	void printstack()
	{
		cout << "Stack is ==> ";
		position_LL q = top_ll;
		while (q != NULL)
		{
			cout << q->data << " ";
			q = q->Next;
		}
		cout << endl;
	}
};
//=====================================================
//Application

int Sum_Queue(Queue_LL t)
{
	int s = 0;
	while (!t.IsEmpty_LL())
	{
		s += t.Dequeue_LL();
	}
	return s;
}
int Maximum_Queue(Queue_LL t)
{
	int Max = t.First_LL();
	while (!t.IsEmpty_LL())
	{
		int x = t.Dequeue_LL();
		if (x > Max)
		{
			Max = x;
		}
	}
	return Max;
}
Queue_LL Extract_Even(Queue_LL t)
{
	Queue_LL Even;
	while (!t.IsEmpty_LL())
	{
		int x = t.Dequeue_LL();
		if (x % 2 == 0)
		{
			Even.Enqueue_LL(x);
		}
	}
	return Even;
}
bool Palindrome(string A)
{
	stack_ll x;
	Queue_LL y;
	for (int i = 0; i < A.length(); i++)
	{
		x.push_ll(A[i]);
		y.Enqueue_LL(A[i]);
	}
	for (int i = 0; i < A.length(); i++)
	{
		if (x.pop_ll() != y.Dequeue_LL())
			return false;
	}
	return true;
}
int main()
{
	Queue_LL A1;
	A1.Enqueue_LL(1);
	A1.Enqueue_LL(1);
	A1.Enqueue_LL(1);
	A1.Enqueue_LL(1);
	A1.Enqueue_LL(1);
	cout << "The Sum Of Queue => " << Sum_Queue(A1) << endl;
	cout << "***************************************************\n";
	Queue_LL A2;
	A2.Enqueue_LL(1);
	A2.Enqueue_LL(2);
	A2.Enqueue_LL(3);
	A2.Enqueue_LL(6);
	A2.Enqueue_LL(4);
	cout << "The Maximum Of Queue => " << Maximum_Queue(A2) << endl;
	cout << "***************************************************\n";
	Queue_LL A3;
	A3.Enqueue_LL(1);
	A3.Enqueue_LL(2);
	A3.Enqueue_LL(3);
	A3.Enqueue_LL(4);
	A3.Enqueue_LL(5);
	A3.Enqueue_LL(6);
	cout << "The Even Number In => ";
	Extract_Even(A3).Print_LL();
	cout << "***************************************************\n";
	if (Palindrome("ABAC"))
	{
		cout << "ABAC => Is Palindrome \n";
	}
	else
	{
		cout << "ABAC => Is Not Palindrome \n";
	}
	if (Palindrome("11211"))
	{
		cout << "11211 => Is Palindrome \n";
	}
	else
	{
		cout << "11211 => Is Not Palindrome \n";
	}
	return 0;
}
