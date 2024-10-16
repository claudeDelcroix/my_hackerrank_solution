int height(struct node* root){
    if(root == NULL){
        return 0;
    }else{
        const int leftHeight = height(root->left);
        const int rightHeight = height(root->right);
        if(leftHeight > rightHeight){
            return (leftHeight + 1);
        }else{
            return (rightHeight + 1);
        }
    }
}
