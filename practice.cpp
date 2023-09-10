#include <iostream>
#include <cstdint> //サイズ指定付き整数型を利用するため
using namespace std;

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
};

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

    return 0;
}

//次回: コンテナ