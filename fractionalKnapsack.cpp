#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

struct Item {

    const char* name;
    int weight;
    int value;
    double wv_ratio;

    //constructor
    Item (const char* n = "Item", int w = 0, int v = 0)
        : name(n), weight(w), value(v), wv_ratio (static_cast<double>(w)/v) 
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
    Knapsack(int mw)

        : maxWeight(mw)
    {
        cout << "knapsack sewn!" << endl;
    }

};

//functions

bool comparison(Item& a, Item& b) {

    return a.wv_ratio > b.wv_ratio;

}

void printSolution(Knapsack& sack) {

    cout << "The optimal solution for a knapsack with a maximum weight of: " << sack.maxWeight << endl;
    cout << "Items and amount of each item taken" << endl;
    for (int i = 0; i <= sack.contents.size() - 1; i++) {

        cout << "Item: " << (sack.contents[i].first).name << " how much taken: " << sack.contents[i].second << endl;

    }

    //print list of items to take

}

//main greedy function to solve problem
void fractionalKnapsack(vector<Item> list, Knapsack& sack) {

    //sort Item by wv_ratio
    sort(list.begin(), list.end(), comparison);

    /*
    //print list
    for (int i = 0; i <= list.size() - 1; i++) {

        cout << list[i].weight << " " << list[i].value << " " << list[i].wv_ratio << endl;
    }
    */

   //current weight in the knapsack
   int curWeight = 0;

   //looping through all items
   for (int i = 0; i <= list.size() - 1; i++) {

        //If adding the item won't exceed the maximum weight
        //add it completely
        if (curWeight + list[i].weight <= sack.maxWeight) {

            curWeight += list[i].weight;
            sack.totalValue += list[i].value;
            sack.contents.push_back(make_pair(list[i], 1.0));

        }

        //If we can't add the whole current item
        //add the fractional part of it
        else {

            double remain = sack.maxWeight - curWeight;
            sack.totalValue += list[i].value * (remain / list[i].weight);
            break;

        }

   }

    printSolution(sack);

}



int main() {

    Item gold("gold", 5, 20);
    Item silver ("silver", 5, 15);
    Item wood ("wood", 1, 5);
    Item sillyString ("sillyString", 1,1);
    Knapsack sack(40);

    vector<Item> vec;
    vec.push_back(gold);
    vec.push_back(silver);
    vec.push_back(wood);
    vec.push_back(sillyString);

    

    cout << "testing knapsack function functionality" << endl;

    fractionalKnapsack(vec, sack);


    
}