ListNode *swapPairs(ListNode *head) {
        
        //NULL
        if(head == NULL)
            return head;

        ListNode *p1 = head, *p2 = p1->next, *temp, *prev;
        while(p2 != NULL){
            
            //change head
            if(p1 == head)
                head = p2;
                
            //swap node pair
            temp = p2->next;
            p2->next = p1;
            p1->next = temp;
            prev = p1;
            
            //iterate
            p1 = temp;
            if(p1 == NULL)
                break;
            else 
                p2 = p1->next;
            if(p2 != NULL)
                prev->next = p2;
        }
        return head;
    }
