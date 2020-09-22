#ifndef CATEGORIZED_ITEM_FACTORY_H
#define CATEGORIZED_ITEM_FACTORY_H

#include "Item.h"
#include "CategorizedItem.h"
#include "Inventory.h"

using namespace std;

class CategorizedItemFactory {
    public:
        static CategorizedItem* fromItem(Item &item);
    private:
        static bool itemNameStartsWith(Item &item, string prefix);
        static Inventory inventory;
};

#endif