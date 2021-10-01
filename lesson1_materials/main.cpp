#include <iostream>
#include <vector>
#include <tuple>
#include <optional>
#include <utility>
#include <algorithm>

using namespace std;


class Poets {
private:
    vector<pair<string, int>> poets;
public:
    Poets() {
        poets = {
                {"Pushkin",   1799},
                {"Lermontov", 1814},
                {"Zhukovsky", 1783}
        };

    }

//    pair <string, int> FindPoet(string find_surname){
//        for (const auto& [surname, birthday]:poets){
//            if (surname == find_surname){
//                return {surname, birthday};
//            }
//        }
//        return {"",0};
//    }

    optional<int> FindPoet(string find_surname) {     //make_optional<pair<string, int>>(surname, birthday)
        for (const auto&[surname, birthday]: poets) {
            if (surname == find_surname) {
                return birthday;
            }
        }
        return nullopt;
    }

};

bool Compare(pair<string, int> poet1, pair<string, int> poet2) {
    return poet1.second < poet2.second;
}

bool (*compare2)(pair<string, int> poet1, pair<string, int> poet2) =
[](pair<string, int> poet1, pair<string, int> poet2) {
    return poet1.second < poet2.second;
};

int& myfunc(int& x){
    return x;
}

int main() {
    {   //1
//    size_t s = 0;
//    int sum = 0;
//    int mas[] = {-1,-2,-4,5};
//    for (int i = 0; i < size(mas); ++i) {
//        cout << mas[i] << " ";
//        sum += mas[i];
//
//    }
//    cout <<'\n' << sum / static_cast<float>(size(mas));

        //2
//    vector<int> my_vec = {};
//    vector<string> my_vec2 = {"Hello","world"};
//
//
//    my_vec.push_back(5);
//    my_vec.push_back(1);
//    my_vec.push_back(2);
//    my_vec.push_back(0);
//    cout << my_vec[2] << endl;
//    auto vec_it = my_vec.begin() + 1;
//    my_vec.insert(vec_it, 6);
//
//    for (const int& v : my_vec) {   // auto
//        cout << v << " ";
//    }
//
//    vector<vector<int>> matrix = {
//            {1,2,3},
//            {4,5,6},
//            {7,8,9}
//    };

        //3
//    tuple<int, string, bool> tuple1 (1, "Hello", false);
//    auto tuple2 = make_tuple(1, "Hello", false);
//    const int x2 = 0;
//    cout << get<x2>(tuple2) << endl;
//
//
//
//    int x = 0;
//    string s = "world";
//    bool b = true;
//
//    tie(x, s, b) = tuple2;
//    cout << x << " " << s << " " << b << endl;


//4

//    pair <int, string> my_pair = {1814,"Lermontov"};
//
//    my_pair.first;
//    my_pair.second;
//
//    Poets poets;
//
//    string surname = "";
//    int year = 0;

//    tie(surname,year) = poets.FindPoet("Pushkin");
//    cout << surname << " " << year << endl;
//
//    tie(surname,year) = poets.FindPoet("Tutchev");
//    cout << surname << " " << year << endl;

//    optional<int> year = poets.FindPoet("Tutchev");
//    if (year.has_value()) cout << year.value() << endl;
//    else cout << "Not found" << endl;

        //5}
    }
    int century = 0;
    int count = 0;
    cin >> century;

    vector<pair<string, int>> poets{
            {"Pushkin",   1799},
            {"Lermontov", 1814},
            {"Zhukovsky", 1783}
    };

    for_each(poets.begin(), poets.end(), [century, &count](const auto& poet) mutable{
        if (poet.second < century*100 && poet.second >= (century-1)*100) {
            cout << poet.first << endl;
            ++count;
        };
    });

    int a = [](){return 5+5;}();

    int x2 = 10;
    int x3 = 15;
//    myfunc(x2) = 56;
    [&x2]()->int {return x2;}() = 57;

    cout << x2 << endl;






//    sort(poets.begin(), poets.end(), compare2);
//
//    for (const auto&[surname, birthday]: poets) {
//        cout << surname << " " << birthday << endl;
//    }


    return 0;
}
















