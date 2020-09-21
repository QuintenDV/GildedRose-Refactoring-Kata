#include "GildedRose.h"
#include "CategorizedItem.cc"
#include "CategorizedItemFactory.cc"


GildedRose::GildedRose(vector<Item> & items) : items(items){
    for (int i=0; i<items.size(); ++i){
        this->categorizedItems.push_back(
            CategorizedItemFactory::fromItem(items[i]));
    }
}

void GildedRose::updateQuality() {
    for (int i = 0; i < categorizedItems.size(); i++) {
        updateSingleItem(categorizedItems[i]);
    }
}

void GildedRose::updateSingleItem(CategorizedItem *item){
    item->updateSellIn();
    item->updateQuality();
}
