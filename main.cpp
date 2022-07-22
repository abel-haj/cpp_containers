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


	// // ----
	// std::vector<int> pushvec;

	// std::cout << "SIZE " << pushvec.size() << std::endl;
	// std::cout << "CAP  " << pushvec.capacity() << std::endl;

	// pushvec.push_back(1);

	// std::cout << "SIZE " << pushvec.size() << std::endl;
	// std::cout << "CAP  " << pushvec.capacity() << std::endl;

	// pushvec.push_back(1);

	// std::cout << "SIZE " << pushvec.size() << std::endl;
	// std::cout << "CAP  " << pushvec.capacity() << std::endl;

	// pushvec.push_back(1);

	// std::cout << "SIZE " << pushvec.size() << std::endl;
	// std::cout << "CAP  " << pushvec.capacity() << std::endl;

	// pushvec.push_back(1);

	// std::cout << "SIZE " << pushvec.size() << std::endl;
	// std::cout << "CAP  " << pushvec.capacity() << std::endl;

	// pushvec.push_back(1);

	// std::cout << "SIZE " << pushvec.size() << std::endl;
	// std::cout << "CAP  " << pushvec.capacity() << std::endl;

	// for (size_t i = 0; i < pushvec.size(); i++)
	// {
	// 	std::cout << pushvec.at(i) << std::endl;
	// }
	// // ----


	// // ----
	// // std::vector<int> falseInser;
	// std::vector<int> inser;
	// std::vector<int>::iterator inserIt;


	// inser.push_back(1);
	// inser.push_back(2);
	// inser.push_back(3);
	// inser.push_back(4);
	// inser.push_back(5);


	// inserIt = inser.begin();
	// for (size_t i = 0; i < 5; i++)
	// {
	// 	inserIt++;
	// }
	// if (inserIt == inser.end())
	// 	std::cout << "YES" << std::endl;
	// else
	// 	std::cout << "NO" << std::endl;
	// inser.insert(inserIt, 0);


	// // std::cout << "Capacity " << inser.capacity() << std::endl; // 5
	// // std::cout << "Size     " << inser.size() << std::endl; // 8
	// for (size_t i = 0; i < inser.size(); i++)
	// {
	// 	std::cout << inser[i] << std::endl;
	// }
	// // std::cout << std::endl;


	// // inserIt = inser.begin();
	// // inser.insert(inserIt, 10);


	// // std::cout << inser.capacity() << std::endl;
	// // std::cout << inser.size() << std::endl;
	// // std::cout << std::endl;
	// // ----


	// // ----
	// ft::vector<int>clr;

	// clr.push_back(1);
	// clr.push_back(2);
	// clr.push_back(3);

	// std::cout << "Capacity " << clr.capacity() << std::endl;
	// std::cout << "Size     " << clr.size() << std::endl;
	// std::cout << clr[1] << std::endl;

	// clr.clear();

	// std::cout << "Capacity " << clr.capacity() << std::endl;
	// std::cout << "Size     " << clr.size() << std::endl;
	// std::cout << clr[1] << std::endl;
	// // ----


	// // ----
	ft::vector<int>swp1;
	ft::vector<int>swp2;

	swp1.push_back(1);
	swp1.push_back(2);
	swp1.push_back(3);
	swp1.push_back(4);

	swp2.push_back(2);
	swp2.push_back(1);

	std::cout << "Capacity " << swp1.capacity() << " Size     " << swp1.size() << std::endl;
	for (size_t i = 0; i < swp1.size(); i++)
	{
		std::cout << swp1[i] << " ";
	}
	std::cout << "\t\tSWAP 1" << std::endl;
	std::cout << "Capacity " << swp2.capacity() << " Size     " << swp2.size() << std::endl;
	for (size_t i = 0; i < swp2.size(); i++)
	{
		std::cout << swp2[i] << " ";
	}
	std::cout << "\t\t\tSWAP 2" << std::endl;
	std::cout << std::endl;

	swp1.swap(swp2);

	std::cout << "Capacity " << swp1.capacity() << " Size     " << swp1.size() << std::endl;
	for (size_t i = 0; i < swp1.size(); i++)
	{
		std::cout << swp1[i] << " ";
	}
	std::cout << "\t\t\tSWAP 1" << std::endl;
	std::cout << "Capacity " << swp2.capacity() << " Size     " << swp2.size() << std::endl;
	for (size_t i = 0; i < swp2.size(); i++)
	{
		std::cout << swp2[i] << " ";
	}
	std::cout << "\t\tSWAP 2" << std::endl;
	std::cout << std::endl;
	
	// // ----

	return 0;
}