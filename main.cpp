#include <map>
#include <vector>
#include <string>
#include <iostream>

#include "map/map.hpp"
#include "pair/make_pair.hpp"

void	ft_map()
{
	{
		ft::map<int, std::string> m1;

		m1.insert(ft::make_pair(0, "zero"));
		m1.insert(ft::make_pair(1, "one"));
		m1.insert(ft::make_pair(2, "two"));
		m1.insert(ft::make_pair(3, "three"));
		m1.insert(ft::make_pair(4, "four"));
		m1.insert(ft::make_pair(5, "five"));
		m1.insert(ft::make_pair(6, "six"));
		m1.insert(ft::make_pair(7, "seven"));
		m1.insert(ft::make_pair(8, "eight"));
		m1.insert(ft::make_pair(9, "nine"));
		m1.insert(ft::make_pair(10, "ten"));

		{
			std::cout << std::endl << "-----------" << std::endl;
			std::cout << m1[0] << std::endl;
			std::cout << m1[1] << std::endl;
			std::cout << m1[2] << std::endl;
			std::cout << m1[3] << std::endl;
			std::cout << m1[4] << std::endl;
			std::cout << m1[5] << std::endl;
			std::cout << m1[6] << std::endl;
			std::cout << m1[7] << std::endl;
			std::cout << m1[8] << std::endl;
			std::cout << m1[9] << std::endl;
			std::cout << m1[10] << std::endl;
		}


		// // ---------------- ITERATOR
		{
			std::cout << std::endl << "-----------" << std::endl;
			ft::map<int, std::string>::iterator it = m1.begin();
			std::cout << (*it).first << " - " << (*it).second << std::endl;
			++it;
			std::cout << (*it).first << " - " << (*it).second << std::endl;
			++it;
			std::cout << (*it).first << " - " << (*it).second << std::endl;
			++it;
			std::cout << (*it).first << " - " << (*it).second << std::endl;
			++it;
			std::cout << (*it).first << " - " << (*it).second << std::endl;
			++it;
			std::cout << (*it).first << " - " << (*it).second << std::endl;
			++it;
			std::cout << (*it).first << " - " << (*it).second << std::endl;
			++it;
			std::cout << (*it).first << " - " << (*it).second << std::endl;
			++it;
			std::cout << (*it).first << " - " << (*it).second << std::endl;
			++it;
			std::cout << (*it).first << " - " << (*it).second << std::endl;
			++it;
			std::cout << (*it).first << " - " << (*it).second << std::endl;

			std::cout << std::endl;

			std::cout << (*it).first << " - " << (*it).second << std::endl;
			--it;
			std::cout << (*it).first << " - " << (*it).second << std::endl;
			--it;
			std::cout << (*it).first << " - " << (*it).second << std::endl;
			--it;
			std::cout << (*it).first << " - " << (*it).second << std::endl;
			--it;
			std::cout << (*it).first << " - " << (*it).second << std::endl;
			--it;
			std::cout << (*it).first << " - " << (*it).second << std::endl;
			--it;
			std::cout << (*it).first << " - " << (*it).second << std::endl;
			--it;
			std::cout << (*it).first << " - " << (*it).second << std::endl;
			--it;
			std::cout << (*it).first << " - " << (*it).second << std::endl;
			--it;
			std::cout << (*it).first << " - " << (*it).second << std::endl;
			--it;
			std::cout << (*it).first << " - " << (*it).second << std::endl;
		}
		// // ---------------- ITERATOR

		{
			std::cout << std::endl << "-----------" << std::endl;
			m1.erase(m1.begin(), m1.end());

			std::cout << "size now is " << m1.size() << std::endl;
			std::cout << std::endl << "-----------" << std::endl;
		}
	}
}

void	ft_vector()
{
	{
		// ----
		ft::vector<int>clr;

		clr.push_back(1);
		clr.push_back(2);
		clr.push_back(3);

		std::cout << "Capacity " << clr.capacity() << std::endl;
		std::cout << "Size     " << clr.size() << std::endl;

		clr.clear();

		std::cout << "Capacity " << clr.capacity() << std::endl;
		std::cout << "Size     " << clr.size() << std::endl;
		// ----
		std::cout << std::endl << "-----------" << std::endl;
	}

	{
		// ----
		ft::vector<int>swp1;
		ft::vector<int>swp2;

		swp1.push_back(1);
		swp1.push_back(2);
		swp1.push_back(3);
		swp1.push_back(4);

		swp2.push_back(2);
		swp2.push_back(1);

		ft::vector<int>::iterator swp1it = swp1.begin();
		ft::vector<int>::iterator swp2it = swp2.begin();
		std::cout << "|||" << *swp1it << "|||" << std::endl;
		std::cout << "|||" << *swp2it << "|||" << std::endl;

		std::cout << "Capacity " << swp1.capacity() << " Size     " << swp1.size() << std::endl;
		for (size_t i = 0; i < swp1.size(); i++)
		{
			std::cout << swp1[i] << " ";
		}
		std::cout << "\t\tVECTOR 1" << std::endl;
		std::cout << "Capacity " << swp2.capacity() << " Size     " << swp2.size() << std::endl;
		for (size_t i = 0; i < swp2.size(); i++)
		{
			std::cout << swp2[i] << " ";
		}
		std::cout << "\t\t\tVECTOR 2" << std::endl;
		std::cout << std::endl;

		//			//
		swp1.swap(swp2);
		//			//

		std::cout << "Capacity " << swp1.capacity() << " Size     " << swp1.size() << std::endl;
		for (size_t i = 0; i < swp1.size(); i++)
		{
			std::cout << swp1[i] << " ";
		}
		std::cout << "\t\t\tVECTOR 1" << std::endl;
		std::cout << "Capacity " << swp2.capacity() << " Size     " << swp2.size() << std::endl;
		for (size_t i = 0; i < swp2.size(); i++)
		{
			std::cout << swp2[i] << " ";
		}
		std::cout << "\t\tVECTOR 2" << std::endl;
		std::cout << "|||" << *swp1it << "|||" << std::endl;
		std::cout << "|||" << *swp2it << "|||" << std::endl;
		// ----
		std::cout << std::endl << "-----------" << std::endl;
	}

	{
		std::vector<int> their(10, 1337);
		ft::vector<int> mine(10, 1337);

		std::vector<int>::iterator itstd = their.begin();
		ft::vector<int>::iterator itft = mine.begin();

		std::cout << *itstd++ << " " << *itstd++ << " " << *itstd++ << " " << *itstd++ << " " << *itstd++ << " " << *itstd++ << " " << *itstd++ << " " << *itstd++ << " " << *itstd++ << " " << *itstd++ << " " << std::endl;
		std::cout << *itft++ << " " << *itft++ << " " << *itft++ << " " << *itft++ << " " << *itft++ << " " << *itft++ << " " << *itft++ << " " << *itft++ << " " << *itft++ << " " << *itft++ << " " << std::endl;
		std::cout << std::endl << "-----------" << std::endl;
	}

	{
	ft::vector<int> v1(1, 2);

	ft::vector<int>::iterator it1 = v1.begin();
	const ft::vector<int>::const_iterator cit1 = v1.begin();

	std::cout << (it1 == cit1) << std::endl;
	std::cout << (it1 != cit1) << std::endl;
	}
}

int		main()
{
	ft_map();

	ft_vector();

	std::cout << std::endl << "-----------" << std::endl;
	system("leaks a.out");

	return 0;
}