#ifndef			FT_BASE_MAP_HPP
# define		FT_BASE_MAP_HPP

// # include "../pair/pair.hpp"
# include "../pair/make_pair.hpp"	// includes pair.hpp
# include "../other/iterator_traits.hpp"
# include <functional> // less
# include <memory> // allocator
# include <algorithm> // max
# include "map_node.hpp"

namespace ft {

	template < class Key,										// map::key_type
				class T,										// map::mapped_type
				class Compare,									// map::key_compare>
				class Alloc
				>
	class avl_tree {

		public:
			typedef				Key											key_type;
			typedef				T											mapped_type;
			typedef				ft::pair<const key_type, mapped_type>		value_type;
			typedef				Avl_Node<value_type>						node_type;
			typedef				Compare										key_compare;
			typedef				size_t										size_type;

			node_type *								_top;
			node_type *								_last;

		private:
			key_compare								_comp_func;
			typename Alloc::template rebind< Avl_Node<value_type> >::other	_alloc_node;

		public:
			avl_tree () : _top(NULL)
			{
				_last = _alloc_node.allocate(1);
			}
			~avl_tree ()
			{
				// if (_top)
				// 	delete_tree(_top);
				if (_last)
				{
					_alloc_node.deallocate(_last, 1);
					_last = NULL;
				}
			}

			void print()
			{
				std::cout << std::endl;
				std::cout << "------------" << std::endl;

				printBT("", _top, false);
				check_balance(_top);
			}
			size_type erase (const key_type& k)
			{
				size_type ret = erase_wrap(_top, k);
				_last->parent = deepest_right(_top);

				return ret;
			}
			bool insert (const value_type& val)
			{
				bool ret;

				ret = insert_wrap(_top, val, NULL);
				_last->parent = deepest_right(_top);

				return ret;
			}

			node_type * deepest_left(node_type * n)
			{
				if (n)
					while (n->left != NULL)
						n = n->left;
				return n;
			}

			node_type * find(const key_type& k)
			{
				return find_wrap(_top, k);
			}
			node_type * find_wrap(node_type * pos, const key_type& k)
			{
				node_type * ret = _last;
				if (!pos)
					return ret;
				else if (pos && _comp_func(pos->current->first, k) )
					ret = find_wrap(pos->right, k);
				else if (pos &&  _comp_func(k, pos->current->first) )
					ret = find_wrap(pos->left, k);
				else if(k == pos->current->first)
					return pos;
				return ret;
			}

		private:
			void delete_tree(node_type * pos)
			{
				if (pos->left)
					delete_tree(pos->left);
				if (pos->right)
					delete_tree(pos->right);

				_alloc_node.deallocate(pos, 1);
				pos = NULL;
			}

			size_type erase_wrap (node_type *& pos, const key_type& k)
			{
				size_type ret = 0;

				if (pos)
				{
				// Smaller
					if ( _comp_func(k, pos->current->first) )
						ret = erase_wrap(pos->left, k);

					// Greater
					else if ( _comp_func(pos->current->first, k) )
						ret = erase_wrap(pos->right, k);

					// Same
					else
					{
						if ( pos->left == NULL && pos->right == NULL )
						{
							// std::cout << "LR" << std::endl;
							_alloc_node.deallocate(pos, 1);
							// _alloc_node.destroy(pos);
							pos = NULL;

							return 1;
						}

						else if ( pos->left == NULL )
						{
							// std::cout << "L" << std::endl;
							node_type * tmp = pos->right;
							node_type * tmp_p = pos->parent;

							_alloc_node.deallocate(pos, 1);
							// _alloc_node.destroy(pos);
							pos = NULL;

							pos = tmp;
							tmp->parent = tmp_p;
							ret = 1;
						}

						else if ( pos->right == NULL )
						{
							// std::cout << "R" << std::endl;
							node_type * tmp = pos->left;
							node_type * tmp_p = pos->parent;

							_alloc_node.deallocate(pos, 1);
							// _alloc_node.destroy(pos);
							pos = NULL;

							pos = tmp;
							tmp->parent = tmp_p;
							ret = 1;
						}

						else
						{
							// std::cout << "T3" << std::endl;
							node_type * tmp = deepest_left(pos->right);
							pos->current = tmp->current;
							ret = erase_wrap(pos->right, tmp->current->first);
						}
					}

					if (!pos)
						return ret;

					pos->height = 1 + std::max(get_height(pos->left), get_height(pos->right));

					int this_balance = get_balance_factor(pos);

					// LEFT LEFT : RIGHT ROTATION
					if (this_balance > 1 && get_balance_factor(pos->left) > 0)
						pos = right_rotation(pos);

					// RIGHT RIGHT : LEFT ROTATION
					else if (this_balance < -1 && get_balance_factor(pos->right) < 0)
						pos = left_rotation(pos);

					// LEFT RIGHT
					else if (this_balance > 1 && get_balance_factor(pos->left) < 0)
					{
						pos->left = left_rotation(pos->left);
						pos = right_rotation(pos);
					}

					else if (this_balance < -1 && get_balance_factor(pos->right) > 0)
					{
						pos->right = right_rotation(pos->right);
						pos = left_rotation(pos);
					}
				}
				return ret;
			}

			bool insert_wrap (node_type *& pos, const value_type& val, node_type * p)
			{
				node_type	new_node(val);
				int	ret = false;

				if ( pos == NULL )
				{
					pos = _alloc_node.allocate(1);
					_alloc_node.construct(pos, val);
					pos->parent = p;
					return true;
				}

				else
				{
					if ( _comp_func(pos->current->first, val.first) )
						ret = insert_wrap(pos->right, val, pos);
					else if ( _comp_func(val.first, pos->current->first) )
						ret = insert_wrap(pos->left, val, pos);
					else
					{
						// replace value
						pos->current->second = val.second;
						return false;
					}
					if (ret == false)
						return false;

					pos->height = 1 + std::max(get_height(pos->left), get_height(pos->right));

					int this_balance = get_balance_factor(pos);

					// LEFT LEFT : RIGHT ROTATION
					if (this_balance > 1 && get_balance_factor(pos->left) > 0)
						pos = right_rotation(pos);

					// RIGHT RIGHT : LEFT ROTATION
					else if (this_balance < -1 && get_balance_factor(pos->right) < 0)
						pos = left_rotation(pos);

					// LEFT RIGHT
					else if (this_balance > 1 && get_balance_factor(pos->left) < 0)
					{
						pos->left = left_rotation(pos->left);
						pos = right_rotation(pos);
					}

					else if (this_balance < -1 && get_balance_factor(pos->right) > 0)
					{
						pos->right = right_rotation(pos->right);
						pos = left_rotation(pos);
					}
				}

				return ret;
			}
			bool insert_wrap_2 (node_type *& pos, const value_type& val)
			{
				// bool cond;
				int orient = 0;
				node_type * p = NULL;
				node_type * tmp_node = pos;

				// SEARCH
				while (tmp_node)
				{
					if ( _comp_func(tmp_node->current->first, val.first) )
					{
						orient = 1;
						p = tmp_node;
						tmp_node = tmp_node->right;
					}
					else if ( _comp_func(val.first, tmp_node->current->first) )
					{
						orient = 2;
						p = tmp_node;
						tmp_node = tmp_node->left;
					}
					else
					{
						tmp_node->current->second = val.second;
						return false;
					}
				}

				// INSERT
				if (tmp_node == NULL)
				{
					tmp_node = _alloc_node.allocate(1);
					_alloc_node.construct(tmp_node, val);
					tmp_node->parent = p;
					if (orient == 1)
						p->right = tmp_node;
					if (orient == 2)
						p->left = tmp_node;

					// editing top reference
					if (pos == NULL)
						pos = tmp_node;
				}

				// BALANCE
				while (tmp_node)
				{
					p = tmp_node;
					balance_tree(tmp_node);
					tmp_node = tmp_node->parent;
				}

				// update top reference
				pos = p;

				return true;
			}
			void balance_tree(node_type *& pos)
			{
				// if (pos->current->first == 4)
				// 	std::cout << "height " << pos->height << std::endl;

				pos->height = 1 + std::max(get_height(pos->left), get_height(pos->right));
				// if (pos->current->first == 4)
				// 	std::cout << "height " << pos->height << std::endl;
				// 	std::cout << std::endl;

				int this_balance = get_balance_factor(pos);

				// std::cout << this_balance << " " <<
				// get_balance_factor(pos->left) << " " <<
				// get_balance_factor(pos->right) << std::endl;

				// LEFT LEFT : RIGHT ROTATION
				if (this_balance > 1 && get_balance_factor(pos->left) > 0)
					right_rotation(pos);

				// RIGHT RIGHT : LEFT ROTATION
				else if (this_balance < -1 && get_balance_factor(pos->right) < 0)
					left_rotation(pos);

				// LEFT RIGHT
				else if (this_balance > 1 && get_balance_factor(pos->left) < 0)
					left_right_rotation(pos);

				else if (this_balance < -1 && get_balance_factor(pos->right) > 0)
					right_left_rotation(pos);
			}

			node_type * deepest_right(node_type * n)
			{
				if (n)
					while (n->right != NULL)
						n = n->right;
				return n;
			}

			node_type * right_rotation(node_type * y)
			{
				node_type * x = y->left;
				node_type * T2 = x->right;

				x->right = y;
				y->left = T2;
				parent_correction(x, y->parent);

				if (x->right)
					x->right->height = cal_height(x->right);
				if (x->left)
					x->left->height = cal_height(x->left);
				x->height =  cal_height(x);

				return x;
			}

			node_type * left_rotation(node_type * x)
			{
				node_type * y = x->right;
				node_type * T2 = y->left;

				y->left = x;
				x->right = T2;
				parent_correction(y, x->parent);

				if (y->left)
					y->left->height = cal_height(y->left);
				if (y->right)
					y->right->height = cal_height(y->right);
				y->height = cal_height(y);

				return y;
			}

			int cal_height(node_type *r)
			{
				if (r->right && r->left)
				{
					if (r->left->height < r->right->height)
						return r->right->height  + 1;
					else
						return r->left->height + 1;
				}
				else if(r->right && r->left == NULL)
				{
						return r->right->height + 1;
				}
				else if (r->right == NULL && r->left)
					return r->left->height + 1;
				return 1;
			}

			void parent_correction(node_type *&n, node_type *p)
			{
				if (n == NULL)
					return ;
				parent_correction(n->right, n);
				n->parent = p;
				parent_correction(n->left, n);
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

			void printBT(const std::string& prefix, const node_type* node, bool isLeft)
			{
				if( node != NULL )
				{
					std::cout << prefix;

					std::cout << (isLeft ? "├──" : "└──" );

					// print the value of the node
					std::cout << node->height << " : "
					<< "[" << node->current->first
					<< ":" << node->current->second
					<< "]"
					// << " p " << node->parent
					// << " l " << node->left
					// << " r " << node->right
					<< std::endl;

					// enter the next tree level - left and right branch
					printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
					printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
				}
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

	};

};

#endif