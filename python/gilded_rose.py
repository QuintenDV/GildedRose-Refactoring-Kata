# -*- coding: utf-8 -*-
from item_factory import ItemFactory

class GildedRose(object):
    def __init__(self, items):
        self.items = items

    def update_quality(self):
        for item in self.items:
            item.update_quality()