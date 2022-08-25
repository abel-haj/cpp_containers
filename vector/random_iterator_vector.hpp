#ifndef		RANDOM_ITERATOR_VECTOR_HPP
# define	RANDOM_ITERATOR_VECTOR_HPP

// ptrdiff_t
# include <cstddef>
// # include <iostream>
# include "../other/iterator_traits.hpp"

#ifndef OUT
	#define OUT 0
#endif

namespace ft {

	template <class Iterator>
	class vector_iterator {

		public:
			typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;	// Preserves Iterator's category
			typedef typename ft::iterator_traits<Iterator>::value_type			value_type;			// Preserves Iterator's value type
			typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;	// Preserves Iterator's difference type
			typedef typename ft::iterator_traits<Iterator>::pointer				pointer;			// Preserves Iterator's pointer type
			typedef typename ft::iterator_traits<Iterator>::reference			reference;			// Preserves Iterator's reference type

		private:
			pointer		my_iterator;

		public:
			// default
			vector_iterator(void)
			{
				if (OUT)
					std::cout << "RNDM ITERATOR DEFAULT CONSTRUCTOR CALLED" << std::endl;
				my_iterator = NULL;
			}

			vector_iterator(pointer vec)
			{
				my_iterator = vec;
			}

			// copy constr
			template <class Iter>
			vector_iterator(const vector_iterator<Iter> & ri)
			{
				if (OUT)
					std::cout << "RNDM ITERATOR COPY CONSTRUCTOR CALLED" << std::endl;
				my_iterator = ri.base();
			}
			vector_iterator(const vector_iterator & ri)
			{
				if (OUT)
					std::cout << "RNDM ITERATOR COPY CONSTRUCTOR CALLED" << std::endl;
				my_iterator = ri.base();
			}

			// copy assign
			vector_iterator operator=(const vector_iterator & rhs)
			{
				if (OUT)
					std::cout << "RNDM ITERATOR ASSIGNMENT OPERATOR CALLED" << std::endl;
				my_iterator = rhs.base();

				return *this;
			}

			// destruct
			~vector_iterator()
			{
				if (OUT)
					std::cout << "RNDM ITERATOR DESTRUCTOR CALLED" << std::endl;
			}

			pointer base() const
			{
				return my_iterator;
			}

			reference operator*() const
			{
				return *my_iterator;
			}

			vector_iterator operator+ (difference_type n) const
			{
				vector_iterator tmp(my_iterator + n);
				return tmp;
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

			vector_iterator& operator+= (difference_type n)
			{
				my_iterator += n;
				return *this;
			}

			vector_iterator operator- (difference_type n) const
			{
				vector_iterator tmp(my_iterator - n);
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

			vector_iterator& operator-= (difference_type n)
			{
				my_iterator -= n;
				return *this;
			}

			reference operator[] (difference_type n) const
			{
				return my_iterator[n];
			}

			pointer operator->() const
			{
				return &(this->operator*());
			}

	};

	// (1)
	template <class Iterator>
	bool operator== (const vector_iterator<Iterator>& lhs,
					const vector_iterator<Iterator>& rhs)
					{
							return lhs.base() == rhs.base();
					}
	// (2)
	template <class Iterator>
	bool operator!= (const vector_iterator<Iterator>& lhs,
					const vector_iterator<Iterator>& rhs)
					{
							return lhs.base() != rhs.base();
					}
	// (3)
	template <class Iterator>
	bool operator<  (const vector_iterator<Iterator>& lhs,
					const vector_iterator<Iterator>& rhs)
					{
							return lhs.base() < rhs.base();
					}
	// (4)
	template <class Iterator>
	bool operator<= (const vector_iterator<Iterator>& lhs,
					const vector_iterator<Iterator>& rhs)
					{
							return lhs.base() <= rhs.base();
					}
	// (5)
	template <class Iterator>
	bool operator>  (const vector_iterator<Iterator>& lhs,
					const vector_iterator<Iterator>& rhs)
					{
							return lhs.base() > rhs.base();
					}
	// (6)
	template <class Iterator>
	bool operator>= (const vector_iterator<Iterator>& lhs,
					const vector_iterator<Iterator>& rhs)
					{
							return lhs.base() >= rhs.base();
					}

	template <class Iterator>
	vector_iterator<Iterator> operator+ (
		typename vector_iterator<Iterator>::difference_type n,
		const vector_iterator<Iterator>& vec_it)
		{
			return (vec_it + n);
		}

	template <class Iterator>
	typename vector_iterator<Iterator>::difference_type operator- (
		const vector_iterator<Iterator>& lhs,
		const vector_iterator<Iterator>& rhs)
		{
			return lhs.base() - rhs.base();
		}

};

#endif