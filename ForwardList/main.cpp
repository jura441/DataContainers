#include<iostream>
using namespace std;
#define tab "\t"
class Element
{
	int Data;		//значение элемента
	Element* pNext;	//адрес следующего элемента
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		cout << "EDestructor:\t" << this << endl;
	}
	friend class ForwardList;
};

class ForwardList
{
	Element* Head;		//голова списка
public:
	ForwardList()
	{
		Head = nullptr;		//Когда голова списка указывает на 0 - спискок пуст
		cout << "LConstructor:\t" << this << endl;
	}
	~ForwardList()
	{
		cout << "LDestructor:\t" << this << endl;
	}

	//			Adding Elements:
	void push_front(int Data)
	{
		//1.Создаем новый элемент
		Element* New = new Element(Data);
		//2. Присоединяем новый элемент к началу списка
		New->pNext = Head;
		//3. Говорим, что новый элемент является головой списка
		Head = New;

	}
	/*void push_back(int Data)
	{
		Element* Temp = Head;
		while (Temp)
		{
			Temp = Temp->pNext;
		}
		Element* New = new Element(Data);
		Temp->pNext = 0;
	}*/

	void pop_front()
	{
		Element* del = Head;
		Head = Head->pNext;
		delete del;

	}

	//			Methods
	void print()const
	{
		Element* Temp = Head;		//Temp - это итератор
		while (Temp)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;		//Переход на следующий элемент
		}
	}
};

void main()
{
	setlocale(LC_ALL, "");

	int n;
	cout << "Введите размер списка: "; cin >> n;
	ForwardList list;	//Односвязный список list
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);
		//list.push_back(rand() % 100);
	}
	list.print();
	list.pop_front();
	list.print();

}