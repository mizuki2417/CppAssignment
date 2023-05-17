#include<iostream>

// パケット
class packet {
    public:
        int data1;
        int data2;
        int data3;
        int data4;
};

// 入力関数
class input {
    public:
        void input_function(packet& p);
};

void input::input_function(packet& p) {
    std::cout << "entry_number_1: ";
    std::cin >> p.data1;

    std::cout << "entry_number_2: ";
    std::cin >> p.data2;
}

// かけ算
class multi {
    public:
        void multi_function(packet& p);
};

void multi::multi_function(packet& p) {
    p.data3 = p.data1 * p.data2;
    std::cout << p.data1 << " x " << p.data2 << " = " << p.data3 << std::endl;
}

// 自乗
class square {
    public:
        void square_function(packet& p);
};

void square::square_function(packet& p) {
    p.data4 = p.data3 * p.data3;
    std::cout << p.data3 << " ^ 2 = " << p.data4 << std::endl;
}

// 出力
class result {
    public:
        void result_function(packet& p);
};

void result::result_function(packet& p) {
    std::cout << "result : " << p.data4 << " end" << std::endl;
}

int main() {
    packet p;

    input i; multi m; square s; result r;

    i.input_function(p);
    m.multi_function(p);
    s.square_function(p);
    r.result_function(p);

    return 0;
}