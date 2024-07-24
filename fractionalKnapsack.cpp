#include <iostream>
#include <vector>
#include <algorithm>
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

//functions

bool comparison(Item& a, Item& b) {

    return a.wv_ratio > b.wv_ratio;

}

//main greedy function to solve problem
void fractionalKnapsack(vector<Item> list, Knapsack& sack) {

    //sort Item by wv_ratio
    sort(list.begin(), list.end(), comparison);

    //print list
    for (int i = 0; i <= list.size() - 1; i++) {

        cout << list[i].weight << " " << list[i].value << " " << list[i].wv_ratio << endl;
    }

}

int main() {

    Item gold(5, 20);
    Item silver(5, 15);
    Item wood (1, 5);
    Item sillyString (1,1);
    Knapsack sack;

    vector<Item> vec;
    vec.push_back(gold);
    vec.push_back(silver);
    vec.push_back(wood);
    vec.push_back(sillyString);

    fractionalKnapsack(vec, sack);


    
}