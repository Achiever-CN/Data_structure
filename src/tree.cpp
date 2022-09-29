#include "../include/tree.h"

int main(void)
{
        Tree_list *root;
        // Tree_list_clue *clue_root;

        Tree tree(root);
        tree.show(root);
        tree.free_tree(root);
        return 0;
}

