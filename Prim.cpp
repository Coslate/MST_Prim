#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_map>
#include <Prim.h>

AdjList::~AdjList(){
    std::cout<<"It is AdjList destructor."<<std::endl;
}
void AdjList::SetAdjList(LinkedListNode* const head_node, LinkedListNode* const inserted_node, const int weight){
    LinkedList* lookup_head_linked_list = map_linked_list[head_node];
    LinkedList* lookup_inserted_linked_list = map_linked_list[inserted_node];
    if(lookup_head_linked_list == NULL){
        LinkedList* the_linked_list = new LinkedList();
        the_linked_list->InsertTail(weight, inserted_node->GetName());
        map_linked_list[head_node] = the_linked_list;
        collect_linked_list.push_back(the_linked_list);
    }else{
        LinkedList* the_linked_list = map_linked_list[head_node];
        the_linked_list->InsertTail(weight, inserted_node->GetName());
    }

    //The Adjacent List of an undirected graph is bi-directional, which is O(2E)
    if(lookup_inserted_linked_list == NULL){
        LinkedList* the_linked_list = new LinkedList();
        the_linked_list->InsertTail(weight, head_node->GetName());
        map_linked_list[inserted_node] = the_linked_list;
        collect_linked_list.push_back(the_linked_list);
    }else{
        LinkedList* the_linked_list = map_linked_list[inserted_node];
        the_linked_list->InsertTail(weight, head_node->GetName());
    }
}
void AdjList::PrintAdjList(LinkedListNode* const head_node, const bool debug_addr, const bool debug_name, const bool debug_key){
    LinkedList* the_linked_list = map_linked_list[head_node];
    if(the_linked_list != NULL){
        the_linked_list->PrintList(debug_addr, debug_name, debug_key);
    }else{
        std::cout<<"Warning : The head_node has no Adjacent List."<<std::endl;
    }
}
void Prim_Algorithm::InitialSet(Fibonacci_Heap &fib_heap_q, const std::vector<LinkedListNode*> &all_node, std::unordered_map<LinkedListNode*, FTNode*> &map_node_ll2ft){
    for(size_t i=0;i<all_node.size();++i){
        LinkedListNode* inserted_node_ll = all_node[i];
        FTNode* inserted_node_fib = map_node_ll2ft[inserted_node_ll];
        if(i==0){
            inserted_node_fib->SetKey(0);
        }
        fib_heap_q.InsertArbitrary(inserted_node_fib);
    }
}
