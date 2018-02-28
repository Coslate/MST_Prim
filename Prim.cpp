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
    map_weight[head_node][inserted_node] = weight;
//    std::cout<<"Insert : map_weight["<<head_node<<"]["<<inserted_node<<"] = "<<map_weight[head_node][inserted_node]<<std::endl;

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
    map_weight[inserted_node][head_node] = weight;
//    std::cout<<"Insert : map_weight["<<inserted_node<<"]["<<head_node<<"] = "<<map_weight[inserted_node][head_node]<<std::endl;
}
void AdjList::PrintAdjList(std::unordered_map<std::string, LinkedListNode*> &map_node_st2ll, LinkedListNode* const head_node, const bool debug_addr, const bool debug_name, const bool debug_key){
    int count = 0;
    LinkedList* the_linked_list = map_linked_list[head_node];
    if(the_linked_list != NULL){
        the_linked_list->PrintList(debug_addr, debug_name, debug_key);
    }else{
        std::cout<<"Warning : The head_node has no Adjacent List."<<std::endl;
    }

    LinkedListNode* current_node = the_linked_list->GetFristNode();
    while(current_node != NULL){
        if(count == 0){
            std::cout<<"map_weight["<<head_node->GetName()<<"] = ["<<map_weight[map_node_st2ll[head_node->GetName()]][map_node_st2ll[current_node->GetName()]]<<"("<<map_node_st2ll[head_node->GetName()]<<", "<<map_node_st2ll[current_node->GetName()]<<")"<<", ";
        }else if(count == the_linked_list->GetListSize()-1){
            std::cout<<map_weight[map_node_st2ll[head_node->GetName()]][map_node_st2ll[current_node->GetName()]]<<"("<<map_node_st2ll[head_node->GetName()]<<", "<<map_node_st2ll[current_node->GetName()]<<")"<<"]"<<std::endl;
        }else{
            std::cout<<map_weight[map_node_st2ll[head_node->GetName()]][map_node_st2ll[current_node->GetName()]]<<"("<<map_node_st2ll[head_node->GetName()]<<", "<<map_node_st2ll[current_node->GetName()]<<")"<<", ";
        }
        ++count;
        current_node = current_node->GetNext();
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
/*
void Prim_Algorithm::FindMST(Fibonacci_Heap &fib_heap_q, const std::vector<MST_Edge*> &final_mst, std::unordered_map<FTNode*, LinkedListNode*> &map_node_ft2ll, std::unordered_map<std::string, LinkedListNode*> &map_node_st2ll, const AdjList &adj_list){
    std::unordered_map<LinkedListNode*, std::unordered_map<LinkedListNode*, int>> map_weight = adj_list.ReadMapWeight();
    LinkedListNode* v0 = NULL;
    while(fib_heap_q.GetTotalNodeNum() != 0){
        //Extractmin from the Fibonacci_Heap
        FTNode* min_ft_node = fib_heap_q.ExtractMin();
        LinkedListNode* min_ll_node = map_node_ft2ll[min_ft_node];

        //Get the weight of the edge;
        if(v0 == NULL){
            MST_Edge* inserted_edge = new MST_Edge(0, NULL, min_ll_node);
        }else{
            int edge_weight = map_weight[map_node_st2ll[v0->GetName()]][map_node_st2ll[min_ll_node->GetName()]];
            MST_Edge* inserted_edge = new MST_Edge(edge_weight, )
            
        }
        


        LinkedList* the_linked_list = adj_list.ReadAdjList(min_ll_node);
        LinkedListNode* current_node = the_linked_list->GetFristNode();
        while(current_node != NULL){
            current_node = current_node->GetNext();
        }
    }
}
*/
