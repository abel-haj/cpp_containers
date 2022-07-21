#ifndef		VECTOR_HPP
# define	VECTOR_HPP

// # include <iostream>
// allocator
# include <memory>
// vector iterator
# include <vector>
// print debug
# include <iostream>
// out of range
# include <exception>
# include "random_iterator_vector.hpp"
# include "../other/enable_if.hpp"
# include "../other/is_integral.hpp"

#ifndef OUT
	#define OUT 0
#endif

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
			typedef			ft::random_iterator<value_type>		iterator; // a random access iterator to value_type	convertible to const_iterator
			typedef			typename std::vector<value_type>::const_iterator							const_iterator; // a random access iterator to const value_type
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
				if (OUT)
					std::cout << "VECTOR DEFAULT CONSTRUCTOR CALLED" << std::endl;
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
				if (OUT)
					std::cout << "VECTOR FILL CONSTRUCTOR CALLED" << std::endl;
				_alloc_type = alloc;

				_vec = _alloc_type.allocate(n);
				for (size_type i = 0; i < _capacity; i++)
				{
					_vec[i] = val;
					if (OUT)
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
					typename ft::enable_if< !ft::is_integral<InputIterator>::value, InputIterator >::type = InputIterator())
					: _capacity(0), _total(0)
			{
				if (OUT)
					std::cout << "VECTOR RANGE CONSTRUCTOR CALLED" << std::endl;
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
				if (OUT)
					std::cout << "VECTOR COPY CONSTRUCTOR CALLED" << std::endl;

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

			/**
			 * @brief Destroy the vector object
			 *    destroy all container elements
			 *    deallocate all the storage capacity allocated by the vector
			 */
			~vector(void)
			{
				if (OUT)
					std::cout << "VECTOR DESTRUCTOR CALLED" << std::endl;
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
				if (OUT)
					std::cout << "VECTOR COPY ASSIGNMENNT CALLED" << std::endl;

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
			// BEGIN
			      iterator begin(void)
			{
				// const-qualified?
				return ft::random_iterator<value_type>(_vec);
			}

			const_iterator begin(void) const;

			// END
			      iterator end(void)
			{
				// const-qualified?
				return ft::random_iterator<value_type>(_vec + _total);
			}

			const_iterator end(void) const;

			// RBEGIN
			//       reverse_iterator rbegin(void);
			// const_reverse_iterator rbegin(void) const;

			// REND
			//       reverse_iterator rend(void);
			// const_reverse_iterator rend(void) const;
			//														//
			//						ITERATORS						//


			//						CAPACITY						//
			//														//
			size_type size(void) const
			{
				return _total;
			}

			size_type max_size(void) const
			{
				return _alloc_type.max_size();
			}

			void resize (size_type n, value_type val = value_type())
			{
				// reduce
				if (_capacity > n)
				{
					pointer tmp;
					tmp = _alloc_type.allocate(n);

					for  (size_type i=0; i<_total; i++)
					{
						tmp[i] = _vec[i];
					}
					for  (size_type i=_total; i<n; i++)
					{
						tmp[i] = val;
					}
					_capacity = n;

					_alloc_type.deallocate(_vec, _capacity);
					_vec = tmp;
				}

				// increase
				else if (n > _capacity)
				{
					pointer tmp;
					int newcap;

					tmp = _vec;
					newcap = (_capacity * 2) > n ? _capacity * 2 : n;
					_vec = _alloc_type.allocate(newcap, _vec);

					for (size_type i=0; i<_total; i++)
					{
						_vec[i] = tmp[i];
					}
					for (size_type i=_total; i<newcap; i++)
					{
						_vec[i] = val;
						_total++;
					}

					_alloc_type.deallocate(tmp, _capacity);
					_capacity = n;
				}
			}

			size_type capacity(void) const
			{
				return _capacity;
			}

			bool empty(void) const
			{
				return _total == 0;
			}

			void reserve (size_type n)
			{
				if (n > _capacity)
				{
					pointer tmp;

					tmp = _vec;
					_vec = _alloc_type.allocate(n, _vec);

					for (size_type i=0; i<_total; i++)
					{
						_vec[i] = tmp[i];
					}
					for (size_type i=_total; i<n; i++)
					{
						_vec[i] = value_type();
					}

					_alloc_type.deallocate(tmp, _capacity);
					_capacity = n;
				}
			}
			//														//
			//						CAPACITY						//


			//					ELEMENT ACCESS					//
			//													//
			reference operator[] (size_type n)
			{
				if (OUT)
					std::cout << "ACCESSING INDEX " << n << std::endl;
				return _vec[n];
			}

			const_reference operator[] (size_type n) const
			{
				if (OUT)
					std::cout << "ACCESSING INDEX " << n << "(const)" << std::endl;
				return _vec[n];
			}

			      reference at (size_type n)
			{
				if (n < 0  || n >= _total)
					throw std::out_of_range("vector");
				return _vec[n];
			}
			const_reference at (size_type n) const
			{
				if (n >= _capacity || n < 0)
					throw std::out_of_range("vector");
				return _vec[n];
			}

			      reference front(void)
			{
				return *(_vec);
			}
			const_reference front(void) const
			{
				return *(_vec);
			}

			      reference back(void)
			{
				return *(_vec + _total - 1);
			}
			const_reference back(void) const
			{
				return *(_vec + _total - 1);
			}
			//													//
			//					ELEMENT ACCESS					//

			//					MODIFIERS					//
			//												//
			// range (1)
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last)
			{
				int newcapacity;

				newcapacity = last - first;

				if (newcapacity > _capacity)
				{
					_alloc_type.deallocate(_vec, _capacity);
					_vec = _alloc_type.allocate(newcapacity);
					_capacity = newcapacity;
				}
				_total = 0;
				for (size_type i=0; i<newcapacity; i++)
				{
					_vec[i] = *first;
					first++;
					_total++;
				}
			}
			// fill (2)
			void assign (size_type n, const value_type& val)
			{
				// Any elements held in the container before the call are destroyed
				_alloc_type.destroy(_vec);
				_total = 0;

				// reallocate only only if the new vector size surpasses the current vector capacity
				if (n > _capacity)
				{
					_alloc_type.deallocate(_vec, _capacity);
					_vec = _alloc_type.allocate(n);
					_capacity = n;
				}
				for (size_type i=0; i<n; i++)
				{
					_vec[i] = val;
					_total++;
				}
			}

			void push_back (const value_type& val);

			void pop_back(void)
			{
				_total--;
			}

			// single element (1)
			iterator insert (iterator position, const value_type& val);
			// fill (2)
				void insert (iterator position, size_type n, const value_type& val);
			// range (3)
			template <class InputIterator>
				void insert (iterator position, InputIterator first, InputIterator last);

			iterator erase (iterator position);
			iterator erase (iterator first, iterator last);

			void swap (vector& x);

			void clear(void);
			//												//
			//					MODIFIERS					//

	};

	// # include "vector.tpp"

};

#endif