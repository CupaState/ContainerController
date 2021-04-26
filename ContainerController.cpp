#include "ContainerController.h"
#include <algorithm>
#include <set>

void ContainerController::DeleteRandomCountOfElements(std::vector<int>& vec)
{
	int index_for_delete = std::rand() % 15;
	vec.erase(vec.begin(), vec.begin() + index_for_delete);
}

//In this function, we remove the random number of elements, not the random elements themselves, as you might think at first glance.
void ContainerController::DeleteRandomCountOfElements(std::map<int, int>& m)
{
	int index_for_delete = std::rand() % 15;
	index_for_delete += 15;
	const std::map<int, int>::iterator it = m.find(index_for_delete);
	m.erase(it, m.end());
}

void ContainerController::FillRandomNumbers(std::vector<int>& vec)
{
	for (int i = 0; i < 30; ++i)
		vec[i] = std::rand() % 9;
}

void ContainerController::FillRandomNumbers(std::map<int, int>& m)
{
	for (int i = 0; i < 30; ++i)
		m.emplace(i, std::rand() % 9);
}

void ContainerController::PrintContainer(std::vector<int>& vec)
{
	for (int& el : vec)
		std::cout << el << '\t';
	std::cout << '\n';
}

void ContainerController::PrintContainer(std::map<int, int>& m)
{
	for (int i = 0; i < m.size(); ++i)
		std::cout << m[i] << '\t';
	std::cout << '\n';
}

void ContainerController::DeleteUniqueElements(std::vector<int>& vec, std::map<int, int>& m)
{
	std::set<int> m_set;	//to move duplicate elements to vector
	std::map<int, int> new_map;	//to move duplicate elements from m

	for (int i = 0; i < vec.size(); ++i)
	{
		auto iter = m.find(vec[i]);
		if (iter != m.end())
			m_set.emplace((*iter).second);
	}

	vec.clear();
	vec.resize(m_set.size());

	//Filling vector
	std::set<int>::iterator it = m_set.begin();
	for (int i = 0; i < m_set.size(); ++i)
	{
		vec[i] = *it;
		++it;
	}

	int index_map = 0;
	for (auto m_iterator = m.begin(); m_iterator != m.end(); ++m_iterator)
	{
		auto iter = m_set.find((*m_iterator).second);
		if (iter != m_set.end())
		{
			new_map.emplace(index_map, (*m_iterator).second);
			++index_map;
		}
	}

	m.clear();
	m = std::move(new_map);
}
