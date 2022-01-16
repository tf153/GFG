// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
    Node * findmid(Node *head){
        if(head==NULL || head->next==NULL)
            return head;
        Node *fastptr=head;
        Node *slowptr=head;
        while(fastptr && fastptr->next){
            fastptr=fastptr->next->next;
            if(fastptr)
                slowptr=slowptr->next;
        }
        return slowptr;
    }
    Node *merge(Node *head1,Node *head2){
        if(!head1 && head2)
            return head2;
        if(!head2 && head1)
            return head1;
        Node *result=NULL;
        Node *curr=NULL;
        Node *ptr1=head1;
        Node *ptr2=head2;
        while(ptr1 && ptr2){
            if(ptr1->data<=ptr2->data){
                if(!result){
                    result=ptr1;
                    curr=ptr1;
                }
                else{
                    curr->next=ptr1;
                    curr=curr->next;
                }
                ptr1=ptr1->next;
            }
            else{
                if(!result){
                    result=ptr2;
                    curr=ptr2;
                }
                else{
                    curr->next=ptr2;
                    curr=curr->next;
                }
                ptr2=ptr2->next;
            }
        }
        while(ptr1){
            curr->next=ptr1;
            curr=curr->next;
            ptr1=ptr1->next;
        }
        while(ptr2){
            curr->next=ptr2;
            curr=curr->next;
            ptr2=ptr2->next;
        }
        if(!ptr1 && !ptr2)
            curr->next=NULL;
        return result;
    }
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        if(head && !head->next)
            return head;
        if(head && head->next){
            Node *mid=findmid(head);
            Node *head1=(mid!=NULL) ? (mid->next): NULL;
            mid->next=NULL;
            head=mergeSort(head);
            head1=mergeSort(head1);
            return merge(head,head1);
        }
    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends