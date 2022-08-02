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
# include "../other/reverse_iterator.hpp"
# include "../other/enable_if.hpp"
# include "../other/is_integral.hpp"
# include "../other/equal.hpp"
# include "../other/lexicographical_compare.hpp"

#ifndef OUT
	#define OUT 0
#endif

namespace ft {

	template < class T, class Alloc = std::allocator<T> >
	class vector {

		public:
			typedef				T											value_type; // The first template parameter (T)
			typedef				std::allocator<value_type>					allocator_type; // The second template parameter (Alloc)
			typedef	typename	allocator_type::reference					reference; // allocator_type::reference
			typedef	typename	allocator_type::const_reference				const_reference; // allocator_type::const_reference
			typedef	typename	allocator_type::pointer						pointer; // allocator_type::pointer
			typedef	typename	allocator_type::const_pointer				const_pointer; // allocator_type::const_pointer
			typedef				ft::vector_iterator<value_type>				iterator; // a random access iterator to value_type	convertible to const_iterator
			typedef				ft::vector_iterator<const value_type>		const_iterator; // a random access iterator to const value_type
			typedef				ft::reverse_iterator<iterator>				reverse_iterator; // reverse_iterator<iterator>
			typedef				ft::reverse_iterator<const_iterator>		const_reverse_iterator; // reverse_iterator<const_iterator>
			typedef				ptrdiff_t									difference_type; // a signed integral type, identical to: iterator_traits<iterator>::difference_type
			typedef				size_t										size_type; // an unsigned integral type that can represent any non-negative value of difference_type

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
					_alloc_type.construct(_vec + i, val);
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
					_alloc_type.construct(_vec + i, *first);

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
					_alloc_type.construct(_vec + _total, x[_total]);
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
					_alloc_type.construct(_vec + _total, x[_total]);
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
				return iterator(_vec);
			}

			const_iterator begin(void) const
			{
				return const_iterator(_vec);
			}

			// END
			      iterator end(void)
			{
				// const-qualified?
				return iterator(_vec + _total);
			}

			const_iterator end(void) const
			{
				return const_iterator(_vec + _total);
			}

			// RBEGIN
			      reverse_iterator rbegin(void)
				  {
					return reverse_iterator(this->end());
				  }
			const_reverse_iterator rbegin(void) const
			{
				return const_reverse_iterator(this->end());
			}

			// REND
			      reverse_iterator rend(void)
				  {
					return reverse_iterator(this->begin());
				  }
			const_reverse_iterator rend(void) const
			{
				return const_reverse_iterator(this->begin());
			}
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
						_alloc_type.construct(tmp + i, _vec[i]);
					for  (size_type i=_total; i<n; i++)
						_alloc_type.construct(tmp + i, val);
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
					_vec = _alloc_type.allocate(newcap);

					for (size_type i=0; i<_total; i++)
					{
						_alloc_type.construct(_vec + i, tmp[i]);
					}
					for (size_type i=_total; i<newcap; i++)
					{
						_alloc_type.construct(_vec + i, val);
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
					_vec = _alloc_type.allocate(n);

					for (size_type i=0; i<_total; i++)
					{
						_alloc_type.construct(_vec + i, tmp[i]);
					}
					for (size_type i=_total; i<n; i++)
					{
						_alloc_type.construct(_vec + i, value_type());
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
				size_type newcapacity;

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
					_alloc_type.construct(_vec + i, *first);
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
					_alloc_type.construct(_vec + i, val);
					_total++;
				}
			}


			void push_back (const value_type& val)
			{
				if (_total < _capacity)
				{
					_alloc_type.construct(_vec + _total, val);
					_total++;
				}

				else
				{
					if (_capacity == 0)
					{
						_alloc_type.deallocate(_vec, _capacity);
						_vec = _alloc_type.allocate(1);
						_alloc_type.construct(_vec + _total, val);
						_capacity = 1;
						_total = 1;
					}

					else
					{
						pointer tmp;

						tmp = _vec;
						_vec = _alloc_type.allocate(_capacity * 2);

						for (size_type i=0; i<_capacity; i++)
						{
							_alloc_type.construct(_vec + i, tmp[i]);
						}
						_alloc_type.construct(_vec + _total, val);
						_total++;
						
						_alloc_type.deallocate(tmp, _capacity);
						_capacity *= 2;
					}
				}
			}

			void pop_back(void)
			{
				_total--;
			}

			// single element (1)
			iterator insert (iterator position, const value_type& val)
			{
				// there is room
				if (_capacity > _total)
				{
					size_type skip = 0;
					while (position != (_vec + skip))
					{
						skip++;
					}

					for (size_type i=_total; i>skip; i--)
					{
						_alloc_type.construct(_vec + i, _vec[i - 1]);
					}

					_alloc_type.construct(_vec + skip, val);
					
					_total++;
					return _vec + skip;
				}

				// there is no room
				else
				{
					pointer tmp;
					size_type a = 0;

					tmp = _vec;
					_vec = _alloc_type.allocate(_capacity == 0 ? 1 : _capacity * 2);

					while (position != (_vec + a))
					{
						_alloc_type.construct(_vec + a, tmp[a]);
						a++;
					}

					_alloc_type.construct(_vec + a, val);

					for (size_t i=a+1; i<_total+1; i++)
					{
						_alloc_type.construct(_vec + i, tmp[i - 1]);
					}

					_alloc_type.deallocate(tmp, _capacity);
					_total++;
					_capacity++;

					return _vec + a;
				}
			}
			// fill (2)
			void insert (iterator position, size_type n, const value_type& val)
			{
				for (size_type i = 0; i < n; i++)
				{
					this->insert(position, val);
				}
			}
			// range (3)
			template <class InputIterator>
			void insert (iterator position, InputIterator first,
				typename ft::enable_if< !ft::is_integral<InputIterator>::value, InputIterator >::type last)
				// InputIterator last)
			{
				while (first != last)
				{
					this->insert(position, *first);
					position++;
					first++;
				}
			}

			iterator erase (iterator position)
			{
				size_type skip = 0;
				while (position != (_vec + skip))
				{
					skip++;
				}
				// _alloc_type.destroy(_vec[skip]);
				for (size_type i=skip; i<_total-1; i++)
				{
					_alloc_type.construct(_vec + i, _vec[i + 1]);
				}
				_total--;
				return position++;
			}
			iterator erase (iterator first, iterator last)
			{
				size_type first_ers = 0;
				while (first != (_vec + first_ers))
				{
					first_ers++;
				}

				size_type last_ers = first_ers;
				while (last != (_vec + last_ers))
				{
					last_ers++;
				}

				while (last_ers < _total)
				{
					_alloc_type.construct(_vec + first_ers, _vec[last_ers]);
					first_ers++;
					last_ers++;
				}

				_total = _total - (last - first);
				return last - first_ers;
			}

			void swap (vector& x)
			{
				pointer tmp;
				size_type tot;
				size_type cap;

				tmp = _vec;
				tot = _total;
				cap = _capacity;
				_vec = _alloc_type.allocate(x.capacity());
				for (size_type i = 0; i < x.size(); i++)
				{
					_alloc_type.construct(_vec + i, x[i]);
				}
				_total = x.size();
				_capacity = x.capacity();

				_alloc_type.deallocate(x._vec, x.capacity());
				x._vec = _alloc_type.allocate(cap);
				for (size_type i = 0; i < tot; i++)
				{
					_alloc_type.construct(x + i, tmp[i]);
				}
				x._total = tot;
				x._capacity = cap;

				_alloc_type.deallocate(tmp, cap);
			}

			void clear(void)
			{
				_alloc_type.destroy(_vec);
				_total = 0;
			}
			//												//
			//					MODIFIERS					//

			//					ALLOCATOR					//
			//												//
			allocator_type get_allocator() const
			{
				return _alloc_type;
			}
			//												//
			//					ALLOCATOR					//

	};

	//			RELATIONAL OPERATORS				//
	//												//
	// (1)
	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return false;

		return equal(lhs.begin(), lhs.end(), rhs.begin());
	}
	// (2)
	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(lhs == rhs);
	}
	// (3)
	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}
	// (4)
	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (lhs == rhs) || (lhs < rhs);
	}
	// (5)
	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (rhs < lhs);
	}
	// (6)
	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (rhs <= lhs);
	}
	//												//
	//			RELATIONAL OPERATORS				//

	//						SWAP					//
	//												//
	template <class T, class Alloc>
	void swap (ft::vector<T,Alloc>& x, ft::vector<T,Alloc>& y)
	{
		x.swap(y);
	}
	//												//
	//						SWAP					//

};

#endif