#include "Graph.h"
#include<iostream>

int check();
bool twoSAT(int countVer, int  countEdge);

int main()
{
	setlocale(0, "");
	std::cout << "Введите количество вершин\n";
	int countVer = check();

	std::cout << "Введите количество ребер\n";
	int countEdge = check();

	bool result = twoSAT(countVer, countEdge);
	if (result == true)
		std::cout << "YES\n";
	else
		std::cout << "NO\n";

	return 0;
}

int check()
{
	int x;
	std::cin >> x;
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		std::cout << "Нужно ввести число\n";
		std::cin >> x;
	}
	return x;
}


bool twoSAT(int countVer, int  countEdge)
{
	int v1, v2, value;
	std::string operation;
	Graph graph(2 * countVer);

	for (int i = 0; i < countEdge; i++)
	{
		std::cout << "Введите две вершины ребра\n";
		std::cin >> v1 >> v2;

		std::cout << "Введите значение ребра\n";
		std::cin >> value;

		std::cout << "Введите операцию ребра\n";
		std::cin >> operation;

		if (operation == "OR")
		{
			if (value == 1)
			{
				graph.addEdge(2 * v1 - 1, 2 * v2 - 2);
				graph.addEdge(2 * v2 - 1, 2 * v1 - 2);
			}

			if (value == 0)
			{
				graph.addEdge(2 * v1 - 2, 2 * v1 - 1);
				graph.addEdge(2 * v2 - 2, 2 * v2 - 1);
			}
		}

		if (operation == "AND")
		{
			if (value == 1)
			{
				graph.addEdge(2 * v1 - 1, 2 * v1 - 2);
				graph.addEdge(2 * v2 - 1, 2 * v2 - 2);
			}

			if (value == 0)
			{
				graph.addEdge(2 * v1 - 2, 2 * v2 - 1);
				graph.addEdge(2 * v2 - 2, 2 * v1 - 1);
			}
		}

		if (operation == "XOR")
		{
			if (value == 1)
			{
				graph.addEdge(2 * v1 - 1, 2 * v2 - 2);
				graph.addEdge(2 * v2 - 1, 2 * v1 - 2);
				graph.addEdge(2 * v2 - 2, 2 * v1 - 1);
				graph.addEdge(2 * v1 - 2, 2 * v2 - 1);
			}

			if (value == 0)
			{
				graph.addEdge(2 * v1 - 2, 2 * v2 - 2);
				graph.addEdge(2 * v2 - 1, 2 * v1 - 1);
				graph.addEdge(2 * v2 - 2, 2 * v1 - 2);
				graph.addEdge(2 * v1 - 1, 2 * v2 - 1);
			}
		}

	}

	std::string sortVer;
	int* components = graph.graphComp(sortVer);

	bool result = true;
	for (int i = 0; i < 2 * countVer - 1; i += 2)
	{
		if (components[i] == components[i + 1])result = false;
	}

	return result;
}