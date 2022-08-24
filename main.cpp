#include "vector/vector.hpp"
#include <vector>

#include <iostream>
#include <exception>

#define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))

int		main(void)
{
	// std::vector<int>::difference_type;
	// // // std::vector<int>::iterator it1;
	// // // std::vector<int>::const_iterator it2;
	// // // std::vector<int>::reverse_iterator it3;
	// // // std::vector<int>::const_reverse_iterator it4;

	// int	arr[3] = {3, 2, 1};

	// std::vector<int> 	their(arr, arr + 3);
	// ft::vector<int>		mine(arr, arr + 3);
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
	// std::vector<int>::iterator itstd = their.begin();
	// ft::vector<int>::iterator itft = mine.begin();
	// their.clear();
	// their.pop_back();

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
	// ft::vector<int>swp1;
	// ft::vector<int>swp2;

	// swp1.push_back(1);
	// swp1.push_back(2);
	// swp1.push_back(3);
	// swp1.push_back(4);

	// swp2.push_back(2);
	// swp2.push_back(1);

	// std::cout << "Capacity " << swp1.capacity() << " Size     " << swp1.size() << std::endl;
	// for (size_t i = 0; i < swp1.size(); i++)
	// {
	// 	std::cout << swp1[i] << " ";
	// }
	// std::cout << "\t\tSWAP 1" << std::endl;
	// std::cout << "Capacity " << swp2.capacity() << " Size     " << swp2.size() << std::endl;
	// for (size_t i = 0; i < swp2.size(); i++)
	// {
	// 	std::cout << swp2[i] << " ";
	// }
	// std::cout << "\t\t\tSWAP 2" << std::endl;
	// std::cout << std::endl;

	// swp1.swap(swp2);

	// std::cout << "Capacity " << swp1.capacity() << " Size     " << swp1.size() << std::endl;
	// for (size_t i = 0; i < swp1.size(); i++)
	// {
	// 	std::cout << swp1[i] << " ";
	// }
	// std::cout << "\t\t\tSWAP 1" << std::endl;
	// std::cout << "Capacity " << swp2.capacity() << " Size     " << swp2.size() << std::endl;
	// for (size_t i = 0; i < swp2.size(); i++)
	// {
	// 	std::cout << swp2[i] << " ";
	// }
	// std::cout << "\t\tSWAP 2" << std::endl;
	// std::cout << std::endl;
	// // ----


	// // ---- REVERSE ITERATOR
	// ft::vector<std::string> rev_vec;
	// ft::vector<std::string>::iterator rev_vec_it;
	// ft::vector<std::string>::reverse_iterator rev_it_begin;
	// ft::vector<std::string>::reverse_iterator rev_it_end();

	// rev_vec.push_back("one");
	// rev_vec.push_back("two");
	// rev_vec.push_back("three");
	// rev_vec.push_back("four");
	// rev_vec.push_back("five");

	// rev_vec_it = rev_vec.begin();

	// for (ft::vector<std::string>::iterator it=rev_vec_it; it!=rev_vec.end(); it++)
	// {
	// 	std::cout << *it << " ";
	// }
	// std::cout << std::endl;



	// // TEST
	// ft::vector<int> myvector1;
	// for (int i=0; i<10; i++) myvector1.push_back(i);

	// typedef ft::vector<int>::iterator iter_type1;

	// ft::reverse_iterator<iter_type1> rev_begin1 (myvector1.end());
	// ft::reverse_iterator<iter_type1> rev_end1 (myvector1.begin());

	// ft::reverse_iterator<iter_type1> rev_iterator = rev_begin1;
	// while ( rev_iterator != rev_end1 )
	// 	std::cout << *rev_iterator++ << ' ';
	// std::cout << '\n';

	// while ( rev_iterator != rev_begin1 )
	// 	std::cout << *(--rev_iterator) << ' ';
	// std::cout << '\n';
	// // TEST


	// // OPERATOR+ NON MEMBER
	// ft::vector<int> myvector2;
	// for (int i=0; i<10; i++) myvector2.push_back(i);	// myvector2: 0 1 2 3 4 5 6 7 8 9

	// typedef ft::vector<int>::iterator iter_type2;

	// ft::reverse_iterator<iter_type2> rev_it2;

	// rev_it2 = 3 + myvector2.rbegin();

	// std::cout << "The fourth element from the end is: " << *rev_it2 << '\n';
	// // OPERATOR+ NON MEMBER


	// // OPERATOR- NON MEMBER
	// ft::vector<int> myvector3;
	// for (int i=0; i<10; i++) myvector3.push_back(i);

	// ft::reverse_iterator<ft::vector<int>::iterator> from3,until3;

	// from3 = myvector3.rbegin();
	// until3 = myvector3.rend();

	// std::cout << "myvector has " << (until3-from3) << " elements.\n";
	// // OPERATOR- NON MEMBER


	// // RELATIONAL OPERATORS NON MEMBER
	// ft::vector<int> myvector4;
	// for (int i=0; i<10; i++) myvector4.push_back(i);

	// typedef ft::vector<int>::iterator iter_type4;

	// iter_type4 from4 (myvector4.begin());
	// iter_type4 until4 (myvector4.end());

	// ft::reverse_iterator<iter_type4> rev_until4 (from4);
	// ft::reverse_iterator<iter_type4> rev_from4 (until4);

	// std::cout << "result " << (rev_until4 < rev_from4) << ".\n";
	// std::cout << "result " << (rev_until4 <= rev_from4) << ".\n";
	// std::cout << "result " << (rev_until4 > rev_from4) << ".\n";
	// std::cout << "result " << (rev_until4 >= rev_from4) << ".\n";
	// std::cout << "result " << (rev_until4 == rev_from4) << ".\n";
	// std::cout << "result " << (rev_until4 != rev_from4) << ".\n";

	// std::cout << "myvector4:";
	// while (rev_from4 != rev_until4)
	// 	std::cout << ' ' << *rev_from4++;
	// std::cout << '\n';
	// // RELATIONAL OPERATORS NON MEMBER

        /*------------------ std::vectors ---------------------*/
        std::vector<std::string> v1(10, "string1");
        std::vector<std::string> v2(10, "string2");
        v1 = v2;
        /*-----------------------------------------------------*/
        /*------------------ ft::vectors ---------------------*/
        ft::vector<std::string> ft_v1(10, "string1");
        ft::vector<std::string> ft_v2(10, "string2");
        ft_v1 = ft_v2;
        /*----------------------------------------------------*/
        /*------------------ strings to store the results ----*/
        std::string res, ft_res;
        /*----------------------------------------------------*/
        for (std::vector<std::string>::iterator it = v1.begin(); it != v1.end(); ++it) // fill res from v1
            res += *it;

        for (ft::vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it) // fill ft_res from ft_v1
            ft_res += *it;

        EQUAL(res == ft_res);

	return 0;
}