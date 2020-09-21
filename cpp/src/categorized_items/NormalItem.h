#ifndef NORMAL_ITEM_H
#define NORMAL_ITEM_H

#include "../GildedRose.h"
#include "../CategorizedItem.h"

using namespace std;

class NormalItem : public CategorizedItem
{
    public:
        NormalItem(Item &item);
        void updateQuality() override;
        void updateSellIn() override;
};

#endif