#include "vector/vector.hpp"
#include <vector>

#include <iostream>
#include <exception>

int		main(void)
{
	// std::vector<int>::difference_type;
	// // // std::vector<int>::iterator it1;
	// // // std::vector<int>::const_iterator it2;
	// // // std::vector<int>::reverse_iterator it3;
	// // // std::vector<int>::const_reverse_iterator it4;

	int	arr[3] = {3, 2, 1};

	std::vector<int> 	their(arr, arr + 3);
	ft::vector<int>		mine(arr, arr + 3);
	// ft::vector<int>		mine(3, 2);

	// int	a,b;

	// a = their[0];
	// b = mine[0];
	// std::cout << "|" << a << "|" << std::endl;
	// std::cout << "|" << b << "|" << std::endl;

	// std::cout << std::endl;

	// a = their[1];
	// b = mine[1];
	// std::cout << "|" << a << "|" << std::endl;
	// std::cout << "|" << b << "|" << std::endl;

	// std::cout << std::endl;

	// a = their[2];
	// b = mine[2];
	// std::cout << "|" << a << "|" << std::endl;
	// std::cout << "|" << b << "|" << std::endl;

	// ft::vector<int> another(mine);

	// another = mine;

	// std::cout << "SIZE " << another.size() << std::endl;
	// std::cout << "CAPACITY " << another.capacity() << std::endl;

	// std::cout << "|" << another[0] << "|" << another[1] << "|" << another[2] << std::endl;

	// std::vector<int> their(10, 1337);
	// ft::vector<int> mine(10, 1337);
	std::vector<int>::iterator itstd = their.begin();
	ft::vector<int>::iterator itft = mine.begin();
	their.clear();
	their.pop_back();

	// // ----
	// std::vector<int> emptystd;
	// ft::vector<int> emptyft;

	// std::cout << *(emptyft.begin()) << std::endl;
	// std::cout << *(emptyft.end()) << std::endl;
	// // ----


	// itstd = their.end();
	// itft = mine.end();

	// std::cout << *itstd << std::endl;
	// std::cout << *itft << std::endl;

	// std::cout << mine[0] << std::endl;
	// std::cout << mine[1] << std::endl;
	// std::cout << mine[2] << std::endl;

	// // ----
	// itft = mine.begin();
	// int p;
	// p = *(++itft);
	// std::cout << p << std::endl;
	// p = *(++itft);
	// std::cout << p << std::endl;
	// p = *(++itft);
	// std::cout << p << std::endl;
	// // ----

	// // ----
	// itft = mine.begin();
	// std::cout << *itft++ << std::endl;
	// std::cout << *itft++ << std::endl;
	// std::cout << *itft++ << std::endl;
	// std::cout << ">>" << (itft == mine.end()) << "<<" << std::endl;
	// std::cout << *itft-- << std::endl;
	// std::cout << *itft-- << std::endl;
	// std::cout << *itft-- << std::endl;
	// std::cout << ">>" << (itft == mine.begin()) << "<<" << std::endl;
	// // ----


	// // ----
	// for (ft::vector<int>::iterator it = mine.begin(); it != mine.end(); it++)
	// {
	// 	std::cout << *it << std::endl;
	// }
	// // ----


	// // ----
	// ft::vector<int>::iterator itft2 = mine.begin();
	// itft = mine.begin();
	// itft2 = mine.begin();
	// itstd = their.begin();

	// std::cout << *(itft + 5) << std::endl;
	// std::cout << *(5 + itft) << std::endl;
	// std::cout << *(itft - 5) << std::endl;
	// std::cout << *(itft - itft2) << std::endl;
	// std::cout << *itft << std::endl;
	// itft += 3;
	// std::cout << *itft << std::endl;
	// itft -= 3;
	// std::cout << *itft << std::endl;
	// // ----


	// // ----
	// std::vector<int> vec1(3);

	// vec1[2] = 5;
	// vec1[1] = 10;
	// vec1[0] = 5;

	// std::vector<int>::iterator it1;
	// std::vector<int>::iterator it2;

	// it1 = vec1.begin();
	// it2 = vec1.end();

	// it2--;

	// it1+=1;

	// std::cout << *it1 << " " << *it2 << std::endl;
	// std::cout << *(it1 + 1) << std::endl;
	// std::cout << *(1 + it1) << std::endl;
	// std::cout << *(it1 - 1) << std::endl;
	// std::cout << (it1 > it2) << std::endl;
	// std::cout << (it1 < it2) << std::endl;
	// std::cout << (it1 == it2) << std::endl;
	// std::cout << std::endl;

	// for (std::vector<int>::iterator it=vec1.begin(); it!=vec1.end(); it++)
	// {
	// 	std::cout << *it << std::endl;
	// }
	// // ----


	// // ----
	// try {
	// 	their.push_back(2);
	// 	their.at(-1);
	// 	// their.at(2);
	// 	// mine.at(3);
	// } catch (std::out_of_range & e) {
	// 	std::cout << e.what() << std::endl; 
	// }
	// // ----


	// // ----
	// std::vector<int> posvecstd(1);
	// ft::vector<int> posvecft(1);

	// std::cout << posvecstd.front() << std::endl;
	// std::cout << posvecstd.back() << std::endl;
	// std::cout << std::endl;
	// std::cout << posvecft.front() << std::endl;
	// std::cout << posvecft.back() << std::endl;
	// // ----


	// // ----
	// std::vector<int>tmpvec(1, 1);
	// std::cout << their.capacity() << " capacity" << std::endl;
	// std::cout << their.size() << " size" << std::endl;
	// their.assign(tmpvec.begin(), (tmpvec.end()));
	// std::cout << their.capacity() << " capacity" << std::endl;
	// std::cout << their.size() << " size" << std::endl;
	// std::cout << "--------" << std::endl;
	// for (std::vector<int>::iterator it=their.begin(); it!=their.end(); it++)
	// {
	// 	std::cout << *it << std::endl;
	// }
	// // ----


	// // ----
	// ft::vector<int>tmpvec(1, 1);
	// std::cout << tmpvec.size() << " capacity" << std::endl;
	// tmpvec.pop_back();
	// std::cout << tmpvec.size() << " capacity" << std::endl;
	// tmpvec.pop_back();
	// std::cout << tmpvec.size() << " capacity" << std::endl;
	// // ----

	return 0;
}