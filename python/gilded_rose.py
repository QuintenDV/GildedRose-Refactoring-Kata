# -*- coding: utf-8 -*-

from categories import *

SPECIAL_ITEMS = {
    "Backstage passes to a TAFKAL80ETC concert": BackstagePass,
    "Sulfuras, Hand of Ragnaros": Legendary,
    "Aged Brie": AgesWell,
}

class GildedRose(object):
    def __init__(self, items):
        self.items = items
        self.category = Category(SPECIAL_ITEMS)

    def update_quality(self):
        for item in self.items:
            self.update_item_quality(item)

    def update_item_quality(self, item):
        item_category = self.category.get_item_category(item)
        item_category.update_quality(item)

class Item:
    def __init__(self, name, sell_in, quality):
        self.name = name
        self.sell_in = sell_in
        self.quality = quality

    def __repr__(self):
        return "%s, %s, %s" % (self.name, self.sell_in, self.quality)
