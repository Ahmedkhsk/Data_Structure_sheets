//Stack
#include<iostream>
using namespace std;

//Array-Bassed Stack implementation

typedef int ElementType;
typedef int position;

class stack_array
{
private:
    int capacity;
    position top;
    ElementType* elements;
public:
    stack_array(int sizee = 10)
    {
        elements = new ElementType[sizee];
        top = -1;
        capacity = sizee;
    }
    bool isEmpty()
    {
        return top == -1;
    }
    bool isFull()
    {
        return top == capacity - 1;
    }
    void push(ElementType x)
    {
        if (isFull())
            cout << "Error : The Stack Is Full" << endl;
        else
            elements[++top] = x;
    }
    ElementType pop()
    {
        if (isEmpty())
        {
            cout << "Error : The Stack Is Empty" << endl;
            return -1;
        }
        else
            return elements[top--];
    }
    ElementType topp()
    {
        if (isEmpty())
        {
            cout << "Error : The Stack Is Empty" << endl;
            return -1;
        }
        else
            return elements[top];
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
            return -1;
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
            return -1;
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

//==========================================================================================

//Application

void check_Brackets(string s)
{
    stack_ll st;
    bool ok = true;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '}' || s[i] == ']' || s[i] == ')')
        {
            if (st.isEmpty_ll())
                ok = false;
            else
            {
                if (s[i] == '}' && st.topp_ll() != '{')
                    ok = false;
                if (s[i] == ']' && st.topp_ll() != '[')
                    ok = false;
                if (s[i] == ')' && st.topp_ll() != '(')
                    ok = false;
                st.pop_ll();
            }
        }
        else
        {
            if (s[i] == '{' || s[i] == '[' || s[i] == '(')
                st.push_ll(s[i]);
        }
    }
    if (!ok || !st.isEmpty_ll())
        cout << "The check_Brackets ---> Incorrect" << endl;
    else
        cout << "The check_Brackets ---> Correct" << endl;
}

int postfix(char ch[], int n) //implement a function for evaluating postfix expressions.
{
    stack_array s(n);
    for (int i = 0; i < n; i++)
    {
        if (isdigit(ch[i]))
            s.push(ch[i] - '0');
        else
        {
            if (s.isEmpty())
            {
                cout << "Error in expression : " << endl;
                return 0;
            }
            int a = s.pop();
            if (s.isEmpty())
            {
                cout << "Error in expression : " << endl;
                return 0;
            }
            int b = s.pop();
            if (ch[i] == '+')
                s.push(a + b);
            else if (ch[i] == '-')
                s.push(a - b);
            else if (ch[i] == '*')
                s.push(a * b);
            else if (ch[i] == '/')
                s.push(a / b);
        }
    }
    return s.pop();
}

void convert_dec_to_bin(int x) //implement a function for converting decimal to binary.
{
    stack_ll st;
    int rem;
    while (x != 0)
    {
        rem = x % 2;
        st.push_ll(rem);
        x /= 2;
    }
    while (!st.isEmpty_ll())
        cout << st.pop_ll();
    cout << endl;
}
void rearrange(stack_ll& st) //Implement a function to rearrange stack to make even at bottom and odd at top.
{
    stack_ll sE, sO;
    while (!st.isEmpty_ll())
    {
        int a = st.pop_ll();
        if (a % 2 == 0)
            sE.push_ll(a);
        else
            sO.push_ll(a);
    }
    st.makenull();
    while (!sE.isEmpty_ll())
        st.push_ll(sE.pop_ll());
    while (!sO.isEmpty_ll())
        st.push_ll(sO.pop_ll());
}
int main()
{
    //---------------------------------------
    check_Brackets("[(5+x)−(y+z)]");
    check_Brackets("( )(( `)){([( )])}");
    check_Brackets("((( )(( )){([( )])}))");
    check_Brackets(")(( )){([( )])}");
    check_Brackets("(({[ ])}");
    check_Brackets("(");
    //---------------------------------------
    cout << "*****************************************" << endl;
    //---------------------------------------
    char c[] = { '5','7','+','4','2','*','+' };
    cout << "Evaluating Postfix Expressions ---> " << postfix(c, 7) << endl;
    //---------------------------------------
    cout << "*****************************************" << endl;
    //---------------------------------------
    convert_dec_to_bin(13);
    //---------------------------------------
    cout << "*****************************************" << endl;
    //---------------------------------------
    stack_ll stt;
    stt.push_ll(1);
    stt.push_ll(2);
    stt.push_ll(3);
    stt.push_ll(4);
    stt.push_ll(5);
    stt.push_ll(6);
    stt.push_ll(7);
    stt.push_ll(8);
    stt.push_ll(9);
    stt.push_ll(10);
    rearrange(stt);
    stt.printstack();
    return 0;
}
