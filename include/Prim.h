#ifndef _PRIM_H_
#define _PRIM_H_
#include <cstdlib>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <Fibonacci_Heap.h>
#include <Linked_List.h>
#include <AdjList.h>

class MST_Edge{
    LinkedListNode* edge_a;
    LinkedListNode* edge_b;
    int weight;

    public : 
        MST_Edge() : edge_a(NULL), edge_b(NULL), weight(0){};
        MST_Edge(const int weight_val) : edge_a(NULL), edge_b(NULL), weight(weight_val){};
        MST_Edge(LinkedListNode* const a_node, LinkedListNode* const b_node, const int weight_val) : edge_a(a_node), edge_b(b_node), weight(weight_val){};
        ~MST_Edge(){std::cout<<"It is MST_Edge destructor."<<std::endl;edge_a = NULL;edge_b = NULL;weight = 0;};

        inline void            SetEdgeA(LinkedListNode* const a_node){edge_a = a_node;};
        inline void            SetEdgeB(LinkedListNode* const b_node){edge_b = b_node;};
        inline void            SetWeight(const int weight_val){weight = weight_val;};
        inline LinkedListNode* RetEdgeA(){return edge_a;};
        inline LinkedListNode* RetEdgeB(){return edge_b;};
        inline int             RetWeight(){return weight;};
};

namespace Prim_Algorithm{
    void InitialSet(Fibonacci_Heap &fib_heap_q, const std::vector<LinkedListNode*> &all_node, std::unordered_map<LinkedListNode*, FTNode*> &map_node_ll2ft);
    bool CheckIsTheEdge(std::unordered_map<LinkedListNode*, std::unordered_map<LinkedListNode*, int>> &map_weight, LinkedListNode* const candidate_parent, const int &edge_weight, LinkedListNode* const min_ll_node, std::unordered_map<LinkedListNode*, FTNode*> map_node_ll2ft);
    void FindMST(Fibonacci_Heap &fib_heap_q, std::vector<MST_Edge*> &final_mst, std::unordered_map<FTNode*, LinkedListNode*> &map_node_ft2ll, std::unordered_map<std::string, LinkedListNode*> &map_node_st2ll, std::unordered_map<LinkedListNode*, FTNode*> map_node_ll2ft, AdjList &adj_list);
    void PrintMST(const std::vector<MST_Edge*> &final_mst, const int print_width);
    void Release(std::vector<MST_Edge*> &final_mst);
}
#endif
