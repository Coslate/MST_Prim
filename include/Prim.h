#ifndef _PRIM_H_
#define _PRIM_H_
#include <cstdlib>
#include <vector>
#include <unordered_map>
#include <Fibonacci_Heap.h>
#include <Linked_List.h>

class AdjList : public LinkedListNode, public LinkedList{
    std::unordered_map<LinkedListNode*, LinkedList*> map_linked_list;
    std::vector<LinkedList*> collect_linked_list;

    public : 
        AdjList() : LinkedListNode(), LinkedList(){};
        ~AdjList();

        void               SetAdjList(LinkedListNode* const head_node, LinkedListNode* const inserted_node, const int weight);
        void               PrintAdjList(LinkedListNode* const head_node, const bool debug_addr = false, const bool debug_name = false, const bool debug_key = true);
        inline LinkedList* ReadAdjList(LinkedListNode* const head_node){return map_linked_list[head_node];};
};

namespace Prim_Algorithm{
    void InitialSet(Fibonacci_Heap &fib_heap_q, const std::vector<LinkedListNode*> &all_node, std::unordered_map<LinkedListNode*, FTNode*> &map_node_ll2ft);
}
#endif
