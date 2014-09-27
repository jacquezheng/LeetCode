bool isSameTree(TreeNode *p, TreeNode *q) {
  if(p==NULL){
    if(q==NULL)
      return true;
    else
      return false;
  }
  else{
    if(q==NULL)
      return false;
    else{
      if(p->val!=q->val)
        return false;
      else
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
  }
}
