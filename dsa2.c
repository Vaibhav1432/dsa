#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
   int data;
   int key;
   struct node *next;
};
struct node *head = NULL;
struct node *current = NULL;
void printList(){
   struct node *ptr = head;
   printf("\n[ ");
   while(ptr != NULL){        
      printf("(%d,%d) ",ptr->key,ptr->data);
      ptr = ptr->next;
   }
   printf(" ]");
}
void insertFirst(int key, int data){
   struct node *link = (struct node*) malloc(sizeof(struct node));
   link->key = key;
   link->data = data;
   link->next = head;
   head = link;
}
struct node* deleteFirst(){
   struct node *tempLink = head; 
   head = head->next;
   return tempLink;
}
bool isEmpty(){
   return head == NULL;
}
int length(){
   int length = 0;
   struct node *current;
   for(current = head; current!=NULL;
      current = current->next){
      length++;
   }
   return length;
}
struct node* find(int key){
   struct node* current = head;
   if(head == NULL){
      return NULL;
   }
   while(current->key != key){
      if(current->next == NULL){
         return NULL;
      } else {
         current = current->next;
      }
   }

   return current;
}
struct node* delete(int key){
   struct node* current = head;
   struct node* previous = NULL;
   if(head == NULL){
      return NULL;
   }
   while(current->key != key){
      if(current->next == NULL){
         return NULL;
      } else {

         previous = current;
         current = current->next;             
}
}
   if(current == head) {

      head = head->next;
   } else {
      previous->next = current->next;
   }
   return current;
}
