typedef set<int>::iterator Iterator;
pair<Iterator, Iterator> twoSum(const set<int>& bst, int sum) {
  if (bst.size() <= 1) {
    return pair<Iterator, Iterator>(bst.end(), bst.end());
  }
  Iterator i = bst.begin();
  Iterator j = bst.end();
  --j;

  while (i != j) {
    while (i != j && *i + *j > sum) {
      --j;
    }
    if (i != j && *i + *j == sum) {
      return pair<Iterator, Iterator>(i, j);
    }
    ++i;
  }
  return pair<Iterator, Iterator>(bst.end(), bst.end());
}
