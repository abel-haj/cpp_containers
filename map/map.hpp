#ifndef			FT_MAP_HPP
# define		FT_MAP_HPP

// # include "../pair/pair.hpp"
# include "../pair/make_pair.hpp"	// includes pair.hpp
# include "../other/iterator_traits.hpp"
# include <functional> // less
# include <memory> // allocator
# include <map>
# include "base_map.hpp"
# include "bidirectional_iterator_map.hpp"

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
			typedef				ft::pair<const key_type, mapped_type>		value_type;
			typedef				Avl_Node<value_type>						node_type;
			typedef				Compare										key_compare;
			typedef				Alloc										allocator_type;
			typedef typename	allocator_type::reference					reference;
			typedef typename	allocator_type::const_reference				const_reference;
			typedef typename	allocator_type::pointer						pointer;
			typedef typename	allocator_type::const_pointer				const_pointer;
			typedef				map_iterator<pointer>						iterator;
			// typedef			const_iterator;
			// typedef			reverese_iterator;
			// typedef			const_reverese_iterator;
			// typedef typename	iterator_traits<iterator>::difference_type	difference_type;
			typedef				size_t										size_type;
			typedef				ft::avl_tree<key_type, mapped_type, key_compare>	base_map;

		private:
			size_type		_size;
			allocator_type	_alloc_type;
			key_compare		_comp_func;
			std::allocator< node_type >	_alloc_node;
			base_map		_base_map;

		public:
			void print()
			{
				std::cout << std::endl;
				std::cout << "------------" << std::endl;
				_base_map.print();
			}

			// [ CONSTRUCTORS ]
			// empty (1)
			explicit map (const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type())
						: _alloc_type(alloc), _comp_func(comp)
						{}
			// range (2)
			template <class InputIterator>
			map (InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type());
				// : _alloc_type(alloc), _comp_func(comp)
				// {}
			// copy (3)
			map (const map& x);
			// [ CONSTRUCTORS ]

			// [ DESTRUCTOR ]
			~map() {}
			// [ DESTRUCTOR ]

			// [ COPY CONSTRUCTOR ]
			map& operator= (const map& x);
			// [ COPY CONSTRUCTOR ]

			// [ ITERATORS ]
			// 	  iterator begin();
			// const_iterator begin() const;

			// 	  iterator end();
			// const_iterator end() const;

			// 	  reverse_iterator rbegin();
			// const_reverse_iterator rbegin() const;

			// 	  reverse_iterator rend();
			// const_reverse_iterator rend() const;
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
			pair<int,bool> insert (const value_type& val)
			{
				// return ft::make_pair(iterator(), _base_map.insert(val));
				return ft::make_pair(0, _base_map.insert(val));
			}
			// with hint (2)
			// iterator insert (iterator position, const value_type& val);
			// range (3)
			// template <class InputIterator>
			// void insert (InputIterator first, InputIterator last);

			// (1)
			// void erase (iterator position);
			// (2)
			size_type erase (const key_type& k)
			{
				return _base_map.erase(k);
			}
			// (3)
			// void erase (iterator first, iterator last);

			void swap (map& x);

			void clear();
			// [ MODIFIERS ]

			// [ OBSERVERS ]
			key_compare key_comp() const;

			// value_compare value_comp() const;
			// [ OBSERVERS ]

			// [ OPERATIONS ]
			//       iterator find (const key_type& k);
			// const_iterator find (const key_type& k) const;

			size_type count (const key_type& k) const;

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

};

#endif