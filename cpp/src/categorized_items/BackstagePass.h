#ifndef BACKSTAGE_PASS_H
#define BACKSTAGE_PASS_H

#include "../GildedRose.h"
#include "../CategorizedItem.h"

using namespace std;

class BackstagePass : public CategorizedItem
{
    public:
        BackstagePass(Item &item);
        void updateQuality() override;
        void updateSellIn() override;

    private:
        int calculateQualityIncrease();
};

#endif