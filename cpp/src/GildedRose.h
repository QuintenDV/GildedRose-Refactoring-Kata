#ifndef GILDED_ROSE_H
#define GILDED_ROSE_H

#include <string>
#include <vector>

#include "Item.h"
#include "CategorizedItem.h"

using namespace std;

class GildedRose
{
public:
    vector<Item> & items;
    GildedRose(vector<Item> & items);

    void updateQuality();

private:
    void updateSingleItem(Item *item);
    void updateSingleCategorizedItem(CategorizedItem *item);
    vector<CategorizedItem*> categorizedItems;
};

#endif
