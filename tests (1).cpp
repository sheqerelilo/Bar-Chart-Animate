#include <iostream>
#include <sstream>
#include "barchartanimate.h"
using namespace std;


bool testBarDefaultConstructor() {
	cout << "TESTING BAR DEFAULT (3 tests): " << endl;
  Bar b;
    if (b.getName() != "") {
    	cout << "testBarDefaultConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 0) {
    	cout << "testBarDefaultConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "") {
    	cout << "testBarDefaultConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarDefaultConstructor: all passed!" << endl;
    return true;
}

bool testBarParamConstructor() {
	cout << "TESTING BAR PARAM (3 tests): " << endl;
  Bar b("Chicago", 9234324, "US");
    if (b.getName() != "Chicago") {
    	cout << "testBarParamConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 9234324) {
    	cout << "testBarParamConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "US") {
    	cout << "testBarParamConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarParamConstructor: all passed!" << endl;
    return true;
}

void testOperator1(BarChart &bc){
  cout << "TESTING BAR OPERATORS TEST 1 (5 tests): " << endl;
  int count  = 0;
  if(bc[0] <= bc[1]){
    cout << "Less than or equal to passed!" << endl;
    count++;
   }
  if(bc[0] < bc[1]){
    cout << "Less than passed!" << endl;
    count++;
  }
  if(bc[2] >= bc[1]){
    cout << "Greater than passed!" << endl;
    count++;
  }
  if(bc[2] > bc[1]){
    cout << "Greater than passed!" << endl;
    count++;
  }
  if(bc[3] == bc[3]){
    cout << "Equal to passed!" << endl;
    count++;
  }
  if( count != 5){
    cout << "Not all tests passed!" << endl;
  }
  cout << endl;
}
//test all bar operations 
void testOperator2(BarChart &bc){
  cout << "TESTING BAR OPERATORS TEST 2 (5 tests): " << endl;
  int count  = 0;
  if(bc[3] <= bc[4]){
    cout << "Less than or equal to passed!" << endl;
    count++;
   }
  if(bc[2] < bc[3]){
    cout << "Less than passed!" << endl;
    count++;
  }
  if(bc[3] >= bc[1]){
    cout << "Greater than passed!" << endl;
    count++;
  }
  if(bc[4] > bc[3]){
    cout << "Greater than passed!" << endl;
    count++;
  }
  if(bc[1] == bc[1]){
    cout << "Equal to passed!" << endl;
    count++;
  }
  if( count != 5){
    cout << "Not all tests passed!" << endl;
  }
  cout << endl;
}

//tests dump functions twice
void testDump(BarChart &bc){
  stringstream ss;
  string temp;
  cout << "TESTING COUT DUMP: " << endl;
  bc.dump(cout);
  cout << endl << "TESTING STRINGSTREAM DUMP (5 tests): " << endl;
  bc.dump(ss);

  int count = 0;

  getline(ss, temp);
  if(temp == "frame: 1"){
    cout << "Frame case passed!" << endl;
    count++;
  }
  getline(ss, temp);
  if(temp == "e 5 rat"){
    cout << "Bar 1 case passed!" << endl;
    count++;
  }
  getline(ss, temp);
  if(temp == "d 4 mat"){
    cout << "Bar 2 case passed!" << endl;
    count++;
  }
  getline(ss, temp);
  if(temp == "c 3 at"){
    cout << "Bar 3 case passed!" << endl;
    count++;
    }
  getline(ss, temp);
  if(temp == "b 2 bat"){
    cout << "Bar 4 case passed!" << endl;
    count++;
    }
  getline(ss, temp);
  if(temp == "a 1 cat"){
    cout << "Bar 5 case passed!" << endl;
    count++;
    }
  cout << endl;
}
//tests equality operator between bars, tests index function
void testBarChartConstructorMatch1(BarChart &bc, Bar &b){
  cout << "TESTING BARCHART TO BAR EQUALITY (5 tests): " << endl;
  //tests matching bar
  if(b == bc[0]){
    cout << "Match Bar Test 0 passed!" << endl;
  }
  else{
    cout << "Match Bar Test 0 failed!" << endl;
  }
  //tests for all other non-matching bars
  for(int i = 1; i < bc.getSize(); i++){
    if(b == bc[i]){
      cout << "Match Bar Test " << i << " failed!" << endl;
    }
    else{
      cout << "Match Bar Test " << i << " passed!" << endl;
    }
  }
  cout << endl;
}
//tests equality operator
void testBarChartConstructorMatch2(BarChart &bc, BarChart &bc2){
  cout << "TESTING BARCHART TO BAR EQUALITY (5 tests): " << endl;
  for(int i = 1; i < bc.getSize(); i++){
    if(bc[i] == bc2[i]){
      cout << "Match Bar Test " << i << " failed!" << endl;
    }
    else{
      cout << "Match Bar Test " << i << " passed!" << endl;
    }
  }
  cout << endl;
}
void testGraph(BarChart & bc) {
    map<string, string> colorMap;
    colorMap["cat"] = RED;
    colorMap["bat"] = BLUE;
    colorMap["rat"] = GREEN;
    colorMap["mat"] = CYAN;
    int top = 1;
    cout << BLACK << "TESTING GRAPH TEST 1: " << endl;
    bc.graph(cout, colorMap, top);
    cout << endl;
    top = 5;
    cout << BLACK << "TESTING GRAPH TEST 2: " << endl;
    bc.graph(cout, colorMap, top);
    cout << endl;
}

//tests default constructor, param constructor
void testBC(BarChart &bc){
  Bar b("a", 1, "cat");
  //tests BarChart to Bar
  testBarChartConstructorMatch1(bc, b);
  //test BC to BC Test 1
  BarChart bc2(bc);
  testBarChartConstructorMatch2(bc, bc2);
  //tests BC to BC Test 2
  BarChart bc3 = bc;
  testBarChartConstructorMatch2(bc, bc3);

}
// tests default constructor, param constructor
BarChart createBC() {
    BarChart bc(5);
	bc.setFrame("1");
	bc.addBar("a", 1, "cat");
	bc.addBar("b", 2, "bat");
	bc.addBar("c", 3, "at");
	bc.addBar("d", 4, "mat");
	bc.addBar("e", 5, "rat");
    
    return bc;
}
// tests set and get frame three times
void testSetFrame() {
    cout << "TESTING SET FRAME (3 tests): " << endl;
    BarChart bc;
    bc.setFrame("Hello");
    
    if (bc.getFrame() == "Hello") {
        cout << "Passed Test 1!" << endl;
    }
    bc.setFrame("audhaoi hpia sp");
    
    if (bc.getFrame() == "audhaoi hpia sp") {
        cout << "Passed Test 2!" << endl;
    }
    bc.setFrame("1818113278229");
    
    if (bc.getFrame() == "1818113278229") {
        cout << "Passed Test 3!" << endl;
    }
    cout << endl;
}
void testFrameAndAnimate(string filename, bool testnum) {
  cout << "TESTING ADD FRAME AND ANIMATE (2 possible tests): " << endl;
	ifstream file(filename);
	string title;
	getline(file, title);
	string xlabel;
	getline(file, xlabel);
	string source;
	getline(file, source);
	
	BarChartAnimate bca(title, xlabel, source);

    if (testnum) {	
        for (int i = 0; i < 5; i++) {
            bca.addFrame(file);
        }
        bca.animate(cout, 5, -1);
    } else {
        for (int i = 0; i < 100; i++) {
            bca.addFrame(file);
        }
        bca.animate(cout, 15, -1);
    }
    
}
void testSize(BarChart &bc, BarChartAnimate &bca) {
    cout << "TESTING BARCHART AND BARCHARTANIMATE SIZE: " << endl;
    // Testing BCA Size 
    ifstream file;
    file.open("cities.txt");
    string temp;
    getline(file, temp);
    getline(file, temp);
    getline(file, temp);
    
    BarChart bc2;
    BarChartAnimate bca2("okay","yes","no");
    if (bc.getSize() == 5) {
        cout << "BC Size Test 1 passed!" << endl;
    }
    if (bc2.getSize() == 0) {
        cout << "BC Size Test 2 passed!" << endl;
    }
    if(bca.getSize() == 0) {
        cout << "BCA Size Test 1 passed!" << endl;
    } 
    
    for (int i = 0; i < 5; i++) {
        bca2.addFrame(file);
    }
    if (bca2.getSize() == 5) {
        cout << "BCA Size Test 2 passed!" << endl;
    }
    file.close();
    cout << endl;
}
BarChartAnimate createBCA() {
    BarChartAnimate bca("test1","test2","test3");
    return bca;
}

int main() {
  BarChart bc = createBC();
  BarChartAnimate bca = createBCA();

	testBarDefaultConstructor();
	testBarParamConstructor();
  testOperator1(bc);
	testOperator2(bc);
	testSize(bc,bca);

   testBC(bc);
    testDump(bc);
    testSetFrame();
    testGraph(bc);
    // Tests add frame and animate
    cout << BLACK << "Would you like to test Animate Test 1? (Yes/No)" << endl;
    string user;
    cin >> user;
    
    string filename;
    filename = "cities.txt";
    bool usernum = true;
    
    if (user == "Yes") {
        testFrameAndAnimate(filename,usernum);
    }
    // Tests add frame and animate
    filename = "brands.txt";
    cout << BLACK << "Would you like to test Animate Test 2? (Yes/No)" << endl;
    cin >> user;
    if (user == "Yes") {
        usernum = false;
        testFrameAndAnimate(filename,usernum);
    }
    
    return 0;
}