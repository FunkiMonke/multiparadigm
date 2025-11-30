#include "intlist.h"

// Constructor
Intlist :: Intlist() : Head(nullptr)
{
}

// Destructor

Intlist :: ~Intlist()
{
    Node* temp;
    while (Head != nullptr)
	{
    	temp = Head;
    	Head = Head -> Next;
    	delete temp;
	}
}

// Tests

bool Intlist :: Empty() const
{
	return (Head == nullptr) ? true : false;
}

// Insert (simple insert at beginning)

bool Intlist :: Insert(const int& new_element)
{
	Node* new_node;
	new_node = new Node;
	new_node -> Element = new_element;
	new_node -> Next = Head;
	Head = new_node;
	return true;
}

// Delete

bool Intlist :: Delete(const int& del_element)
{
	Node* temp;
	Node* previous;

	if (Empty()) 
		return false;
	else if (Head -> Element == del_element)
	{
		temp = Head;
		Head = Head -> Next;
		delete temp;
		return true;
	}
	else if (Head -> Next == nullptr)
		return false;
	else 
	{
		previous = Head;
		temp = Head -> Next;
		while ((temp -> Element != del_element) &&
			(temp -> Next != nullptr))
		{
		previous = temp;
		temp = temp -> Next;
		}
		if (temp -> Element == del_element)
		{
		previous -> Next = temp -> Next;
		delete temp;
		return true;
		}
		else  // list exhausted
		return false;
	}
}

// Print

void Intlist :: Print(ostream& out_stream) const
{
	Node* temp;
	temp = Head;
	while (temp != nullptr)
	{
		out_stream << temp -> Element << " ";
		temp = temp -> Next;
	}
}

// Overloaded output operator

ostream& operator<<(ostream& out_stream,
                    const Intlist& out_list)
{
	out_list.Print(out_stream);
	return out_stream;
}

int Intlist::getHead()
{
	return Head->Element;
}

void Intlist::doubleElements()
{
	Node* temp = Head;
	while (temp!=nullptr)
	{
		temp->Element = temp->Element*2;
		temp = temp->Next;
	}
	delete temp;
}

int Intlist::count()
{
	int count = 0;
	Node* temp = Head;
	while (temp!=nullptr)
	{
		count++;
		temp = temp->Next;
	}
	return count;
}

int Intlist::valueAt(const int index)
{
	Node* temp = Head;
	for (int i = 0; i < index; i++)
	{
		temp = temp->Next;
	}

	return temp->Element;
}

int Intlist::occurs(const int i)
{
	Node* temp = Head;
	int count =0;
	while (temp!= nullptr)
	{
		if (temp->Element==i)
		{
			count++;
		}
		temp=temp->Next;
	}
	return count;
}

bool Intlist::insertAtEnd(int n)
{
	Node* temp = Head;
	Node* prev = temp;
	while (temp!=nullptr)
	{
		prev = temp;
		temp = temp->Next;
	}
	
	Node* nn = new Node(n, nullptr);
	prev->Next = nn;
	return true;
}