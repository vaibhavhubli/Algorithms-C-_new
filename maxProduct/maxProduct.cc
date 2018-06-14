/*
	Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

	Example 1:

	Input: ["abcw","baz","foo","bar","xtfn","abcdef"]
	Output: 16 
	Explanation: The two words can be "abcw", "xtfn".
	Example 2:

	Input: ["a","ab","abc","d","cd","bcd","abcd"]
	Output: 4 
	Explanation: The two words can be "ab", "cd".
	Example 3:

	Input: ["a","aa","aaa","aaaa"]
	Output: 0 
	Explanation: No such pair of words.
	
	https://leetcode.com/problems/maximum-product-of-word-lengths/description/
	
	*/

class Solution {
public:
    int maxProduct(vector<string>& words) {
        
        vector<int> charArr(words.size(), 0);
        
        for (int i = 0; i < words.size(); i++) {
            string w = words[i];
            for (int j = 0; j < w.size(); j++) {
                charArr[i] |= (1 << w[j] - 'a');
            }
        }
        
        int maxProd = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if ( (charArr[i] & charArr[j]) == 0) {
                    maxProd = max(maxProd, (int)(words[i].size() * words[j].size()));
                }
            }
        }
        
        return maxProd;
    }
};