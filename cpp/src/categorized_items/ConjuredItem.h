#ifndef CONJURED_ITEM_H
#define CONJURED_ITEM_H

#include "../GildedRose.h"
#include "../CategorizedItem.h"

using namespace std;

class ConjuredItem : public CategorizedItem
{
    public:
        ConjuredItem(Item &item);
        void updateQuality() override;
        void updateSellIn() override;
};

#endif