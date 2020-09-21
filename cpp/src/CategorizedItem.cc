#include "CategorizedItem.h"

CategorizedItem::CategorizedItem(Item &item) : item(item)
{}

void CategorizedItem::increaseQualityBy(int amountToIncrease){
    this->item.quality += amountToIncrease;
    this->item.quality = min(this->item.quality, 50);
}
void CategorizedItem::decreaseQualityBy(int amountToDecrease){
    this->item.quality -= amountToDecrease;
    this->item.quality = max(this->item.quality, 0);
}
void CategorizedItem::incrementQuality(){
    this->increaseQualityBy(1);
}
void CategorizedItem::decrementQuality(){
    this->decreaseQualityBy(1);
}
void CategorizedItem::decrementSellIn(){
    this->item.sellIn--;
}
int CategorizedItem::getQuality(){
    return this->item.quality;
}
int CategorizedItem::getSellIn(){
    return this->item.sellIn;
}
void CategorizedItem::setQuality(int newQuality){
    this->item.quality = newQuality;
}
void CategorizedItem::setSellIn(int newSellIn){
    this->item.sellIn = newSellIn;
}