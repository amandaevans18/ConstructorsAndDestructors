#pragma once
template <typename T>
class tVector
{
	const static size_t GROWTH_FACTOR = 2;

	T *arr;                             // pointer to underlying array
	size_t arrSize;                     // stores the number of elements currently used
	size_t arrCapacity;                 // stores the capacity of the underlying array

public:
	tVector();                          // initializes the vector's default values
	~tVector();                         // destroys the underlying array

	T *data();                          // returns a pointer to the underlying array

	void reserve(size_t newCapacity);   // resizes the vector to at least this many elements

	void push_back(const T &value);     // adds an element to the end of the vector
	void pop_back();                    // drops the last element of the vector

	T &at(size_t index);                // returns the element at the given element

	size_t size() const;                // returns current number of elements
	size_t capacity() const;            // returns maximum number of elements we can store

	tVector(const tVector &vec); //copy constuctor

	tVector& operator=(const tVector &vec); // copy assignment

	T& operator[] (size_t index); //allow access to elements in arr without calling the at


	bool empty();         // Returns true if the vector contains no elements.
	void resize(size_t);  // Resizes the vector to contain the given number of elements.
	void shrink_to_fit(); // Resizes the vector's capacity to match its size.
	void clear();         // Empties the vector (all elements are destroyed in this process)
};

template<typename T>
inline tVector<T>::tVector()
{
	
}

template<typename T>
inline tVector<T>::~tVector()
{
	arrCapacity = 0;
	arrSize = 0;
	delete[] arr;
}

template<typename T>
inline T * tVector<T>::data()
{
	return *arr;
}

template<typename T>
inline void tVector<T>::reserve(size_t newCapacity)
{
	if (size > newCapacity) 
	{
		return; 
	}
	T *temp = new T[newCapacity]();
	for (int i = 0; i < newCapacity; i++) 
	{
		if (i < arrSize)
		{
			break;
		}
		else
		{
			temp[i] = arr[i];
		}
	}

	*arr = *temp;
	delete temp;

}

template<typename T>
inline void tVector<T>::push_back(const T & value)
{
	arrSize++;
	if (arrCapacity <= arrSize ) 
	{
		reserve(arrCapacity + 1);
	}
	else
	{
		arr[arrSize] = value;
	}
}

template<typename T>
inline void tVector<T>::pop_back()
{
	arr[arrSize - 1] = NULL;
}

template<typename T>
inline T & tVector<T>::at(size_t index)
{
	// TODO: insert return statement here
	return arr[index];
}

template<typename T>
inline size_t tVector<T>::size() const
{
	return arrSize;
}

template<typename T>
inline size_t tVector<T>::capacity() const
{
	return arrCapacity;
}

template<typename T>
inline tVector<T>::tVector(const tVector & vec)
{
	return arr = vec;
}

template<typename T>
inline tVector<T> & tVector<T>::operator=(const tVector & vec)
{
	// TODO: insert return statement her
	for (size_t i = 0; i < arrCapacity; i++)
	{
		arr[i] = vec[i];
	}
	arrCapacity = vec.arrCapacity;
	arrSize = vec, arrSize;
	return arr[i];
}

template<typename T>
inline T & tVector<T>::operator[](size_t index)
{
	// TODO: insert return statement here
	return arr.at(index);
}

template<typename T>
inline bool tVector<T>::empty()
{
	if (arrSize == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
inline void tVector<T>::resize(size_t)
{

}

template<typename T>
inline void tVector<T>::shrink_to_fit()
{
}

template<typename T>
inline void tVector<T>::clear()
{
}
