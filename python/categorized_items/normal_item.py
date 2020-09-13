# -*- coding: utf-8 -*-
from categorized_item import CategorizedItem

class NormalItem(CategorizedItem):
    def __init__(self, item):
        super().__init__(item)

    def update_sell_in(self):
        self.decrease_sell_in()

    def update_quality(self):
        if self.sell_in < 0:
            self.decrease_quality()
        self.decrease_quality()


