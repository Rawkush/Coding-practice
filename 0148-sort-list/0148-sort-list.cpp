class Solution {
public:
    /*
    * only 2 algo can do nlogn, heapsort and merge sort,
    * heapsort cant be used as it need direct idex traversal for getting parent node
   * so merge sort is the only option
   * in nmerge sort index only tell us array start and end, after that index is used to get the data but in linear fashion
   * which is same as done in linked list
    */

    // Returns {head, tail} of the merged sorted list
    pair<ListNode*, ListNode*> MergeTwoSortedList(ListNode* l1, ListNode* l2) {
        // Dummy node to simplify edge cases
        ListNode dummy(0);
        ListNode* curr = &dummy;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        // Attach remaining nodes
        curr->next = l1 ? l1 : l2;

        // Advance curr to the actual tail
        while (curr->next)
            curr = curr->next;

        ListNode* head = dummy.next;
        ListNode* tail = curr;

        return {head, tail};
    }

    ListNode* getTail(ListNode*head, int size) {
        while(head->next && size>1) {
            head = head->next;
            size--;
        }
        return head;
    }

    int getLen(ListNode* head) {
        int s = 0; // size of list
        while(head) {
            head=head->next;
            s++;
        }
        return s;
    }

    ListNode* sortList(ListNode* head) {
        int size = getLen(head);
        int brokenListSize = 1; // 
        while(brokenListSize <= size) {
            ListNode *head1 = head; //firstList head
            ListNode *head2 = NULL; 
            ListNode *tail1 = NULL;
            ListNode *tail2 = NULL;
            ListNode *prevListTail = NULL;  
            int numberofLists = size/brokenListSize;
            // cout<<"list size "<<numberofLists<<endl;
            for(int i=0; i<=numberofLists/2; i++) {
                if(!head1) break;
                tail1 = getTail(head1, brokenListSize);
                // cout<<"tail "<<tail1->val<<endl;
                head2 = tail1->next;
                if(!head2) break;// only one list remains which is sorted
                // cout<<head1->val<<" "<<head2->val<<endl;

                tail1->next = NULL; // break the list
                tail2 = getTail(head2, brokenListSize);
                ListNode *nextHead = tail2->next; // next list head;
                tail2->next = NULL; //break the list
                // cout<<head1->val<<" "<<head2->val<<endl;
                auto res = MergeTwoSortedList(head1, head2);
                head1 = nextHead;
                if(i==0) head = res.first;
                if(prevListTail) {
                    prevListTail->next = res.first;
                    prevListTail = res.second;
                } else {    
                    prevListTail = res.second;
                }
            }

            if(head1 && prevListTail) {
                prevListTail->next = head1;
            }
            brokenListSize*=2; // double the size now
        }
        return head;
    }
};