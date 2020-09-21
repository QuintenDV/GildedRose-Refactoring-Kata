#ifndef AGED_CHEESE_H
#define AGED_CHEESE_H

#include "../GildedRose.h"
#include "../CategorizedItem.h"

using namespace std;

class AgedCheese : public CategorizedItem
{
    public:
        AgedCheese(Item &item);
        void updateQuality() override;
        void updateSellIn() override;
};

#endif