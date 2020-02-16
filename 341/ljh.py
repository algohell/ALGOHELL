import re
class NestedIterator:
    def __init__(self, nestedList):
        self.nList = re.findall("[-]*\d+",str(nestedList))
        self.it = iter(self.nList)
        self._thenext = None
    def next(self):
        return int(self._thenext)
    def hasNext(self):
        try:
            self._thenext = next(self.it)
            return True
        except StopIteration:
            return False

i, v = NestedIterator([[1,1],-12,[1,-1]]), []
while i.hasNext():
    v.append(i.next())
print(v)