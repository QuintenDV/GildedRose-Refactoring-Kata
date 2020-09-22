#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <unordered_set>

using namespace std;

class Inventory {
    public:
        Inventory();
        bool isAgedCheese(string);
        bool isLegendary(string);
    private:
        unordered_set<string> legendaries;
        unordered_set<string> agedCheeses;
        void initAgedCheeses();
        void initLegendaries();
};



#endif