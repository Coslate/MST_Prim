#ifndef _PRIM_H_
#define _PRIM_H_
#include <cstdlib>
#include <vector>
#include <unordered_map>
#include <Fibonacci_Heap.h>
#include <Linked_List.h>

class AdjList : public LinkedListNode, public LinkedList{
    int total_list_size;
    std::unordered_map<LinkedListNode*, LinkedList*> map_linked_list;
    std::vector<LinkedList*> collect_linked_list;

    public : 
        AdjList() : LinkedListNode(), LinkedList(){};
        ~AdjList();

        void SetAdjList(LinkedListNode* const head_node, LinkedListNode* const inserted_node);
};

#endif
