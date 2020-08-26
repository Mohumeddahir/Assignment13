/*
 *This program deals with the implementation of binarysearchtree where
 *we store aand access elements by a specific key and beyond that, doing some
 *deletion of elements and some ordering. We extend it to some aspects of inheritance.
 *Course : CSCI161.
 *Date : 1st of april, 2020.
 *Author : Khalid.
*/
#include<iostream>
#include"BinarySearchTree.hpp"
#include"PatientInfo.hpp"
using namespace std;
//The constructor is left empty as the base constructor is called first.
BinarySearchTree :: BinarySearchTree(){
}
//we called the copy constructor of the base class and that is why we have it
//infront of the binarysearch copy constructor.
BinarySearchTree :: BinarySearchTree(const BinarySearchTree &copy) : BinaryTree(copy){
	cout<<"BinarySearchTree copy constructor is called. "<<endl;
}
//the destructor of the base class is automatically called for deallocation
//and for that reason, this is left blank.
BinarySearchTree :: ~BinarySearchTree(){

}
//this is private recursive helper function that generates the get element and searches
//it from the eleemnts. it returns a PatientInfo object. 
PatientInfo BinarySearchTree :: generate_getelement(TreeNode *node, string key){
	PatientInfo pin;
	if(node == nullptr){
		return pin;}
	if(node->element.get_id() == key){
		return node->element;}
	if(node->element.get_id() > key){
		return generate_getelement(node->lchild, key);}
	if(node->element.get_id() < key){
		return generate_getelement(node->rchild, key);}
}
//This function call the recursive helper function and gets the elements.
PatientInfo BinarySearchTree :: get_element(string key){
	return generate_getelement(root, key);
}
//A private recursive helper function that generates the insertion of an elements and
//returns back a pointer to a TreeNode.
BinaryTree :: TreeNode *BinarySearchTree :: generate_insert(TreeNode *node, PatientInfo element){
	if(node == nullptr){
		return new TreeNode(element, nullptr, nullptr);}
	if(node->element > element){
		node->lchild =  generate_insert(node->lchild, element);}
	if(node->element < element){
		node->rchild =  generate_insert(node->rchild, element);}
	return node;
}
//this funtion calls the helper function that inserts the element.
void BinarySearchTree  :: insert(PatientInfo element){
	root = generate_insert(root, element);
}
/*
BinarySearchTree :: TreeNode *BinarySearchTree :: generate_remove(TreeNode *node PatientInfo pi){
	if(node == nullptr){
		return;}
	if(node->element.get_id() == pi){
		if(node->lchild == nullptr && node->rchild == nullptr){
			if(node != root){
				TreeNode *temp = node;
				if(node->parent->lchild == temp){
					node->lchild = nullptr;}
				else 
		}
		else if(
	
}
*/
void BinarySearchTree :: remove(PatientInfo pi){

}

