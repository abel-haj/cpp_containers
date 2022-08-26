#ifndef			FT_BASE_MAP_HPP
# define		FT_BASE_MAP_HPP

# include <functional> // less
# include <memory> // allocator
# include <algorithm> // max

# include "../pair/make_pair.hpp"	// includes pair.hpp
# include "../other/iterator_traits.hpp"
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
			avl_tree () : _top(NULL), _comp_func(key_compare())
			{
				_last = _alloc_node.allocate(1);
			}
			avl_tree (const avl_tree &a)
			{
				_top = NULL;
				_last = NULL;
				_comp_func = a._comp_func;
				_last = _alloc_node.allocate(1);
				copy(a._top);
			}
			avl_tree & operator= (const avl_tree & t)
			{
				// delete
				if (_top)
				{
					delete_tree(_top);
				}
				// delete
				if (_last)
				{
					_alloc_node.deallocate(_last, 1); // no destroy // was not constructed
					_last = NULL;
				}

				// copy
				if (t._last)
				{
					_last = _alloc_node.allocate(1);
					_alloc_node.construct(_last, node_type(*t._last));
				}
				// copy
				if (t._top)
				{
					_top = _alloc_node.allocate(1);
					_alloc_node.construct(_top, node_type(*t._top));
					copy_tree(_top->right, t._top->right);
					copy_tree(_top->left, t._top->left);
				}

				return *this;
			}
			~avl_tree ()
			{
				if (_last)
				{
					_alloc_node.deallocate(_last, 1); // no destroy // was not constructed
					_last = NULL;
				}
			}

			void copy(node_type * t)
			{
				if (t)
				{
					insert(*(t->current));
					copy(t->right);
					copy(t->left);
				}
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

			node_type * deepest_left(node_type * n) const
			{
				if (n)
				{
					while (n->left != NULL)
						n = n->left;
				}
				return n;
			}
			node_type * deepest_right(node_type * n)
			{
				if (n)
					while (n->right != NULL)
						n = n->right;
				return n;
			}

			node_type * find(const key_type& k) const
			{
				return find_wrap(_top, k);
			}
			node_type * find_wrap(node_type * pos, const key_type& k) const
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
			void copy_tree(node_type *& t, node_type * c)
			{
				if (c)
				{
					t = _alloc_node.allocate(1);
					_alloc_node.construct(t, node_type(*c));
					copy_tree(t->right, c->right);
					copy_tree(t->left, c->left);
				}
			}

			void delete_tree(node_type * pos)
			{
				if (pos->left)
					delete_tree(pos->left);
				if (pos->right)
					delete_tree(pos->right);

				_alloc_node.destroy(pos);
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
					else if(k == pos->current->first)
					{

						if ( pos->left == NULL && pos->right == NULL )
						{
							_alloc_node.destroy(pos);
							_alloc_node.deallocate(pos, 1);
							pos = NULL;

							return 1;
						}

						else if ( pos->left == NULL )
						{
							node_type * tmp = pos->right;
							node_type * tmp_p = pos->parent;

							_alloc_node.destroy(pos);
							_alloc_node.deallocate(pos, 1);
							pos = NULL;

							pos = tmp;
							tmp->parent = tmp_p;
							ret = 1;
						}

						else if ( pos->right == NULL )
						{
							node_type * tmp = pos->left;
							node_type * tmp_p = pos->parent;

							_alloc_node.destroy(pos);
							_alloc_node.deallocate(pos, 1);
							pos = NULL;

							pos = tmp;
							tmp->parent = tmp_p;
							ret = 1;
						}
						else
						{
							node_type * tmp = deepest_left(pos->right);

							pos->copy_current(tmp->current);

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

	};

};

#endif