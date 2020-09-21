#include "AgedCheese.h"

AgedCheese::AgedCheese(Item &item) : CategorizedItem(item){}

void AgedCheese::updateQuality(){
    if (CategorizedItem::getSellIn() < 0) {
        CategorizedItem::incrementQuality();
    }
    CategorizedItem::incrementQuality();
}

void AgedCheese::updateSellIn(){
    CategorizedItem::decrementSellIn();
}