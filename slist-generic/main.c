#include "slist.h"

int main(void) {
  SLNode *n0 = INIT_SL_NODE((char)'h');
  SLNode *n1 = INIT_SL_NODE(123);
  SLNode *n2 = INIT_SL_NODE(0.666666);
  SLNode *n3 = INIT_SL_NODE((size_t)99999);
  SLNode *n4 = INIT_SL_NODE("哈哈哈");

  LinkSLNode(n0, n1);
  LinkSLNode(n1, n2);
  LinkSLNode(n2, n3);
  LinkSLNode(n3, n4);

  TraverseSL(n0);
  RemoveSLNode(n3);
  n4 = INIT_SL_NODE("hahaha");
  LinkSLNode(n3, n4);
  TraverseSL(n0);

  DestorySL(&n0);

  return 0;
}