#include <iostream>
#include <string>
#include <fstream>
#include "BSTree.h"

using namespace std;

// DO NOT SUBMIT TO Gradescope
// a local test file

BSTree read_from_file(string file_name)
{
  // open the file and use the input operator (operator>>)
  // to construct a new tree 
      
  ifstream infile(file_name); 
  if (infile.fail())
    throw "Error while attempting to read file: " + file_name;
  BSTree new_tree;
  infile >> new_tree;
  return new_tree;
}


int main()
{
  try {
    // use data_files
    for(int i = 1; i <= 12; i++) {
      string dir = "data_files/" + std::to_string(i);
      BSTree l = read_from_file(dir + "l");
      cout << "average search time linear " << i << " "
	   << l.get_average_search_time() << endl;
      
      BSTree p = read_from_file(dir + "p");
      cout << "average search time perfect "<< i << " "
	   << p.get_average_search_time() << endl;
      
      BSTree r = read_from_file(dir + "r");
      cout << "average search time random "<< i << " "
	   << r.get_average_search_time() << endl;

      if(i <= 4) {
	// print the tree p
	cout << "prefect tree " << i << endl << p;
      }

      cout << endl;
    }
  } catch (string& error) {
    cout << error << endl;
  }
}

