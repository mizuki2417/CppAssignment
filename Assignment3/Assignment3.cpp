#include <fstream>
#include <iostream>

// 演算用関数の宣言
double add(double x, double y);
double multi(double x, double y);

int main(int argc, char* argv[]) {
    if(argc != 3) {
        std::cout << "[Different number of parameters]" << std::endl;
        return 1;
    }

    // ファイルの読込
    std::ifstream fin(argv[1]);
    if (!fin) {
        std::cout << "[Could not open file]" << std::endl;
        return 1;
    }

    const int line = 5; // 行数
    const int row = 3; // 列数
    std::string none;
    double data[line][row], a[line], b[line], sum[line], product[line];

    fin >> none; fin >> none; fin >> none;
    for (int i = 1; i < line; i++) {
        for (int j = 0; j < row; j++) {
            fin >> data[i][j];
            if (j > 1) {
                a[i] = data[i][1];
                b[i] = data[i][2];

                sum[i] = add(a[i], b[i]);
                product[i] = multi(a[i], b[i]);
            }
        }
    }

    fin.close();

    // ファイルの出力
    std::ofstream fout(argv[2]);
    if(!fout) {
        std::cout << "[Could not open file]" << std::endl;
        return 1;
    }

    fout << "No." << "\t\t" << "add" << "\t\t" << "multi" << std::endl;
    for (int i = 1; i < line; i++) {
        fout << i <<"\t\t" << sum[i] << "\t\t" << product[i] << std::endl;
    }

    fout.close();

    return 0;
}

// 演算用関数の定義
double add(double x, double y) {
    return x + y;
}

double multi(double x, double y) {
    return x * y;
}