/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
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
};