#ifndef CSmartPtr
#define CSmartPtr
#include "CRefCounter.h"
//zad 1
template <typename T> class CMySmartPointer
{
public:
	CMySmartPointer(T *pcPointer)
	{
		pc_pointer = pcPointer;
		pc_counter = new CRefCounter();
		pc_counter->iAdd();
	}
	CMySmartPointer(const CMySmartPointer &pcOther)
	{
		pc_pointer = pcOther.pc_pointer;
		pc_counter = pcOther.pc_counter;
		pc_counter->iAdd();
	}
	~CMySmartPointer()
	{
		if (pc_counter->iDec() == 0)
		{
			delete pc_pointer;
			delete pc_counter;
		}
	}

	T& operator*() { return(*pc_pointer); }
	T* operator->() { return(pc_pointer); }
	//zad 2 
	void operator=(const CMySmartPointer &pcother) 
	{
		this->~CMySmartPointer();
		this->pc_counter = pcother.pc_counter;
		this->pc_pointer = pcother.pc_pointer;
	}
private:
	CRefCounter *pc_counter;
	T *pc_pointer;
};

#endif CSmartPtr