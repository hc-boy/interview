#include<stdio.h>
#include<stdlib.h>
struct TreeNode {
      char val;
      struct TreeNode *left;
      struct TreeNode *right;
};
struct TreeNode* buildTree(char* preorder, int preorderSize, char* inorder, int inorderSize){
    if(preorderSize == 0 || inorderSize == 0)
        return NULL;
    
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    int index;
    root -> val = preorder[0];
    for(index = 0;index < inorderSize;index++)
        if(inorder[index] == preorder[0])
            break;
    root -> left = buildTree(preorder + 1,index,inorder,index);
    root -> right = buildTree(preorder + index + 1,preorderSize - index - 1,inorder + index + 1,preorderSize - index - 1);
    return root;
}
 void tra(struct TreeNode* root, int* returnSize, char* ans){
    if(root==NULL)return;
    
    tra(root->left,returnSize,ans);
    
    tra(root->right,returnSize,ans);

    ans[(*returnSize)++]=root->val;
}
char* postorderTraversal(struct TreeNode* root, int* returnSize){
    (*returnSize)=0;
    int* ans= malloc(sizeof(char)*30);
    tra(root, returnSize,ans);
    return ans;
}
int main(){
    int n;
    char* inorder="ABC";
    char* preorder="BAC";
    n=3
    struct TreeNode* root = buildTree(preorder,n,inorder,n);
    int size;
    char* ans=postorderTraversal(root,&size);
    print("%s\n",ans);

}
