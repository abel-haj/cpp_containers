#ifndef		RANDOM_ITERATOR_VECTOR_HPP
# define	RANDOM_ITERATOR_VECTOR_HPP

// ptrdiff_t
# include <cstddef>
// # include <iostream>

#ifndef OUT
	#define OUT 0
#endif

namespace ft {

	template <class T,											// iterator::value_type
			class Category = std::random_access_iterator_tag,	// iterator::iterator_category
			class Distance = ptrdiff_t,						// iterator::difference_type
			class Pointer = T*,								// iterator::pointer
			class Reference = T&								// iterator::reference
			>
	class vector_iterator {

		public:
			typedef		Category		iterator_category;		// the first template parameter (Category)
			typedef		T				value_type;				// the second template parameter (T)
			typedef		ptrdiff_t		difference_type;		// the third template parameter (Distance)
			typedef		T			*	pointer;				// the fourth template parameter (Pointer)
			typedef		T			&	reference;				// the fifth template parameter (Reference)

		private:
			pointer		my_iterator;

		public:
			// default
			vector_iterator(void)
			{
				if (OUT)
					std::cout << "RNDM ITERATOR DEFAULT CONSTRUCTOR CALLED" << std::endl;
			}

			vector_iterator(pointer vec)
			{
				my_iterator = vec;
			}

			// copy constr
			vector_iterator(const vector_iterator & ri)
			{
				if (OUT)
					std::cout << "RNDM ITERATOR COPY CONSTRUCTOR CALLED" << std::endl;
				my_iterator = ri.my_iterator;
			}

			// copy assign
			vector_iterator operator=(const vector_iterator & rhs)
			{
				if (OUT)
					std::cout << "RNDM ITERATOR ASSIGNMENT OPERATOR CALLED" << std::endl;
				my_iterator = rhs.my_iterator;

				return *this;
			}

			// destruct
			~vector_iterator()
			{
				if (OUT)
					std::cout << "RNDM ITERATOR DESTRUCTOR CALLED" << std::endl;
			}

			pointer base()
			{
				return my_iterator;
			}

			bool operator==(const vector_iterator & rhs) const
			{
				return my_iterator == rhs.my_iterator;
			}

			bool operator!=(const vector_iterator & rhs) const
			{
				return my_iterator != rhs.my_iterator;
			}

			reference operator*()
			{
				return *my_iterator;
			}

			vector_iterator operator++(void)
			{
				my_iterator++;
				return *this;
			}

			vector_iterator operator++(int)
			{
				vector_iterator tmp;

				tmp = *this;
				my_iterator++;
				return tmp;
			}

			vector_iterator operator--(void)
			{
				my_iterator--;
				return *this;
			}

			vector_iterator operator--(int)
			{
				vector_iterator tmp;

				tmp = *this;
				my_iterator--;
				return tmp;
			}

			friend vector_iterator operator+(const vector_iterator & lhs, const int & n)
			{
				return (lhs.my_iterator + n);
			}
			friend vector_iterator operator+(const int & n, const vector_iterator & rhs)
			{
				return (rhs.my_iterator + n);
			}
			friend vector_iterator operator-(const vector_iterator & lhs, const int & n)
			{
				return (lhs.my_iterator - n);
			}

			friend difference_type operator-(const vector_iterator & lhs, const vector_iterator & rhs)
			{
				return (lhs.my_iterator - rhs.my_iterator);
			}

			friend bool operator<(const vector_iterator & lhs, const vector_iterator & rhs)
			{
				return lhs.my_iterator < rhs.my_iterator;
			}
			friend bool operator>(const vector_iterator & lhs, const vector_iterator & rhs)
			{
				return lhs.my_iterator > rhs.my_iterator;
			}
			friend bool operator<=(const vector_iterator & lhs, const vector_iterator & rhs)
			{
				return lhs.my_iterator <= rhs.my_iterator;
			}
			friend bool operator>=(const vector_iterator & lhs, const vector_iterator & rhs)
			{
				return lhs.my_iterator >= rhs.my_iterator;
			}

			vector_iterator operator+=(const int & n)
			{
				my_iterator += n;
				return *this;
			}
			vector_iterator operator-=(const int & n)
			{
				my_iterator -= n;
				return *this;
			}

			int operator[](const int & n) const
			{
				return my_iterator[n];
			}
	};

}

#endif