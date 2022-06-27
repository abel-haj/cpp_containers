#ifndef		VECTOR_HPP
# define	VECTOR_HPP

// # include <iostream>
// allocator
# include <memory>
// vector iterator
# include <vector>
// print debug
# include <iostream>
# include "random_iterator_vector.hpp"

// DEEP vs SHALLOW

namespace ft {

	template < class T, class Alloc = std::allocator<T> >
	class vector {

		public:
			typedef			T								value_type; // The first template parameter (T)
			typedef			std::allocator<value_type>		allocator_type; // The second template parameter (Alloc)
			typedef			value_type	&					reference; // allocator_type::reference
			typedef	const	value_type						const_reference; // allocator_type::const_reference
			typedef			value_type	*					pointer; // allocator_type::pointer
			typedef	const	value_type	*					const_pointer; // allocator_type::const_pointer
			typedef			random_iterator<value_type>		iterator; // a random access iterator to value_type	convertible to const_iterator
			typedef			std::vector<value_type>::const_iterator							const_iterator; // a random access iterator to const value_type
			// typedef										reverse_iterator; // reverse_iterator<iterator>
			// typedef										const_reverse_iterator; // reverse_iterator<const_iterator>
			typedef			ptrdiff_t						difference_type; // a signed integral type, identical to: iterator_traits<iterator>::difference_type
			typedef			size_t							size_type; // an unsigned integral type that can represent any non-negative value of difference_type

		private:
			pointer			_vec;
			size_type		_capacity;
			size_type		_total;
			allocator_type	_alloc_type;

		public:

			/**
			 * @brief Construct a new vector object with DEFAULT constructor
			 * 
			 * @param alloc 
			 */
			explicit vector (const allocator_type& alloc = allocator_type()) : _capacity(0), _total(0)
			{
				std::cout << "DEFAULT CONSTRUCTOR CALLED" << std::endl;
				_alloc_type = alloc;
				_vec = _alloc_type.allocate(_capacity);
			}

			/**
			 * @brief Construct a new vector object with FILL constructor
			 * 
			 * @param n 
			 * @param val 
			 * @param alloc 
			 */
			vector (size_type n, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type()) : _capacity(n), _total(0)
			{
				std::cout << "FILL CONSTRUCTOR CALLED" << std::endl;
				_alloc_type = alloc;

				_vec = _alloc_type.allocate(n);
				for (size_type i = 0; i < _capacity; i++)
				{
					_vec[i] = val;
					std::cout << "ASSIGNING " << val << std::endl;
					_total++;
				}
			}

			/**
			 * @brief Construct a new vector object with RANGE constructor
			 * 
			 * @tparam InputIterator 
			 * @param first 
			 * @param last 
			 * @param alloc 
			 */
			template <class InputIterator>
			vector (InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type(),
					std::enable_if< std::is_integral<value_type>::value, value_type >* = nullptr)
					: _capacity(0), _total(0)
			{
				std::cout << "RANGE CONSTRUCTOR CALLED" << std::endl;
				_alloc_type = alloc;

				size_type	new_capacity;

				new_capacity = last - first;
				_vec = _alloc_type.allocate(new_capacity);

				for (size_type i = _total; i < new_capacity; i++)
				{
					_vec[i] = *first;

					first++;

					_capacity++;
					_total++;
				}
			}

			/**
			 * @brief Construct a new vector object from an existing vector
			 * 
			 * @param x 
			 */
			vector (const vector& x) : _capacity(0), _total(0)
			{
				std::cout << "COPY CONSTRUCTOR CALLED" << std::endl;

				// allocate
				_vec = _alloc_type.allocate(x._capacity);
				_capacity = x._capacity;

				// copy
				while (_total < x._total)
				{
					_vec[_total] = x[_total];
					_total++;
				}
			}

			//	
			//	
			/**
			 * @brief Destroy the vector object
			 *    destroy all container elements
			 *    deallocate all the storage capacity allocated by the vector
			 */
			~vector(void)
			{
				std::cout << "DESTRUCTOR CALLED" << std::endl;
				_alloc_type.deallocate(_vec, _capacity);

				// TO VERIFY // recursive?
				// _alloc_type.destroy(_vec);

				_capacity = 0;
				_total = 0;
			}

			/**
			 * @brief 
			 * 
			 * @param x 
			 * @return vector& 
			 */
			vector& operator= (const vector& x)
			{
				std::cout << "COPY ASSIGNMENNT CALLED" << std::endl;

				// deallocate
				_alloc_type.deallocate(_vec, _capacity);

				// allocate
				_vec = _alloc_type.allocate(x._capacity);
				_capacity = x._capacity;

				// copy
				while (_total < x._total)
				{
					_vec[_total] = x[_total];
					_total++;
				}

				return *this;
			}


			//						ITERATORS						//
			//														//
				  iterator begin()
			{
				return
			}
			const_iterator begin() const;
			//														//
			//						ITERATORS						//


			//						CAPACITY						//
			//														//
			size_type size(void) const
			{
				return _total;
			}

			size_type capacity(void) const
			{
				return _capacity;
			}
			//														//
			//						CAPACITY						//


			//					ELEMENT ACCESS					//
			//													//
			reference operator[] (size_type n)
			{
				std::cout << "ACCESSING INDEX " << n << std::endl;
				return _vec[n];
			}
			const_reference operator[] (size_type n) const
			{
				std::cout << "ACCESSING INDEX " << n << "(const)" << std::endl;
				return _vec[n];
			}
			//													//
			//					ELEMENT ACCESS					//

	};

	// # include "vector.tpp"

}

#endif