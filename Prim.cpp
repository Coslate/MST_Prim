#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_map>
#include <Prim.h>

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
bool Prim_Algorithm::CheckIsTheEdge(std::unordered_map<LinkedListNode*, std::unordered_map<LinkedListNode*, int>> &map_weight, LinkedListNode* const candidate_parent, const int &edge_weight, LinkedListNode* const min_ll_node, std::unordered_map<LinkedListNode*, FTNode*> map_node_ll2ft){
    if((map_weight[candidate_parent].find(min_ll_node) != map_weight[candidate_parent].end()) && (edge_weight == map_node_ll2ft[min_ll_node]->GetKey())){
        return true;
    }else{
        return false;
    }
}
void Prim_Algorithm::FindMST(Fibonacci_Heap &fib_heap_q, std::vector<MST_Edge*> &final_mst, std::unordered_map<FTNode*, LinkedListNode*> &map_node_ft2ll, std::unordered_map<std::string, LinkedListNode*> &map_node_st2ll, std::unordered_map<LinkedListNode*, FTNode*> map_node_ll2ft, AdjList &adj_list){
    std::unordered_map<LinkedListNode*, std::unordered_map<LinkedListNode*, int>> map_weight = adj_list.ReadMapWeight();

    while(fib_heap_q.GetTotalNodeNum() != 0){
        //Extractmin from the Fibonacci_Heap
        FTNode* min_ft_node = fib_heap_q.ExtractMin();
        LinkedListNode* min_ll_node = map_node_ft2ll[min_ft_node];

        //Inserted the MST edge to final_mst
        if(final_mst.size() == 0){
            MST_Edge* inserted_edge = new MST_Edge(NULL, min_ll_node, 0);
            final_mst.push_back(inserted_edge);
        }else{
            for(std::vector<MST_Edge*>::reverse_iterator i = final_mst.rbegin(); i!=final_mst.rend(); ++i){
                LinkedListNode* candidate_parent = (*i)->RetEdgeB();
                int edge_weight = map_weight[candidate_parent][min_ll_node];
                if(CheckIsTheEdge(map_weight, candidate_parent, edge_weight, min_ll_node, map_node_ll2ft)){
                    MST_Edge* inserted_edge = new MST_Edge(candidate_parent, min_ll_node, edge_weight);
                    final_mst.push_back(inserted_edge);
                    break;
                }
            }
        }
        
        if(fib_heap_q.GetTotalNodeNum() != 0){
            //Decrease all the adjacent node with the value of edge weight
            LinkedList* the_linked_list = adj_list.ReadAdjList(min_ll_node);
            LinkedListNode* current_node = the_linked_list->GetFristNode();
            while(current_node != NULL){
                LinkedListNode* node_to_decrease_ll = map_node_st2ll[current_node->GetName()];
                FTNode* node_to_decrease = map_node_ll2ft[node_to_decrease_ll];
                fib_heap_q.DecreaseKey(node_to_decrease, map_weight[min_ll_node][node_to_decrease_ll]);
                current_node = current_node->GetNext();
            }
        }
    }
}
void Prim_Algorithm::PrintMST(const std::vector<MST_Edge*> &final_mst, const int print_width){
    int min_edge = 0;
    std::cout<<"MST : "<<std::endl;
    for(size_t i=0;i<final_mst.size();++i){
        LinkedListNode* start_node = final_mst[i]->RetEdgeA();
        LinkedListNode* end_node = final_mst[i]->RetEdgeB();
        int edge_weight = final_mst[i]->RetWeight();

        if(start_node == NULL){
            printf("(%*s --> %*s, weight = %*d)\n", print_width,  "NULL", print_width, end_node->GetName().c_str(), print_width, edge_weight);
        }else{
            printf("(%*s --> %*s, weight = %*d)\n", print_width, start_node->GetName().c_str(), print_width, end_node->GetName().c_str(), print_width, edge_weight);
        }
        min_edge += edge_weight;
    }
    printf("minimum total edge weight = %d\n", min_edge);
}
void Prim_Algorithm::Release(std::vector<MST_Edge*> &final_mst){
    while (!final_mst.empty()){
        MST_Edge* edge_to_delete = final_mst.back();
        final_mst.pop_back();
        delete edge_to_delete;
    }
}
