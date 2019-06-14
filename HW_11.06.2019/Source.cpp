#include"Student.h"
#include<vector>
#include<list>
#include<math.h>
#include<algorithm>
#include <ctime>
#include<time.h>
//#define CLOCKS_PER_SEC 1000000

int main() {
	srand(time(NULL));

	//task 1
	Student s("Tyrion");
	s.random(10);
	cout << s << endl;

	//task 2
	//2.	Заполните вектор vector<double> числами, представляющими собой углы в радианах.
	//Используя объект — функцию, удалите из вектора все числа, синус которых меньше 0, 5.
	double R = 0;//pi radian = 3.14 = 180 degree -> sin(0.53radian)~=0.5
	vector<double> v;

	double n = 0;
	for (R = 0; R <= 3.14; R += 0.12) {
		v.push_back(R);
	}
	for_each(v.begin(), v.end(), [](double v) {cout << "sin " << v << " = " << sin(v) << endl; });
	cout << endl;
	
	//removing radians with sin < 0.5
	v.erase(remove_if(v.begin(), v.end(),
		[](double v) { 
		return (sin(v) < 0.5);
	}
	), v.end());

	cout << endl << "Sinuses of radians (> 0.5) from vector v" << endl;
	for_each(v.begin(), v.end(), [](double v) {cout << "sin " << v << " = " << sin(v) << endl; });
	cout << endl;

	//task 3
	//3.	Напишите программу, сравнивающую время сортировки элементов контейнера
	//посредством метода list::sort() и алгоритма std::sort().
	//Сделайте соответствующие выводы.

	list<int> l1;
	vector<int> v2;
	for (int i = 0; i < 10; i++) {
		l1.push_back(rand() % 100);
		v2.push_back(rand() % 100);
	}
	for_each(l1.begin(), l1.end(), [](int a) {cout << a << " "; });
	cout << endl;

	//пришлось захватить в блок begin-end clock()еще и распечатку, иначе если засекать время только на сортировку,
	//то будет всегда ноль, т.к. слишком маленькое время требуется
	int begin = clock();
	l1.sort();//list::sort()
	for_each(l1.begin(), l1.end(), [](int a) {cout << a << " "; });
	int end = clock();

	int time_spent1 = (end - begin)*1000/CLOCKS_PER_SEC;
	cout << "Time: " << time_spent1 << endl << endl;
	
	for_each(v2.begin(), v2.end(), [](int a) {cout << a << " "; });
	cout << endl;

	int begin2 = clock();
	sort(v2.begin(), v2.end());//std::sort()
	for_each(v2.begin(), v2.end(), [](int a) {cout << a << " "; });
	int end2 = clock();

	int time_spent2 = (end2 - begin2)*1000/CLOCKS_PER_SEC;
	cout << "Time: " << time_spent2 << endl;


	system("pause");
	return 0;
}