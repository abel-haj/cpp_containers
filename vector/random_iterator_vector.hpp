#ifndef		RANDOM_ITERATOR_VECTOR_HPP
# define	RANDOM_ITERATOR_VECTOR_HPP

// ptrdiff_t
# include <iostream>

namespace ft {
	template <class T,											// iterator::value_type
			class Category = std::random_access_iterator_tag,	// iterator::iterator_category
			class Distance = ptrdiff_t,						// iterator::difference_type
			class Pointer = T*,								// iterator::pointer
			class Reference = T&								// iterator::reference
			>
		class random_iterator {

		public:
			typedef		Category		iterator_category;		// the first template parameter (Category)
			typedef		T				value_type;				// the second template parameter (T)
			typedef		ptrdiff_t		difference_type;		// the third template parameter (Distance)
			typedef		T			*	pointer;				// the fourth template parameter (Pointer)
			typedef		T			&	reference;				// the fifth template parameter (Reference)

			pointer		my_iterator;
			

			// default
			random_iterator(void) {}

			random_iterator(pointer vec)
			{
				my_iterator = vec;
			}

			// copy constr
			random_iterator(const random_iterator & ri)
			{
				*this = ri;
			}

			// copy assign
			random_iterator operator=(const random_iterator & rhs)
			{
				my_iterator = rhs.my_iterator;

				return *this;
			}

			// destruct
			~random_iterator() {}

			bool operator==(const random_iterator & rhs)
			{
				return *my_iterator == *rhs.my_iterator;
			}

			bool operator!=(const random_iterator & rhs)
			{
				return *my_iterator != *rhs.my_iterator;
			}

			reference operator*()
			{
				return *my_iterator;
			}

			random_iterator operator++(void)
			{
			}

			random_iterator operator++(int)
			{}

	};

}

/*
https://en.cppreference.com/w/cpp/language/operators

https://stackoverflow.com/questions/68212323/implementing-an-iterator-something-like-from-stl-for-my-own-custom-vector-temp

Is default-constructible, copy-constructible, copy-assignable and destructible

X a;
X b(a);
b = a;
*/

#endif