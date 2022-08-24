#ifndef		FT_PAIR_HPP
# define	FT_PAIR_HPP

namespace ft {

	template <class T1, class T2>
	struct pair {

		typedef		T1		first_type;
		typedef		T2		second_type;

		first_type			first;
		second_type			second;

		// default (1)
		pair() : first(), second()
		{}
		// copy (2)
		template<class U, class V>
		pair (const pair<U,V>& pr) : first(pr.first), second(pr.second)
		{}
		// initialization (3)
		pair (const first_type& a, const second_type& b) : first(a), second(b)
		{}

		// note	
		// implicitly declared:
		// copy (1)
		pair& operator= (const pair& pr)
		{
			first = pr.first;
			second = pr.second;
			return *this;
		}

	};

	// (1)
	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first == rhs.first) && (lhs.second == rhs.second);
	}
	// (2)
	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(lhs == rhs);
	}
	// (3)
	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first < rhs.first) || (!(lhs.first < rhs.first) && lhs.second < rhs.second);
	}
	// (4)
	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(rhs < lhs);
	}
	// (5)
	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (rhs < lhs);
	}
	// (6)
	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(lhs < rhs);
	}

};

#endif