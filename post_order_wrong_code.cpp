void postOrderIterative(tree_node* root) 
 
    if (root == NULL) 
        return; 
  
    // Create two stacks 
    stack<tree_node *> s1, s2; 
   
  
    // push root to first stack 
    s1.push(root); 
    tree_node* node; 
  
    // Run while first stack is not empty 
    while (s1.is_empty() != -1) { 
        // Pop an item from s1 and push it to s2 
        node = s1.peek(); 
        s1.pop(); 
        s2.push(node); 
  
        // Push left and right children 
        // of removed item to s1 
        if (node->left) 
            s1.push(node->left); 
        if (node->right) 
            s1.push(node->right); 
    } 
  
    // Print all elements of second stack 
    while (s2.is_empty() != -1 ){ 
        node = s2.peek(); 
        s2.pop(); 
        cout << node->info << " "; 
    } 
 