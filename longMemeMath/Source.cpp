#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <ctime>
#include <cstdio>
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
		}
	}
	void minus(vector<int> num1, vector<int> num2)
	{
		if (num1.size() > num2.size())
		{
			int temp = num1.size() - 1;
			for (int a = num2.size(); a > 0; a--) // >0)
			{                                     // (_>  goooooooosePOWEEEEEEEEEEEEEEEEEEEEER
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
			int i = 0;
			while (1)
			{
				if (num1[i] == 0)
					num1[i] = ' ';
				else
					break;
				i++;

			}
			for (int a = 0; a < num1.size(); a++)
			{
				if (num1[a] == ' ')
				{
					cout << "";
				}
				else
					cout << num1[a];
			}
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
							if (temp == 0)
								cout << "";
							else
							{
								num1[temp] += 10;
								num1[temp - 1]--;
							}
						}
						temp--;
					}
					cout << "Answer: -";
					int i = 0;
					while (1)
					{
						if (num1[i] == 0)
							num1[i] = ' ';
						else
							break;
						i++;

					}
					for (int a = 0; a < num1.size(); a++)
					{
						if (num1[a] == ' ')
						{
							cout << "";
						}
						else
							cout << num1[a];
					}
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
					int i = 0;
					while (1)
					{
						if (num1[i] == 0)
							num1[i] = ' ';
						else
							break;
						i++;

					}
					for (int a = 0; a < num1.size(); a++)
					{
						if (num1[a] == ' ')
						{
							cout << "";
						}
						else
							cout << num1[a];
					}
				}
			}
		}
	}
	void multi(vector<int> num1, vector<int> num2)
	{
		vector<int> res;
		for (int a = 0; a < num1.size() + num2.size() + 5; a++)
		{
			res.push_back(0);
		}
		if (num1.size() >= num2.size())
		{
			int a = 1;
			int temp = res.size() - a;
			for (int n2 = num2.size() - 1; n2 >= 0; n2--)
			{
				for (int n1 = num1.size() - 1; n1 >= 0; n1--)
				{
					res[temp] += num1[n1] * num2[n2];
					if (res[temp] >= 10)
					{
						for (int a = 0; ; a += 10)
						{
							if (a > res[temp])
							{
								a -= 10;
								res[temp] -= a;
								res[temp - 1] += a / 10;
								break;
							}
							continue;
						}
					}
					temp--;
				}
				a++;
				temp = res.size() - a;
			}
		}
		if (num1.size() < num2.size())
		{
			vector<int> tempArray = num1;
			num1 = num2;
			num2 = tempArray;
			int a = 1;
			int temp = res.size() - a;
			for (int n2 = num2.size() - 1; n2 >= 0; n2--)
			{
				for (int n1 = num1.size() - 1; n1 >= 0; n1--)
				{
					res[temp] += num1[n1] * num2[n2];
					if (res[temp] >= 10)
					{
						for (int a = 0; ; a += 10)
						{
							if (a > res[temp])
							{
								a -= 10;
								res[temp] -= a;
								res[temp - 1] += a / 10;
								break;
							}
							continue;
						}
					}
					temp--;
				}
				a++;
				temp = res.size() - a;
			}
		}
		cout << "Answer: ";
		int i = 0;
		while (1)
		{
			if (res[i] == 0)
				res[i] = ' ';
			else
				break;
			i++;

		}
		for (int a = 0; a < res.size(); a++)
		{
			if (res[a] == ' ')
			{
				cout << "";
			}
			else
				cout << res[a];
		}
	}
	void divison(vector<int> num1, vector<int> num2)
	{
		if (num1.size() > num2.size())
		{
			vector<int> tempNum2;
			for (int a = 0; a < num1.size(); a++)
				tempNum2.push_back(0);
			int temp = tempNum2.size() - 1;
			for (int a = num2.size() - 1; a >= 0; a--)
			{
				tempNum2[temp] += num2[a];
				temp--;
			}
			bool trigger = false;
			int count = 0;
			vector<int> saveNum2;
			for (int a = 0; a < tempNum2.size(); a++)
			{
				saveNum2.push_back(0);
			}
			for (int a = 0; a < tempNum2.size(); a++)
			{
				saveNum2[a] += tempNum2[a];
			}
			while (1)
			{
				for (int a = 0; a < num1.size(); a++)
				{
					if (num1[a] == tempNum2[a])
					{
						if (a == num1.size())
						{
							count++;
							trigger = true;
							break;
						}
						continue;
					}
					else if (num1[a] < tempNum2[a])
					{
						trigger = true;
						break;
					}
					else if (num1[a] > tempNum2[a])
					{
						trigger = false;
						break;
					}
				}
				if (trigger == true)
					break;
				else if (trigger == false)
				{
					count++;
					for (int i = tempNum2.size() - 1; i >= 0; i--)
					{
						tempNum2[i] += saveNum2[i];
						if (tempNum2[i] >= 10)
						{
							if (i == 0)
								cout << "";
							else
							{
								tempNum2[i] -= 10;
								tempNum2[i - 1]++;
							}
						}
					}
				}
			}
			cout << "Answer: " << count << endl;
		}
		else if (num1.size() == num2.size())
		{
			bool trigger = false;
			int count = 0;
			if (num1.size() == 1)
			{
				count = num1[0] / num2[0];
			}
			else
			{
				vector<int> saveNum2;
				for (int a = 0; a < num2.size(); a++)
				{
					saveNum2.push_back(0);
				}
				for (int a = 0; a < num2.size(); a++)
				{
					saveNum2[a] += num2[a];
				}
				while (1)
				{
					for (int a = 0; a < num1.size(); a++)
					{
						if (num1[a] == num2[a])
						{
							if (a == num1.size() - 1)
							{
								count++;
								trigger = true;
								break;
							}
							continue;
						}
						else if (num1[a] < num2[a])
						{
							trigger = true;
							break;
						}
						else if (num1[a] > num2[a])
						{
							trigger = false;
							break;
						}
					}
					if (trigger == true)
						break;
					else if (trigger == false)
					{
						count++;
						for (int i = num2.size() - 1; i >= 0; i--)
						{
							num2[i] += saveNum2[i];
							if (num2[i] >= 10)
							{
								if (i == 0)
									cout << "";
								else
								{
									num2[i] -= 10;
									num2[i - 1]++;
								}
							}
						}
					}
				}
			}
			cout << "Answer: " << count << endl;
		}
		else if (num1.size() < num2.size())
		{
			int zero = -1;
			while (1)
			{
				if (num1.size() == num2.size())
					break;
				num1.push_back(0);
				zero++;
			}
			int count = 0;
			for (int a = 0; a < num1.size(); a++)
			{
				if (num1[a] == num2[a])
				{
					if (a = num1.size() - 1)
					{
						cout << "Answer: 0,";
						for (int a = 0; a < zero; a++)
							cout << "0";
						cout << count;
						break;
					}
					else
					{
						cout << "Answer: 0" << endl;
						break;
					}
				}
				
			}
		}
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
		int option;
		cout << "Choose your destiny: " << endl;
		cout << "1. +" << endl << "2. -" << endl << "3. *" << endl << "4. /" << endl << "5. For exit" << endl;
		cin >> option;
		if (option == 5)
			return 0;
		else if (option != 1 && option != 2 && option !=3 && option != 4)
		{
			cout << "Incorrect option" << endl;
			system("pause");
			break;
		}
		cout << "Enter first number: ";
		string num1;
		cin >> num1;
		cout << endl;
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
			cout << "Zero cant be first number. Try again" << endl;
			continue;
		}
		cout << "Enter second number: ";
		string num2;
		cin >> num2;
		cout << endl;
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
			cout << "Zero cant be first number. Try again" << endl;
			continue;
		}
		if (regex_search(num2.c_str(), check, reg))
		{
			cout << "Incorrect symbol was detected" << endl;
			system("pause");
			break;
		}
		double start = clock();
		if (option == 1 || option == 2 || option == 3 || option == 4)
			math.conver(num1, num2, option);
		cout << endl << "Time: " << (clock() - start) / CLOCKS_PER_SEC << endl << endl;
	}
	return 0;
}