#include <iostream> //基本的に必要
#include <string> //文字列使うなら必要
using namespace std; // std::coutの省略

//ソース: https://www.asahi-net.or.jp/~yf8k-kbys/newcpp0.html

void c_out(){
    cout << "hello" << endl;  //cout: 「画面」, <<: 「押し込め」, endl: 「改行」, ;: 「終了」
}

void cin_p(){
    string name;
    int old;

    cout << "こんにちは" << endl;
    cout << "あなたの名前は?" << endl;
    cin >> name; //nameに押し込む (代入)
    cout << name << "さん。よろしく" << endl;

    cout << "年齢は?" << endl;
    cin >> old;
    cout << old << "歳ですか" << endl;
}

class Cat{
    private:
        string name; //コンストラクタに必要な変数定義,メンバ変数

    public:
        Cat(string s){ //呼び出しに必要なコンストラクタ (代入したいものをとりこめるコンストラクタ)
            name = s;
        }

        void speak() const{ //メソッド, constで変数を変えることができなくなる
            cout << "うわへへ" << name << endl;
        }
};

class Dog
{
    string name;
    public:
        Dog(string);
        void naku() const;
};

Dog::Dog(string s):name(s){}

void Dog::naku() const{
    cout << "わん。ぼくは" << name << "だ。" << endl;
}

int main(){ //メインクラスは一番下にして関数を受け取る
    c_out();

    Cat dora("ボス"); //インスタンス化 doraは単なる名前 
    cout << "あなたの名付けた猫がメモリ上に生成されました" << endl;
    cout << "猫が鳴きます"  << endl;

    dora.speak();

    Dog pochi("ポチ");
    cout << "犬が鳴きます" << endl;

    pochi.naku();
    //ちなみにpochi.name = "太郎" とするとnameはprivateなためエラーになる
}

//こっちのほうがわかりやすい https://rinatz.github.io/cpp-book/ 次回別ファイルにて練習