#include <iostream>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <vector>
#include <Prim.h>

int main(){
    bool debug_addr = true;
    bool debug_name = true;
    bool debug_key = true;
    
    //Declare a new adjacent list to represent Graph(V, E)
    AdjList a1;
    Fibonacci_Heap fib_heap_q;

    //Generate the Graph(V, E)
    LinkedListNode* node_a = new LinkedListNode(INT_MAX, "a");
    LinkedListNode* node_b = new LinkedListNode(INT_MAX, "b");
    LinkedListNode* node_h = new LinkedListNode(INT_MAX, "h");
    LinkedListNode* node_i = new LinkedListNode(INT_MAX, "i");
    LinkedListNode* node_c = new LinkedListNode(INT_MAX, "c");
    LinkedListNode* node_g = new LinkedListNode(INT_MAX, "g");
    LinkedListNode* node_f = new LinkedListNode(INT_MAX, "f");
    LinkedListNode* node_d = new LinkedListNode(INT_MAX, "d");
    LinkedListNode* node_e = new LinkedListNode(INT_MAX, "e");

    std::vector<LinkedListNode*> all_node;
    all_node.push_back(node_a);
    all_node.push_back(node_b);
    all_node.push_back(node_h);
    all_node.push_back(node_i);
    all_node.push_back(node_c);
    all_node.push_back(node_g);
    all_node.push_back(node_f);
    all_node.push_back(node_d);
    all_node.push_back(node_e);
    
    //Generate the correspondent Fibonacci Node.
    FTNode* node_a_fib = new FTNode(node_a->GetData());
    FTNode* node_b_fib = new FTNode(node_b->GetData());
    FTNode* node_h_fib = new FTNode(node_h->GetData());
    FTNode* node_i_fib = new FTNode(node_i->GetData());
    FTNode* node_c_fib = new FTNode(node_c->GetData());
    FTNode* node_g_fib = new FTNode(node_g->GetData());
    FTNode* node_f_fib = new FTNode(node_f->GetData());
    FTNode* node_d_fib = new FTNode(node_d->GetData());
    FTNode* node_e_fib = new FTNode(node_e->GetData());

    //Generate the correspondence between Fibonacci Node & LinkedListNode
    std::unordered_map<LinkedListNode*, FTNode*> map_node_ll2ft;
    std::unordered_map<FTNode*, LinkedListNode*> map_node_ft2ll;
    std::unordered_map<std::string, LinkedListNode*> map_node_st2ll;

    map_node_ll2ft[node_a] = node_a_fib;
    map_node_ll2ft[node_b] = node_b_fib;
    map_node_ll2ft[node_h] = node_h_fib;
    map_node_ll2ft[node_i] = node_i_fib;
    map_node_ll2ft[node_c] = node_c_fib;
    map_node_ll2ft[node_g] = node_g_fib;
    map_node_ll2ft[node_f] = node_f_fib;
    map_node_ll2ft[node_d] = node_d_fib;
    map_node_ll2ft[node_e] = node_e_fib;

    map_node_ft2ll[node_a_fib] = node_a;
    map_node_ft2ll[node_b_fib] = node_b;
    map_node_ft2ll[node_h_fib] = node_h;
    map_node_ft2ll[node_i_fib] = node_i;
    map_node_ft2ll[node_c_fib] = node_c;
    map_node_ft2ll[node_g_fib] = node_g;
    map_node_ft2ll[node_f_fib] = node_f;
    map_node_ft2ll[node_d_fib] = node_d;
    map_node_ft2ll[node_e_fib] = node_e;

    map_node_st2ll["a"] = node_a;
    map_node_st2ll["b"] = node_b;
    map_node_st2ll["h"] = node_h;
    map_node_st2ll["i"] = node_i;
    map_node_st2ll["c"] = node_g;
    map_node_st2ll["g"] = node_g;
    map_node_st2ll["f"] = node_f;
    map_node_st2ll["d"] = node_d;
    map_node_st2ll["e"] = node_e;

    std::cout<<"-----------------LinkedListNode-----------------"<<std::endl;
    std::cout<<"node_a = ("<<node_a->GetData()<<", "<<node_a<<")"<<std::endl;
    std::cout<<"node_b = ("<<node_b->GetData()<<", "<<node_b<<")"<<std::endl;
    std::cout<<"node_h = ("<<node_h->GetData()<<", "<<node_h<<")"<<std::endl;
    std::cout<<"node_i = ("<<node_i->GetData()<<", "<<node_i<<")"<<std::endl;
    std::cout<<"node_c = ("<<node_c->GetData()<<", "<<node_c<<")"<<std::endl;
    std::cout<<"node_g = ("<<node_g->GetData()<<", "<<node_g<<")"<<std::endl;
    std::cout<<"node_f = ("<<node_f->GetData()<<", "<<node_f<<")"<<std::endl;
    std::cout<<"node_d = ("<<node_d->GetData()<<", "<<node_d<<")"<<std::endl;
    std::cout<<"node_e = ("<<node_e->GetData()<<", "<<node_e<<")"<<std::endl;
    std::cout<<"----------------All node-----------------"<<std::endl;
    for(size_t i=0;i<all_node.size();++i){
        if(i == all_node.size()-1){
            std::cout<<all_node[i]->GetName()<<"]"<<std::endl;
        }else if(i == 0){
            std::cout<<"all_node = ["<<all_node[i]->GetName()<<", ";
        }else{
            std::cout<<all_node[i]->GetName()<<", ";
        }
    }

    std::cout<<"-----------------FTNode-----------------"<<std::endl;
    std::cout<<"node_a_fib = ("<<node_a_fib->GetKey()<<", "<<node_a_fib<<")"<<std::endl;
    std::cout<<"node_b_fib = ("<<node_b_fib->GetKey()<<", "<<node_b_fib<<")"<<std::endl;
    std::cout<<"node_h_fib = ("<<node_h_fib->GetKey()<<", "<<node_h_fib<<")"<<std::endl;
    std::cout<<"node_i_fib = ("<<node_i_fib->GetKey()<<", "<<node_i_fib<<")"<<std::endl;
    std::cout<<"node_c_fib = ("<<node_c_fib->GetKey()<<", "<<node_c_fib<<")"<<std::endl;
    std::cout<<"node_g_fib = ("<<node_g_fib->GetKey()<<", "<<node_g_fib<<")"<<std::endl;
    std::cout<<"node_f_fib = ("<<node_f_fib->GetKey()<<", "<<node_f_fib<<")"<<std::endl;
    std::cout<<"node_d_fib = ("<<node_d_fib->GetKey()<<", "<<node_d_fib<<")"<<std::endl;
    std::cout<<"node_e_fib = ("<<node_e_fib->GetKey()<<", "<<node_e_fib<<")"<<std::endl;

    std::cout<<"-----------------map_node_ll2ft-----------------"<<std::endl;
    std::cout<<"map_node_ll2ft["<<node_a<<"] = ("<<map_node_ll2ft[node_a]->GetKey()<<", "<<map_node_ll2ft[node_a]<<")"<<std::endl;
    std::cout<<"map_node_ll2ft["<<node_b<<"] = ("<<map_node_ll2ft[node_b]->GetKey()<<", "<<map_node_ll2ft[node_b]<<")"<<std::endl;
    std::cout<<"map_node_ll2ft["<<node_h<<"] = ("<<map_node_ll2ft[node_h]->GetKey()<<", "<<map_node_ll2ft[node_h]<<")"<<std::endl;
    std::cout<<"map_node_ll2ft["<<node_i<<"] = ("<<map_node_ll2ft[node_i]->GetKey()<<", "<<map_node_ll2ft[node_i]<<")"<<std::endl;
    std::cout<<"map_node_ll2ft["<<node_c<<"] = ("<<map_node_ll2ft[node_c]->GetKey()<<", "<<map_node_ll2ft[node_c]<<")"<<std::endl;
    std::cout<<"map_node_ll2ft["<<node_g<<"] = ("<<map_node_ll2ft[node_g]->GetKey()<<", "<<map_node_ll2ft[node_g]<<")"<<std::endl;
    std::cout<<"map_node_ll2ft["<<node_f<<"] = ("<<map_node_ll2ft[node_f]->GetKey()<<", "<<map_node_ll2ft[node_f]<<")"<<std::endl;
    std::cout<<"map_node_ll2ft["<<node_d<<"] = ("<<map_node_ll2ft[node_d]->GetKey()<<", "<<map_node_ll2ft[node_d]<<")"<<std::endl;
    std::cout<<"map_node_ll2ft["<<node_e<<"] = ("<<map_node_ll2ft[node_e]->GetKey()<<", "<<map_node_ll2ft[node_e]<<")"<<std::endl;

    std::cout<<"-----------------map_node_ft2ll-----------------"<<std::endl;
    std::cout<<"map_node_ft2ll["<<node_a_fib<<"] = ("<<map_node_ft2ll[node_a_fib]->GetData()<<", "<<map_node_ft2ll[node_a_fib]<<")"<<std::endl;
    std::cout<<"map_node_ft2ll["<<node_b_fib<<"] = ("<<map_node_ft2ll[node_b_fib]->GetData()<<", "<<map_node_ft2ll[node_b_fib]<<")"<<std::endl;
    std::cout<<"map_node_ft2ll["<<node_h_fib<<"] = ("<<map_node_ft2ll[node_h_fib]->GetData()<<", "<<map_node_ft2ll[node_h_fib]<<")"<<std::endl;
    std::cout<<"map_node_ft2ll["<<node_i_fib<<"] = ("<<map_node_ft2ll[node_i_fib]->GetData()<<", "<<map_node_ft2ll[node_i_fib]<<")"<<std::endl;
    std::cout<<"map_node_ft2ll["<<node_c_fib<<"] = ("<<map_node_ft2ll[node_c_fib]->GetData()<<", "<<map_node_ft2ll[node_c_fib]<<")"<<std::endl;
    std::cout<<"map_node_ft2ll["<<node_g_fib<<"] = ("<<map_node_ft2ll[node_g_fib]->GetData()<<", "<<map_node_ft2ll[node_g_fib]<<")"<<std::endl;
    std::cout<<"map_node_ft2ll["<<node_f_fib<<"] = ("<<map_node_ft2ll[node_f_fib]->GetData()<<", "<<map_node_ft2ll[node_f_fib]<<")"<<std::endl;
    std::cout<<"map_node_ft2ll["<<node_d_fib<<"] = ("<<map_node_ft2ll[node_d_fib]->GetData()<<", "<<map_node_ft2ll[node_d_fib]<<")"<<std::endl;
    std::cout<<"map_node_ft2ll["<<node_e_fib<<"] = ("<<map_node_ft2ll[node_e_fib]->GetData()<<", "<<map_node_ft2ll[node_e_fib]<<")"<<std::endl;

    std::cout<<"-----------------map_node_st2ll-----------------"<<std::endl;
    std::cout<<"map_node_st2ll[a] = ("<<map_node_st2ll["a"]->GetData()<<", "<<map_node_st2ll["a"]<<")"<<std::endl;
    std::cout<<"map_node_st2ll[b] = ("<<map_node_st2ll["b"]->GetData()<<", "<<map_node_st2ll["b"]<<")"<<std::endl;
    std::cout<<"map_node_st2ll[h] = ("<<map_node_st2ll["h"]->GetData()<<", "<<map_node_st2ll["h"]<<")"<<std::endl;
    std::cout<<"map_node_st2ll[i] = ("<<map_node_st2ll["i"]->GetData()<<", "<<map_node_st2ll["i"]<<")"<<std::endl;
    std::cout<<"map_node_st2ll[c] = ("<<map_node_st2ll["c"]->GetData()<<", "<<map_node_st2ll["c"]<<")"<<std::endl;
    std::cout<<"map_node_st2ll[g] = ("<<map_node_st2ll["g"]->GetData()<<", "<<map_node_st2ll["g"]<<")"<<std::endl;
    std::cout<<"map_node_st2ll[f] = ("<<map_node_st2ll["f"]->GetData()<<", "<<map_node_st2ll["f"]<<")"<<std::endl;
    std::cout<<"map_node_st2ll[d] = ("<<map_node_st2ll["d"]->GetData()<<", "<<map_node_st2ll["d"]<<")"<<std::endl;
    std::cout<<"map_node_st2ll[e] = ("<<map_node_st2ll["e"]->GetData()<<", "<<map_node_st2ll["e"]<<")"<<std::endl;

    std::cout<<"-----------------Set Adjacent List of Graph(V, E)-----------------"<<std::endl;
    a1.SetAdjList(node_a, node_b, 4);
    a1.SetAdjList(node_a, node_h, 8);
    a1.SetAdjList(node_b, node_c, 8);
    a1.SetAdjList(node_b, node_h, 11);
    a1.SetAdjList(node_h, node_g, 1);
    a1.SetAdjList(node_h, node_i, 7);
    a1.SetAdjList(node_g, node_f, 2);
    a1.SetAdjList(node_g, node_i, 6);
    a1.SetAdjList(node_c, node_i, 2);
    a1.SetAdjList(node_c, node_d, 7);
    a1.SetAdjList(node_c, node_f, 4);
    a1.SetAdjList(node_f, node_d, 14);
    a1.SetAdjList(node_f, node_e, 10);
    a1.SetAdjList(node_d, node_e, 9);
    std::cout<<"-----------------AdjList::PrintAdjList, node_a-----------------"<<std::endl;
    a1.PrintAdjList(node_a, debug_addr, debug_name, debug_key);
    std::cout<<"-----------------AdjList::PrintAdjList, node_b-----------------"<<std::endl;
    a1.PrintAdjList(node_b, debug_addr, debug_name, debug_key);
    std::cout<<"-----------------AdjList::PrintAdjList, node_h-----------------"<<std::endl;
    a1.PrintAdjList(node_h, debug_addr, debug_name, debug_key);
    std::cout<<"-----------------AdjList::PrintAdjList, node_c-----------------"<<std::endl;
    a1.PrintAdjList(node_c, debug_addr, debug_name, debug_key);
    std::cout<<"-----------------AdjList::PrintAdjList, node_i-----------------"<<std::endl;
    a1.PrintAdjList(node_i, debug_addr, debug_name, debug_key);
    std::cout<<"-----------------AdjList::PrintAdjList, node_g-----------------"<<std::endl;
    a1.PrintAdjList(node_g, debug_addr, debug_name, debug_key);
    std::cout<<"-----------------AdjList::PrintAdjList, node_d-----------------"<<std::endl;
    a1.PrintAdjList(node_d, debug_addr, debug_name, debug_key);
    std::cout<<"-----------------AdjList::PrintAdjList, node_e-----------------"<<std::endl;
    a1.PrintAdjList(node_e, debug_addr, debug_name, debug_key);
    std::cout<<"-----------------AdjList::PrintAdjList, node_f-----------------"<<std::endl;
    a1.PrintAdjList(node_f, debug_addr, debug_name, debug_key);

    
    std::cout<<"-----------------Prim_Algorithm::InitialSet-----------------"<<std::endl;
    Prim_Algorithm::InitialSet(fib_heap_q, all_node, map_node_ll2ft);
    fib_heap_q.Traverse();



    return EXIT_SUCCESS;
}
