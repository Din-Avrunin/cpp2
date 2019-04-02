#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"

int main() {

  ariel::Tree threetree;
  ariel::Tree treeone;
  ariel::Tree Treetwo;
 
  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);
  treeone.insert(50);
  treeone.insert(30);
  treeone.insert(70);
  treeone.insert(20);
  treeone.insert(40);
  treeone.insert(60);
  treeone.insert(80);





  badkan::TestCase tc("Binary tree");
  tc

  
  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_OK    (threetree.print())
  .CHECK_EQUAL (treeone.size(),7)
  .CHECK_EQUAL (treeone.root(),50)
  .CHECK_EQUAL (treeone.contains(60),true)
  .CHECK_OK    (treeone.remove(80))
  .CHECK_THROWS(treeone.remove(80))
  .CHECK_THROWS (treeone.right(70))   
  .CHECK_EQUAL (treeone.parent(40),30)
  .CHECK_EQUAL (treeone.parent(60),70)
  .CHECK_THROWS(treeone.parent(50))
  .CHECK_THROWS (treeone.left(20))  
  .CHECK_OK    (treeone.remove(50))
  .CHECK_OK    (treeone.print())
  .CHECK_OK    (treeone.print())

  

  .CHECK_THROWS (Treetwo.root())
  .CHECK_EQUAL (Treetwo.size(),0)
  .CHECK_OK    (Treetwo.insert(3))
  .CHECK_OK    (Treetwo.insert(1))
  .CHECK_OK    (Treetwo.insert(10))
  .CHECK_EQUAL (Treetwo.contains(3),true)
  .CHECK_OK    (Treetwo.insert(5))
  .CHECK_OK    (Treetwo.insert(4))
  .CHECK_OK    (Treetwo.insert(7))
  .CHECK_OK    (Treetwo.insert(16))
  .CHECK_OK    (Treetwo.insert(15))
  .CHECK_OK    (Treetwo.insert(20))
  .CHECK_EQUAL (Treetwo.root(),3)
  .CHECK_EQUAL (Treetwo.parent(1),3)
  .CHECK_OK    (Treetwo.remove(3))
  .CHECK_EQUAL (Treetwo.contains(3),false)
  .CHECK_OK    (Treetwo.print())
  .CHECK_EQUAL (Treetwo.parent(16),10)
  .CHECK_EQUAL (Treetwo.right(5),7)
  .CHECK_OK    (Treetwo.remove(1))
  .CHECK_EQUAL (Treetwo.contains(30),false)
  .CHECK_THROWS(Treetwo.remove(3))
  .CHECK_OK    (Treetwo.remove(4))
  .CHECK_THROWS (Treetwo.left(5))
  .CHECK_OK    (Treetwo.print()) 
    .print();
  
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}