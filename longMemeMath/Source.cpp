#include <iostream>
#include <string>
#include <regex>
#include <vector>
using namespace std;
class math
{
private:
	void plus(vector<int> num1, vector<int> num2)
	{
		if (num1.size() >= num2.size())
		{
			int temp = num1.size() - 1;
			for (int a = num2.size(); a > 0; a--)
			{
				num1[temp] += num2[a - 1];
				if (num1[temp] >= 10)
				{
					if (temp == 0)
						cout << "";
					else
					{
						num1[temp] -= 10;
						num1[temp - 1] += 1;
					}
				}
				temp--;
			}
			cout << "Answer: ";
			for (int a = 0; a < num1.size(); a++)
				cout << num1[a];
			cout << endl << endl;
		}
		else
		{
			vector<int> tempArray = num1;
			num1 = num2;
			num2 = tempArray;
			int temp = num1.size() - 1;
			for (int a = num2.size(); a > 0; a--)
			{
				num1[temp] += num2[a - 1];
				if (num1[temp] >= 10)
				{
					if (temp == 0)
						cout << "";
					else
					{
						num1[temp] -= 10;
						num1[temp - 1] += 1;
					}
				}
				temp--;
			}
			cout << "Answer: ";
			for (int a = 0; a < num1.size(); a++)
				cout << num1[a];
			cout << endl << endl;
		}
	}
	void minus(vector<int> num1, vector<int> num2)
	{
		if (num1.size() > num2.size())
		{
			int temp = num1.size() - 1;
			for (int a = num2.size(); a > 0; a--)
			{
				num1[temp] -= num2[a - 1];
				if (num1[temp] < 0)
				{
					num1[temp] += 10;
					num1[temp - 1]--;
				}
				temp--;
			}
			cout << "Answer: ";
			for (int a = 0; a < num1.size(); a++)
					cout << num1[a];
			cout << endl << endl;
		}
		else if (num1.size() < num2.size())
		{
			vector<int> tempArray = num1;
			num1 = num2;
			num2 = tempArray;
			int temp = num1.size() - 1;
			for (int a = num2.size(); a > 0; a--)
			{
				num1[temp] -= num2[a - 1];
				if (num1[temp] < 0)
				{
					num1[temp] += 10;
					num1[temp - 1]--;
				}
				temp--;
			}
			cout << "Answer: -";
			for (int a = 0; a < num1.size(); a++)
				cout << num1[a];
			cout << endl << endl;
		}
		else if (num2.size() == num2.size())
		{
			for (int a = 0; a < num1.size(); a++)
			{
				if (num1[a] == num2[a])
				{
					if (a == num1.size() - 1)
					{
						cout << "Answer: 0" << endl;
						break;
					}
					continue;
				}
				else if (num1[a] < num2[a])
				{
					vector<int> tempArray = num1;
					num1 = num2;
					num2 = tempArray;
					int temp = num1.size() - 1;
					for (int a = num2.size(); a > 0; a--)
					{
						num1[temp] -= num2[a - 1];
						if (num1[temp] < 0)
						{
							num1[temp] += 10;
							num1[temp - 1]--;
						}
						temp--;
					}
					cout << "Answer: -";
					for (int a = 0; a < num1.size(); a++)
						cout << num1[a];
					cout << endl << endl;
					break;
				}
				else if (num1[a] > num2[a])
				{
					int temp = num1.size() - 1;
					for (int a = num2.size(); a > 0; a--)
					{
						num1[temp] -= num2[a - 1];
						if (num1[temp] < 0)
						{
							num1[temp] += 10;
							num1[temp - 1]--;
						}
						temp--;
					}
					cout << "Answer: ";
					for (int a = 0; a < num1.size(); a++)
						cout << num1[a];
					cout << endl << endl;
					break;
				}
			}
		}
	}
	void multi(vector<int> num1, vector<int> num2)
	{
		
	}
	void divison(vector<int> num1, vector<int> num2A)
	{

	}
public:
	void conver(string num1, string num2, int option)
	{
		vector<int> num1Array;
		int i;
		string temp;
		for (int a = 0; a < num1.size(); a++)
		{
			temp = num1[a];
			i = stoi(temp);
			num1Array.push_back(i);
		}
		vector<int> num2Array;
		for (int a = 0; a < num2.size(); a++)
		{
			temp = num2[a];
			i = stoi(temp);
			num2Array.push_back(i);
		}
		if (option == 1)
			plus(num1Array, num2Array);
		else if (option == 2)
			minus(num1Array, num2Array);
		else if (option == 3)
			multi(num1Array, num2Array);
		else
			divison(num1Array, num2Array);

	}
};
int main()
{
	while (1)
	{
		math math;
		cout << "Enter first number: " << endl;
		string num1;
		cin >> num1;
		cmatch check;
		regex reg("[\\D]");
		if (regex_search(num1.c_str(), check, reg))
		{
			cout << "Incorrect symbol was detected" << endl;
			system("pause");
			break;
		}
		string temp;
		temp = num1[0];
		int i;
		try
		{
			i = stoi(temp);
		}
		catch (const std::exception&)
		{
			cout << "Error. Is it Alt+2+6?" << endl;
			system("pause");
			break;
		}
		if (i == 0)
		{
			cout << "Try again" << endl;
			continue;
		}
		cout << "Enter second number: " << endl;
		string num2;
		cin >> num2;
		temp = num2[0];
		try
		{
			i = stoi(temp);
		}
		catch (const std::exception&)
		{
			cout << "Error. Is it Alt+2+6?" << endl;
			system("pause");
			break;
		}
		if (i == 0)
		{
			cout << "Try again" << endl;
			continue;
		}
		if (regex_search(num2.c_str(), check, reg))
		{
			cout << "Incorrect symbol was detected" << endl;
			system("pause");
			break;
		}
		int option;
		cout << "Choose your destiny: " << endl;
		cout << "1. +" << endl << "2. -" << endl << "3. *" << endl << "4. /" << endl << "5. For exit"<< endl;
		cin >> option;
		if (option == 1 || option == 2 || option == 3 || option == 4)
			math.conver(num1, num2, option);
		else if (option == 5)
			return 0;
		else
		{
			cout << "Incorrect option" << endl;
			system("pause");
			continue;
		}
	}
	return 0;
}