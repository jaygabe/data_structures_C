/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */

/**
 * Encodes a tree to a single string.
 *
 * @param {TreeNode} root
 * @return {string}
 */
var serialize = function(root) {
    
};

/**
 * Decodes your encoded data to tree.
 *
 * @param {string} data
 * @return {TreeNode}
 */
var deserialize = function(data) {
    
};

/**
 * Your functions will be called as such:
 * deserialize(serialize(root));
 */

// Solutions

// 1) Level-order traversal


// 2) Preorder Traversal


// 3) Recursive


// 4) 13-bit encoding for each node


// 5) Iterators


// 6) stringify and parse


// 7) BFS and DFS


// 8) Global Index

/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */

/**
 * Encodes a tree to a single string.
 *
 * @param {TreeNode} root
 * @return {string}
 */
var serialize = function(root) {
    let result = [];

    function serializeHelper(root) {
        if (!root) return result.push('null');
        result.push(root.val);
        serializeHelper(root.left);
        serializeHelper(root.right);
    }

    serializeHelper(root);
    return result.join(',');
};

/**
 * Decodes your encoded data to tree.
 *
 * @param {string} data
 * @return {TreeNode}
 */
var deserialize = function(data) {
    let arr = data.split(',');
    let index = 0;

    function deserializeHelper() {
        if (index === arr.length || arr[index] === 'null') return null;
        let node = new TreeNode(arr[index]);
        index++;
        node.left = deserializeHelper();
        index++;
        node.right = deserializeHelper();
        return node;
    }

    return deserializeHelper();
};