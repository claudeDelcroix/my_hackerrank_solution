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

void printCurrentLevelOrder(struct node* root,int level){
    if(root == NULL){
        return;
    }
    if(level == 1){
        printf("%d ",root->data);
    }else if(level > 1){
        printCurrentLevelOrder(root->left,level - 1);
        printCurrentLevelOrder(root->right,level - 1);
    }
}

void levelOrder( struct node *root) {
    int h = height(root);
    for(int i = 1;i <= h;i++){
        printCurrentLevelOrder(root,i);
    }
}
