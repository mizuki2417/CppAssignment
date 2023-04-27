#include <iostream>
#include <string>

const int num = 100;

// Databaseクラスの宣言
class Database {
    private:
        int id;
        char first_name[100];
        char last_name[100];
    public:
        void add();
        int get_id() {return id;};
        std::string get_first_name() {return first_name;};
        std::string get_last_name() {return last_name;};
        void display_name();
};

// Databaseクラスメンバ関数の定義
void Database::add() {
    std::cout << "id : ";
    std::cin >> id;

    std::cout << "name : ";
    std::cin >> first_name;

    std::cin >> last_name;

    std::cout << '\n';
}

void Database::display_name() {
    for (int i = 0; i < 100; i++) {
        std::cout << first_name[i];last_name[i];
    }
    std::cout << " ";
    for (int i = 0; i < 100; i++) {
        std::cout << last_name[i];
    }
}

// select関数の宣言
int select();

int main() {
    Database d[num];

    int i = 0, s = 4;
    while(!(s == 3)) {
        s = select();
        if (s == 0) {
            d[i].add();
        }
        else if (s == 1) {
            int id;
            std::cout << "id : ";
            std::cin >> id;

            for(int j = 0; j < num; j++) {
                if (id == d[j].get_id()) {
                    d[j].display_name();
                }
            }

            std::cout << '\n';
            std::cout << '\n';
        }
        else if (s == 2) {
            std::string first_name, last_name;
            std::cout << "name > ";
            std::cin >> first_name;
            std::cin >> last_name;

            for(int j = 0; j < num; j++) {
                if (first_name == d[j].get_first_name()) {
                    std::cout << d[j].get_id();
                }
            }

            std::cout << '\n';
            std::cout << '\n';
        }
        i++;
    }


}

// select関数の定義
int select() {
    int select;

    std::cout << "select(0-3)" << std::endl;
    std::cout << "0.add new entry," << std::endl;
    std::cout << "1.search name," << std::endl;
    std::cout << "2.search id," << std::endl;
    std::cout << "3.quit this program," << std::endl;

    std::cin >> select;

    // 0-3以外が入力された場合の処理
    while(std::cin.fail()) {
        std::cout << "[Please input integer]" << std::endl;
        std::cin.clear();
        std::cin.ignore(1024, '\n');

        std::cin >> select;
    }

    return select;
}