#ifndef			FT_MAP_HPP
# define		FT_MAP_HPP

// # include "../pair/pair.hpp"
# include "../pair/make_pair.hpp"	// includes pair.hpp
# include "../other/iterator_traits.hpp"
# include "../other/reverse_iterator.hpp"
# include <functional> // less
# include <memory> // allocator
# include "base_map.hpp"
# include "bidirectional_iterator_map.hpp"
# include "../other/equal.hpp"
# include "../other/lexicographical_compare.hpp"

namespace ft {

	template < class Key,										// map::key_type
				class T,										// map::mapped_type
				class Compare = std::less<Key>,					// map::key_compare
				class Alloc = std::allocator< ft::pair<const Key,T> >		// map::allocator_type
				>
	class map {

		public:
			typedef				Key											key_type;
			typedef				T											mapped_type;
			typedef				Compare										key_compare;
			typedef				Alloc										allocator_type;
			typedef				ft::pair<const key_type, mapped_type>		value_type;
			typedef				ft::pair<const key_type, const mapped_type>	const_value_type;
			typedef				Avl_Node<value_type>						node_type;
			typedef				ft::avl_tree<key_type, mapped_type, key_compare, Alloc>	base_map;
			typedef typename	allocator_type::reference					reference;
			typedef typename	allocator_type::const_reference				const_reference;
			typedef typename	allocator_type::pointer						pointer;
			typedef typename	allocator_type::const_pointer				const_pointer;
			typedef typename	ft::map_iterator<node_type, value_type>		iterator;
			typedef typename	ft::map_iterator<node_type, const_value_type>	const_iterator;
			typedef				ft::reverse_iterator<iterator>				reverse_iterator;
			typedef				ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			// typedef typename	iterator_traits<iterator>::difference_type	difference_type;
			typedef				size_t										size_type;

		private:
			size_type					_size;
			allocator_type				_alloc_type;
			key_compare					_comp_func;
			std::allocator< node_type >	_alloc_node;
			base_map					_base_map;

		public:
			void print()
			{
				_base_map.print();
			}

			// [ CONSTRUCTORS ]
			// empty (1)
			explicit map (const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type())
						: _size(0), _alloc_type(alloc), _comp_func(comp)
						{}
			// range (2)
			template <class InputIterator>
			map (InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
				: _size(0), _alloc_type(alloc), _comp_func(comp)
				{
					while (first != last)
					{
						insert(*first);
						first++;
					}
				}
			// copy (3)
			map (const map& x) // elements // allocator // comparator
			{
				*this = x;
			}
			// [ CONSTRUCTORS ]

			// [ DESTRUCTOR ]
			~map() {}
			// [ DESTRUCTOR ]

			// [ COPY CONSTRUCTOR ]
			map& operator= (const map& x)
			{
				_base_map = x._base_map;
				_comp_func = x._comp_func;
				_alloc_node = x._alloc_node;
				_alloc_type = x._alloc_type;
				_size = x._size;

				return *this;
			}
			// [ COPY CONSTRUCTOR ]

			// [ ITERATORS ]
				  iterator begin()
				{
					if (empty())
						return end();
					return iterator(_base_map._top, _base_map._last, _base_map.deepest_left(_base_map._top));
				}
			const_iterator begin() const
			{
				if (empty())
					return end();
				return const_iterator(_base_map._top, _base_map._last, _base_map.deepest_left(_base_map._top));
			}

				  iterator end()
				{
					return iterator(_base_map._top, _base_map._last, _base_map._last);
				}
			const_iterator end() const
			{
				return const_iterator(_base_map._top, _base_map._last, _base_map._last);
			}

				  reverse_iterator rbegin()
			{
				return reverse_iterator(end());
			}

			const_reverse_iterator rbegin() const
			{
				return const_reverse_iterator(end());
			}

				  reverse_iterator rend()
				{
					return reverse_iterator(begin());
				}
			const_reverse_iterator rend() const
			{
				return const_reverse_iterator(begin());
			}
			// [ ITERATORS ]

			// [ CAPACITY ]
			bool empty() const { return (_size == 0); }

			size_type size() const { return _size; }

			size_type max_size() const { return _alloc_type.max_size(); }
			// [ CAPACITY ]

			// [ ELEMENT ACCESS ]
			mapped_type& operator[] (const key_type& k);
			// [ ELEMENT ACCESS ]

			// [ MODIFIERS ]
			// single element (1)
			pair<iterator,bool> insert (const value_type& val)
			{
				bool ret;

				ret = _base_map.insert(val);
				if (ret)
					_size++;
				node_type * found = _base_map.find(val.first);
				return ft::make_pair(iterator(_base_map._top, _base_map._last, found), ret);
			}
			// with hint (2)
			iterator insert (iterator position, const value_type& val)
			{
				return insert(val);
			}
			// range (3)
			template <class InputIterator>
			void insert (InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					insert(*first);
					first++;
				}
			}

			// (1)
			void erase (iterator position)
			{
				erase((*position).first);
			}
			// (2)
			size_type erase (const key_type& k)
			{
				size_type n;
				n = _base_map.erase(k);
				if (n)
					_size--;
				return n;
			}
			// (3)
			void erase (iterator first, iterator last)
			{
				while (first != last)
				{
					erase(*first);
					first++;
				}
			}

			void swap (map& x)
			{
				map tmp;

				tmp = *this;
				*this = x;
				x = tmp;
			}

			void clear()
			{
				erase(begin(), end());
			}
			// [ MODIFIERS ]

			// [ OBSERVERS ]
			key_compare key_comp() const
			{
				return key_compare();
				return _comp_func;
			}

			// value_compare value_comp() const;
			// [ OBSERVERS ]

			// [ OPERATIONS ]
			    	 iterator find (const key_type& k)
				{
					node_type * found = _base_map.find(k);
					return iterator(_base_map._top, _base_map._last, found);
				}
			const_iterator find (const key_type& k) const
			{
				node_type * found = _base_map.find(k);
				return const_iterator(_base_map._top, _base_map._last, found);
			}

			size_type count (const key_type& k) const
			{ return _size; }

			//       iterator lower_bound (const key_type& k);
			// const_iterator lower_bound (const key_type& k) const;

			//       iterator upper_bound (const key_type& k);
			// const_iterator upper_bound (const key_type& k) const;

			// pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
			// pair<iterator,iterator>             equal_range (const key_type& k);
			// [ OPERATIONS ]

			// [ ALLOCATOR ]
			allocator_type get_allocator() const { return _alloc_type; }
			// [ ALLOCATOR ]

	};

	template <class Key, class T, class Compare, class Alloc>
	void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
	{
		x.swap(y);
	}

	// (1)
	template <class Key, class T, class Compare, class Alloc>
	bool operator== ( const map<Key,T,Compare,Alloc>& lhs,
					const map<Key,T,Compare,Alloc>& rhs )
	{
		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	// (2)
	template <class Key, class T, class Compare, class Alloc>
	bool operator!= ( const map<Key,T,Compare,Alloc>& lhs,
					const map<Key,T,Compare,Alloc>& rhs )
	{
		return !(lhs == rhs);
	}

	// (3)
	template <class Key, class T, class Compare, class Alloc>
	bool operator<  ( const map<Key,T,Compare,Alloc>& lhs,
					const map<Key,T,Compare,Alloc>& rhs );
	// {}

	// (4)
	template <class Key, class T, class Compare, class Alloc>
	bool operator<= ( const map<Key,T,Compare,Alloc>& lhs,
					const map<Key,T,Compare,Alloc>& rhs )
	{
		return !(lhs > rhs);
	}

	// (5)
	template <class Key, class T, class Compare, class Alloc>
	bool operator>  ( const map<Key,T,Compare,Alloc>& lhs,
					const map<Key,T,Compare,Alloc>& rhs );
	// {}

	// (6)
	template <class Key, class T, class Compare, class Alloc>
	bool operator>= ( const map<Key,T,Compare,Alloc>& lhs,
					const map<Key,T,Compare,Alloc>& rhs )
	{
		return !(lhs < rhs);
	}



};

#endif