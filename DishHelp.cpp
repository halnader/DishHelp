#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>

using namespace std;

const int SIZE = 10;
const int LIST = 20;

class Dish
{
	public:
		Dish()
		{
			dish = " ";
			prepTime = 0;
			size = SIZE;
			for (int i = 0; i < size; i++)
				ingred[i] = " ";
		}
		void ingredFill(ifstream & in)
		{
			string ingre = " ";
			size = 0;
			while(ingre != "*")
			{
				in >> ingre;
				if (ingre != "*")
				{
					ingred[size] = ingre;
					size++;
				}
			}
		}
		void print(ostream & out)
		{
			out << endl << dish << endl << "\nTime Required: " << prepTime << " min\n"
				<< "\nIngredients:\n\n";
			for (int i = 0; i < size; i++)
				out << setw(ingred[i].length() + 2) <<ingred[i] << endl;
		}	
		string dish;
		int prepTime;
		int size;
		string ingred[SIZE];
};

int main()
{
	ifstream fin("dishlist.txt");
	if(!fin)
		cout << "File Error";
	int numDishes = 0;
	Dish dishes[LIST];
	for (int i = 0; i < LIST; i++)
	{
		string dish = " ";
		int prep = 0;
		if(fin >> dishes[i].dish >> dishes[i].prepTime)
		{
			dishes[i].ingredFill(fin);
			numDishes++;
		}
	}
	
	srand(time(NULL));
	
	int cont = -1;
	while (cont != 0)
	{
		cin >> cont;
		if (cont == 1)
		{
			system("CLS");
			int choice = rand() % numDishes;
			dishes[choice].print(cout);
		}
	}
		
	return EXIT_SUCCESS;
}
