
#include"List.h"
#define tab "\t"
#define delimeter "\n------------------------------------------\n"
///////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////		Element         	 /////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>List<T>::Element::Element(T Data, Element* pNext, Element* pPrev)
	:Data(Data), pNext(pNext), pPrev(pPrev)
{
#ifdef DEBUG
	cout << "EConstructor:\t" << this << endl;
#endif // DEBUG
}
template<typename T>List<T>::Element::~Element()
{
#ifdef DEBUG
	cout << "EDestructor:\t" << this << endl;
#endif // DEBUG
}

///////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////		ConstBaseIterator	 /////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>List<T>::ConstBaseIterator::ConstBaseIterator(Element* Temp) :Temp(Temp)
{
#ifdef DEBUG
	cout << "CBItConstructor:\t" << this << endl;
#endif // DEBUG

}
template<typename T>List<T>::ConstBaseIterator:: ~ConstBaseIterator()
{
#ifdef DEBUG
	cout << "CBItConstructor:\t" << this << endl;
#endif // DEBUG
}

template<typename T> bool List<T>::ConstBaseIterator::operator==(const ConstBaseIterator& other)const
{
	return this->Temp == other.Temp;
}
template<typename T> bool List<T>::ConstBaseIterator::operator!=(const ConstBaseIterator& other)const
{
	return this->Temp != other.Temp;
}

template<typename T> const T& List<T>::ConstBaseIterator:: operator*()const
{
	return Temp->Data;
}


///////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////		ConstIterator 		   ///////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>List<T>::ConstIterator::ConstIterator(Element* Temp) :ConstBaseIterator(Temp)
{
#ifdef DEBUG
	cout << "CIItConstructor:\t" << this << endl;
#endif // DEBUG
}
template<typename T>List<T>::ConstIterator::~ConstIterator()
{
#ifdef DEBUG
	cout << "CIItDestructor:\t" << this << endl;
#endif // DEBUG
}
template<typename T>typename List<T>::ConstIterator& List<T>::ConstIterator::operator++()
{
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
	return *this;
}
template<typename T>typename List<T>::ConstIterator List<T>::ConstIterator::operator++(int)
{
	ConstIterator old = *this;
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
	return old;
}
template<typename T>typename List<T>::ConstIterator& List<T>::ConstIterator::operator--()
{
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
	return *this;
}
template<typename T>typename List<T>::ConstIterator List<T>::ConstIterator::operator--(int)
{
	ConstIterator old = *this;
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
	return old;

}


///////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////	ConstReverseIterator       ///////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////


template<typename T>List<T>::ConstReverseIterator::ConstReverseIterator(Element* Temp) :ConstBaseIterator(Temp)
{
#ifdef DEBUG
	cout << "CRItConstructor:\t" << this << endl;
#endif // DEBUG

}
template<typename T>List<T>::ConstReverseIterator::~ConstReverseIterator()
{
#ifdef DEBUG
	cout << "CRItDestructor:\t" << this << endl;
#endif // DEBUG

}

template<typename T>typename List<T>::ConstReverseIterator::ConstReverseIterator& List<T>::ConstReverseIterator::operator++()
{
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
	return *this;
}
template<typename T>typename List<T>::ConstReverseIterator::ConstReverseIterator& List<T>::ConstReverseIterator::operator++(int)
{
	ConstReverseIterator old = *this;
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
	return old;
}
template<typename T> typename List<T>::ConstReverseIterator::ConstReverseIterator& List<T>::ConstReverseIterator::operator--()
{
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
	return *this;
}
template<typename T> typename List<T>::ConstReverseIterator::ConstReverseIterator& List<T>::ConstReverseIterator::operator--(int)
{
	ConstReverseIterator old = *this;
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
	return old;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////				Iterator&ReverseIterator     /////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T> T& List<T>::Iterator:: operator*()
{
	return ConstBaseIterator::Temp->Data;
}
template<typename T> T& List<T>::ReverseIterator:: operator*()
{
	return ConstBaseIterator::Temp->Data;
}


///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////				List		///////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>typename List<T>::ConstIterator  List<T>::cbegin()const
{
	return Head;
}
template<typename T>typename List<T>::ConstIterator List<T>::cend()const
{
	return nullptr;
}
template<typename T>typename List<T>::ConstReverseIterator List<T>::crbegin()const
{
	return Tail;
}
template<typename T>typename List<T>::ConstReverseIterator List<T>::crend()const
{
	return nullptr;
}
template<typename T>typename List<T>::Iterator List<T>::begin()
{
	return Head;
}
template<typename T>typename List<T>::Iterator List<T>::end()
{
	return nullptr;
}
template<typename T>typename List<T>::ReverseIterator List<T>::rbegin()
{
	return Tail;
}
template<typename T>typename List<T>::ReverseIterator List<T>::rend()
{
	return nullptr;
}
template<typename T>List<T>::List()
{
	Head = Tail = nullptr;
	size = 0;
	cout << "LConstructor:\t" << this << endl;
}
template<typename T>List<T>::List(const initializer_list<T>& il) :List()
{
	//int* - указатель
	//const int* - константный указатель
	//int const* - указатель на константу
	//const int const* - константный указатель на константу
	for (T const* it = il.begin(); it != il.end(); ++it)
		push_back(*it);

	//for (T i : il)push_back(i);
}
template<typename T>List<T>::List(const List<T>& other) :List()
{
	//for (ConstIterator it = other.cbegin(); it != other.cend(); ++it)push_back(*it);
	*this = other;
	cout << "LCopyConstructor:\t" << this << endl;
}
template<typename T>List<T>::List(List<T>&& other) :List()
{
	*this = std::move(other);	//Функция move принудительно вызывает
	cout << "LMoveConstructor:\t" << this << endl;
}
template<typename T>List<T>::~List()
{
	//while (Head) pop_front();
	while (Tail)pop_back();
	cout << "LDestructor:\t" << this << endl;
}

//`				Operators
template<typename T>List<T>& List<T>:: operator=(const List<T>& other)
{
	if (this == &other)return *this;
	while (Head)pop_front();
	for (List<T>::ConstIterator it = other.cbegin(); it != other.cend(); ++it)
		push_back(*it);
	cout << "LCopyAssignment:\t" << this << endl;
	return *this;
}
template<typename T>List<T>& List<T>::operator=(List<T>&& other)noexcept
{
	if (this == &other)return *this;
	while (Head)pop_front();
	this->Head = other.Head;
	this->Tail = other.Tail;
	this->size = other.size;
	other.Head = nullptr;
	other.Tail = nullptr;
	other.size = 0;
	cout << "LMoveAssingnment:\t" << this << endl;
	return *this;
}

//				Adding Elements:
template<typename T>void List<T>::push_front(T Data)
{
	/*Element* New = new Element(Data);
	if (Head == nullptr && Tail == nullptr)
	{
		Head = Tail = New;
	}
	else
	{
		New->pNext = Head;
		Head->pPrev = New;
		Head = New;
	}*/
	if (Head == nullptr && Tail == nullptr)
		Head = Tail = new Element(Data);
	else
		Head = Head->pPrev = new Element(Data, Head);
	size++;
}
template<typename T>void List<T>::push_back(T Data)
{
	/*Element* New = new Element(Data);
	if (Head == nullptr && Tail == nullptr)
	{
		Head = Tail = New;
	}
	else
	{
		New->pPrev = Tail;
		Tail->pNext = New;
		Tail = New;
	}*/
	if (Head == nullptr && Tail == nullptr)
		Head = Tail = new Element(Data);
	else
		Tail = Tail->pNext = new Element(Data, nullptr, Tail);
	size++;
}
template<typename T>void List<T>::insert(T Data, int index)
{
	//if (index > size)return;
	if (index > size)throw  out_of_range("Error: Out of range exeption");
	//if (index > size)throw exception("Error: Out of range");
	//out_of_range - выход за пределы
	if (index == 0)return push_front(Data);
	if (index == size)return push_back(Data);

	Element* Temp;
	if (index < size / 2)
	{
		Temp = Head;
		for (int i = 0; i < index; i++)Temp = Temp->pNext;
	}
	else
	{
		Temp = Tail;
		for (int i = 0; i < size - index - 1; i++)Temp = Temp->pPrev;
	}
	/*Element* New = new Element(Data);
	New->pNext = Temp;
	New->pPrev = Temp->pPrev;
	Temp->pPrev->pNext = New;
	Temp->pPrev = New;*/
	Temp->pPrev = Temp->pPrev->pNext = new Element(Data, Temp, Temp->pPrev);
	size++;
}

//				Removing Elements:
template<typename T>void List<T>::pop_front()
{
	if (Head == nullptr && Tail == nullptr)return;
	if (Head == Tail)
	{
		delete Head;
		Head = Tail = nullptr;
	}
	else
	{
		Head = Head->pNext;
		delete Head->pPrev;
		Head->pPrev = nullptr;
	}
}
template<typename T>void List<T>::pop_back()
{
	if (Head == Tail)return pop_front();
	Tail = Tail->pPrev;
	delete Tail->pNext;
	Tail->pNext = nullptr;
	size--;
}
template<typename T>void List<T>::erase(int index)
{
	if (index >= size)throw out_of_range("Error: Out of range exeption in erase()");
	if (index == 0)return pop_front();
	//1. Доходим до удаляемого элемента
	Element* Temp;
	if (index < size / 2)
	{
		Temp = Head;
		for (int i = 0; i < index; i++)Temp = Temp->pNext;
	}
	else
	{
		Temp = Tail;
		for (int i = 0; i < size - index - 1; i++)Temp = Temp->pPrev;
	}
	//2. Исключаем элемент из списка
	Temp->pPrev->pNext = Temp->pNext;
	Temp->pNext->pPrev = Temp->pPrev;
	//3. Удаляем элемент из списка
	delete Temp;
	size--;
}
//				Methods:
template<typename T>void List<T>::print()const
{
	cout << "Head:" << Head << endl;
	for (Element* Temp = Head; Temp; Temp = Temp->pNext)
		cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
	cout << "Количество элементов: " << size << endl;
}
template<typename T>void List<T>::reverse_print()const
{
	cout << "Tail:" << Tail << endl;
	for (Element* Temp = Tail; Temp; Temp = Temp->pPrev)
		cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
	cout << "Количество элементов: " << size << endl;
}

template<typename T>List<T> operator+(const List<T>& left, const List<T>& right)
{
	List<T> cat = left;		//CopyComstructor
	for (typename List<T>::ConstIterator it = right.cbegin(); it != right.cend(); ++it)
	{
		cat.push_back(*it);
		//(*it) *= 100;
	}
	return cat;
}
