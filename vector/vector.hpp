#ifndef		VECTOR_HPP
# define	VECTOR_HPP

// ptrdiff_t
# include <cstddef>
// allocator
# include <memory>
// vector iterator
# include <vector>
// out of range
# include <exception>
# include "random_iterator_vector.hpp"
# include "../other/reverse_iterator.hpp"
# include "../other/enable_if.hpp"
# include "../other/is_integral.hpp"
# include "../other/equal.hpp"
# include "../other/lexicographical_compare.hpp"

namespace ft {

	template < class T, class Alloc = std::allocator<T> >
	class vector {

		public:
			typedef				T											value_type; // The first template parameter (T)
			typedef				Alloc										allocator_type; // The second template parameter (Alloc)
			typedef	typename	allocator_type::reference					reference; // allocator_type::reference
			typedef	typename	allocator_type::const_reference				const_reference; // allocator_type::const_reference
			typedef	typename	allocator_type::pointer						pointer; // allocator_type::pointer
			typedef	typename	allocator_type::const_pointer				const_pointer; // allocator_type::const_pointer
			typedef				ft::vector_iterator<pointer>				iterator; // a random access iterator to value_type	convertible to const_iterator
			typedef				ft::vector_iterator<const_pointer>				const_iterator; // a random access iterator to const value_type
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
				_alloc_type = alloc;
				_vec = _alloc_type.allocate(n);
				for (size_type i = 0; i < _capacity; i++)
				{
					_alloc_type.construct(_vec + i, val);
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
			vector (typename ft::enable_if< !ft::is_integral<InputIterator>::value, InputIterator >::type first,
					InputIterator last,
					const allocator_type& alloc = allocator_type())
					: _capacity(0), _total(0)
			{
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
				for (size_type i=0; i<_total; i++)
					_alloc_type.destroy(_vec + i);

				_alloc_type.deallocate(_vec, _capacity);

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
				// destroy
				for (size_type i=0; i<_total; i++)
					_alloc_type.destroy(_vec + i);

				// deallocate
				_alloc_type.deallocate(_vec, _capacity);

				// allocate
				_vec = _alloc_type.allocate(x._capacity);
				_capacity = x._capacity;
				_total = 0;

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
				if (_capacity >= n)
				{
					for (size_type i = _total; i < n; i++)
						_alloc_type.construct(_vec + i, val);

					for (size_type i = n; i < _total; i++)
						_alloc_type.destroy(_vec + i);

					_total = n;
				}

				// increase
				else
				{
					pointer tmp;
					size_type newcap;

					newcap = (_capacity * 2) > n ? _capacity * 2 : n;

					if (newcap > max_size())
						throw std::length_error("ft::vector::resize");

					tmp = _alloc_type.allocate(newcap);

					for (size_type i=0; i<_total; i++)
						_alloc_type.construct(tmp + i, _vec[i]);

					for (size_type i=_total; i<newcap; i++)
						_alloc_type.construct(tmp + i, val);

					for (size_type i=0; i<_total; i++)
						_alloc_type.destroy(_vec + i);

					_alloc_type.deallocate(_vec, _capacity);
					_total = _capacity = n;
					_vec = tmp;
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
				if (n > max_size())
					throw std::length_error("ft::vector::reserve");
				if (n > _capacity)
				{
					pointer tmp;

					tmp = _vec;
					_vec = _alloc_type.allocate(n);

					for (size_type i=0; i<_total; i++)
						_alloc_type.construct(_vec + i, tmp[i]);

					for (size_type i=_total; i<n; i++)
						_alloc_type.construct(_vec + i, value_type());

					for (size_type i=0; i<_total; i++)
						_alloc_type.destroy(_vec + i);

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
				return _vec[n];
			}

			const_reference operator[] (size_type n) const
			{
				return _vec[n];
			}

			      reference at (size_type n)
			{
				if (n >= _total)
					throw std::out_of_range("vector");
				return _vec[n];
			}
			const_reference at (size_type n) const
			{
				if (n >= _capacity)
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
				_alloc_type.destroy(_vec + (_total - 1));
				_total--;
			}

			// single element (1)
			iterator insert (iterator position, const value_type& val)
			{
				difference_type dist;
				dist = std::distance(this->begin(), position);

				if ( _capacity == _total )
				{
					if ( _capacity == 0 )
						this->reserve(1); // length error
					else
						this->reserve(_capacity * 2); // length error
				}

				for (difference_type i=_total; i>dist; i--)
					_alloc_type.construct(_vec + i, _vec[i - 1]);

				_alloc_type.construct(_vec + dist, val);
				++_total;
				return iterator(_vec + dist);
			}
			// fill (2)
			void insert (iterator position, size_type n, const value_type& val)
			{
				difference_type dist = std::distance(begin(), position);

				if (_total == 0)
					reserve(n);
				else if (_total + n > _capacity)
				{
					if (_capacity * 2 >= _total + n)
						reserve(_capacity * 2);
					else
						reserve(_total + n);
				}

				for (difference_type i = _total - 1;i >= dist;--i)
					_alloc_type.construct(_vec + (i + n), _vec[i]);

				for (size_t i = 0; i < n; ++i)
					_alloc_type.construct(_vec + dist++, val);

				_total += n;
			}
			// range (3)
			template <class InputIterator>
			void insert (iterator position, InputIterator first,
				typename ft::enable_if< !ft::is_integral<InputIterator>::value, InputIterator >::type last)
			{
				size_type n;

				n = std::distance(first, last);

				// there is room
				if (_capacity >= _total + n)
				{
					while (first != last)
					{
						this->insert(position, *first);
						first++;
					}
				}

				// there is not
				else
				{
					size_type newcapacity;
					size_type pos_at;
					pointer tmp;

					newcapacity = ((_capacity * 2) > (n + _total)) ? _capacity * 2 : n + _total;
					pos_at = std::distance(this->begin(), position);

					if (newcapacity > max_size())
						throw std::length_error("ft::vector::insert (3)");

					tmp = _alloc_type.allocate(newcapacity);

					for (size_type i=0; i<pos_at; i++)
						_alloc_type.construct(tmp + i, _vec[i]);

					for (size_type i=pos_at; i<pos_at+n; i++)
					{
						_alloc_type.construct(tmp + i, *first);
						first++;
					}

					for (size_type i=pos_at+n; i<_total+n; i++)
						_alloc_type.construct(tmp + i, _vec[i - n]);

					for (size_type i=0; i<_total; i++)
						_alloc_type.destroy(_vec + i);

					_alloc_type.deallocate(_vec, _capacity);
					_vec = tmp;
					_total += n;
					_capacity = newcapacity;
				}
			}

			iterator erase (iterator position)
			{
				size_type skip = 0;
				while (position != iterator(_vec + skip))
					skip++;

				for (size_type i=skip; i<_total-1; i++)
					_alloc_type.construct(_vec + i, _vec[i + 1]);

				_total--;
				return position++;
			}
			iterator erase (iterator first, iterator last)
			{
				size_type first_ers = 0;
				while (first != iterator(_vec + first_ers))
					first_ers++;

				size_type last_ers = first_ers;
				while (last != iterator(_vec + last_ers))
					last_ers++;

				while (last_ers < _total)
				{
					_alloc_type.construct(_vec + first_ers, _vec[last_ers]);
					first_ers++;
					last_ers++;
				}

				_total = _total - (last - first);
				return first;
			}

			void swap (vector& x)
			{
				pointer tmp;
				size_type tot;
				size_type cap;

				tmp = _vec;
				tot = _total;
				cap = _capacity;

				_total = x.size();
				_capacity = x.capacity();
				_vec = x._vec;

				x._total = tot;
				x._capacity = cap;
				x._vec = tmp;
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
	// (1)
	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return false;

		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
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
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
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
	//			RELATIONAL OPERATORS				//

	//						SWAP					//
	template <class T, class Alloc>
	void swap (ft::vector<T,Alloc>& x, ft::vector<T,Alloc>& y)
	{
		x.swap(y);
	}
	//						SWAP					//

};

#endif