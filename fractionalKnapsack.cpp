#include <iostream>
using namespace std;

struct Item {

    int weight;
    int value;
    double wv_ratio;

    //constructor
    Item (int w, int v)
        : weight(w), value(v), wv_ratio (static_cast<double>(w)/v) 
        {
            cout << "weight: " << weight << endl;
            cout << "value: " << value << endl;
            cout << "weight-value ratio: " << wv_ratio << endl;
        }
};

int main() {

    Item gold(5, 20);
}