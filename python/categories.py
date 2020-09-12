# -*- coding: utf-8 -*-

class Category:

    def __init__(self, special_items):
        self.special_items = special_items

    def get_item_category(self, item):
        return self.special_items.get(item.name, General)


class General(Category):
    @classmethod
    def update_quality(cls,item):
        if item.quality > 0:
            item.quality = item.quality - 1
        else:
            if item.quality < 50:
                item.quality = item.quality + 1
        item.sell_in = item.sell_in - 1
        if item.sell_in < 0:
            if item.quality > 0:
                item.quality = item.quality - 1

class Legendary(Category):
    @classmethod
    def update_quality(cls,item):
        pass

class AgesWell(Category):
    @classmethod
    def update_quality(cls, item):
        if item.quality < 50:
            item.quality = item.quality + 1
        item.sell_in = item.sell_in - 1
        if item.sell_in < 0:
            if item.quality < 50:
                item.quality = item.quality + 1

class BackstagePass(Category):
    @classmethod
    def update_quality(cls, item):
        if item.quality < 50:
            item.quality = item.quality + 1
            if item.sell_in < 11:
                if item.quality < 50:
                    item.quality = item.quality + 1
            if item.sell_in < 6:
                if item.quality < 50:
                    item.quality = item.quality + 1
        item.sell_in = item.sell_in - 1
        if item.sell_in < 0:
            item.quality = 0