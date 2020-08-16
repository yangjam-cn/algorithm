//#include"list_link.c"
#include"list_clink.h"
int main(void)
{
    cl_list list = init_clist();
    int i = 0;
    for (i = 0; i < 3; i++) {
        add_node(list);
    }
    print_clist(list);
    delete_clist(list);
    return 0;
}