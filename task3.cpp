#include <iostream>
#include <ctime>

using namespace std;

void random();
void guess(int);
int entry(int);

int main()
{
	int start = 2;
	do
	{
		if (start == 1)
		{
			random();
		}
		else if (start == 2)
		{
			cout << "how many digits the number of guessed (bulls) and how many numbers guessed, and is in the right place (cow).\n";
		}
		cout << "start: 1\nexet: 0\nhelp: 2\n";
		cin >> start;
	} while (start != 0);
}

void random()
{
	srand(time(NULL));
	int secret = rand() % 8999 + 1000;
	guess(secret);
}

void guess(int secret)
{
	int check = 0;
	int attempt = 0;

	do
	{
		cout << "out number";
		cin >> check;
		for (int i = 1, cow = 0, bulls = 0; i <= 4; i++)
		{
			if (check / 1000 == secret / 1000 &&
				i == 1 ||
				check / 100 % 10 == secret / 100 % 10 &&
				i == 2 ||
				check / 10 % 10 == secret / 10 % 10 &&
				i == 3 ||
				check % 10 == secret % 10 &&
				i == 4)
			{
				cow++;
			}
			else if (check / 1000 == secret / 100 % 10 &&
				i == 1 ||
				check / 1000 == secret / 10 % 10 &&
				i == 1 ||
				check / 1000 == secret % 10 &&
				i == 1 ||
				check / 100 % 10 == secret / 1000 &&
				i == 2 ||
				check / 100 % 10 == secret / 10 % 10 &&
				i == 2 ||
				check / 100 % 10 == secret % 10 &&
				i == 2 ||
				check / 10 % 10 == secret / 100 % 10 &&
				i == 3 ||
				check / 10 % 10 == secret / 1000 &&
				i == 3 ||
				check / 10 % 10 == secret % 10 &&
				i == 3 ||
				check % 10 == secret / 100 % 10 &&
				i == 4 ||
				check % 10 == secret / 10 % 10 &&
				i == 4 ||
				check % 10 == secret / 1000 &&
				i == 4)
			{
				bulls++;
			}
			if (i == 4)
			{
				cout << "cow = " << cow << " bulls = " << bulls << endl;
			}
		}
		attempt++;
	} while (secret != check);
	cout << "\tattempt = " << attempt << endl;
}