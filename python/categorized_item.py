# -*- coding: utf-8 -*-
from item import Item

class CategorizedItem(Item):
    def __init__(self, item):
        super().__init__(item.name, item.sell_in, item.quality)

    def increase_quality(self, amount_to_increase=1, maximum_quality=50):
        self.quality += amount_to_increase
        self.quality = min(self.quality, maximum_quality)

    def decrease_quality(self, amount_to_decrease=1):
        self.quality -= amount_to_decrease
        self.quality = max(self.quality, 0)

    def decrease_sell_in(self):
        self.sell_in -= 1

    def update_quality(self):
        print("THE BASIC METHOD WAS CALLED")

