#include<iostream>

template<class T>
int Min(T a, T b) 
{
	if (a < b) 
	{
		return a;
	}
	else 
	{
		return b;
	}
}


template<class T>
int Max(T a, T b)
{
	if (a > b )
	{
		return a;
	}
	else
	{
		return b;
	}
}

int main() 
{


	return 0;
}