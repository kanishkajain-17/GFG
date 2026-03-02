struct Node{
    Node* links[26]; 

    Node(){
        for(int i = 0; i < 26; i++)
            links[i] = NULL;
    }

    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }
};
class Solution {
  public:
    int countSubs(string& s) {
        
        int count = 0;
        Node* root = new Node();
        for(int i = 0; i < s.size(); i++){
            Node * node = root;
            for(int j = i; j < s.size(); j++){
                if(!node->containsKey(s[j])){
                    count++;
                    node->put(s[j], new Node());
                }
                node = node->get(s[j]);
            }
        }
        return count;
        
    }
};