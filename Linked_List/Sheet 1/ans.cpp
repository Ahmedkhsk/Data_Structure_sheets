//Array Of List
#include <iostream>
#include<algorithm>
using namespace std;

typedef int ElementType;
typedef int Position;

class list
{
private:
	int capacity;
	ElementType* elements;
	Position last;
public:
	list(int n = 10)
	{
		capacity = n;
		elements = new ElementType[capacity];
		last = -1;
	}
	bool isEmpty()
	{
		return last == -1;
	}
	bool isFull()
	{
		return last == capacity - 1;
	}

	Position End()
	{
		return last + 1;
	}
	Position First()
	{
		if (isEmpty())
		{
			return End();
		}
		else
		{
			return 0;
		}
	}
	Position Next(Position p)
	{
		if (p >= last)
		{
			return End();
		}
		else if (p < 0)
		{
			//cout << "ERROR position out of Range \n";
			return -1;
		}
		return p + 1;
	}
	Position Previous(Position p)
	{
		if (p > End())
		{
			cout << "ERROR the index is greater than size of array \n";
			return End();
		}
		else if (p <= 0)
		{
			cout << "ERROR position out of Range \n";
			return -1;
		}
		return p - 1;
	}
	void Insert(ElementType x, Position p)
	{
		if (isFull())
		{
			cout << "list is full \n";
			return;

		}
		else if (p<0 || p>End())
		{
			cout << "postion is out of range \n";
			return;
		}
		else if (p == End())
		{
			elements[p] = x;
			last++;
			return;
		}
		for (Position i = last; i >= p; i--)
		{
			elements[i + 1] = elements[i];
		}
		elements[p] = x;
		last++;
	}
	void Delete(Position p)
	{
		if (isEmpty())
		{
			cout << "list is empty";
			return;

		}
		else if (p < 0 || p >= End())
		{

			//cout << "postion is out of range";
			return;
		}
		else if (p == last)
		{
			last--;
			return;
		}
		for (Position i = p; i < last; i++)
		{
			elements[i] = elements[i + 1];
		}
		last--;
	}
	Position Locate(ElementType x)
	{
		for (Position i = First(); i != End(); i++)
		{
			if (elements[i] == x)
			{
				return i;
				break;
			}
		}
		return -1;
	}
	ElementType Retrieve(Position p)
	{
		if (p >= End() || p < 0)
		{
			//cout << "ERROR out of Range \n";
			return -1;
		}
		return elements[p];
	}
	void MakeNull()
	{
		last = -1;
	}
	void printList()
	{
		for (Position i = First(); i != End(); i++)
		{
			cout << elements[i] << " ";
		}
		cout << endl;
	}
};

void Purge(list& t) //Remove Duplicates From List.
{
	for (Position i = t.First(); i != t.End(); i = t.Next(i))
	{
		for (Position j = t.First(); (j != t.End()); j = t.Next(j))
		{
			if (t.Retrieve(i) == t.Retrieve(j) && (i != j))
			{
				t.Delete(j);
			}
		}
	}
}
void Reverse(list& t) //Reverses List.
{
	for (Position i = t.First(), j = t.Previous(t.End()); i != j && i != t.Next(j); i = t.Next(i), j = t.Previous(j))
	{
		ElementType a = t.Retrieve(i);
		ElementType b = t.Retrieve(j);
		t.Delete(i);
		t.Insert(b, i);
		t.Delete(j);
		t.Insert(a, j);
	}
}
void Insert_After(ElementType x, ElementType y, list& t) //insert X after Y.
{
	if (t.Locate(y) == -1)
	{
		t.Insert(x, t.End());
	}
	else
	{
		t.Insert(x, t.Next(t.Locate(y)));
	}
}
list Concatenate(list x, list y) //Concatenates Two Lists.
{
	int c = x.End() + y.End();
	list z(c);
	for (int i = 0; i < x.End(); i++)
	{
		z.Insert(x.Retrieve(i), z.End());
	}
	for (int j = 0; j < y.End(); j++)
	{
		z.Insert(y.Retrieve(j), z.End());
	}
	return z;
}
void Split(list L, list& lOdd, list& lEven) //Splits The Linked To Two Lists, One For Odd Numbers And One For Even Numbers.
{
	Position curr = L.First();
	while (curr != L.End())
	{
		ElementType x = L.Retrieve(curr);
		if (x % 2 == 0)
		{
			lEven.Insert(x, lEven.End());
		}
		else
		{
			lOdd.Insert(x, lOdd.End());
		}
		curr = L.Next(curr);
	}
}
ElementType Sum_List(list L) //Calculates The Summation Of All Values In The List.
{
	Position curr = L.First();
	ElementType s = 0;
	while (curr != L.End())
	{
		ElementType x = L.Retrieve(curr);
		s = s + x;
		curr = L.Next(curr);
	}
	return s;
}
void RemoveOccurences1(ElementType e, list& x) //Remove All Element X in The List.
{
	if (x.Locate(e) == -1)
	{
		cout << "element not found \n";
		return;
	}
	else
	{
		for (int i = 0; i < x.End(); i++)
		{
			x.Delete(x.Locate(e));
		}
	}
}
int LocateInRange(list l, ElementType x, Position Start, Position End) //Check x Is Belong To The Range. 
{
	if (l.isEmpty())
	{
		return -1;
	}
	while (Start != End)
	{
		if (l.Retrieve(Start) == x)
		{
			return Start;
		}
		Start = l.Next(Start);
	}
	return -1;
}
void RemoveOccurences2(list& l, ElementType x, Position Start, Position End) //Remove All Element X in The Range.
{
	while (Start != End)
	{
		if (LocateInRange(l, x, Start, End) != -1)
		{
			l.Delete(LocateInRange(l, x, Start, End));
		}
		else
		{
			Start = l.Next(Start);
		}
	}
}
int main()
{
	list L1(10);
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
	L1.printList();
	cout << "The Purge : ";
	Purge(L1);
	L1.printList();
	cout << "******************************************* \n";
	list L2(10);
	L2.Insert(1, L2.End());
	L2.Insert(2, L2.End());
	L2.Insert(3, L2.End());
	L2.Insert(4, L2.End());
	L2.Insert(5, L2.End());
	L2.Insert(6, L2.End());
	L2.Insert(7, L2.End());
	cout << "The List : ";
	L2.printList();
	cout << "The Reverse : ";
	Reverse(L2);
	L2.printList();
	cout << "******************************************* \n";
	list L3(10);
	L3.Insert(1, L3.End());
	L3.Insert(2, L3.End());
	L3.Insert(3, L3.End());
	L3.Insert(4, L3.End());
	L3.Insert(5, L3.End());
	L3.Insert(6, L3.End());
	L3.Insert(7, L3.End());
	cout << "The List : ";
	L3.printList();
	cout << "Insert After Y : ";
	Insert_After(10, 5, L3);
	L3.printList();
	cout << "Insert After Y And Y not found: ";
	Insert_After(10, 99, L3);
	L3.printList();
	cout << "******************************************* \n";
	list L4(10);
	L4.Insert(1, L4.End());
	L4.Insert(1, L4.End());
	L4.Insert(1, L4.End());
	L4.Insert(2, L4.End());
	L4.Insert(2, L4.End());
	L4.Insert(3, L4.End());
	L4.Insert(3, L4.End());
	L4.Insert(1, L4.End());
	L4.Insert(3, L4.End());
	cout << "The First List : ";
	L4.printList();
	list L5(10);
	L5.Insert(1, L5.End());
	L5.Insert(2, L5.End());
	L5.Insert(3, L5.End());
	L5.Insert(4, L5.End());
	L5.Insert(5, L5.End());
	L5.Insert(6, L5.End());
	L5.Insert(7, L5.End());
	cout << "The Second List : ";
	L5.printList();
	cout << "The Concatenates Between First List And Second List : ";
	Concatenate(L4, L5).printList();
	cout << "******************************************* \n";
	list L6(10), LOdd(10), LEven(10);
	L6.Insert(1, L6.End());
	L6.Insert(2, L6.End());
	L6.Insert(3, L6.End());
	L6.Insert(4, L6.End());
	L6.Insert(5, L6.End());
	L6.Insert(6, L6.End());
	L6.Insert(7, L6.End());
	cout << "The List : ";
	L6.printList();
	Split(L6, LOdd, LEven);
	cout << "The Odd List : ";
	LOdd.printList();
	cout << "The Even List : ";
	LEven.printList();
	cout << "******************************************* \n";
	list L7(10);
	L7.Insert(1, L7.End());
	L7.Insert(2, L7.End());
	L7.Insert(3, L7.End());
	L7.Insert(4, L7.End());
	L7.Insert(5, L7.End());
	L7.Insert(6, L7.End());
	L7.Insert(7, L7.End());
	cout << "The List : ";
	L7.printList();
	cout << "The Sum Of List : " << Sum_List(L7) << endl;
	cout << "******************************************* \n";
	list L8(10);
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
	L8.printList();
	cout << "The RemoveOccurences1 : ";
	RemoveOccurences1(3, L8);
	L8.printList();
	cout << "******************************************* \n";
	list L9(10);
	L9.Insert(1, L9.End());
	L9.Insert(2, L9.End());
	L9.Insert(3, L9.End());
	L9.Insert(4, L9.End());
	L9.Insert(5, L9.End());
	L9.Insert(6, L9.End());
	L9.Insert(7, L9.End());
	cout << "The List : ";
	L9.printList();
	cout << "Locate In Range is : ";
	if (LocateInRange(L9, 3, 4, 6) == -1)
	{
		cout << "The element is not exits in The Range \n";
	}
	else
	{
		cout << "The element is exits in The Range \n";
	}
	cout << "******************************************* \n";
	list L10(10);
	L10.Insert(1, L10.End());
	L10.Insert(2, L10.End());
	L10.Insert(3, L10.End());
	L10.Insert(4, L10.End());
	L10.Insert(2, L10.End());
	L10.Insert(2, L10.End());
	L10.Insert(7, L10.End());
	cout << "The List : ";
	L10.printList();
	cout << "The RemoveOccurences2 : ";
	RemoveOccurences2(L10, 2, 2, 5);
	L10.printList();
	cout << "******************************************* \n";
	return 0;
}