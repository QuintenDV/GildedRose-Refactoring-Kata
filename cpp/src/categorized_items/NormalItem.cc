#include "NormalItem.h"

NormalItem::NormalItem(Item &item) : CategorizedItem(item){}

void NormalItem::updateQuality(){
    if (CategorizedItem::getSellIn() < 0) {
        CategorizedItem::decrementQuality();
    }
    CategorizedItem::decrementQuality();
}
void NormalItem::updateSellIn(){
    CategorizedItem::decrementSellIn();
}