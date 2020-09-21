#include <string>
#include <vector>

#include "CategorizedItemFactory.h"
#include "categorized_items/NormalItem.cc"
#include "categorized_items/BackstagePass.cc"

using namespace std;

CategorizedItem* CategorizedItemFactory::fromItem(Item &item){
    if (CategorizedItemFactory::itemNameStartsWith(item, "Backstage passes")){
        return new BackstagePass(item);
    }
    if (CategorizedItemFactory::itemNameStartsWith(item, "Conjured")){
        return new NormalItem(item);
    }
    return new NormalItem(item);
}

bool CategorizedItemFactory::itemNameStartsWith(Item &item, string prefix){
    string s = item.name;
    return s.rfind(prefix, 0) == 0;
}