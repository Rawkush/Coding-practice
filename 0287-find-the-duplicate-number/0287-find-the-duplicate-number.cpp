class Solution {
public:
 
 /**
 * Two pointers / floydd warshall
 * TC O(n)
 * SC O(1)
 */
 
  int findDuplicate(vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[nums[0]];
    //since number must exist according to pigeon hole principle
    // therefore this loop will terminate
    while(slow!=fast){
      slow = nums[slow];
      fast = nums[nums[fast]];
    }

    // now i have two LL
    // head1 => 0 , tail1 = slow
    // head2 => nums[slow], tail2 = slow
    int head1 = 0;
    int head2 = fast;
    // according to floydd cycle detection 
    while(head1 != head2){
      head1 = nums[head1];
      head2 = nums[head2];
    }
    return head1;
  }
  

  /**
    use array as hashmap
  */

//   int helper(vector<int>& nums, int idx){
//     if(idx>=nums.size()) return -1;
//     int itm = nums[idx];
//     int di = helper(nums, idx+1);
//     if(di> 0) return di;
//     if(nums[itm]==itm && itm!=idx) return itm;
//     nums[itm] = itm;
//     return -1;
//   }

//   int findDuplicate(vector<int>& nums) {
//    return helper(nums, 0);
//   }


  /**
  -ve marking
  */
  // int findDuplicate(vector<int>& nums) {
  //   for(int i=0; i<nums.size(); i++){
  //     int index = abs(nums[i]);
  //     int itemAtIdx = nums[index];
  //     if(itemAtIdx<0) return index;
  //     nums[index] = -nums[index];
  //   }
  //   return 0;
  // } 
};