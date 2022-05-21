/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* temp3 = l1;
        ListNode* temp4 = l2;
        int carry = 0;
       while(l1 != nullptr && l2 != nullptr){
           int sum = l1->val + l2->val + carry;
          
           if(sum > 9){
               l1->val = sum%10;
               l2->val = sum%10;
               carry = 1;
               
           } else {
               l1->val = sum;
               l2->val = sum;
               carry = 0;
           }
           temp3 = l1;
           temp4 = l2;
           l1 = l1->next;
           l2 = l2->next;
       }
        
        if(l1 == nullptr && l2 == nullptr && carry == 1){  
            temp3->next = new ListNode();
            temp3->next->val = 1;
            l1 = temp3;
            return temp1;
        } else if(l1 == nullptr && l2 == nullptr && carry == 0) {
            return temp1;
        }
    
    if(l1 == nullptr && l2 != nullptr){
        int sum = 0;
       
            while(l2 != nullptr){
                if(carry == 1){
                    sum = l2->val + 1;
                     if(sum > 9){
                       carry = 1;
                          if(l2->next == nullptr){
                             l2->next = new ListNode();
                              l2->next->val =1;
                               l2->val = sum%10;
                         l2 = l2->next;
                              return temp2;
                         }
                       l2->val = sum%10;
                        
                     } else {
                        carry = 0;
                         l2->val += 1;
                       }
                }
                l2 = l2->next;
            }
        return temp2;
    }
    
     if(l2 == nullptr && l1 != nullptr){
        int sum = 0;
       
            while(l1 != nullptr){
                if(carry == 1){
                    sum = l1->val + 1;
                     if(sum > 9){
                       carry = 1;
                         if(l1->next == nullptr){
                             l1->next = new ListNode();
                             
                         }
                       l1->val = sum%10;
                     } else {
                        carry = 0;
                         l1->val +=1;
                       }
                } 
                l1 = l1->next;
            }
         return temp1;
    }
        return temp1;
    }
};
