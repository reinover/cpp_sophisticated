// Заглушка.
// lesson1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
/*
Имеется база сотрудников и номеров их телефонов. Требуется написать соответствующие структуры 
для хранения данных, и заполнить контейнер записями из базы. Затем необходимо реализовать 
методы обработки данных, а также вывести на экран всю необходимую информацию.
Важно! Имена переменным, классам и функциям давайте осознанные, состоящие из слов на английском языке.

1 Создайте структуру Person с 3 полями: фамилия, имя, отчество. Поле отчество должно быть опционального 
типа, т.к. не у всех людей есть отчество. Перегрузите оператор вывода данных для этой структуры. 
Также перегрузите операторы < и == (используйте tie).

*/

#include <iostream>
#include <vector>
#include <limits>
#include <tuple>
using namespace std;

class Time {
private:
	int hour, minute, second;
public:
	Time(): hour(0), minute(0), second(0){}
	Time(int h, int m, int s) : hour(h), minute(m), second(s) {}
	friend bool operator< (const Time& t1, const Time& t2);
};
bool operator<(const Time& t1, const Time& t2) {
	/*if (t1.hour != t2.hour) {
		return t1.hour < t2.hour;
	}
	if (t1.minute != t2.minute) {
		return t1.minute < t2.minute;
	}
	return t1.second < t2.second;*/

	// Альтернативное решение блога сверху через vector:
	//return vector<int>{t1.hour, t1.minute, t1.second} < vector<int>{t2.hour, t2.minute, t2.second};

	// Ещё один вариант через tie из tuple
	return tie(t1.hour, t1.minute, t1.second) < tie(t2.hour, t2.minute, t2.second);
}

int main()
{
	vector<int> numbers{ -5, -7, 3 };
	int sum = 0;
	for (auto n : numbers) {
		sum += n;
	}
	int average = sum / numbers.size();
	cout << average << endl;

	cout << endl;
	cout << "numeric_limits<size_t>::min() && numeric_limits<size_t>::max()  ::" << endl;
	cout << "\t" << sizeof(size_t) << " bytes" << endl;
	cout << "\tMin: " << numeric_limits<size_t>::min() << endl;
	cout << "\tMax: " << numeric_limits<size_t>::max() << endl;

	average = sum / static_cast<int>(numbers.size());
	cout << endl;
	cout << "С помощью static_cast преобразовали numbers.size() к типу int из size_t:" << endl;
	cout << average << endl;

	// Кортежи
	Time breakfast_time(9, 15, 0);
	Time lunch_time(13, 0, 0);
	// -- что такое boolalpha?
	cout << boolalpha << (breakfast_time < lunch_time) << endl;

	{
		// Создаём кортеж
		tuple<int, string, double> tuple1(1, "Hello", 2.72);
		auto tuple2 = make_tuple(2, "world", 3.14);

		// Получаем значения кортежа
		auto hello = get<1>(tuple1);
		auto world = get<1>(tuple2);
		cout << world << endl;
		// Странно, но нижеприведённый код не работает, cout справляется только если
		// кортеж создан с помощью make_tuple
		 //cout << hello << endl;
		cout << get<0>(tuple1) << endl;

		// Меняем значения кортежа
		get<0>(tuple2) += get<0>(tuple1);
		cout << get<0>(tuple2) << endl;

		// Распаковка значений кортежа
		int x;
		string s;
		double d;
		tie(x, s, d) = tuple2;
		// s отчего то не может вывести
		cout << x << " " << d << endl;

		// функция tie принимает только ссылки на объекты хранящиеся в других переменных.

		auto students = {
			make_tuple(234, "John Doe's", 3.7),
			make_tuple(345, "Billy Foo's", 4.0),
			make_tuple(456, "Cathy Bar's", 3.5),
		};
	}
}
