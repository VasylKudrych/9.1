#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

enum Specialty { KN, IT, ME, FI, TTI };
string SpecialtyStr[]{ "Комп'ютерні науки" , "Інформаційні науки" , "Математика та економіка" , "Фізика та інформатика" , "Трудове навчання" };

struct Student
{
	string prizv;
	int kurs;
	Specialty specialty;
	int Phisic;
	int Math;
	union
	{
		int Prog;
		int Num_methods;
		int Pedagogy;
	};


};

void Create(Student* s, const int N);
void Print(Student* p, const int N);
void Print_Students_Who_Have_5_In_Phisics_In_Math(Student* p, const int N);
int* Kilk(Student* s, const int N, int* array);


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << "Введiть кiлькiсть студентiв: "; cin >> N;
	cout << endl;

	Student* p = new Student[N];

	Create(p, N);
	Print(p, N);
	cout << endl;
	int array[3] = { 0,0,0 };
	Kilk(p, N, array);
	cout << "Кількість оцінок «5 з математики» - " << array[2] << endl;
	cout << "Кількість оцінок «4 з математики» - " << array[1] << endl;
	cout << "Кількість оцінок «3 з математики» - " << array[0] << endl;
	Print_Students_Who_Have_5_In_Phisics_In_Math(p, N);

	return 0;

}

void Create(Student* s, const int N)
{
	int kurs, specialty;

	for (int i = 0; i < N; i++)
	{
		cout << "Студент № " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();
		cout << "Прiзвище: "; getline(cin, s[i].prizv);
		cout << "Курс: ";  cin >> s[i].kurs;
		cout << "Спецiальність (0 - КН, 1 - IН, 2 - МЕ, 3 - ФI, 4 - ТТI): ";
		cin >> specialty;
		s[i].specialty = (Specialty)specialty;
		cout << "Оцiнка з фізики - "; cin >> s[i].Phisic;
		cout << "Оцiнка з математики - "; cin >> s[i].Math;
		switch (s[i].specialty)
		{
		case KN:
			cout << "Оцінка з програмування :"; cin >> s[i].Prog;
			break;
		case IT:
			cout << "Оцінка з Чисельних методів :"; cin >> s[i].Num_methods;
			break;
		case ME:
		case FI:
		case TTI:
			cout << "Оцінка з Педагогіки :"; cin >> s[i].Pedagogy;
			break;
		}
		cout << endl;
	}
}

void Print(Student* p, const int N)
{
	cout << "=================================================================================" << endl;
	cout << "| № |   Прізвище   | Курс | Спецiальнiсть | Оцінка з фiзики | Оцінка з математика |  Оцінка з програмування | Оцінка з чисельних методів |" << endl;
	cout << "---------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(2) << left << i + 1 << " ";
		cout << "| " << setw(13) << left << p[i].prizv
			<< "| " << setw(4) << right << p[i].kurs << " "
			<< "| " << setw(23) << left << SpecialtyStr[p[i].specialty] << " "
			<< "| " << setw(15) << right << p[i].Phisic << " "
			<< "| " << setw(19) << right << p[i].Math << " ";
		switch (p[i].specialty)
		{
		case KN:
			cout << "| " << setw(22) << right << p[i].Prog << " |" << setw(30) << "|" << setw(22) << " |" << endl;
			break;
		case IT:
			cout << "| " << setw(24) << " |" << setw(29) << right << p[i].Num_methods << "|" << setw(22) << " |" << endl;
			break;
		case ME:
		case FI:
		case TTI:
			cout << "| " << setw(24) << " |" << setw(30) << "|" << setw(21) << right << p[i].Pedagogy << " |" << endl;
			break;
		}

	}
	cout << "=================================================================================" << endl;
	cout << endl;
}

int* Kilk(Student* s, const int N, int* array)
{
	int three = 0, four = 0, five = 0;
	for (int i = 0; i < N; i++)
	{
		if (s[i].Math == 3)
		{
			three++;
		}
		if (s[i].Math == 4)
		{
			four++;
		}
		if (s[i].Math == 5)
		{
			five++;
		}
	}
	array[0] = three;
	array[1] = four;
	array[2] = five;
	return array;
}

void Print_Students_Who_Have_5_In_Phisics_In_Math(Student* p, const int N)
{
	int № = 0;
	cout << " :" << endl;

	for (int i = 0; i < N; i++)
	{
		if (p[i].Phisic == 5 && p[i].Math == 5)
			cout << ++№ << "." << p[i].prizv << endl;
	}
}
