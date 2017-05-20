#include "Pile.h"

Pile::Pile()
{
	HowMuchElements = 0;
}
Pile::~Pile()
{

}
code Pile::push(const StackSort &val)
{
	if (!full())
	{
		StackArray[HowMuchElements++] = val;
		return Success;
	}
	else
	{
		return overload;
	}
}

code Pile::pop()
{
	if (!empty())
	{
		HowMuchElements--;
		return Success;
	}
	else
	{
		return Empty;
	}
}

code Pile::top(StackSort &val)const
{
	if (!empty())
	{
		val = StackArray[HowMuchElements - 1];
	}
	else
	{
		return Empty;
	}
}

code Pile::secondTop(StackSort &val)const
{
	if (!empty())
	{
		val = StackArray[HowMuchElements - 2];
		return Success;
	}
	else
	{
		return Empty;
	}
}

code Pile::printStack()const
{
	
	if (!empty())
	{
		cout << endl << "Here the Stack is Print" << endl;

		for (int cnt = HowMuchElements; cnt > 0; cnt--)
			cout <<"the case "<<cnt<<" contain the value "<< StackArray[cnt - 1] <<endl;
			
		cout << endl;
		return Success;
		
	}
	else
	{
		return Empty;
	}
}

code Pile::trashStack()
{
	if (!empty())
	{
		do
		{
			pop();
		} while (!empty());
		return Empty;
	}
}

bool Pile::full()const
{
	if (HowMuchElements == tailleMax)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Pile::empty()const
{
	if (HowMuchElements == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Pile::GetHowMuchElements()const
{
	return HowMuchElements;
}
