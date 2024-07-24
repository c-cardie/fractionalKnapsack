#include <iostream>
#include <vector>
using namespace std;

struct Item {

    int weight;
    int value;
    double wv_ratio;

    //constructor
    Item (int w = 0, int v = 0)
        : weight(w), value(v), wv_ratio (static_cast<double>(w)/v) 
        {
            cout << "weight: " << weight << endl;
            cout << "value: " << value << endl;
            cout << "weight-value ratio: " << wv_ratio << endl;
        }
};

struct Knapsack {

int maxWeight;

//the "double" part of the pair is how much of the item was taken
vector<pair<Item, double>> contents;

double totalValue;

//constructor
Knapsack()
{
    cout << "knapsack sewn!" << endl;
}

};

int main() {

    Item gold(5, 20);
    Knapsack sack;
    
}