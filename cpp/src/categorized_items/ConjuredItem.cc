#include "ConjuredItem.h"

ConjuredItem::ConjuredItem(Item &item) : CategorizedItem(item){}

void ConjuredItem::updateQuality(){
    if (CategorizedItem::getSellIn() < 0) {
        CategorizedItem::decreaseQualityBy(2);
    }
    CategorizedItem::decreaseQualityBy(2);
}
void ConjuredItem::updateSellIn(){
    CategorizedItem::decrementSellIn();
}