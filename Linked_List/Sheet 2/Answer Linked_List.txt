//Linked_List
#include <iostream>
using namespace std;

typedef int ElementType;

struct Node
{
	ElementType Data;
	Node* Next; //next will saves address of node
};
typedef Node* Position;

class Linked_List
{

	Node* Head;
	Node* Tail;
	int Counter;
public:
	Linked_List()
	{
		Head = new Node();
		Head->Next = NULL;
		Tail = NULL;
		Counter = 0;
	}
	Position First()
	{
		if (Counter == 0)
		{
			return NULL;
		}
		return Head;
	}
	bool IsEmpty()
	{
		return Counter == 0;
	}
	Position End()
	{
		if (Head->Next == NULL)
		{
			return Head;
		}
		return Tail;
	}
	Position NEXT(Position p)
	{
		if (p == Tail || p == NULL)
		{
			return NULL;
		}
		return p->Next;
	}
	Position Previous(Position p)
	{
		if (p == Head)
		{
			return NULL;
		}
		Position temp = Head;
		while (temp != NULL && temp->Next != p)
		{
			temp = temp->Next;
		}
		return temp;
	}
	Position Locate(ElementType x)
	{
		Position temp = Head;
		while (temp->Next != NULL)
		{
			if (temp->Next->Data == x)
			{
				return temp;
			}
			else
			{
				temp = temp->Next;
			}
		}
		return temp;
	}
	void Insert(ElementType x, Position p)
	{
		if (p == NULL)
		{
			p = End();
		}
		Position node = new Node();
		node->Data = x;
		node->Next = p->Next;
		p->Next = node;
		if (node->Next == NULL)
		{
			Tail = node;
		}
		Counter++;
	}
	void Delete(Position p)
	{
		if (p->Next == Tail)
		{
			Tail = p;
		}
		Position temp = p->Next;
		p->Next = p->Next->Next;
		temp = NULL;
		delete temp;
		Counter--;
	}
	ElementType Retrieve(Position p)
	{
		if (p == NULL || p->Next == NULL)
		{
			return -9999;
		}
		else if (p == End())
		{
			return End()->Data;
		}
		else
		{
			return p->Next->Data;
		}
	}
	void Print()
	{
		if (Head->Next == NULL)
		{
			cout << "The List Is Empty\n";
		}
		else
		{
			Position p = Head;
			while (p->Next != NULL)
			{
				cout << p->Next->Data << " ";
				p = p->Next;
			}
			cout << endl;
		}
	}
	int Size()
	{
		return Counter;
	}
};
void Purge(Linked_List& x)
{
	Position temp = x.First();
	Position temp1;
	while (x.NEXT(temp) != NULL)
	{
		temp1 = x.NEXT(temp);
		while (temp1->Next != NULL)
		{
			if (x.Retrieve(temp) == x.Retrieve(temp1))
			{
				x.Delete(temp1);
			}
			else
			{
				temp1 = x.NEXT(temp1);
			}
		}
		temp = x.NEXT(temp);
	}
}
void Reverse(Linked_List& t)
{
	for (Position i = t.First(), j = t.Previous(t.End()); i != j && i != t.NEXT(j); i = t.NEXT(i), j = t.Previous(j))
	{
		ElementType a = t.Retrieve(i);
		ElementType b = t.Retrieve(j);
		t.Delete(i);
		t.Insert(b, i);
		t.Delete(j);
		t.Insert(a, j);
	}
}
void Insert_After(ElementType x, ElementType y, Linked_List& t)
{
	t.Insert(x, t.NEXT(t.Locate(y)));
}
Linked_List Concatenate(Linked_List l1, Linked_List l2)
{
	Linked_List l;
	Position p;
	p = l1.First();
	while (p != l1.End())
	{
		l.Insert(l1.Retrieve(p), l.End());
		p = l1.NEXT(p);
	}
	p = l2.First();
	while (p != l2.End())
	{
		l.Insert(l2.Retrieve(p), l.End());
		p = l2.NEXT(p);
	}
	return l;
}
void Split(Linked_List l, Linked_List& odd, Linked_List& even)
{
	Position p = l.First();
	while (p != l.End())
	{
		if (l.Retrieve(p) % 2 == 0)
		{
			even.Insert(l.Retrieve(p), even.End());
		}
		else
		{
			odd.Insert(l.Retrieve(p), odd.End());
		}
		p = l.NEXT(p);
	}
}
int Sum_LL(Linked_List l)
{
	int s = 0;
	Position p = l.First();
	while (p != l.End())
	{
		s += l.Retrieve(p);
		p = l.NEXT(p);
	}
	return s;
}
void RemoveOccurences1(ElementType e, Linked_List& x) //Remove All Element X in The List.
{
	Position p = x.First();
	while (p != x.End())
	{
		if (x.Retrieve(p) == e)
		{
			x.Delete(p);
		}
		else
		{
			p = x.NEXT(p);
		}
	}
}
int main()
{
	Linked_List L1;
	L1.Insert(1, L1.End());
	L1.Insert(1, L1.End());
	L1.Insert(1, L1.End());
	L1.Insert(2, L1.End());
	L1.Insert(2, L1.End());
	L1.Insert(3, L1.End());
	L1.Insert(3, L1.End());
	L1.Insert(1, L1.End());
	L1.Insert(3, L1.End());
	cout << "The List : ";
	L1.Print();
	cout << "The Purge : ";
	Purge(L1);
	L1.Print();
	cout << "******************************************* \n";
	Linked_List L2;
	L2.Insert(1, L2.End());
	L2.Insert(2, L2.End());
	L2.Insert(3, L2.End());
	L2.Insert(4, L2.End());
	L2.Insert(5, L2.End());
	L2.Insert(6, L2.End());
	L2.Insert(7, L2.End());
	cout << "The List : ";
	L2.Print();
	cout << "The Reverse : ";
	Reverse(L2);
	L2.Print();
	cout << "******************************************* \n";
	Linked_List L3;
	L3.Insert(1, L3.End());
	L3.Insert(2, L3.End());
	L3.Insert(3, L3.End());
	L3.Insert(4, L3.End());
	L3.Insert(5, L3.End());
	L3.Insert(6, L3.End());
	L3.Insert(7, L3.End());
	cout << "The List : ";
	L3.Print();
	cout << "Insert After Y : ";
	Insert_After(10, 5, L3);
	L3.Print();
	cout << "Insert After Y And Y not found: ";
	Insert_After(10, 99, L3);
	L3.Print();
	cout << "******************************************* \n";
	Linked_List L4 , LResult;
	L4.Insert(1, L4.End());
	L4.Insert(2, L4.End());
	L4.Insert(3, L4.End());
	cout << "The First List : ";
	L4.Print();
	Linked_List L5;
	L5.Insert(4, L5.End());
	L5.Insert(5, L5.End());
	L5.Insert(6, L5.End());
	cout << "The Second List : ";
	L5.Print();
	cout << "The Concatenates Between First List And Second List : ";
	LResult = Concatenate(L4, L5);
	LResult.Print();
	cout << "******************************************* \n";
	Linked_List L6, LEven, LOdd;
	L6.Insert(1, L6.End());
	L6.Insert(2, L6.End());
	L6.Insert(3, L6.End());
	L6.Insert(4, L6.End());
	L6.Insert(5, L6.End());
	L6.Insert(6, L6.End());
	L6.Insert(7, L6.End());
	cout << "The List : ";
	L6.Print();
	Split(L6, LOdd, LEven);
	cout << "The Odd List : ";
	LOdd.Print();
	cout << "The Even List : ";
	LEven.Print();
	cout << "******************************************* \n";
	Linked_List L7;
	L7.Insert(1, L7.End());
	L7.Insert(2, L7.End());
	L7.Insert(3, L7.End());
	L7.Insert(4, L7.End());
	L7.Insert(5, L7.End());
	L7.Insert(6, L7.End());
	L7.Insert(7, L7.End());
	cout << "The List : ";
	L7.Print();
	cout << "The Sum Of List : " << Sum_LL(L7) << endl;
	cout << "******************************************* \n";
	Linked_List L8;
	L8.Insert(1, L8.End());
	L8.Insert(1, L8.End());
	L8.Insert(1, L8.End());
	L8.Insert(2, L8.End());
	L8.Insert(2, L8.End());
	L8.Insert(3, L8.End());
	L8.Insert(3, L8.End());
	L8.Insert(1, L8.End());
	L8.Insert(3, L8.End());
	cout << "The List : ";
	L8.Print();
	cout << "The RemoveOccurences1 : ";
	RemoveOccurences1(3, L8);
	L8.Print();
	cout << "******************************************* \n";
	system("pause");
	return 0;
}