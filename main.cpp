#include "PatientInfo.hpp"
#include "BinarySearchTree.hpp"
#include "BinaryTree.hpp"
#include <iostream>
#include <random>
#include <vector>
#include <ctime>
#include <algorithm>
	using std::string;
	using std::cout;
	using std::endl;
	using std::vector;

int main() {
	int room = 355;
	char ward = 'C';
	string firstname = "Bingo";
	string letters[] = {"E","U","O","W","Y","B","X","N","G","D","A","M","C","L","R","P","T","K","Q","S","J","V","F","I","Z","H"};

	vector<string> lastnames;
	for (int i=0; i<26; i++) {
		lastnames.push_back(letters[i]);
	}

	//std::random_device rd;
	//std::mt19937 g(rd());

	//std::shuffle(lastnames.begin(),lastnames.end(),g);
	cout<<"letters in random order";
	for(int i = 0; i < 26; i++){
		cout<<lastnames[i]<<", ";
	}
	cout<<endl;

	// create a list of patients
	vector<PatientInfo> patients;
	for (int i=0; i<26; i++) {
		patients.push_back(PatientInfo(lastnames[i],firstname,ward,room));
	}

	cout << "The list of patients in randomized order:\n";
	for (int i=0; i<26; i++) {
		cout << patients[i] << endl;
	}

	BinarySearchTree bst;



	for (int i=0; i<26; i++) {
		bst.insert(patients[i]);
	}

cout << "After inserting the elements, the inorder traversal is \n";
	Deque<PatientInfo> queue;
	bst.in_order(queue);

queue.print_queue();
cout << endl;

bst.DOT_translation();
/*

	cout << "All inserted.\n";
	// checking to see if the base BinaryTree is reponding:
	cout << "Number of patients = "<<bst.size()<<endl;
	cout << "Height of the tree is "<<bst.height()<<endl;


	Deque<PatientInfo> queue;
	bst.in_order(queue);

	cout << "The patient list, in order of Id: \n";
	for (int i=0; i<26; i++) {
		cout << queue.dequeue() << endl;
	}
	// a leaf node is removed.
	p = bst.get_element("C_23");
	cout << "the patient with id C_23 is "<<p<<endl;
	bst.remove_element(p);

	// a node with a single left child is removed.
	p = bst.get_element("J_7");
	bst.remove_element(p);

	// the root node
	p = bst.get_element("W_1");
	bst.remove_element(p);

	// a node with 2 children
	p = bst.get_element("F_5");
	bst.remove_element(p);

	bst.DOT_translation();

	cout << "Number of patients = "<<bst.size()<<endl;
	cout << "Height of the tree is "<<bst.height()<<endl;

	// as the various remove functions are implemented,
	// add more testing here.


*/
	cout << "All done!\n";
	return 0;


}
