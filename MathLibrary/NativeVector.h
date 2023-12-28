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

		T* end() { return m_buffer + m_size; };

	public:
		NativeVector() : m_size{ 0 } {};
		template<size_t N>
		NativeVector(const T (& array)[N])
		{
			m_size = N;
			m_buffer = new T[m_size];
			m_capacity = m_size;
			std::move(array, array + m_size, m_buffer);
		}
		~NativeVector() { delete[] m_buffer; };

		int size() const { return m_size; };
		size_t byteSize() const { return sizeof(T) * m_size; };
		void append(const T element) noexcept
		{
			if (m_capacity <= m_size)
			{
				auto t_buffer = std::move(m_buffer);
				m_buffer = new T[++m_size];
				std::move(t_buffer, t_buffer + m_size - 1, m_buffer);
				m_buffer[m_size - 1] = element;
				++m_capacity;
				delete[] t_buffer;
			}
			else
			{
				m_buffer[m_size++] = element;
			}
		}

		template<size_t N>
		void appendArray(const T(&array)[N]) noexcept
		{
			if (m_capacity <= m_size + N)
			{
				auto t_buffer = std::move(m_buffer);
				m_size = m_size + N;
				m_buffer = new T[m_size];
				std::move(t_buffer, t_buffer + m_size - N, m_buffer);
				m_capacity = m_size;
				delete[] t_buffer;
			}
			std::move(array, array + N, m_buffer + m_size - N);
		}

		void merge(const NativeVector<T>& other)
		{
			if (*this != other)
			{
				auto t_buffer = std::move(m_buffer);
				m_buffer = new T[m_size + other.m_size];
				std::move(t_buffer, t_buffer + m_size, m_buffer);
				delete[] t_buffer;

				std::copy(other.m_buffer, other.m_buffer + other.m_size, m_buffer + m_size);
				m_size += other.m_size;
				m_capacity = m_size;
			}
		};

		T const& operator[](const int i)
		{
			if (i >= m_size || i < -m_size)
			{
				throw std::out_of_range("Out of range");
			}
			if (i >= 0)
				return m_buffer[i];
			else
				return *(this->end() + i);
		}
		NativeVector& operator=(NativeVector&& other) noexcept
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

		NativeVector& operator=(NativeVector& other) noexcept
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

		bool operator!=(const NativeVector& other)
		{
			return !(*m_buffer == *other.m_buffer);
		}
	};

}
