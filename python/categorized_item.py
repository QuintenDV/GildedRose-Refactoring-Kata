# -*- coding: utf-8 -*-
from abc import ABC, abstractmethod
from item import Item

class CategorizedItem(Item, ABC):

    MAX_QUALITY = 50

    def __init__(self, item):
        super().__init__(item.name, item.sell_in, item.quality)

    def increase_quality(self, amount_to_increase=1):
        self.quality += amount_to_increase
        self.quality = min(self.quality, CategorizedItem.MAX_QUALITY)

    def decrease_quality(self, amount_to_decrease=1):
        self.quality -= amount_to_decrease
        self.quality = max(self.quality, 0)

    def decrease_sell_in(self):
        self.sell_in -= 1

    @abstractmethod
    def update_quality(self):
        pass

    @abstractmethod
    def update_sell_in(self):
        pass
