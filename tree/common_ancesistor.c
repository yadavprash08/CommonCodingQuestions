// Finding the Lowest Common Ancestor for the node
typedef struct tree_node{
	int value;
	tree_node* left;
	tree_node* right;
}tree_node;

// This is when we assume that there are not duplicate in the tree.
tree_node* lowest_ancestor(tree_node*, int, int);

tree_node* lowest_ancestor(tree_node* root, int val1, int val2){
	int val1_found=0, val2_found =0;
	return search_elements(root, val1, val2, &val1_found, &val2_found);
}

tree_node* search_elements(tree_node* root, int val1, int val2, int *found1, int *found2){
	if(NULL == root){ return NULL;}
	if((0 == (val1_found+val2_found)) && (root->value == val1 || root->value == val2)){ return root; }
	
	tree_node* result;

	result = search_elements(root->left, val1, val2, &val1_found, &val2_found);
	if(NULL != result){
		return result;
	}
	result = search_elements(root->right, val1, val2, &val1_found, &val2_found);
	if(NULL != result){
		return result;
	}
	if(2 == val1_found+val2_found){
		return root;
	}
	return NULL;
}
