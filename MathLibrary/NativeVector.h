#pragma once
#include <ostream>

namespace MathLibrary
{
	template <typename T>
	class NativeVector
	{
	private:
		int m_size;
		int m_capacity = 1;
		T* m_buffer = new T[m_capacity];
	public:
		NativeVector() : m_size{ 0 } {};
		~NativeVector() { delete[] m_buffer; };
		int size() { return m_size; };
		size_t byteSize() { return sizeof(T) * m_size; };

		void append(const T element)
		{
			if (m_capacity <= m_size)
			{
				auto t_buffer = std::move(m_buffer);
				m_buffer = new T[++m_size];
				std::move(t_buffer, t_buffer + m_size - 1, m_buffer);
				m_buffer[m_size - 1] = std::move(element);
				++m_capacity;
				delete[] t_buffer;
			}
			else
			{
				m_buffer[m_size++] = element;
			}
		}

		T pop() {};
		T merge() {};

		T const& operator[](const int i)
		{
			return m_buffer[i];
		}
		NativeVector& operator=(NativeVector&& other)
		{
			if (this != other)
			{
				delete[] m_buffer;
				m_size = other.m_size;
				m_capacity = other.m_capacity;
				m_buffer = std::move(other.m_buffer);

				other.m_capacity = 0;
				other.m_size= 0;
				other.m_buffer = nullptr;
			}
			return *this;
		}

		NativeVector& operator=(NativeVector& other)
		{
			if (this != other)
			{
				m_buffer = new T[m_capacity];
				m_size = other.m_size;
				m_capacity = other.m_capacity;
				for (int i = 0; i < m_size; i++)
				{
					m_buffer[i] = other.m_buffer[i];
				}
			}
			return *this;
		}

		/* TO DO */
		// Add pop and top option
		// Add use [-1] as last element
		// Add merge two vectors
	};

}
