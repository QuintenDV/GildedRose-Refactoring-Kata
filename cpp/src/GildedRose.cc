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
    // The commented out code calls the still working legacy code
    // for (int i = 0; i < items.size(); i++) {
    //     updateSingleItem(&items[i]);
    // }
    // The code below calls uses the categorizedItems
    for (int i = 0; i < categorizedItems.size(); i++) {
        updateSingleCategorizedItem(categorizedItems[i]);
    }
}

void GildedRose::updateSingleCategorizedItem(CategorizedItem *item){
    item->updateSellIn();
    item->updateQuality();
}

void GildedRose::updateSingleItem(Item *item){
    if (item->name == "Aged Brie"){
            item->sellIn--;
        if (item->quality < 50) {
            item->quality++;
        }
        if (item->sellIn < 0) {
            if (item->quality < 50) {
                item->quality++;
            }
        }
        return;
    }

    if (item->name == "Sulfuras, Hand of Ragnaros") {
        return;
    }

    if (item->name == "Backstage passes to a TAFKAL80ETC concert"){
        if (item->quality < 50) {
            item->quality++;

            if (item->sellIn < 11) {
                if (item->quality < 50) {
                    item->quality++;
                }
            }
            if (item->sellIn < 6) {
                if (item->quality < 50) {
                    item->quality++;
                }
            }
        }

        item->sellIn--;

        if (item->sellIn < 0) {
            item->quality = 0;
        }
        return;
    }

    if (item->quality > 0) {
        item->quality--;
    }
    item->sellIn--;
    if (item->sellIn < 0) {
        if (item->quality > 0) {
            item->quality--;
        }
    }
}