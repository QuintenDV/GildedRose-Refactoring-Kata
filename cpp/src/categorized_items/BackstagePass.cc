#include "BackstagePass.h"

BackstagePass::BackstagePass(Item &item) : CategorizedItem(item){}

void BackstagePass::updateQuality(){
    if (CategorizedItem::getSellIn() >= 0) {
        int qualityIncrease = BackstagePass::calculateQualityIncrease();
        CategorizedItem::increaseQualityBy(qualityIncrease);
    } else {
        BackstagePass::setQuality(0);
    }
}

int BackstagePass::calculateQualityIncrease(){
    int qualityIncrease = 1;
    if (BackstagePass::getSellIn() < 10){
        qualityIncrease++;
    }
    if (BackstagePass::getSellIn() < 5){
        qualityIncrease++;
    }
    return qualityIncrease;
}

void BackstagePass::updateSellIn(){
    CategorizedItem::decrementSellIn();
}