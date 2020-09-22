#include <string>
#include <vector>

#include "CategorizedItemFactory.h"
#include "categorized_items/NormalItem.cc"
#include "categorized_items/BackstagePass.cc"
#include "categorized_items/AgedCheese.cc"
#include "categorized_items/LegendaryItem.cc"
#include "Inventory.cc"

using namespace std;

Inventory CategorizedItemFactory::inventory = Inventory();

CategorizedItem* CategorizedItemFactory::fromItem(Item &item){
    if (CategorizedItemFactory::itemNameStartsWith(item, "Backstage passes")){
        return new BackstagePass(item);
    }
    if (CategorizedItemFactory::itemNameStartsWith(item, "Conjured")){
        return new NormalItem(item);
    }

    if (inventory.isAgedCheese(item.name)){
        return new AgedCheese(item);
    }
    if (inventory.isLegendary(item.name)){
        return new LegendaryItem(item);
    }

    return new NormalItem(item);
}

bool CategorizedItemFactory::itemNameStartsWith(Item &item, string prefix){
    string s = item.name;
    return s.rfind(prefix, 0) == 0;
}