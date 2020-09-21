#ifndef LEGENDARY_ITEM_H
#define LEGENDARY_ITEM_H

#include "../GildedRose.h"
#include "../CategorizedItem.h"

using namespace std;

class LegendaryItem : public CategorizedItem
{
    public:
        LegendaryItem(Item &item);
        void updateQuality() override;
        void updateSellIn() override;
};

#endif