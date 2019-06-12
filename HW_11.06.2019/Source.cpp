#include"Student.h"
#include"SortingTime.h"
#include<vector>
#include<math.h>

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



	system("pause");
	return 0;
}