#pragma once

#include <algorithm>
#include <stdexcept>


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

		T& At(size_t i)
		{
			if (i < count && i >= 0)
				return arr[i];
			else // Index is 300$
				throw std::out_of_range("Index is out of range.");
		}

		void Reserve(size_t newCapacity)
		{
			T* newArr = new T[newCapacity];
			std::copy(arr, arr + std::min(count, newCapacity), newArr);

			delete[] arr;
			arr = newArr;
			capacity = newCapacity;
		}

		void PushBack(T element)
		{
			if (capacity <= count)
				Reserve(capacity << 1);

			arr[count++] = element;
		}

		T PopBack()
		{
			T result = At(count - 1);
			--count;
			return result;
		}

		T& operator [](size_t i)
		{
			return At(i);
		}

		Vector<T>& operator +(T element)
		{
			PushBack(element);
			return *this;
		}

		void operator +=(T element)
		{
			PushBack(element);
		}
	};
}
