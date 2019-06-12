#include"Student.h"
#include<vector>
#include<list>
#include<math.h>
#include <ctime>

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
	clock_t start1 = clock();
	l1.sort();//list::sort()
	clock_t stop1 = clock();
	cout << endl;
	for_each(l1.begin(), l1.end(), [](int a) {cout << a << " "; });
	double time_spent1 = (double)(stop1- start1)*1000.0;
	cout << "Time: " << time_spent1 << endl << endl;

	
	for_each(v2.begin(), v2.end(), [](int a) {cout << a << " "; });
	clock_t start2 = clock();
	//sort(v.begin(), v.end(), greater<int>());//std::sort()
	clock_t stop2 = clock();
	cout << endl;
	for_each(v2.begin(), v2.end(), [](int a) {cout << a << " "; });
	double time_spent2 = (double)(stop2 - start2)*1000.0;
	cout << "Time: " << time_spent2 << endl;




	system("pause");
	return 0;
}