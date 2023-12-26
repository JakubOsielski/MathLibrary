#pragma once
#include <ostream>

namespace MathLibrary
{
	template<typename T>
	concept Stremable = requires (T t, std::ostream & os)
	{
		os << t;
	};

	template <Stremable T1, Stremable T2>
	class NativePair
	{
	private:
		T1 m_key;
		T2 m_value;

	public:
		NativePair(const T1 key, const T2 value) : m_key{ key }, m_value{ value } {};
		~NativePair() {};



		friend 	std::ostream& operator<<(std::ostream& os, const NativePair<T1, T2>& n_pair) {
			os << "(" << n_pair.m_key << ", " << n_pair.m_value << ")";
			return os;
		}

	};

}