#include <iostream>
#include <cstdint> //サイズ指定付き整数型を利用するため
#include <array>
#include <tuple>
#include <unordered_map>
using namespace std;

// ソース：https://rinatz.github.io/cpp-book/ 

//変数
void variables(){
    std::int32_t x = 5; //コンパイラに適したデータ型を用いる
    unsigned int y = 4000000000; //正の数しか表現できないが大きな値を使うことができる
    std::cout << x << std::endl; //::はスコープ演算子。複数のnamespace内に同様の変数名がある場合に指定

    //列挙型(配列のようなもの)
    enum Day {
        //列挙子は他の列挙型変数で用いてはならないが、クラス間ならセーフ
        sunday, //0
        monday, //1
        tuesday, //2
        wednesday = 5, //5
        thursday, //6
        friday, //7
        saturday = 0 //0
    };
    std::cout << sunday << std::endl;
}

enum class Day {
    sunday,
    monday,
    tuesday,
    wednesday,
    thursday,
    friday,
    saturday
};

//ポインタ
void pointer(){
    int number = 496;
    int* pointer; //ポインタ変数を作成
    pointer = &number; //番地を代入

    cout << pointer << ":" << *pointer << endl; //その番地にある値を出力

    int* np = nullptr; //値をnull(何も参照していない)にしたい場合nullptrを使う
};

int Add(int x, int y){
    return x + y;
}

//配列
void PrintArray2(const int* x) { //配列は暗黙的にポインタ型になる
    for (int i = 0; i < 5; i++) {
        cout << x[i] << endl;
    }
}


int main(){
    std::cout << "Hello, world!" << std::endl;
    variables();
    pointer();

    //関数とポインタ
    int (*fp)(int, int) = Add;
    int result = fp(3, 5); //アドレスから間接的に関数を呼び出す。コールバックがかかわっているらしい
    cout << result << endl;

    //lambda関数
    int init = 5;

    auto lambda = [init](int a, int b){return init + a + b;}; //コピーして使うとコンパイル時に上部にある変数をコピー(参照ではない)するためinitは5となる
    auto rlambda = [&init](int a, int b){return init + a + b;}; //参照型にするとメモリ上の値を参照するためinitは0となる

    init = 0;

    int result_copy = lambda(2, 4);
    cout << "コピーキャプチャの場合" << result_copy << endl;

    int result_ref = rlambda(2, 4);
    cout << "参照キャプチャの場合" << result_ref << endl;

    //配列
    int array1[5] = {0, 1, 2, 3, 4};
    PrintArray2(array1);

    //高度な配列
    std::array<int, 5>array2 = {0, 1, 2, 3, 4};
    auto size = array2.size();
    for (int i = 0; i < size; i++) {
        cout << array2[i] << endl;
    }

    int arr1_1[3] = {};
    //int arr1_2[3] = arr1_1; //NG
    std::array<int, 3> arr2_1{};
    std::array<int, 3> arr2_2 = arr2_1; //OK

    //タプル
    //いろんな型の要素を含むことができる
    std::tuple<std::string, int, std::string> person {"Bob", 20, "USA"};
    cout << std::get<0>(person) << std::get<1>(person) << std::get<2>(person) << endl;

    //tie(): タプルの要素を一括で変数に代入することができる
    std::string name;
    int age;
    std::string country;

    std::tie(name, age, country) = person;

    std::unordered_map<std::string, int> persons = {
        {"Alice", 18},
        {"Bob", 20}
    };
    persons.insert({"Eve", 19});
    persons.erase("Alice");

    cout << persons["Bob"] << endl;

    return 0;
}