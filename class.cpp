#include <iostream>
#include <string>
using namespace std;

//ロケットクラスとその内部の宣言
class Rocket{
    private:
        int fuel;
        int speed;

    public:
        bool stop;
        Rocket(int);
        void acceleration();
};

//ロケットコンストラクタの定義 「::」 ～の内部みたいなイメージ
Rocket::Rocket(int x): fuel(x), speed(0){}

//ロケットクラス内に加速関数をつくる
void Rocket::acceleration(){
    stop = false;

    if (fuel >= 2){
        speed += 2;
        fuel -= 2;
        
        cout << "現在の燃料は" << fuel << "です" << endl;
        cout << "現在の速度は" << speed << "です" << endl;

    }else{
        cout << "燃料切れです" << endl;
        stop = true;
    }
}

int main(){
    cout << "メモリ上にロケットを作ります。燃料を入力してください" << endl;
    int n;
    cin >> n;

    Rocket tepodon(n); //テポドンロケット生成→テポドンオブジェクト
    tepodon.stop = false;

    for (int i = 0; i < 4; i++){
        if (tepodon.stop == false){
            cout << "加速します" << endl;
            tepodon.acceleration();

        }else{
            tepodon.acceleration();
            cout << "墜落しました" << endl;
            break;
        }
    }

    if (tepodon.stop == false){
        cout << "月に到着しました" << endl;
    }
}

// 次回：8. コンストラクタの引数