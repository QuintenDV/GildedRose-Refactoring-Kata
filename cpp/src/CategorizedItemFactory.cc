#include <string>
#include <vector>

#include "CategorizedItemFactory.h"
#include "categorized_items/NormalItem.cc"

using namespace std;

CategorizedItem* CategorizedItemFactory::fromItem(Item &item){
    return new NormalItem(item);

    // if (this->itemNameStartsWith(item, "BackstagePasses")){
    //     return nullptr
    // }
    // if (this->itemNameStartsWith(item, "Conjured")){
    //     return nullptr
    // }
    // return nullptr
}

// bool CategorizedItemFactory::itemNameStartsWith(Item *item, string prefix){
//     string s = item->name;
//     return s.rfind(prefix, 0) == 0
// }