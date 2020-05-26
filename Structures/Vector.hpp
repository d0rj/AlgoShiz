#pragma once

#include <algorithm>


namespace AlgoShiz 
{
	template <typename T>
	class Vector
	{
	private:
		T* arr;
		size_t capacity;
		size_t count;
	public:
		Vector() : arr(new T[1]), capacity(1), count(0) {}
		Vector(size_t count, T placeholder = 0) : arr(new T[count]), capacity(count), count(count)
		{
			for (size_t i = 0; i < capacity; ++i)
				arr[i] = placeholder;
		}

		size_t Length() { return count; }

		void PushBack(T element)
		{
			if (capacity <= count)
			{
				T* newArr = new T[capacity << 1];
				std::copy(arr, arr + count, newArr);

				delete[] arr;
				arr = newArr;
				capacity <<= 1;
			}

			arr[count++] = element;
		}

		T& operator [](size_t i)
		{
			if (i < count)
				return arr[i];
			else
				throw 1;
		}

		Vector<T>& operator +(T element)
		{
			PushBack(element);
			return *this;
		}
	};
}
