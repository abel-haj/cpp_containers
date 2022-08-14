#ifndef			FT_MAP_HPP
# define		FT_MAP_HPP

// # include "../pair/pair.hpp"
# include "../pair/make_pair.hpp"	// includes pair.hpp
# include "../other/iterator_traits.hpp"
# include <functional> // less
# include <memory> // allocator
# include <map>
# include "AVL_Node.hpp"
# include "bidirectional_iterator_map.hpp"

namespace ft {

	template < class Key,										// map::key_type
				class T,										// map::mapped_type
				class Compare = std::less<Key>,					// map::key_compare
				class Alloc = std::allocator<pair<const Key,T> >		// map::allocator_type
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

		private:
			size_type		_size;
			allocator_type	_alloc_type;
			key_compare		_comp_func;
			node_type *		_top;
			std::allocator< Avl_Node<value_type> >	_alloc_node;

		public:

			void erase (const key_type& k)
			{
				erase_wrap(_top, k);
			}
			void erase_wrap (node_type *& pos, const key_type& k)
			{
				if (pos == NULL)
				{
				}

				else
				{
					// Smaller
					if ( _comp_func(k, pos->current->first) )
					{
						erase_wrap(pos->left, k);
					}

					// Greater
					else if ( _comp_func(pos->current->first, k) )
					{
						erase_wrap(pos->right, k);
					}

					// Same
					else
					{
						if ( pos->left == NULL && pos->right == NULL )
						{
							std::cout << "LR" << std::endl;
							_alloc_node.deallocate(pos, 1);
							// _alloc_node.destroy(pos);
							pos = NULL;
						}

						else if ( pos->left == NULL )
						{
							std::cout << "L" << std::endl;
							node_type * tmp = pos->right;
							node_type * tmp_p = pos->parent;

							_alloc_node.deallocate(pos, 1);
							// _alloc_node.destroy(pos);
							pos = NULL;

							pos = tmp;
							tmp->parent = tmp_p;
						}

						else if ( pos->right == NULL )
						{
							std::cout << "R" << std::endl;
							node_type * tmp = pos->left;
							node_type * tmp_p = pos->parent;

							_alloc_node.deallocate(pos, 1);
							// _alloc_node.destroy(pos);
							pos = NULL;

							pos = tmp;
							tmp->parent = tmp_p;
						}

						else
						{
							std::cout << "T3" << std::endl;
							node_type * tmp = smallest_left(pos->right);
							// std::cout << "| - " << tmp->current->first << " " << tmp->current->second << std::endl;

							// node_type * tmp_l = tmp->left;
							node_type * tmp_r = tmp->right;
							node_type * tmp_p = tmp->parent;

							node_type * n_tmp_l = pos->left;
							node_type * n_tmp_r = pos->right;
							node_type * n_tmp_p = pos->parent;

							_alloc_node.deallocate(pos, 1);

							pos = tmp;
							pos->left = n_tmp_l;
							pos->right = n_tmp_r;
							pos->parent = n_tmp_p;

							// tmp_p->left = tmp_r;

							tmp_r->parent = tmp_p;
						}
					}
				}
			}

			node_type * smallest_left(node_type * n)
			{
				while (n->left != NULL)
				{
					n = n->left;
				}

				return n;
			}

			void insert (const value_type& val)
			{
				insert_wrap(_top, val, NULL);
			}
			void insert_wrap (node_type *& pos, const value_type& val, node_type * p)
			{
				node_type	new_node(val);

				if ( pos == NULL )
				{
					pos = _alloc_node.allocate(1);
					pos->parent = p;
					_alloc_node.construct(pos, val);
				}

				else
				{
					if ( _comp_func(pos->current->first, val.first) )
						insert_wrap(pos->right, val, pos);
					else if ( _comp_func(val.first, pos->current->first) )
						insert_wrap(pos->left, val, pos);
					else
					{
						// replace value
					}
						
					pos->height = 1 + std::max(get_height(pos->left), get_height(pos->right));

					int this_balance = get_balance_factor(pos);

					// LEFT LEFT : RIGHT ROTATION
					if (this_balance > 1 && get_balance_factor(pos->left) > 0)
					{
						// std::cout << "comp FIRST " << pos->current->second << std::endl;
						right_rotation(pos);
					}

					// RIGHT RIGHT : LEFT ROTATION
					else if (this_balance < -1 && get_balance_factor(pos->right) < 0)
					{
						// std::cout << "comp LAST" << std::endl;
						left_rotation(pos);
					}

					// LEFT RIGHT
					else if (this_balance > 1 && get_balance_factor(pos->left) < 0)
					{
						// std::cout << "LEFT RIGHT HERE" << std::endl;
						left_right_rotation(pos);
					}

					else if (this_balance < -1 && get_balance_factor(pos->right) > 0)
					{
						// std::cout << "RIGHT LEFT HERE" << std::endl;
						right_left_rotation(pos);
					}

				}
			}

			void left_right_rotation(node_type * & n)
			{
				// A
				node_type * tmp_left = n->left;
				// B
				node_type * tmp_right = n->left->right;
				// C
				n->left = tmp_right;

				node_type * tmp_right_l = tmp_right->left;
				tmp_right->left = tmp_left;
				tmp_right->parent = n;

				tmp_left->right = tmp_right_l;
				tmp_left->parent = tmp_right;

				right_rotation(n);
			}

			void right_left_rotation(node_type * & n)
			{
				// A
				node_type * tmp_right = n->right;
				// B
				node_type * tmp_left = n->right->left;
				// C
				n->right = tmp_left;

				node_type * tmp_left_r = tmp_left->right;
				tmp_left->right = tmp_right;
				tmp_left->parent = n;

				tmp_right->left = tmp_left_r;
				tmp_right->parent = tmp_left;

				left_rotation(n);
			}

			void right_rotation(node_type * & n)
			{
				// POS PARENT ??
				node_type * tmp_l = n->left;
				n->left = tmp_l->right;
				tmp_l->right = n;
				tmp_l->parent = NULL;
				n = tmp_l;

				n->right->height = 1 + std::max(get_height(n->right->left), get_height(n->right->right));
				n->left->height = 1 + std::max(get_height(n->left->left), get_height(n->left->right));
				n->height = 1 + std::max(get_height(n->left), get_height(n->right));
			}

			void left_rotation(node_type * & n)
			{
				node_type * tmp_r = n->right;
				node_type * tmp_r_l = tmp_r->left;
				tmp_r->left = n;
				n->right = tmp_r_l;
				n = tmp_r;

				n->right->height = 1 + std::max(get_height(n->right->left), get_height(n->right->right));
				n->left->height = 1 + std::max(get_height(n->left->left), get_height(n->left->right));
				n->height = 1 + std::max(get_height(n->left), get_height(n->right));
			}

template<class F>
int calheight(F *p)
{
  if (p == NULL)
    return (1);
  if(p->left && p->right)
  {
    if (p->left->height < p->right->height)
      return p->right->height + 1;
    else
      return  p->left->height + 1;
  }
  else if(p->right == NULL && p->left)
  {
    return p->left->height + 1;
  }
  else if(p->left ==NULL && p->right)
  {
    return p->right->height + 1;
  }
  return 1;
}

template<class F>
void check_balance(F *s)
{
  if (s == nullptr)
    return ;
  if (s->right)
    check_balance(s->right);
  if (s->left)
    check_balance(s->left);
  int bal = calheight(s->left) - calheight(s->right);
  if (bal >= 2 || bal <= -2)
  {
    std::cout << "KO: " << " unbalanced tree at node " << s->current->first << "\n";
    return ;
  }
}

			size_type get_height(node_type * n)
			{
				if (n)
					return n->height;
				return 0;
			}

			int get_balance_factor(node_type * n)
			{
				if (n)
					return get_height(n->left) - get_height(n->right);
				return 0;
			}

			void print()
			{
				std::cout << std::endl;
				std::cout << "------------" << std::endl;

				printBT("", _top, false);
				// check_balance(_top);
			}
			void printBT(const std::string& prefix, const node_type* node, bool isLeft)
			{
				if( node != NULL )
				{
					std::cout << prefix;

					std::cout << (isLeft ? "├──" : "└──" );

					// print the value of the node
					std::cout << node->height << " : " << node->current->second << std::endl;

					// enter the next tree level - left and right branch
					printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
					printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
				}
			}

			// [ CONSTRUCTORS ]
			// empty (1)
			explicit map (const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type())
						: _alloc_type(alloc), _comp_func(comp), _top(NULL)
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
			// pair<iterator,bool> insert (const value_type& val);
			// with hint (2)
			// iterator insert (iterator position, const value_type& val);
			// range (3)
			// template <class InputIterator>
			// void insert (InputIterator first, InputIterator last);

			// (1)
			// void erase (iterator position);
			// (2)
			// size_type erase (const key_type& k);
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