//TreeType.cxx#include "TreeType.h"void Destroy(TreeNode* &tree);void CopyTree(TreeNode* &copy, const TreeNode* originalTree);void RetrieveHelper(TreeNode* tree, ItemType &item, bool &found);void InsertHelper(TreeNode* &ptr, ItemType item);void Delete(TreeNode* &tree, ItemType item);void DeleteNode(TreeNode* &tree);void GetPredecessor(TreeNode* tree, ItemType& data);void Inorder(TreeNode* tree, ofstream& outFile);struct TreeNode{  ItemType info;  TreeNode* left;  TreeNode* right;};TreeType::TreeType()// Purpose: Default Constructor // Input: none// Pre: none// Output: none// Post: item is created.// Note: none{  root = NULL;}TreeType::~TreeType()// Purpose: Destructor // Input: none// Pre: object is created// Output: none// Post: item is deleted// Note: none{  Destroy(root);}void Destroy(TreeNode* &tree)// Used by Destructor{  if (tree != NULL)  {    Destroy(tree->left);    Destroy(tree->right);    delete tree;  }}TreeType::TreeType(const TreeType &originalTree)// Purpose: Copy Constructor to make a deep copy// Input: originalTree// Pre: object is created// Output: TreeType// Post: deep copy is made// Note: none{  CopyTree(root, originalTree.root);}void CopyTree(TreeNode* &copy, const TreeNode* originalTree)// Used by copy constructore{  if (originalTree == NULL)    copy = NULL;  else  {    copy = new TreeNode;    copy->info = originalTree->info;    CopyTree(copy->left, originalTree->left);    CopyTree(copy->right, originalTree->right);  }}void TreeType::operator=(const TreeType &originalTree)// Purpose: To overload operator, recursive function CopyTree to copy tree pointed// to by originalTree into self // Input: originalTree// Pre: onject must exist// Output: none// Post: copy is made and operator is overloaded.// Note: none{  if (&originalTree == this)    return;                // Ignore assigning self to self.  Destroy(root);           // Deallocate existing tree nodes.  CopyTree(root, originalTree.root);}bool TreeType::IsEmpty() const// Purpose: Determines if tree is empty // Input: none// Pre: tree is created// Output: bool// Post: bool is returned true or false// Note: none{  return (root == NULL);}bool TreeType::IsFull() const// Purpose: To determin if tree is full// Input: none// Pre: tree is created// Output: bool// Post: bool is returned true or false// Note: none{   TreeNode* ptr;      ptr = new TreeNode;   if(ptr == NULL)     return true;   else   {     delete ptr;     return false;   }}void updateTreeHelper(TreeNode* tree, ItemType item, bool &found, float& A, float& B,float& C,float& D,float& E,float& F)// Used by updateTree{  if (tree == NULL)    found = false;                              // item is not found.  else if (item.ComparedTo(tree->info) == LESS)    updateTreeHelper(tree->left, item, found, A, B, C, D, E, F);    // Search left subtree.  else if (item.ComparedTo(tree->info) == GREATER)    updateTreeHelper(tree->right, item, found, A, B, C, D, E, F);   // Search right subtree.  else  {		if(tree->info.gradeis() == 'A') {A--;}    if(tree->info.gradeis()== 'B') {B--;}	    if(tree->info.gradeis()== 'C') {C--;}    if(tree->info.gradeis()== 'D') {D--;}    if(tree->info.gradeis()== 'E') {E--;}    if(tree->info.gradeis()== 'F') {F--;}	    tree->info = item;  	// item is found.		if(tree->info.gradeis() == 'A') {A++;}    if(tree->info.gradeis()== 'B') {B++;}	    if(tree->info.gradeis()== 'C') {C++;}    if(tree->info.gradeis()== 'D') {D++;}    if(tree->info.gradeis()== 'E') {E++;}    if(tree->info.gradeis()== 'F') {F++;}	    found = true;  }}void TreeType::updateTree (ItemType newItem, bool& found, float& A, float& B,float& C,float& D,float& E,float& F)// Purpose: To update tree item info and change counters// Input: newitem, found, A,B,C,D,E,F// Pre: all object are created// Output: none// Post: tree is updated if found and values incremented accordingly// Note: none {  updateTreeHelper(root, newItem, found, A, B, C, D, E, F);}void TreeType::RetrieveItem(ItemType& item, bool& found)// Purpose: To retrieve ite from tree or if it cant be found// Input: item , found// Pre: tree is created// Output: item , bool// Post: bool is returned true or false and item may be found// Note: none{  RetrieveHelper(root, item, found);}void RetrieveHelper(TreeNode* tree, ItemType &item, bool &found)// Used by RetrieveItem{  if (tree == NULL)    found = false;                              // item is not found.  else if (item.ComparedTo(tree->info) == LESS)    RetrieveHelper(tree->left, item, found);    // Search left subtree.  else if (item.ComparedTo(tree->info) == GREATER)    RetrieveHelper(tree->right, item, found);   // Search right subtree.  else  {    item = tree->info;                           // item is found.    found = true;  }}void TreeType::InsertItem(ItemType item)// Purpose: To insert item to tree// Input: item// Pre: tree is created// Output: none// Post: item added to tree// Note: none{  InsertHelper(root, item);}void InsertHelper(TreeNode* &ptr, ItemType item)// Used by InsertItem{  if (ptr == NULL)  {     ptr =new TreeNode;     ptr->right = NULL;     ptr->left = NULL;     ptr->info = item;  }  else if(item.ComparedTo(ptr->info)== LESS)          InsertHelper(ptr->left, item);  else if(item.ComparedTo(ptr->info) == GREATER)          InsertHelper(ptr->right, item);}void TreeType::DeleteItem(ItemType item)// Purpose: To delete item from tree// Input: item// Pre: tree is created, item is in tree// Output: none// Post: item is deleted from tree// Note: none{    Delete(root, item);}void Delete(TreeNode* &tree, ItemType item)//Used by DeleteItem{  if (item.ComparedTo(tree->info) == LESS)     Delete(tree->left, item);  else     if (item.ComparedTo(tree->info) == GREATER)	Delete(tree->right, item);     else        DeleteNode(tree);} 	void DeleteNode(TreeNode* &tree)//Used by DeleteItem{  ItemType data;  TreeNode* tempPtr;  tempPtr = tree;  if (tree->left == NULL)  {    tree = tree->right;    delete tempPtr;  }  else     if (tree->right == NULL)    {       tree = tree->left;       delete tempPtr;    }    else    {       GetPredecessor(tree->left, data);       tree->info = data;       Delete(tree->left, data);    // Delete predecessor node.    }}void GetPredecessor(TreeNode* tree, ItemType& data)//Used by DeleteItem// Sets data to the info member of the right-most node in tree.{  while (tree->right != NULL)    tree = tree->right;  data = tree->info;}void TreeType::PrintInorder(ofstream& outFile) const// Purpose: To print values in tree in order// Input: outFile// Pre: tree is created// Output: none// Post: tree is printed in order// Note: none{  Inorder(root, outFile);}void Inorder(TreeNode* tree, ofstream& outFile)// Used by PrintInorder// Prints info member of items inorder.{  if (tree != NULL)  {    Inorder(tree->left, outFile);   // Print left subtree.    tree->info.WriteItemToFile(outFile);    Inorder(tree->right, outFile);  // Print right subtree.  }}void printPreorderHelper (TreeNode* tree, ofstream& outFile)// Used by PrintPreorder{	if (tree != NULL)  {	tree->info.WriteItemToFile(outFile);    printPreorderHelper(tree->left, outFile);   // Print left subtree.	printPreorderHelper(tree->right, outFile);  // Print right subtree.  }}void TreeType :: PrintPreorder (ofstream& outFile) const // Purpose: To print values in tree in preorder// Input: outFile// Pre: tree is created// Output: none// Post: tree is printed in preorder// Note: none{	printPreorderHelper ( root, outFile);}void printPostorderHelper (TreeNode* tree, ofstream& outFile)// Used by PrintPostorder{	if (tree != NULL)  {    printPostorderHelper(tree->left, outFile);   // Print left subtree.	printPostorderHelper(tree->right, outFile);  // Print right subtree.    tree->info.WriteItemToFile(outFile);  }}void TreeType :: PrintPostorder (ofstream& outFile) const// Purpose: To print values in tree in postorder// Input: outFile// Pre: tree is created// Output: none// Post: tree is printed in postorder// Note: none{	printPostorderHelper( root, outFile);}void countNodeHelper (TreeNode* tree, int& numOfNodes)//Used by countNode{  if (tree != NULL)  {    countNodeHelper(tree->left, numOfNodes);   	countNodeHelper(tree->right, numOfNodes);      numOfNodes ++;  }}void TreeType::countNode(int& numOfNodes)// Purpose: To count nodes in tree// Input numofNodes// Pre: tree is created// Output: none// Post: node number is found// Note: none{  countNodeHelper(root, numOfNodes);}int printHeightofTreeHelper (TreeNode* tree)// Used by printHeightofTree{	if (tree == NULL)     { return 0;}     int left = 1 + printHeightofTreeHelper (tree -> left);	int right = 1 + printHeightofTreeHelper (tree -> right);		if (left > right)	  {		return left;	  }    else 	  {		return right;	  }	}void TreeType::printHeightofTree(ofstream& outFile) const// Purpose: To print height of tree// Input: outFile// Pre: tree is created// Output: none// Post: tree height is printed// Note: none{	int height;	height = printHeightofTreeHelper(root);	outFile << "Height of Tree: " << (height - 1) << endl << endl; }