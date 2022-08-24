#ifndef		FT_BIDIRECTIONAL_ITERATOR_MAP_HPP
# define	FT_BIDIRECTIONAL_ITERATOR_MAP_HPP

# include "iterator_traits.hpp"

namespace ft {

	template <class Node, class T>
	class map_iterator {

	public:
		typedef typename ft::map_iterator_traits<T*>::iterator_category	iterator_category;
		typedef typename ft::map_iterator_traits<T*>::value_type		value_type;
		typedef typename ft::map_iterator_traits<T*>::difference_type	difference_type;
		typedef typename ft::map_iterator_traits<T*>::pointer			pointer;
		typedef typename ft::map_iterator_traits<T*>::reference			reference;
		typedef map_iterator<Node, const T>								const_iterator;

		// typedef	T		value_type;
		typedef	Node	node_type;
		typedef	Node *	pointer_type;

		pointer_type			_top;
		pointer_type			_last;
		pointer_type			_pos;
	private:

	public:
		map_iterator()
		: _top(NULL), _last(NULL), _pos(NULL) {}

		map_iterator(const pointer_type t, const pointer_type l, const pointer_type c)
		: _top(t), _last(l), _pos(c) {}

		map_iterator(const map_iterator & ri)
		{
			*this = ri;
		}

		map_iterator & operator=(const map_iterator & rhs)
		{
			_top = rhs._top;
			_last = rhs._last;
			_pos = rhs._pos;
			return *this;
		}

		~map_iterator() {}

		pointer_type getT() const
		{ return _top; }
		pointer_type getL() const
		{ return _last; }
		pointer_type getP() const
		{ return _pos; }

		operator const_iterator()
		{
			return const_iterator(_top, _last, _pos);
		}

		bool operator==(const map_iterator & rhs) const
		{
			return _pos == rhs._pos;
		}

		bool operator!=(const map_iterator & rhs) const
		{
			return !(_pos == rhs._pos);
			// return !(*this == rhs);
		}
		bool operator!=(const_iterator & rhs) const
		{
			return !(_pos == rhs._pos);
			// return !(*this == rhs);
		}

		reference		operator*() const
		{
			return *(_pos->current);
		}

		map_iterator	operator--()
		{
			if (_pos == _last)
			{
				_pos = _last->parent;
			}

			else if (_pos && _pos->left) // protect
			{
				_pos = _pos->left;
				// deepest on right
				while (_pos->right != NULL)
					_pos = _pos->right;
			}

			else if (_pos)
			{
				pointer_type tmp = _pos->parent;

				while (tmp != NULL && _pos == tmp->left)
				{
					_pos = tmp;
					tmp = tmp->parent;
				}

				_pos = tmp;
			}

			return *this;
		}
		map_iterator	operator++()
		{
			if (_pos && _pos->right) // protect
			{
				_pos = _pos->right;
				// deepest on left
				while (_pos->left != NULL)
					_pos = _pos->left;
			}
			else if (_pos)
			{
				pointer_type tmp = _pos->parent;

				while (tmp != NULL && _pos == tmp->right)
				{
					_pos = tmp;
					tmp = tmp->parent;
				}
				_pos = tmp;
			}
			if(_pos == NULL)
			{
				_pos = _last;
 			}
			return *this;
		}

		map_iterator	operator--(int)
		{
			map_iterator tmp = *this;
			--(*this);
			return tmp;
		}
		map_iterator	operator++(int)
		{
			map_iterator tmp = *this;
			++(*this);
			return tmp;
		}

		pointer		operator->() const
		{
			return (_pos->current);
			return &(operator*());
		}

		// template<class NN, class TT>
		
		// {
		// 	lhs._top = rhs._top;
		// 	lhs._last = rhs._last;
		// 	lhs._pos = rhs._pos;
		// 	return lhs;
		// }

	};

	template<class NN, class TT>
	bool operator!=(
			map_iterator<NN, TT> & lhs,
			const map_iterator<NN, TT> & rhs)
	{
		return lhs.getP() != rhs.getP();
	}
	template<class NN, class TT>
	bool operator!=(
			const map_iterator<NN, TT> & lhs,
			map_iterator<NN, TT> & rhs)
	{
		return lhs.getP() != rhs.getP();
	}
	template<class NN, class TT>
	bool operator!=(
			map_iterator<NN, TT> & lhs,
			map_iterator<NN, TT> & rhs)
	{
		return lhs.getP() != rhs.getP();
	}
	template<class NN, class TT>
	bool operator!=(
			const map_iterator<NN, TT> & lhs,
			const map_iterator<NN, TT> & rhs)
	{
		return lhs.getP() != rhs.getP();
	}

};

#endif