# -*- coding: utf-8 -*-
from categorized_item_factory import CategorizedItemFactory

class GildedRose(object):
    def __init__(self, items):
        self.categorized_items = [CategorizedItemFactory.from_item(item) for item in items]

    def update_quality(self):
        for item in self.categorized_items:
            item.update_sell_in()
            item.update_quality()