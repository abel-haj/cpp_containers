#ifndef		FT_AVL_NODE_HPP
# define	FT_AVL_NODE_HPP

# include <memory>

# include "../pair/pair.hpp"
#include <execinfo.h>
#include <iostream>
#include<unistd.h>

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
			~Avl_Node()
			{
				if (current)
				{
					// std::cout << "Freed 8 " << current << std::endl;
					_alloc.destroy(current);
					_alloc.deallocate(current, 1);
					current = NULL;
				}
			}

			// Copy Constructor
			Avl_Node(const Avl_Node & an) : parent(NULL), right(NULL), left(NULL), current(NULL), height(1)
			{
				*this = an;
			}

			// Constructor (2)
			Avl_Node(const data_type & p) : parent(NULL), right(NULL), left(NULL), height(1)
			{
				current = _alloc.allocate(1);
				// std::cout << "Alloc11 " << current << std::endl;
				_alloc.construct(current, ft::make_pair(p.first, p.second));
			}

			// Copy Assignment
			Avl_Node & operator=(const Avl_Node & x)
			{
				if (current)
				{
					// std::cout << "Freed 9 " << current << std::endl;
					_alloc.destroy(current);
					_alloc.deallocate(current, 1);
				}
				parent = x.parent;
				right = x.right;
				left = x.left;
				if (x.current)
				{
					current = _alloc.allocate(1);
					// std::cout << "Alloc10 " << current << std::endl;
					_alloc.construct(current, ft::make_pair(x.current->first, x.current->second));
				}
				height = x.height;
				return *this;
			}
	};

};

#endif