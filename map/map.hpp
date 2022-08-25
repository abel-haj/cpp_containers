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
# include "../vector/vector.hpp"

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
			typedef				const value_type							const_value_type;
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
			typedef	typename	Alloc::template rebind< base_map >::other	allocator_tree;

			class value_compare
			{
				friend class map;
				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {}
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			};

		private:
			allocator_tree				_alloc_tree;
			allocator_type				_alloc_type;
			base_map *					_base_map;
			key_compare					_comp_func;
			size_type					_size;

		public:
			void print()
			{
				_base_map->print();
			}

			// [ CONSTRUCTORS ]
			// empty (1)
			explicit map (const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type())
						: _alloc_tree(allocator_tree()), _alloc_type(alloc), _comp_func(comp), _size(0)
						{
							_base_map = _alloc_tree.allocate(1);
							// std::cout << "Alloc 7 " << _base_map << std::endl;
							_alloc_tree.construct(_base_map, base_map());
						}
			// range (2)
			template <class InputIterator>
			map (InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
				: _alloc_tree(allocator_tree()), _alloc_type(alloc), _base_map(NULL), _comp_func(comp), _size(0)
				{
					_base_map = _alloc_tree.allocate(1);
					// std::cout << "Alloc 8 " << _base_map << std::endl;
					_alloc_tree.construct(_base_map, base_map());
					while (first != last)
					{
						insert(*first);
						first++;
					}
				}
			// copy (3)
			map (const map& x)
			: _alloc_tree(allocator_tree()), _alloc_type(allocator_type()), _base_map(NULL), _comp_func(key_compare()), _size(0)
			{
				_base_map = _alloc_tree.allocate(1);
				// std::cout << "Alloc 9 " << _base_map << std::endl;
				_alloc_tree.construct(_base_map, base_map());

				_comp_func = x._comp_func;
				_alloc_type = x._alloc_type;
				_comp_func = x._comp_func;
				_size = x._size;
				for (const_iterator it = x.begin(); it != x.end(); it++)
				{
					_base_map->insert(*it);
				}
			}
			// [ CONSTRUCTORS ]

			// [ DESTRUCTOR ]
			~map()
			{
				clear();
				// std::cout << "Freed 7 " << _base_map << std::endl;
				_alloc_tree.destroy(_base_map);
				_alloc_tree.deallocate(_base_map, 1);
			}
			// [ DESTRUCTOR ]

			// [ COPY CONSTRUCTOR ]
			map& operator= (const map& x)
			{
				clear();

				_alloc_type = x._alloc_type;
				_alloc_tree = x._alloc_tree;
				_comp_func = x._comp_func;
				_size = x._size;

				for (const_iterator it = x.begin(); it != x.end(); it++)
					_base_map->insert(*it);

				return *this;
			}
			// [ COPY CONSTRUCTOR ]

			// [ ITERATORS ]
				iterator begin()
				{
					if (empty())
						return end();
					return iterator(_base_map->_top, _base_map->_last, _base_map->deepest_left(_base_map->_top));
				}
			const_iterator begin() const
			{
				if (empty())
					return end();
				return const_iterator(_base_map->_top, _base_map->_last, _base_map->deepest_left(_base_map->_top));
			}

				  iterator end()
				{
					return iterator(_base_map->_top, _base_map->_last, _base_map->_last);
				}
			const_iterator end() const
			{
				return const_iterator(_base_map->_top, _base_map->_last, _base_map->_last);
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
			mapped_type& operator[] (const key_type& k)
			{
				node_type * found = _base_map->find(k);
				if (iterator(_base_map->_top, _base_map->_last, found) != end())
				{
					// If k matches the key of an element in the container, the function returns a reference to its mapped value.
					return ((*iterator(_base_map->_top, _base_map->_last, found)).second);
				}
				// else the function inserts a new element with that key and returns a reference to its mapped value
				this->insert(ft::make_pair(k, mapped_type()));
				found = _base_map->find(k);
				return ((*iterator(_base_map->_top, _base_map->_last, found)).second);
			}
			
			// [ ELEMENT ACCESS ]

			// [ MODIFIERS ]
			// single element (1)
			pair<iterator,bool> insert (const value_type& val)
			{
				bool ret;
				ret = _base_map->insert(val);
				if (ret)
					_size++;
				node_type * found = _base_map->find(val.first);
				return ft::make_pair(iterator(_base_map->_top, _base_map->_last, found), ret);
			}
			// with hint (2)
			iterator insert (iterator , const value_type& val)
			{
				return insert(val).first;
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
				if(empty() ==  true)
					return ;
				erase((*position).first);
			}
			// (2)
			size_type erase (const key_type& k)
			{ 
				size_type n;
				n = _base_map->erase(k);
				if (n)
					_size--;
				return n;
			}
			// (3)
			void erase (iterator first, iterator last)
			{
				if(empty() ==  true)
					return ;
				ft::vector<key_type> backup;
				while (first != last)
				{
					backup.push_back(first->first);
					first++;
				}
				for (typename ft::vector<key_type>::iterator it = backup.begin(); it != backup.end(); it++)
				{
					erase(*it);
				}
			}

			void swap (map& x)
			{
				base_map * tmp = this->_base_map;
				size_type size_tmp = this->_size;
				this->_base_map = x._base_map;
				this->_size  = x._size;
				x._base_map =  tmp;
				x._size = size_tmp;
			}

			void clear()
			{
				erase(begin(), end());
			}
			// [ MODIFIERS ]

			// [ OBSERVERS ]
			key_compare key_comp() const
			{
				return _comp_func;
			}

			value_compare value_comp() const
			{
				return (value_compare(_comp_func));
			}
			// [ OBSERVERS ]

			// [ OPERATIONS ]
			    iterator find (const key_type& k)
				{
					node_type * found = _base_map->find(k);
					return iterator(_base_map->_top, _base_map->_last, found);
				}
			const_iterator find (const key_type& k) const
			{
				node_type * found = _base_map->find(k);
				return const_iterator(_base_map->_top, _base_map->_last, found);
			}

			size_type count (const key_type& k) const
			{
				node_type * found = _base_map->find(k);
				node_type * tmp_end = _base_map->_last;
				if (found != tmp_end)
					return (1);
				return (0);
			}

			iterator lower_bound (const key_type& k)
			{
				iterator it = find(k);
				if (it != end())
					return (it);
				iterator tmp(_base_map->_top, _base_map->_last, _base_map->deepest_left(_base_map->_top));
				while ( tmp != end() )
				{
					if (_comp_func(k, (*tmp).first) &&
						_comp_func(k, _base_map->deepest_right(_base_map->_top)->current->first))
					{
						return (iterator(tmp));
					}
					tmp++;
				}
				return (end());
			}
			const_iterator lower_bound (const key_type& k) const
			{
				const_iterator it = find(k);
				if (it != end())
					return (it);
				const_iterator tmp(_base_map->_top, _base_map->_last, _base_map->deepest_left(_base_map->_top));
				while ( tmp != end() )
				{
					if (_comp_func(k, (*tmp).first) &&
						_comp_func(k, _base_map->deepest_right(_base_map->_top)->current->first))
						return (tmp);
					tmp++;
				}
				return (end());
			}
			iterator upper_bound (const key_type& k)
			{
				iterator it = find(k);
				if (it != end())
					return (++it);

				iterator tmp = begin();
				while ( tmp != end() )
				{
					if (_comp_func(k, (*tmp).first) &&
						_comp_func(k, _base_map->deepest_right(_base_map->_top)->current->first))
						return (iterator(tmp));
					tmp++;
				}
				return (end());
			}
			const_iterator upper_bound (const key_type& k) const
			{
				const_iterator it = find(k);
				if (it != end())
					return (++it);

				const_iterator tmp = begin();
				while ( tmp != end() )
				{
					if (_comp_func(k, (*tmp).first) &&
						_comp_func(k, _base_map->deepest_right(_base_map->_top)->current->first))
						return (const_iterator(tmp));
					tmp++;
				}
				return (end());
			}

			pair<const_iterator,const_iterator> equal_range (const key_type& k) const
			{
				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			}
			pair<iterator,iterator>             equal_range (const key_type& k)
			{
				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			}
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


	template <class Key, class T, class Compare, class Alloc>
	bool	operator == (const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return ((lhs.size() == rhs.size()) && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator != (const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator > (const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator < (const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator >= (const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
			return (!(lhs < rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator <= (const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return (!(lhs > rhs));
	}



};

#endif