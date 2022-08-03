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
			{}
			// initialization (2)
			explicit reverse_iterator (iterator_type it) : _current(it)
			{}
			// copy (3)
			template <class Iter>
			reverse_iterator (const reverse_iterator<Iter>& rev_it) : _current(rev_it.base())
			{}

			iterator_type base() const
			{
				return _current;
			}

			reference operator*() const
			{
				iterator_type tmp;
				tmp = _current;
				tmp--;
				return *tmp;
			}

			reverse_iterator operator+ (difference_type n) const
			{
				reverse_iterator tmp(_current - n);
				return tmp;
			}

			reverse_iterator& operator++()
			{
				_current--;
				return *this;
			}
			reverse_iterator  operator++(int)
			{
				reverse_iterator tmp(_current);
				_current--;
				return tmp;
			}

			reverse_iterator& operator+= (difference_type n)
			{
				_current -= n;

				return *this;
			}

			reverse_iterator operator- (difference_type n) const
			{
				reverse_iterator tmp(_current + n);
				return tmp;
			}

			reverse_iterator& operator--()
			{
				_current++;
				return *this;
			}
			reverse_iterator  operator--(int)
			{
				reverse_iterator tmp(_current);
				_current++;
				return tmp;
			}

			reverse_iterator& operator-= (difference_type n)
			{
				_current += n;
				return *this;
			}

			pointer operator->() const
			{
				return &(this->operator*());
			}

			reference operator[] (difference_type n) const
			{
				return _current[-n - 1];
			}

	};

	// (1)
	template <class Iterator>
	bool operator== (const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs)
					{
						return (lhs.base() == rhs.base());
					}
	// (2)
	template <class Iterator>
	bool operator!= (const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs)
					{
						return !(lhs == rhs);
					}
	// (3)
	template <class Iterator>
	bool operator<  (const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs)
					{
						return (lhs.base() > rhs.base());
					}
	// (4)
	template <class Iterator>
	bool operator<= (const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs)
					{
						return (lhs.base() >= rhs.base());
					}
	// (5)
	template <class Iterator>
	bool operator>  (const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs)
					{
						return !(lhs < rhs) && (lhs != rhs);
					}
	// (6)
	template <class Iterator>
	bool operator>= (const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs)
					{
						return !(lhs < rhs);
					}

	template <class Iterator>
	reverse_iterator<Iterator> operator+ (
			typename reverse_iterator<Iterator>::difference_type n,
			const reverse_iterator<Iterator>& rev_it)
			{
				reverse_iterator<Iterator> new_it (rev_it.base() - n);
				return new_it;
			}

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator- (
		const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs)
		{
			return (rhs.base() - lhs.base());
		}

};

#endif