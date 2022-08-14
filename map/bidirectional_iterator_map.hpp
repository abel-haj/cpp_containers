#ifndef		FT_BIDIRECTIONAL_ITERATOR_MAP_HPP
# define	FT_BIDIRECTIONAL_ITERATOR_MAP_HPP

# include "iterator_traits.hpp"

namespace ft {

	template <class Iterator>
	class map_iterator {

		public:
			typedef typename ft::map_iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename ft::map_iterator_traits<Iterator>::value_type			value_type;
			typedef typename ft::map_iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename ft::map_iterator_traits<Iterator>::pointer				pointer;
			typedef typename ft::map_iterator_traits<Iterator>::reference			reference;

			map_iterator() {}
			map_iterator(const map_iterator & ri);
			map_iterator & operator=(const map_iterator & rhs);
			~map_iterator() {}

	};

};

#endif