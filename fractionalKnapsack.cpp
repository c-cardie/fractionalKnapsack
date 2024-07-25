#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

struct Item {

    const char* name;
    int weight;
    int value;
    double vw_ratio;

    //constructor
    Item (const char* n = "Item", int w = 0, int v = 0)
        : name(n), weight(w), value(v), vw_ratio (static_cast<double>(v)/w) 
        {
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
    }

};

//functions

bool comparison(Item& a, Item& b) {

    return a.vw_ratio > b.vw_ratio;

}

void printSolution(Knapsack& sack) {

    cout << "The optimal solution for a knapsack with a maximum weight of: " << sack.maxWeight << endl;
    cout << "The total value of the items in the knapsack is $" << sack.totalValue << endl;
    cout << "Items and amount of each item taken" << endl;
    for (int i = 0; i <= sack.contents.size() - 1; i++) {

        cout << "Item: " << (sack.contents[i].first).name << ":" << " how much taken: " << sack.contents[i].second << endl;

    }

    //print list of items to take

}

//main greedy function to solve problem
void fractionalKnapsack(vector<Item> list, Knapsack& sack) {

    //sort Item by wv_ratio
    sort(list.begin(), list.end(), comparison);

    
    //print list (for debuggining only)

    /*
    for (int i = 0; i <= list.size() - 1; i++) {

        cout << list[i].name << " " << list[i].weight << " " << list[i].value << " " << list[i].vw_ratio << endl;
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
            sack.contents.push_back(make_pair(list[i], static_cast<double>(remain / list[i].weight)));
            break;

        }

   }

    printSolution(sack);

}



int main() {

    //create items
    Item gold("gold", 5, 20);
    Item silver ("silver", 5, 15);
    Item wood ("wood", 1, 5);
    Item sillyString ("sillyString", 1,1);
    Item diamond("diamond", 2, 60);
    Item bronze("bronze", 4, 12);
    Item platinum("platinum", 6, 70);
    Item iron("iron", 3, 8);
    Item copper("copper", 4, 10);
    Item lead("lead", 7, 14);
    Knapsack sack(20);

    //create vector
    vector<Item> vec;

    //put 10 items onto the vector
    vec.push_back(gold);
    vec.push_back(silver);
    vec.push_back(wood);
    vec.push_back(sillyString);
    vec.push_back(diamond);
    vec.push_back(bronze);
    vec.push_back(platinum);
    vec.push_back(iron);
    vec.push_back(copper);
    vec.push_back(lead);

    //solve the problem and print the 
    fractionalKnapsack(vec, sack);


    
}