# -*- coding: utf-8 -*-
from categorized_item import CategorizedItem

class ConjuredItem(CategorizedItem):
    def __init__(self, item):
        super().__init__(item)

    def update_sell_in(self):
        self.decrease_sell_in()

    def update_quality(self):
        if self.sell_in < 0:
            self.decrease_quality(amount_to_decrease=2)
        self.decrease_quality(amount_to_decrease=2)