// www.coders-hub.com/2015/07/red-black-tree-rb-tree-using-c.html#.VxyVnFZ97Io


#include<iostream>

template <class Type> class RBtree {
 private:
  struct node {
    Type key;
    node *parent;
    char color;
    node *left;
    node *right;
  };

  node *root;
  node *q;




 public:
  RBtree()
  {
    q=NULL;
    root=NULL;
  }
  void insert(Type z) {
  node *p, *q;
  node *t = new node;
  t->key = z;
  t->left = NULL;
  t->right = NULL;
  t->color = 'r';
  p=root;
  q=NULL;
  if(root==NULL)
  {
    root=t;
    t->parent=NULL;
  }
  else
  {
    while(p!=NULL)
    {
      q=p;
      if(p->key<t->key)
        p=p->right;
      else
        p=p->left;
    }
    t->parent=q;
    if(q->key<t->key)
      q->right=t;
    else
      q->left=t;
  }
  insertfix(t);
}

  void insertfix(node *t)
{
  node *u;
  if(root==t)
  {
    t->color='b';
    return;
  }
  while(t->parent!=NULL&&t->parent->color=='r')
  {
    node *g=t->parent->parent;
    if(g->left==t->parent)
    {
      if(g->right!=NULL)
      {
        u=g->right;
        if(u->color=='r')
        {
          t->parent->color='b';
          u->color='b';
          g->color='r';
          t=g;
        }
      }
      else
      {
        if(t->parent->right==t)
        {
          t=t->parent;
          leftrotate(t);
        }
        t->parent->color='b';
        g->color='r';
        rightrotate(g);
      }
    }
    else
    {
      if(g->left!=NULL)
      {
        u=g->left;
        if(u->color=='r')
        {
          t->parent->color='b';
          u->color='b';
          g->color='r';
          t=g;
        }
      }
      else
      {
        if(t->parent->left==t)
        {
          t=t->parent;
          rightrotate(t);
        }
        t->parent->color='b';
        g->color='r';
        leftrotate(g);
      }
    }
    root->color='b';
  }
}
  void leftrotate(node *p)
{
  if(p->right==NULL)
    return ;
  else
  {
    node *y=p->right;
    if(y->left!=NULL)
    {
      p->right=y->left;
      y->left->parent=p;
    }
    else
      p->right=NULL;
    if(p->parent!=NULL)
      y->parent=p->parent;
    if(p->parent==NULL)
      root=y;
    else
    {
      if(p==p->parent->left)
        p->parent->left=y;
      else
        p->parent->right=y;
    }
    y->left=p;
    p->parent=y;
  }
}

  void rightrotate(node *p)
{
  if(p->left==NULL)
    return ;
  else
  {
    node *y=p->left;
    if(y->right!=NULL)
    {
      p->left=y->right;
      y->right->parent=p;
    }
    else
      p->left=NULL;
    if(p->parent!=NULL)
      y->parent=p->parent;
    if(p->parent==NULL)
      root=y;
    else
    {
      if(p==p->parent->left)
        p->parent->left=y;
      else
        p->parent->right=y;
    }
    y->right=p;
    p->parent=y;
  }
}

  node* successor(node *p) {
    node *y=NULL;
    if(p->left!=NULL)
    {
      y=p->left;
      while(y->right!=NULL)
        y=y->right;
    }
    else
    {
      y=p->right;
      while(y->left!=NULL)
        y=y->left;
    }
    return y;
  }

  void disp() { display(root); }

  void display(node *p) {
  if (root == NULL) {
    std::cout << "\nEmpty Tree.";
    return ; }
  
  if(p!=NULL)
  {
    std::cout<<"\n\t NODE: ";
    std::cout<<"\n Key: "<<p->key;
    std::cout<<"\n Colour: ";
    if(p->color=='b')
      std::cout<<"Black";
    else
      std::cout<<"Red";
    if(p->parent!=NULL)
      std::cout<<"\n Parent: "<<p->parent->key;
    else
      std::cout<<"\n There is no parent of the node.  ";
    if(p->right!=NULL)
      std::cout<<"\n Right Child: "<<p->right->key;
    else
      std::cout<<"\n There is no right child of the node.  ";
    if(p->left!=NULL)
      std::cout<<"\n Left Child: "<<p->left->key;
    else
      std::cout<<"\n There is no left child of the node.  ";
    std::cout<<std::endl;
    if(p->left)
    {
      std::cout<<"\n\nLeft:\n";
      display(p->left);
    }
    /*else
      std::cout<<"\nNo Left Child.\n";*/
    if(p->right)
    {
      std::cout<<"\n\nRight:\n";
      display(p->right);
    }
    /*else
      std::cout<<"\nNo Right Child.\n"*/
  }
}

  void search(Type x){
  if(root==NULL)
  {
    std::cout<<"\nEmpty Tree\n" ;
    return  ;
  }
  node *p=root;
  int found=0;
  while(p!=NULL&& found==0)
  {
    if(p->key==x)
      found=1;
    if(found==0)
    {
      if(p->key<x)
        p=p->right;
      else
        p=p->left;
    }
  }
  if(found==0)
    std::cout<<"\nElement Not Found.";
  else
  {
    std::cout<<"\n\t FOUND NODE: ";
    std::cout<<"\n Key: "<<p->key;
    std::cout<<"\n Colour: ";
    if(p->color=='b')
      std::cout<<"Black";
    else
      std::cout<<"Red";
    if(p->parent!=NULL)
      std::cout<<"\n Parent: "<<p->parent->key;
    else
      std::cout<<"\n There is no parent of the node.  ";
    if(p->right!=NULL)
      std::cout<<"\n Right Child: "<<p->right->key;
    else
      std::cout<<"\n There is no right child of the node.  ";
    if(p->left!=NULL)
      std::cout<<"\n Left Child: "<<p->left->key;
    else
      std::cout<<"\n There is no left child of the node.  ";
    std::cout<<std::endl;

  }
}

};
