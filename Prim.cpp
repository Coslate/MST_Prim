#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_map>
#include <Prim.h>

AdjList::~AdjList(){
    std::cout<<"It is AdjList destructor."<<std::endl;
}
void AdjList::SetAdjList(LinkedListNode* const head_node, LinkedListNode* const inserted_node){
    LinkedList* lookup_linked_list = map_linked_list[head_node];
    if(lookup_linked_list == NULL){
        LinkedList* the_linked_list = new LinkedList();
        the_linked_list->InsertFront(inserted_node);
        map_linked_list[head_node] = the_linked_list; 
    }else{
        LinkedList* the_linked_list = map_linked_list[head_node];
        the_linked_list->InsertFront(inserted_node);
    }
}
