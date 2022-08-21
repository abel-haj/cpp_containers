#ifndef		FT_BIDIRECTIONAL_ITERATOR_MAP_HPP
# define	FT_BIDIRECTIONAL_ITERATOR_MAP_HPP

# include "iterator_traits.hpp"

namespace ft {

	template <class Node, class T>
	class map_iterator {

	public:
		// typedef typename ft::map_iterator_traits<Iterator>::iterator_category	iterator_category;
		// typedef typename ft::map_iterator_traits<Iterator>::value_type			value_type;
		// typedef typename ft::map_iterator_traits<Iterator>::difference_type		difference_type;
		// typedef typename ft::map_iterator_traits<Iterator>::pointer				pointer;
		// typedef typename ft::map_iterator_traits<Iterator>::reference			reference;

		typedef	T		value_type;
		typedef	Node	node_type;
		typedef	Node *	pointer_type;

	private:
		pointer_type			_top;
		pointer_type			_last;
		pointer_type			_current;

	public:
		map_iterator()
		: _top(NULL), _last(NULL), _current(NULL) {}

		map_iterator(pointer_type t, pointer_type l, pointer_type c)
		: _top(t), _last(l), _current(c) {}

		map_iterator(const map_iterator & ri)
		{
			_top = ri._top;
			_last = ri._last;
			_current = ri._current;
		}

		map_iterator & operator=(const map_iterator & rhs)
		{
			_top = rhs._top;
			_last = rhs._last;
			_current = rhs._current;
		}

		~map_iterator() {}

		bool operator==(const map_iterator & rhs)
		{
			return _current == rhs._current;
		}

		bool operator!=(const map_iterator & rhs)
		{
			return !(*this == rhs);
		}

		value_type&		operator*() const
		{
			return *_current->current;
		}

		map_iterator	operator--()
		{

		}
		map_iterator	operator++()
		{
			_current = _current->parent;
		}

		map_iterator	operator--(int);
		map_iterator	operator++(int);
		value_type*		operator->() const;

	};

};

#endif