#include <iostream>

// Statisticsクラスの宣言
class Statistics {
    private:
        static const int num = 100;
        int count = 0; // データ数
        double data[num];
    public:
        void enter();
        void average();
};

// Statisticsクラスメンバ関数の定義
void Statistics::enter() {
    double e;
    std::cout << "enter data > ";

    std::cin >> e;

    // 入力と入力が失敗した際の例外処理
    while(std::cin.fail()) {
        std::cout << "[Please input double]" << std::endl;
        std::cin.clear();
        std::cin.ignore(1024, '\n');

        std::cout << "enter data > ";
        std::cin >> e;
    }

    data[count] = e;

    std::cout << '\n';

    count++;
}

// 平均値を求めるメンバ関数
void Statistics::average() {
    int i;
    double sum = 0, ave;

    for (i = 0; i < count; i++) {
        sum += data[i];
    }

    ave = sum / count;

    std::cout << "ave = " << ave << std::endl;

    std::cout << '\n';
}

// select関数の宣言
int select();

int main() {
    Statistics sta;
    
    int s = 3;
    while(!(s == 2)) {
        s = select();
        if (s == 0) {
            sta.enter();
        }
        else if (s == 1) {
            sta.average();
        }
        else if (s != 2) {
            std::cout << "select(0-2)" << std::endl;
        }
    }

    return 0;
}

// select関数の定義
int select() {
    int select;

    std::cout << "select(0-2)" << std::endl;
    std::cout << "0.enter" << std::endl;
    std::cout << "1.print average" << std::endl;
    std::cout << "2.quit program" << std::endl;

    std::cin >> select;

    // 0-2以外が入力された場合の例外処理
    while(std::cin.fail()) {
        std::cout << "[Please input integer]" << std::endl;
        std::cin.clear();
        std::cin.ignore(1024, '\n');

        std::cin >> select;
    }

    return select;
}