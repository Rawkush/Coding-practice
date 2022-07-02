#include<iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

/**
  Suppose we have a list A=  1,2,3,4,5 and List B= 7,6,5,3,4,5
  this is not allowed, once our list intersect all the remaining data will same as it is not about data but address in linked list,
  so we can't have an Node which points to two different location
  what is let's say above list intersect at 3
  so let's add 15 at the last of list A  we get  => 1,2,3,4,5, 15
  this will automatically means list B => 3,4,5,15
  since the list intersection doesn't mean having same data it means having same node


  From above we can conclude the below equations
    let x be number of node shared between A and B
    y be remaining elements of A
    z be the remaining elements of B

    therefore total number of elements in A = y+x
    total number of elements in B = z+x
    let z=0
    therefore A = y+x
              B=x
              => A-B =y+x-x
              => A-B = y
    => since we know that all last elements will be same therefore if list A if longer than list B
    by 2 elements,
    we can gurantee that starting 2 elements of A won't be in B,
    so we first find length of both lists, subtracttheir length
    and move the head of longer list by the difference

  After doing this we get both list of same size, now we can check at each node if they intersect if not
  move head of both list by 1

  Q: why are we moving both list pointers simultaneously,
  A: because shared list length will be same, and Length of A and B after above iteration is same,
     so we can can gurantee that index 0 of list can never intersect with anythingother that index 0 of B

*/

/**
 * We traverse both lists to find their lengths. Then we traverse the longer list by the difference in
 * lengths. Then we traverse both lists in parallel until we find a common node
 *
 * @param headA the head of the first linked list
 * @param headB the head of the second linked list
 *
 * @return The node where the intersection occurs.
 */
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
 int diffLength=0;
 int headALength=0;
 int headBLength=0;
 ListNode *ptr1= headA;
 ListNode *ptr2= headB;

 while(ptr1!=NULL){
  headALength++;
  ptr1 = ptr1->next;
 }
 while(ptr2!=NULL){
   headBLength++;
   ptr2 = ptr2->next;
 }

 ptr1=headA;
 ptr2=headB;
 if(headALength> headBLength){
   diffLength=headALength-headBLength;
   while(diffLength>0){
     ptr1 = ptr1->next;
     diffLength--;
   }
 }else{
   diffLength=headBLength-headALength;
   while(diffLength>0){
     ptr2 = ptr2->next;
     diffLength--;
   }
 }

  /** Now both list are of same length */
  while(ptr1!=ptr2) {
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }
  return ptr1;
}

int main(){
  ListNode *headA = new ListNode(1);
  ListNode i(2);
  headA->next = &i;
  ListNode i(3);
  ListNode *headB = new ListNode(2);
  ListNode* newHead=getIntersectionNode(headA, headB);
  while(newHead!=NULL){
    cout<<newHead->val<<" ";
  }
  return 0;
}