#include <string>
#include <vector>

#include "CategorizedItemFactory.h"
#include "categorized_items/NormalItem.cc"
#include "categorized_items/BackstagePass.cc"
#include "categorized_items/AgedCheese.cc"
#include "categorized_items/LegendaryItem.cc"

using namespace std;

CategorizedItem* CategorizedItemFactory::fromItem(Item &item){
    if (CategorizedItemFactory::itemNameStartsWith(item, "Backstage passes")){
        return new BackstagePass(item);
    }
    if (CategorizedItemFactory::itemNameStartsWith(item, "Conjured")){
        return new NormalItem(item);
    }

    // Hardcoded stuff
    if (CategorizedItemFactory::itemNameStartsWith(item, "Aged Brie")){
        return new AgedCheese(item);
    }
    if (CategorizedItemFactory::itemNameStartsWith(item, "Sulfuras")){
        return new LegendaryItem(item);
    }
    //
    return new NormalItem(item);
}

bool CategorizedItemFactory::itemNameStartsWith(Item &item, string prefix){
    string s = item.name;
    return s.rfind(prefix, 0) == 0;
}