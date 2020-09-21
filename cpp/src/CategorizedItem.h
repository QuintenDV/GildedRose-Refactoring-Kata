#ifndef CATEGORIZED_ITEM_H
#define CATEGORIZED_ITEM_H

#include "Item.h"

using namespace std;

class CategorizedItem {
    public:
        CategorizedItem(Item &item);
        void increaseQualityBy(int amountToIncrease);
        void decreaseQualityBy(int amountToDecrease);
        void incrementQuality();
        void decrementQuality();
        void decrementSellIn();
        virtual void updateQuality() = 0;
        virtual void updateSellIn() = 0;
        int getQuality();
        int getSellIn();
        void setQuality(int newQuality);
        void setSellIn(int newSellIn);
    private:
        Item &item;
};

#endif