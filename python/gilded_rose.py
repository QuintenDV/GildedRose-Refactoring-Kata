# -*- coding: utf-8 -*-

class GildedRose(object):
    def __init__(self, categorized_items):
        self.categorized_items = categorized_items

    def update_quality(self):
        for item in self.categorized_items:
            item.update_sell_in()
            item.update_quality()