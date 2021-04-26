#pragma once
#include <vector>
#include <map>
#include <iostream>
#include <random>

class ContainerController
{
public:
	ContainerController() = default;
	~ContainerController() = default;

	void DeleteRandomCountOfElements(std::vector<int>& vec);
	void DeleteRandomCountOfElements(std::map<int, int>& m);
	void FillRandomNumbers(std::vector<int>& vec);
	void FillRandomNumbers(std::map<int, int>& m);
	void PrintContainer(std::vector<int>& vec);
	void PrintContainer(std::map<int, int>& m);
	void DeleteUniqueElements(std::vector<int>& vec, std::map<int, int>& m);
};

