#ifndef		FT_AVL_NODE_HPP
# define	FT_AVL_NODE_HPP

// allocator
# include <memory>

# include "../pair/pair.hpp"

namespace ft {

	template <class T>
	class Avl_Node {

		private:
			typedef				T														data_type;
			typedef				std::allocator< Avl_Node<data_type> >					Alloc;
			typedef	typename	Alloc::template rebind< data_type >::other				allocator_type;
			typedef	typename	Alloc::template rebind< Avl_Node<data_type> >::other	allocator_node;

			allocator_node			_alloc_node;
			allocator_type			_alloc;

		public:
			Avl_Node *				parent;
			Avl_Node *				right;
			Avl_Node *				left;
			data_type *				current;
			size_t					height;

			// Default Constructor
			Avl_Node() : parent(NULL), right(NULL), left(NULL), current(NULL), height(1) {}

			// Destructor
			~Avl_Node()
			{
				if (current)
				{
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
				_alloc.construct(current, ft::make_pair(p.first, p.second));
			}

			// Copy Assignment
			Avl_Node & operator=(const Avl_Node & x)
			{
				if (current)
				{
					_alloc.destroy(current);
					_alloc.deallocate(current, 1);
				}
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

			void copy_current(const data_type * c)
			{
				if (current)
				{
					_alloc.destroy(current);
					_alloc.deallocate(current, 1);
				}
				current = _alloc.allocate(1);
				_alloc.construct(current, ft::make_pair(c->first, c->second));
			}
	};

};

#endif