#pragma once
#include<string>
#include<iostream>
#include<queue>
#include<ctime>
using namespace std;

//1.	Создайте класс, в котором  есть ostream& operator<<.
//Класс должен содержать очередь с приоритетом.
//Создайте генератор — заполнитель очереди случайными числами.
//Заполните priority_queue, используя генератор, затем выведите содержимое очереди на экран.

class Student {
	string name;
	priority_queue<int> grades;
public:
	Student();
	Student(string name);
	Student(string name, priority_queue<int> q);
	priority_queue<int> getQueue();

	void random(int size);

	friend ostream& operator<<(ostream& os, Student obj);
	
};