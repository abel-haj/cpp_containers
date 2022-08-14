#ifndef		FT_AVL_NODE_HPP
# define	FT_AVL_NODE_HPP

# include <memory>

# include "../pair/pair.hpp"

namespace ft {

	template <class T>
	class Avl_Node {

		private:
			typedef T				data_type;
			std::allocator<data_type>	_alloc;

		public:
			Avl_Node *				parent;
			Avl_Node *				right;
			Avl_Node *				left;
			data_type *				current;
			size_t					height;

			Avl_Node() : current(NULL), parent(NULL), right(NULL), left(NULL), height(1) {}
			Avl_Node(const data_type * p) : parent(NULL), right(NULL), left(NULL), height(1)
			{
				current = _alloc.allocate(1);
				_alloc.construct(current, ft::make_pair(p->first, p->second));
			}
			Avl_Node(const data_type & p) : parent(NULL), right(NULL), left(NULL), height(1)
			{
				current = _alloc.allocate(1);
				_alloc.construct(current, ft::make_pair(p.first, p.second));
			}
			~Avl_Node() { if (current) { _alloc.deallocate(current, 1); current = NULL; } }

			Avl_Node & operator=(const Avl_Node & x)
			{
				if (current)
					delete current;
				parent = x.parent;
				right = x.right;
				left = x.left;
				current = x.current;
				height = x.height;
				return *this;
			}
			Avl_Node & operator=(const Avl_Node * x)
			{
				if (current)
					delete current;
				parent = x->parent;
				right = x->right;
				left = x->left;
				current = x->current;
				height = x->height;
				return *this;
			}

	};

};

#endif