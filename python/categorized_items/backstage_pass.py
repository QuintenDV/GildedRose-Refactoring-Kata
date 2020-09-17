# -*- coding: utf-8 -*-
from categorized_item import CategorizedItem

class BackstagePass(CategorizedItem):
    def __init__(self, item):
        super().__init__(item)

    def update_sell_in(self):
        self.decrease_sell_in()

    def update_quality(self):
        if self.get_sell_in() >= 0:
            quality_increment = self._calculate_quality_increment()
            self.increase_quality(quality_increment)
        else:
            self.set_quality(0)

    def _calculate_quality_increment(self):
        quality_increment = 1
        if self.get_sell_in() < 10:
            quality_increment += 1
        if self.get_sell_in() < 5:
            quality_increment += 1
        return quality_increment


