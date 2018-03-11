#ifndef _PRIM_H_
#define _PRIM_H_
#include <cstdlib>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <Fibonacci_Heap.h>
#include <Linked_List.h>
#include <AdjList.h>
#include <MST_Edge.h>

namespace Prim_Algorithm{
    void InitialSet(Fibonacci_Heap &fib_heap_q, const std::vector<LinkedListNode*> &all_node, std::unordered_map<LinkedListNode*, FTNode*> &map_node_ll2ft);
    bool CheckIsTheEdge(std::unordered_map<LinkedListNode*, std::unordered_map<LinkedListNode*, int>> &map_weight, LinkedListNode* const candidate_parent, const int &edge_weight, LinkedListNode* const min_ll_node, std::unordered_map<LinkedListNode*, FTNode*> map_node_ll2ft);
    void FindMST(Fibonacci_Heap &fib_heap_q, std::vector<MST_Edge*> &final_mst, std::unordered_map<FTNode*, LinkedListNode*> &map_node_ft2ll, std::unordered_map<std::string, LinkedListNode*> &map_node_st2ll, std::unordered_map<LinkedListNode*, FTNode*> map_node_ll2ft, AdjList &adj_list);
    void PrintMST(const std::vector<MST_Edge*> &final_mst, const int print_width);
    void Release(std::vector<MST_Edge*> &final_mst);
}
#endif
