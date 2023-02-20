#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main() {
	/////////////////////////////// ARRAY ///////////////////////////////
	cout << "/////////////////////////////// ARRAY ///////////////////////////////" << endl;
	
	array<int, 5> arr = {1, 2, 3, 4, 5}; //Declaring array
	//Printing array
	cout << "Array: " << endl;
	for (auto i : arr) {
		cout << i << endl;
	}
	cout << "Size of array arr: " << arr.size() << endl; //To find the size of the array
	cout << "Element at index 2: " << arr.at(2) << endl; //To find element at a certain index
	//To check if the array is empty
	if (arr.empty() == 1) {
		cout << "Array arr is empty." << endl;
	}
	else {
		cout << "Array arr is not empty." << endl;
	}
	cout << "The first element of the array arr is: " << arr.front() << endl; //To find the first element of the array
	cout << "The last element of the array arr is: " << arr.back() << endl; //To find the last element of the array
	arr.fill(10); //Filling array with 10
	//Printing Array
	cout << "Array: " << endl;
	for (auto i : arr) {
		cout << i << endl;
	}
	cout << endl;
	cout << endl;

	/////////////////////////////// VECTOR ///////////////////////////////
	cout << "/////////////////////////////// VECTOR ///////////////////////////////" << endl;

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	cout << "Size of vector v: " << v.size() << endl; //To find the size of the vector
	cout << "First element of vector v: " << v.front() << endl; //To find the first element of the vector
	cout << "Maximum size that vector v can have: " << v.max_size() << endl; //To find the maximum size that v can have
	cout << "Current capacity of vector v: " << v.capacity() << endl; //To find the current capacity of the vector
	cout << "Vector: " << endl;
	for (auto i : v) {
		cout << i << endl;
	}
	cout << endl;
	cout << endl;

	/////////////////////////////// DEQUE ///////////////////////////////
	cout << "/////////////////////////////// DEQUE ///////////////////////////////" << endl;
	deque<int> d = { 1,2,3 }; //Creating a deque
	d.push_back(5); //Push element inside the deque
	d.push_front(0); //Push element in the front of the deque
	cout << "Deque before erasing the first element: " << endl;
	for (int i = 0; i < d.size(); i++) {
		cout << d.at(i) << endl;
	}

	d.erase(d.begin()); //Erase the first element of the deque

	cout << "Deque after erasing the first element: " << endl;
	for (int i = 0; i < d.size(); i++) {
		cout << d.at(i) << endl;
	}
	cout << endl;
	cout << endl;

	/////////////////////////////// LIST ///////////////////////////////
	cout << "/////////////////////////////// LIST ///////////////////////////////" << endl;
	list<int> l(3,5); //Creating a list
	l.push_back(2); //Push element in the list
	l.push_front(0); //Push element in the front of the list
	cout << "Following is the list created:" << endl;
	for (int i : l) {
		cout << i << endl;
	}
	cout << "Size of list is: " << l.size() << endl; // To print the size of the list
	cout << endl;
	cout << endl;

	/////////////////////////////// STACK ///////////////////////////////
	cout << "/////////////////////////////// STACK ///////////////////////////////" << endl;
	stack<string> s; //Created a stack s
	//Adding elements to list
	s.push("Atharva"); 
	s.push("Gauba");
	s.push("Prakhar");
	cout << "Size of the stack is: " << s.size() << endl; //Size of stack is
	cout << "Following is the stack created: " << endl;
	//Printing stack
	while (s.empty() == 0) {
		cout << s.top() << endl;
		s.pop();
	}
	//Checking if the stack is empty or not
	if (s.empty()) {
		cout << "Stack is empty";
	}
	else {
		cout << "Stack is not empty";
	}
	cout << endl;
	cout << endl;

	/////////////////////////////// QUEUE ///////////////////////////////
	cout << "/////////////////////////////// QUEUE ///////////////////////////////" << endl;
	queue<int> q; //Declared a queue
	//Adding elements to the queue
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);
	cout << "Size of the queue q: " << q.size() << endl; //Printing size of the queue
	cout << "First element of queue q: " << q.front() << endl; //Printing the first element of the queue
	cout << "Last element of queue q: " << q.back() << endl; //Printing the last element of the queue
	//Printing the queue
	cout << "Queue q: " << endl;
	while (!q.empty()) {
		cout << q.front() << endl;
		q.pop();
	}
	cout << endl;
	cout << endl;

	/////////////////////////////// PRIORITY QUEUE ///////////////////////////////
	cout << "/////////////////////////////// PRIORITY QUEUE ///////////////////////////////" << endl;
	priority_queue<int> maxpq; //Declaring a priority queue
	//Adding elements to the queue maxpq
	maxpq.push(1);
	maxpq.push(2);
	maxpq.push(3);
	maxpq.push(4);
	maxpq.push(5);
	int maxn = maxpq.size();
	//Printing the queue
	cout << "Priority Queue maxpq: " << endl;
	for (int i = 0; i < maxn; i++) {
		cout << maxpq.top() << endl;
		maxpq.pop();
	}

	priority_queue<int, vector<int>, greater<int>> minipq; //Declaring a priority queue minipq
	//Adding elements to queue minipq
	minipq.push(1);
	minipq.push(2);
	minipq.push(3);
	minipq.push(4);
	minipq.push(5);
	int minin = minipq.size();
	//Printing the Priority Queue minipq
	cout << "Priority Queue minipq: " << endl;
	for (int i = 0; i < minin; i++) {
		cout << minipq.top() << endl;
		minipq.pop();
	}
	cout << "Checking whether priority queue minipq is empty or not: " << endl;
	if (minipq.empty()) {
		cout << "Queue is empty" << endl;
	}
	else {
		cout << "Queue is not empty" << endl;
	}
	cout << endl;
	cout << endl;

	/////////////////////////////// SET /////////////////////////////////
	cout << "/////////////////////////////// SET /////////////////////////////////" << endl;
	set<int> st; //Declaring a set
	//Adding elements to the set
	st.insert(11);
	st.insert(11);
	st.insert(11);
	st.insert(22);
	st.insert(33);
	st.insert(44);
	st.insert(44);
	st.insert(55);
	cout << "Size of set st: " << s.size() << endl;
	//Printing set st
	cout << "Set st:" << endl;
	for (int i : st) {
		cout << i << endl;
	}
	//Erasing a eleement from the set st
	st.erase(55);
	//Checking if the element mentioned is present in the set or not
	if (st.count(22) == 1) {
		cout << "This element is present in the set" << endl;
	}
	else {
		cout << "This element is not present in the set" << endl;
	}
	cout << endl;
	cout << endl;
	

	/////////////////////////////// MAP /////////////////////////////////
	cout << "/////////////////////////////// MAP /////////////////////////////////" << endl;
	map<int, string> m; //Declaring a map m
	//Adding key and values to the map
	m[0] = "Atharva Sachin Tilak";
	m[1] = "Harshit Gauba";
	m[3] = "Prakhar Agarwal";
	m[4] = "Pratyush Jain";
	m[5] = "Arpit Kumar";
	//Printing the size of the map m
	cout << "Size of Map = " << m.size() << endl;
	//Checking if a element is present in the map m
	if (m.count(6) == 1) {
		cout << "This key is present in the map" << endl;
	}
	else {
		cout << "This key is not present in the map" << endl;
	}
	//Printing the map m
	map<int, string>::iterator i = m.begin();
	while (i != m.end()) {
		cout << "Key = " << i->first << ", Value = " << i->second << endl;
		i++;
	}
	cout << endl;
	cout << endl;

	/////////////////////////////// MULTISET /////////////////////////////////
	cout << "/////////////////////////////// MULTISET /////////////////////////////////" << endl;
	multiset<int> ms; //Declaring a multiset ms
	//Adding elements to the multiset ms
	ms.insert(10);
	ms.insert(20);
	ms.insert(30);
	ms.insert(40);
	ms.insert(50);
	ms.insert(20);
	//Printing the multiset ms
	multiset<int>::iterator it;
	cout << "Mustiset ms: " << endl;
	for (it = ms.begin(); it != ms.end(); it++) {
		cout << *it << endl;
	}
	ms.erase(ms.begin(), ms.find(30)); //Erasing element from multiset ms
	cout << "Multiset ms after erasing some elements: " << endl;
	//Printing the multiset
	for (it = ms.begin(); it != ms.end(); it++) {
		cout << *it << endl;
	}
	cout << endl;
	cout << endl;

	/////////////////////////////// MULTIMAP /////////////////////////////////
	cout << "/////////////////////////////// MULTIMAP /////////////////////////////////" << endl;
    multimap<int, int> mm; //Declaring multimap mm
	//Adding elements to multimap mm
	mm.insert(pair<int, int>(1, 10));
	mm.insert(pair<int, int>(2, 20));
	mm.insert(pair<int, int>(3, 30));
	mm.insert(pair<int, int>(4, 40));
	mm.insert(pair<int, int>(5, 50));
	mm.insert(pair<int, int>(1, 20));
	mm.insert(pair<int, int>(4, 30));
	multimap<int, int>::iterator itr;
	//Printing the multimap mm
	for (itr = mm.begin(); itr != mm.end(); itr++) {
		cout << "Key = " << itr->first << ", Value = " << itr->second << endl;
 	}
	int n =  mm.erase(4); //Erasing elements from the multimap mm
	//Printing multimap after erasing element
	for (itr = mm.begin(); itr != mm.end(); itr++) {
		cout << "Key = " << itr->first << ", Value = " << itr->second << endl;
	}
	cout << endl;
	cout << endl;

	/////////////////////////////// UNORDERED SET /////////////////////////////////
	cout << "/////////////////////////////// UNORDERED SET /////////////////////////////////" << endl;
    unordered_set<string> us; //Declaring a unordered set us
	//Adding elements to the set us
	us.insert("INDIA");
	us.insert("AUSTRALIA");
	us.insert("LONDON");
	us.insert("GERMANY");
	us.insert("JAPAN");

	string key = "LONDON";
	//Checking wether the key is present in the set or not
	if (us.find(key) == us.end()) {
		cout << key << " not found" << endl;
	}
	else {
		cout << "Found " << key << endl;
	}
	//Printing the unordered set us
	cout << "Unordered Set us:" << endl;
	unordered_set<string>::iterator its;
	for (its = us.begin(); its != us.end(); its++) {
		cout << *its << endl;
	}
	cout << endl;
	cout << endl;
	
	/////////////////////////////// UNORDERED MAP /////////////////////////////////
	cout << "/////////////////////////////// UNORDERED MAP /////////////////////////////////" << endl;
	unordered_map<string, int> um;
	um["A"] = 1;
	um["B"] = 2;
	um["C"] = 3;
	um["D"] = 4;
	um["E"] = 5;
	//Findin if the element mentioned is present in the map or not
	if (um.find("G") == um.end()) {
		cout << "Key is not present" << endl;
	}
	else {
		cout << "Key is present" << endl;
	}
	//Printing the Unordered map um
	cout << "Unordered Map um: " << endl;
	for (auto i : um) {
		cout << i.first << " - " << i.second << endl;
	}
	cout << endl;
	cout << endl;

	/////////////////////////////// UNORDERED MULTISET /////////////////////////////////
	cout << "/////////////////////////////// UNORDERED MULTISET /////////////////////////////////" << endl;
	unordered_multiset<int> ums; //Declaring a unordered Multiset ums
	//Adding elements to ums
	ums.insert(15);
	ums.insert(25);
	ums.insert(35);
	ums.insert(45);
	ums.insert(55);
	//Printing size of ums
	cout << "Size of the multiset: " << ums.size() << endl;
	unordered_multiset<int>::iterator itm;
	//Printing ums
	cout << "Multiset ums: " << endl;
	for (itm = ums.begin(); itm != ums.end(); itm++) {
		cout << *itm << endl;
	}
	
	/////////////////////////////// UNORDERED MULTIMAP /////////////////////////////////
	cout << "/////////////////////////////// UNORDERED MULTIMAP /////////////////////////////////" << endl;
	//Creating a unordered multimap umm
	unordered_multimap<string, int> umm(
		{
		{"Mouse", 5},
		{"Keyboard", 8},
		{"Computer", 8},
		{"Earphone", 8},
		{"Mic", 3}
		}
	);
	unordered_multimap<string, int>::iterator itb;
	//Printing umm
	for (itb = umm.begin(); itb != umm.end(); itb++) {
		cout << "Key = " << itb->first << ", Value = " << itb->second << endl;
	}
	//Checking wether umm is empty or not
	if (umm.empty() == 1) {
		cout << "This map is empty" << endl;
	}
	else {
		cout << "This map is not empty" << endl;
	}
}