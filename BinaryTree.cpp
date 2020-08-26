/*
 *This program is implementing some basic function in binary
 *trees using linked representation. we highly use recursive
 *function to analyze the tree. finally, we implement some
 *ordering to allow complete transversal of the tree.
 *Course : CSCI161.
 *Date  : 18march, 2020.
 *Name : Khalid.
*/

#include "BinaryTree.hpp"
#include "Deque.hpp"
#include <math.h>
using namespace std;

// something to get you started.
// The tricky bits (recursion, pointers and Node-copying)
// 	are covered (and tested).

//Creates a BinaryTree whose root contains the element, and its
//left and right subtrees are copied from the BinaryTree inputs.
	BinaryTree::BinaryTree(PatientInfo element, BinaryTree left_tree, BinaryTree right_tree) {
		// some help to get started...
		// Create subtree structures whose roots will be the left and right child
		// of the newly created tree.
		TreeNode * left_subtree = build_subtree(left_tree.root);
		TreeNode * right_subtree = build_subtree(right_tree.root);
		root = new TreeNode(element, left_subtree, right_subtree);
		m_size = 1 + left_tree.m_size + right_tree.m_size;
		// fill in the rest yourself
	}
//Creates a BinaryTree whose root contains the element.
	BinaryTree::BinaryTree(PatientInfo element) {
		// this one's for you.
		root = new TreeNode(element, nullptr, nullptr);
		m_size = m_size + 1;
	}
//Creates a binary tree with no elements and root is pointing to null.
	BinaryTree::BinaryTree() {
		root = nullptr;
		m_size = 0;
	}

	// private recursive helper function
	// completed and tested.
//A recursive function that builds a subtree structure,
//that is a deep copy of the subtree rooted at node.
	BinaryTree::TreeNode * BinaryTree::build_subtree(const TreeNode * node) {
		  if (node == nullptr) {
				return nullptr;
			}
			return new TreeNode(node->element,build_subtree(node->lchild),
					build_subtree(node->rchild));
	}
			 
	// completed and tested.
	// It is necessary to have a deep copy as all the
	// deleting of nodes in a tree that is not a deep
	// copy will produce ++++ seg faults.
	// Not so when every tree is deep-copied.
//Creates a tree that is the same as the one to be copied.
	BinaryTree::BinaryTree( const BinaryTree & copy) {
		root = build_subtree(copy.root);
		m_size = copy.m_size;
	}


	// completed and tested
	// passes all the work to the recursive function.
//Removes any dynamically allocated memory.
	BinaryTree::~BinaryTree() {
		delete_subtree(root);
	}

	// recursive helper function
	// completed and tested.
//A recursive function that deletes the entire subtree rooted at node.
	BinaryTree::TreeNode * BinaryTree::delete_subtree( TreeNode * node ) {
		if (node == nullptr) {
			return nullptr;
		}
	
		if (node->lchild != nullptr) {
			node->lchild = delete_subtree(node->lchild);
		}
		if (node->rchild != nullptr) {
			node->rchild = delete_subtree(node->rchild);
		}
		delete node;
		return nullptr;
	}

//getting the number of elements in the binary tree.
	int BinaryTree::size() const {
		// yours
		return m_size;
	}
//return 1 if empty or else return 0;
	bool BinaryTree::is_empty() const {
		// yours
		if(m_size == 0)
			return true;
		else
			return false;
	}
//it is the maximum number of nodes in a path from root to the leaf.
// from the root to a leaf of the BinaryTree.
	int BinaryTree::height() const {
		// yours
		return get_height(root);
	}

	// recursive helper function
//A private recursive function for determining the height of a subtree
//starting at the given node.
	int BinaryTree::get_height(TreeNode * subroot) const {
		// your turn to try a recursive function
		if(subroot == nullptr){
			return 0;
		}
			
		int lh = get_height(subroot->lchild);
		int rh = get_height(subroot->rchild);
			
		return 1 + std::max(lh, rh);
	}

	// We will be going over all the traversals in lectures and labs
	// Once you understand what is happening, these are easy!
	//
	void BinaryTree::pre_order(Deque<PatientInfo>& Q) const {
		// yours
		gen_preorder(Q, root); 
	}

	// recursive helper function
//recursive helper function for ordering the elements in preorder transversal.
	void BinaryTree::gen_preorder(Deque<PatientInfo> & Q, TreeNode * node) const {
		//yours
		if(node == nullptr)
			return;
		else{
			Q.push(node->element);
			gen_preorder(Q, node->lchild);
			gen_preorder(Q, node->rchild);
		}
	}

	void BinaryTree::in_order(Deque<PatientInfo> & Q) const {
		// yours
		gen_inorder(Q, root);
	}

	// recursive helper function
//recursive helper function for ordering the elements in inorder transversal.
	void BinaryTree::gen_inorder(Deque<PatientInfo> & Q, TreeNode * node) const {
		// yours
		if(node == nullptr)
			return;
		else{
			gen_inorder(Q, node->lchild);
			Q.push(node->element);
			gen_inorder(Q, node->rchild);
		}
		
	}

	void BinaryTree::post_order(Deque<PatientInfo> & Q) const {
		// yours
		gen_postorder(Q, root);
	}

	// recursive helper function
//recursive helper function for ordering the elements in postorder transversal.
	void BinaryTree::gen_postorder(Deque<PatientInfo>& Q, TreeNode * node) const {
		// yours
		if(node == nullptr)
			return;
		else{
			gen_postorder(Q, node->lchild);
			gen_postorder(Q, node->rchild);
			Q.push(node->element);
		}
	}
void BinaryTree::DOT_translation() {
	cout << "DOT translation begins:"<<endl;
	cout<<"digraph BST {"<<endl;
	cout<<"\tnode [fontname=\"Arial\"];"<<endl;
	if (root) {
		doDotPrint(root);
	}
	cout<<"}"<<endl;
	cout << "DOT translation ends:"<<endl;
}
void BinaryTree::doDotPrint(BinaryTree::TreeNode * node) {
	if (node->lchild) {
		cout<<"\t"<<node->element.get_id()
		<<" -> "<<node->lchild->element.get_id()
		<<";"<<endl;
		doDotPrint(node->lchild);
	}
	if (node->rchild) {
		cout <<"\t"<<node->element.get_id()
		<<" -> "<<node->rchild->element.get_id()
		<<";"<<endl;
		doDotPrint(node->rchild);
	}
}	
