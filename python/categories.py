# -*- coding: utf-8 -*-

class Category:

    def __init__(self, special_items):
        self.special_items = special_items

    def get_item_category(self, item):
        return self.special_items.get(item.name, General)

    @classmethod
    def increase_quality(cls, item, amount_to_increase=1):
        item.quality += amount_to_increase
        item.quality = min(item.quality, 50)

    @classmethod
    def decrease_quality(cls, item, amount_to_decrease=1):
        item.quality -= amount_to_decrease
        item.quality = max(item.quality, 0)

    @classmethod
    def decrease_sell_in(cls, item):
        item.sell_in -= 1

class General(Category):
    @classmethod
    def update_quality(cls,item):
        cls.decrease_sell_in(item)
        if item.sell_in < 0:
            cls.decrease_quality(item)
        cls.decrease_quality(item)

class Legendary(Category):
    @classmethod
    def update_quality(cls,item):
        pass

class AgesWell(Category):
    @classmethod
    def update_quality(cls, item):
        cls.decrease_sell_in(item)
        if item.sell_in < 0:
            cls.increase_quality(item)
        cls.increase_quality(item)

class BackstagePass(Category):
    @classmethod
    def update_quality(cls, item):
        amount_to_increase = cls.calculate_amount_to_increase(item)
        cls.increase_quality(item, amount_to_increase)

        cls.decrease_sell_in(item)
        if item.sell_in < 0:
            item.quality = 0

    @classmethod
    def calculate_amount_to_increase(cls, item):
        amount_to_increase = 1
        if item.sell_in < 11:
            amount_to_increase += 1
        if item.sell_in < 6:
            amount_to_increase += 1
        return amount_to_increase