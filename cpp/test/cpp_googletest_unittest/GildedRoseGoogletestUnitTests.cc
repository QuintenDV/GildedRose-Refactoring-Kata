#include <gtest/gtest.h>
#include "GildedRose.h"

void runGildedRose(vector<Item> itemsBeforeTest, vector<Item> targetItems, int nIterations){
    GildedRose app(itemsBeforeTest);
    for (int x = 0; x < nIterations; ++x) {
        app.updateQuality();
    }

    for (int i = 0; i < targetItems.size(); ++i) {
        EXPECT_EQ(app.items[i].name, targetItems[i].name);
        EXPECT_EQ(app.items[i].quality, targetItems[i].quality);
        EXPECT_EQ(app.items[i].sellIn, targetItems[i].sellIn);
    }
}

TEST(GildedRoseTest, NormalItems) {
    vector<Item> itemsBeforeTest;
    itemsBeforeTest.push_back(Item("+5 Dexterity Vest", 10, 20));
    itemsBeforeTest.push_back(Item("Helmet of Intelligence", 2, 50));
    itemsBeforeTest.push_back(Item("Spoiled Fried Chicken", -5, 5));
    itemsBeforeTest.push_back(Item("Unicorn Horn", 0, 10));

    vector<Item> targetItems;
    targetItems.push_back(Item("+5 Dexterity Vest", 5, 15));
    targetItems.push_back(Item("Helmet of Intelligence", -3, 42));
    targetItems.push_back(Item("Spoiled Fried Chicken", -10, 0));
    targetItems.push_back(Item("Unicorn Horn", -5, 0));

    runGildedRose(itemsBeforeTest, targetItems, 5);
}

TEST(GildedRoseTest, LegendaryItems) {
    vector<Item> itemsBeforeTest;
    itemsBeforeTest.push_back(Item("Sulfuras, Hand of Ragnaros", 0, 80));

    vector<Item> targetItems;
    targetItems.push_back(Item("Sulfuras, Hand of Ragnaros", 0, 80));

    runGildedRose(itemsBeforeTest, targetItems, 5);
}

TEST(GildedRoseTest, WellAgingCheese) {
    vector<Item> itemsBeforeTest;
    itemsBeforeTest.push_back(Item("Aged Brie", 2, 0));
    itemsBeforeTest.push_back(Item("Aged Brie", -10, 0));

    vector<Item> targetItems;
    targetItems.push_back(Item("Aged Brie", -3, 8));
    targetItems.push_back(Item("Aged Brie", -15, 10));

    runGildedRose(itemsBeforeTest, targetItems, 5);
}

TEST(GildedRoseTest, BackstagePasses) {
    vector<Item> itemsBeforeTest;
    itemsBeforeTest.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 15, 20));
    // itemsBeforeTest.push_back(Item("Backstage passes to an Iron Maiden concert", 12, 10));
    // itemsBeforeTest.push_back(Item("Backstage passes to a Slayer concert", 7, 10));
    // itemsBeforeTest.push_back(Item("Backstage passes to a Taylor Swift concert", 2, 49));

    vector<Item> targetItems;
    targetItems.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 10, 25));
    // targetItems.push_back(Item("Backstage passes to an Iron Maiden concert", 7, 18));
    // targetItems.push_back(Item("Backstage passes to a Slayer concert", 2, 23));
    // targetItems.push_back(Item("Backstage passes to a Taylor Swift concert", -3, 0));

    runGildedRose(itemsBeforeTest, targetItems, 5);
}