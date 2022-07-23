#ifndef			REVERSE_ITERATOR_VECTOR_HPP
# define		REVERSE_ITERATOR_VECTOR_HPP

// # include <cstddef>
# include "../other/iterator_traits.hpp"

namespace ft {

	template <class Iterator>
	class reverse_iterator {

		private:
			// ...

		public:
			Iterator															iterator_type;		// Iterator's type
			typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;	// Preserves Iterator's category
			typedef typename ft::iterator_traits<Iterator>::value_type			value_type;			// Preserves Iterator's value type
			typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;	// Preserves Iterator's difference type
			typedef typename ft::iterator_traits<Iterator>::pointer				pointer;			// Preserves Iterator's pointer type
			typedef typename ft::iterator_traits<Iterator>::reference			reference;			// Preserves Iterator's reference type

	};

};

#endif