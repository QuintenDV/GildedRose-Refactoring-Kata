# -*- coding: utf-8 -*-
from abc import ABC, abstractmethod
from item import Item

class CategorizedItem(ABC):

    MAX_QUALITY = 50

    def __init__(self, item):
        self.item = item

    def increase_quality(self, amount_to_increase=1):
        self.item.quality += amount_to_increase
        self.item.quality = min(self.item.quality, CategorizedItem.MAX_QUALITY)

    def decrease_quality(self, amount_to_decrease=1):
        self.item.quality -= amount_to_decrease
        self.item.quality = max(self.item.quality, 0)

    def decrease_sell_in(self):
        self.item.sell_in -= 1

    def get_sell_in(self):
        return self.item.sell_in

    def get_quality(self):
        return self.item.quality

    def set_sell_in(self, new_sell_in):
        self.item.sell_in = new_sell_in

    def set_quality(self, new_quality):
        self.item.quality = new_quality

    @abstractmethod
    def update_quality(self):
        pass

    @abstractmethod
    def update_sell_in(self):
        pass
