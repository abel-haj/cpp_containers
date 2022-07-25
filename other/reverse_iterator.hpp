#ifndef			REVERSE_ITERATOR_VECTOR_HPP
# define		REVERSE_ITERATOR_VECTOR_HPP

// # include <cstddef>
# include "../other/iterator_traits.hpp"

namespace ft {

	template <class Iterator>
	class reverse_iterator {

		private:
			Iterator	_current;

		public:
			typedef Iterator													iterator_type;		// Iterator's type
			typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;	// Preserves Iterator's category
			typedef typename ft::iterator_traits<Iterator>::value_type			value_type;			// Preserves Iterator's value type
			typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;	// Preserves Iterator's difference type
			typedef typename ft::iterator_traits<Iterator>::pointer				pointer;			// Preserves Iterator's pointer type
			typedef typename ft::iterator_traits<Iterator>::reference			reference;			// Preserves Iterator's reference type

			// default (1)
			reverse_iterator() : _current()
			{
				// std::cout << "1" << std::endl;
			}
			// initialization (2)
			explicit reverse_iterator (iterator_type it) : _current(it)
			{
				// std::cout << "2" << std::endl;
			}
			// copy (3)
			template <class Iter>
			reverse_iterator (const reverse_iterator<Iter>& rev_it) : _current(rev_it.base())
			{
				// std::cout << "3" << std::endl;
			}

			iterator_type base() const
			{
				return _current;
			}

			reference operator*() const
			{
				// std::cout << "here 1" << std::endl;
				iterator_type tmp;
				tmp = _current;
				tmp--;
				return *tmp;
			}

			reverse_iterator operator+ (difference_type n) const
			{
				return _current - n;
			}

			reverse_iterator& operator++()
			{
				// std::cout << "here 2" << std::endl;
				_current--;
				return *this;
			}
			reverse_iterator  operator++(int)
			{
				reverse_iterator tmp(_current);
				_current--;
				return tmp;
			}

			reverse_iterator operator- (difference_type n) const
			{
				return _current + n;
			}

			reverse_iterator& operator+= (difference_type n)
			{
				_current -= n;

				return *this;
			}

	};

};

#endif