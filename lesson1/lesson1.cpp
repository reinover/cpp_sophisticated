#include <iostream>
#include <optional>
#include <tuple>
#include <iterator>
#include <string>
#include <vector>

/* 1 */
struct Person {
	std::string first_name;
	std::string second_name;
	std::optional<std::string> last_name;
};

std::ostream& operator<<(std::ostream &out, struct Person &person) {
	out << person.second_name << person.first_name << *person.last_name;
	return out;
}

class Time {
private:
	int hour, minute, second;
public:
	Time() : hour(0), minute(0), second(0) {}
	Time(int h, int m, int s) : hour(h), minute(m), second(s) {}
	friend bool operator<(const Time& t1, const Time& t2);
	friend bool operator==(const Time& t1, const Time& t2);
};

bool operator<(const Time& t1, const Time& t2) {
	return std::tie(t1.hour, t1.minute, t1.second) < std::tie(t2.hour, t2.minute, t2.second);
}

bool operator==(const Time& t1, const Time& t2) {
	return std::tie(t1.hour, t1.minute, t1.second) == std::tie(t2.hour, t2.minute, t2.second);
}

/* 2 */

struct PhoneNumber {
	int city{};
	int country{};
	std::string number;
	std::optional<int> addition_number;
};

std::ostream operator<<(std::ostream &out, struct PhoneNumber &pn) {
	out << "+" << pn.country << "(" << pn.city << ")" << pn.number << *pn.addition_number;
	// По какой то причине (пишет, что происходит обращение к удалённому конструктору) это строка выдаёт ошибку
	// Хотя, по сути в операторе перегрузки для такой же структуры Person всё работает нормально.
//    return out;
}


bool compare_by_names(std::tuple<std::string, std::string, std::string, long> first, std::tuple<std::string, std::string, std::string, long> second) {
	return get<0>(first) < get<0>(second);
}

bool compare_by_phones(std::tuple<std::string, std::string, std::string, long> first, std::tuple<std::string, std::string, std::string, long> second) {
	return get<3>(first) < get<3>(second);
}

std::tuple<std::string, long> GetPhoneNumber(std::string second_name, std::vector<std::tuple<std::string, std::string, std::string, long>> &address_book) {
	int count = 0;
	std::tuple<std::string, long> result = std::make_tuple("", 0);
	std::for_each(address_book.begin(), address_book.end(), [&second_name, &count, &result](std::tuple<std::string, std::string, std::string, long> &t) {
		if (second_name == get<0>(t)) {
			get<0>(result) = get<0>(t);
			get<1>(result) = get<3>(t);
			count++;
		}
	});
	if (count > 1) {
		get<0>(result) = "found more than 1";
		get<1>(result) = 0;
		return result;
	}
	else if (count == 1) {
		return result;
	}
	return std::make_tuple("not found", 0);
}

void ChangePhoneNumber(std::vector<std::tuple<std::string, std::string, std::string, long>> &address_book) {
	std::string human_name;
	std::cout << "Введите имя человека: ";
	std::cin >> human_name;

	for (auto &ab : address_book) {
		auto first_name = get<0>(ab);
		if (first_name == human_name) {
			long new_phone_num = 0;
			std::cout << "Введите его новый номер: ";
			std::cin >> new_phone_num;
			get<3>(ab) = new_phone_num;
		}
	}
}

int main() {
	/* 1 */
	{
		Person p;
		p.first_name = "Sergey ";
		p.second_name = "Nenashev ";
		p.last_name = "Valerievich";
		std::cout << p << std::endl;

		Time time1(1, 1, 1);
		Time time2(2, 2, 2);
		Time time3(2, 2, 2);
		std::cout << (time1 < time2) << std::endl;
		std::cout << std::boolalpha << (time1 < time2) << std::endl;
		std::cout << std::boolalpha << (time1 == time2) << std::endl;
		std::cout << std::boolalpha << (time2 == time3) << std::endl;
	}

	/* 2 */
	PhoneNumber pn;
	pn.number = "123456";
	pn.country = 7;
	pn.city = 8182;

	/* 3 */

	std::tuple<std::string, std::string, std::string, long> human1("Иванов", "Иван", "Иванович", 7921123123123);
	auto human2 = std::make_tuple("Петров", "Пётр", "Петрович", 7921098098098);
	auto human3 = std::make_tuple("Сидоров", "Клим", "Александрович", 766609870987);
	std::vector<std::tuple<std::string, std::string, std::string, long>> address_book;
	address_book = {
			human1,
			human2,
			human3
	};

	std::sort(address_book.begin(), address_book.end(), compare_by_names);
	std::sort(address_book.begin(), address_book.end(), compare_by_phones);

	for (auto ab : address_book) {
		auto first_name = get<0>(ab);
		auto second_name = get<1>(ab);
		auto last_name = get<2>(ab);
		auto phone = get<3>(ab);
		std::cout << first_name << " " << second_name << " " << last_name << " " << phone << std::endl;
	}

	ChangePhoneNumber(address_book);

	for (auto ab : address_book) {
		auto first_name = get<0>(ab);
		auto second_name = get<1>(ab);
		auto last_name = get<2>(ab);
		auto phone = get<3>(ab);
		std::cout << first_name << " " << second_name << " " << last_name << " " << phone << std::endl;
	}

	auto gpn = GetPhoneNumber("Петров", address_book);
	std::cout << get<0>(gpn) << " phone num: " << get<1>(gpn);

	return 0;
}