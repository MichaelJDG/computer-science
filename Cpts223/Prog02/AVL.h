/**********************************************************
 * AVL Tree Implementation file
 *
 *  ** riffed and modified heavily by Aaron Crandall - 2016
 *  ** All implementation in header because of templating
 *
 **********************************************************/

#ifndef AVLTREE_H_
#define AVLTREE_H_

#include <queue>
#include <iostream>

using namespace std;

template<class T>
class AVLNode {
public:
    // Default blank AVLNode constructor
    AVLNode() {
        left = right = nullptr;
        height = 0;
    }

    // Constructor with provided element (data) and children
    AVLNode(const T& el, AVLNode *l = nullptr, AVLNode *r = nullptr) {
        key = el;
        left = l;
        right = r;
        height = 0;
    }

    T key;                  // Key to compare/insert on of type <T>
    AVLNode *left, *right;  // Children of this node
    int height;             // Height of this node in the tree
};

/*
 * Main AVLTree class that stores AVLNode objects
 *  -- REQUIRES: implementation of rotation functions
 *  -- REQUIRES: implementation of node heights
 *  -- REQUIRES: implementation of contains function
 *  -- REQUIRES: implementation of remove function
 */
template<class T>
class AVLTree {
  public:
    AVLTree() { root = nullptr; }
  
    void insert(const T& key) { insert(root, key); }
    void printTree() { printTree(root); }

    bool contains( const T& key ){ return(contains(root, key)); }
    void remove( const T& key ){ remove(root, key); }
  
  private:
    AVLNode<T>* root;

    void rightRotation(AVLNode<T>* &node) {
      AVLNode<T>* left = node->left;
    
      node->left = left->right;
      left->right = node;
      node = left;
    }
  
    /*
     *  Insert function needs updating!
     *  This function needs to update heights as it returns from recursive insert.
     *  If the heights of a node are more than 2 different, rotate to fix
     *  After fixing, repair the heights of all nodes in the rotated tree
     */
     
    unsigned char height(AVLNode<T>* &node)
    {
      
      if (node == NULL)
        return 0;
     return node->height;
    
    }
    
   AVLNode<T>* findmin(AVLNode<T>* node)
   {
	  if (node==NULL)
	  {
		
	  	return node;
	  }
	  else
	  {
		 while(node->left !=NULL)
		 {
			 node=node->left;
		  }
		 return node;
	  }
   }
  
   void rotatewithLeftchild (AVLNode<T>* &node)
   {
     AVLNode<T>* k1 = node -> left;
     node -> left = k1 -> right;
     k1 -> right = node;
     
     node -> height =  ( height(node-> left)>  height(node -> right) ? height(node-> left) :height(node -> right) ) +1;
     k1 -> height =  ( height(k1-> left)> node -> height ? height(k1-> left) :  node -> height       ) +1;
     node = k1; 
   }
   
   void rotatewithRightchild (AVLNode<T>* &node)
   {
     AVLNode<T>* k1 = node -> right;
     node -> right = k1 -> left;
     k1 -> left = node;
     
     node -> height =  ( height(node-> right) >  height(node -> left) ? height(node-> right) : height(node -> left) ) +1;
     k1 -> height = ( height(k1-> right)>  node -> height ? height(k1-> right) : node -> height) +1;
     node = k1; 
   }
   
   void doublewithLeftchild (AVLNode<T>* &node)
   {
     rotatewithRightchild(node -> left); 
     rotatewithLeftchild(node);
   }
   
   void doublewithRightchild (AVLNode<T>* &node)
   {
     rotatewithLeftchild(node -> right); 
     rotatewithRightchild(node);
   }
  
   void balance(AVLNode<T>* &node) // balancing the node
    {
      if (node == nullptr)
      {
        return;
      }
      
      if ( height ( node -> left) - height( node -> right ) > 1 )
      {
        if ( height(node -> left -> left) >= height (node -> left -> right)) 
        {
          rotatewithLeftchild(node);
        }
        else 
        {
          doublewithLeftchild(node);
        }
      }
      else if ( height ( node -> right) - height( node -> left ) > 1 )
      {
        if ( height(node -> right -> right) >= height (node -> right -> left)) 
        {
          rotatewithRightchild(node);
        }
        else 
        {
          doublewithRightchild(node);
        }
      }
      
      node -> height = ( height(node-> left) > height(node -> right) ? height(node-> left) : height(node -> right) ) +1;
      
    }
   
  
    void insert(AVLNode<T>* &node, const T& key) {
      if(node == nullptr) {
        node = new AVLNode<T>(key);
      } else if(key > node->key) {
        insert(node->right, key);
      } else {
        insert(node->left, key);
      }
      balance(node);
    }

    // MUST IMPLEMENT CONTAINS
    bool contains(AVLNode<T>* root, const T& key) 
    {
      if (root == NULL) return (false);
     else 
     {
      if (key == root->key)
       return (true);
     else if (key < root->key)
      return contains(root->left, key);      //you forgot to return the value
     else if (key > root->key)
      return contains(root->right, key);
     }
    }
    
    

    // MUST IMPLEMENT REMOVE
  
   void remove( AVLNode<T>* &root, const T& k) {
      
      if (root == nullptr)
      {
        return ; 
      }
      
      if (k< root -> key){
        remove(root-> left, k); 
      }
      else if ( k > root -> key){
        remove(root-> right, k);
      }
      else if (root -> left != nullptr && root -> right != nullptr) {
        root -> key = findmin(root-> right) -> key;
        remove( root-> right, root-> key);
      }
      else{
        AVLNode<T>* oldNode = root ;
        root = (root -> left != nullptr) ? root -> left : root -> right; 
        delete oldNode;
      }
      balance(root);
      
    } 

    // Should do a level order printout with actual depth (no alignment)
    void printTree(AVLNode<T>* node) {
      queue<AVLNode<T>*> bufQueue;
      int curr_height = node->height;
      bufQueue.push(node);
      while( !bufQueue.empty() ) {
        AVLNode<T>* curr = bufQueue.front();
        if( curr->left  != nullptr ){ bufQueue.push(curr->left ); }
        if( curr->right != nullptr ){ bufQueue.push(curr->right); }
        if( curr->height < curr_height ){
          cout << endl; 
          curr_height = curr->height;
        }
        cout << curr->key << " ";
        bufQueue.pop();
      }
      cout << endl;
    }
  // end private
};

#endif
