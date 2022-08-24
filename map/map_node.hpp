#ifndef		FT_AVL_NODE_HPP
# define	FT_AVL_NODE_HPP

# include <memory>

# include "../pair/pair.hpp"

namespace ft {

	template <class T>
	class Avl_Node {

		private:
			typedef T					data_type;
			typename std::allocator< Avl_Node<data_type> >::template rebind< Avl_Node<data_type> >::other	_alloc_node;
			typename std::allocator< Avl_Node<data_type> >::template rebind< data_type >::other				_alloc;

		public:
			Avl_Node *				parent;
			Avl_Node *				right;
			Avl_Node *				left;
			data_type *				current;
			size_t					height;
			//              ft::pair<const int, int> *
			// ft::Avl_Node<ft::pair<const int, int> > *

			// Default Constructor
			Avl_Node() : parent(NULL), right(NULL), left(NULL), current(NULL), height(1) {}

			// Destructor
			~Avl_Node() { if (current) { _alloc.deallocate(current, 1); current = NULL; } }

			// Copy Constructor
			Avl_Node(const Avl_Node & an) : parent(NULL), right(NULL), left(NULL), current(NULL), height(1)
			{
				*this = an;
			}

			// Copy Assignment
			Avl_Node & operator=(const Avl_Node & x)
			{
				if (current)
					_alloc.deallocate(current, 1);
				parent = x.parent;
				right = x.right;
				left = x.left;
				if (x.current)
				{
					current = _alloc.allocate(1);
					_alloc.construct(current, ft::make_pair(x.current->first, x.current->second));
				}
				height = x.height;
				return *this;
			}

			// Constructor (2)
			Avl_Node(const data_type & p) : parent(NULL), right(NULL), left(NULL), height(1)
			{
				current = _alloc.allocate(1);
				_alloc.construct(current, ft::make_pair(p.first, p.second));
			}
	};

};

#endif