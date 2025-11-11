/* Structure of Node used
struct Node
{
    int coeff;
    int pow;
    struct Node* next;

    Node(int c, int p){
        coeff = c;
        pow = p;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node *addPolynomial(Node *head1, Node *head2) {
        if (!head1) return head2;
        if (!head2) return head1;

        Node* newHead = NULL;
        Node* tail_head1 = NULL;;
        while(head1 && head2){
            if(head1->pow > head2->pow){
                if(!newHead)newHead = head1;
                tail_head1 = head1;
                head1 = head1->next;
            }
            else if(head2->pow > head1->pow){
                Node* temp = head2;
                head2 = head2->next;
                temp->next = head1;
                
                if (tail_head1) tail_head1->next = temp;
                tail_head1 = temp;

                if(!newHead)newHead = temp;
            }
            else{
                head1->coeff += head2->coeff;
                if(!newHead)newHead = head1;
                tail_head1 = head1;
                head1 = head1->next;
                head2 = head2->next;
            }
        }
        if (head2 != NULL) {
            if (tail_head1)
                tail_head1->next = head2;
}
        return newHead;
    }
};
