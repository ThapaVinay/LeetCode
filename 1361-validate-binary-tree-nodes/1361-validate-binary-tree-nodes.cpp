class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        
        vector <int> check(n,0);
        
        for(int i=0; i<n; i++)
        {
            if(leftChild[i] != -1)
                check[leftChild[i]] = 1;
            
            if(rightChild[i] != -1)
                check[rightChild[i]] = 1;
        }
        
        int count = 0;
        int value = 0;
        for(int i=0; i<n; i++)
        {
            if(check[i] == 0)
            {
                value = check[i];
                count ++;

            }
                
        }
        
        if(count > 1)
            return false;
        
        queue <int> q;
        q.push(value);
        set <int> st;
        
        while(!q.empty())
        {
            int a = q.front();
            q.pop();
            
            if(st.find(a) != st.end())
            {
                return false;
            }
            st.insert(a);
            
            if(leftChild[a] != -1)
            {
                q.push(leftChild[a]);
            } 
            
            if(rightChild[a] != -1)
            {
                q.push(rightChild[a]);
            }   
        }
        
        return true;
    }
};