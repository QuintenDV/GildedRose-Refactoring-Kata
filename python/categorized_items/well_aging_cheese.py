# -*- coding: utf-8 -*-
from categorized_item import CategorizedItem

class WellAgingCheese(CategorizedItem):
    def __init__(self, item):
        super().__init__(item)

    def update_quality(self):
        self.decrease_sell_in()
        if self.sell_in < 0:
            self.increase_quality()
        self.increase_quality()


