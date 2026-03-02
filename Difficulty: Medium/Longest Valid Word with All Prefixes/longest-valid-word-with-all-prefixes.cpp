struct Node{
    Node* links[26]; 
    bool flag = false;

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

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag; 
    }
};

class Trie {
private:
    Node* root;

public:
    Trie(){
        root = new Node();
    }
    
    void insert(string word){
        Node* node = root;
        for(char ch : word){
            if(!node->containsKey(ch))
                node->put(ch, new Node());
            node = node->get(ch);
        }
        node->setEnd();
    }
    
    bool checkIfPrefixExists(string word){
        Node* node = root;
        for(char ch : word){
            if(node->containsKey(ch)){
                node = node->get(ch);
                if(node->isEnd() == false)
                    return false;
            }
            else{
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    string longestValidWord(vector<string>& words) {
        
        Trie trie;

        for(auto &it : words)
            trie.insert(it);
            
        string longest = "";
        
        for(auto &it : words){
            if(trie.checkIfPrefixExists(it)){
                
                if(it.length() > longest.length()){
                    longest = it;
                }
                else if(it.length() == longest.length() && it < longest){
                    longest = it;
                }
            }
        }

        if(longest == " ")
            return "None";

        return longest;
    }
};