#include <iostream>
#include <vector>

#define pascalList std::vector<std::vector<int>>

constexpr int size = 10;

void outPut(pascalList list)
{
	for (std::vector<int> row : list)
	{
		for (int val : row)
		{
			std::cout << val << " ";
		}
		std::cout << std::endl;
	}
}

int main()
{
	pascalList list = { };

	for (int y = 0; y <= size; y++)
	{
		std::vector<int> nextLayer = { };

		for (int x = 0; x < y; x++)
		{
			int total = 0;

			if (y == 1)
			{
				nextLayer.push_back(1);
				continue;
			}

			// Gets up-Right
			if (x < list[y - 1].size()) { total += list[y - 1][x]; }
			// Gets up-Left
			if (x > 0) { total += list[y - 1][x-1]; }

			nextLayer.push_back(total);
		}

		list.push_back(nextLayer);
	}

	outPut(list);
}