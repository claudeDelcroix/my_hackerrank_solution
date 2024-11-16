struct node *lca( struct node *root, int v1, int v2 ) {
    while(root != NULL){
        if(v1 < root->data && v2 < root->data){
            root = root->left;
        }else if(v1 > root->data && v2 > root->data){
            root = root->right;
        }else{
            break;
        }
    }
    return root;
}
