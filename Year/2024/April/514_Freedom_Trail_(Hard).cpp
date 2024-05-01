class Solution {
public:

    // int getMinFreedomTrail(string& ring, string& key, int& size, vector<int>& result, vector<bool>& visited, int ringInd, int keyInd){
    //     if(keyInd == key.size()){
    //         return 1;
    //     }
    //     if(result[ringInd] != -1){
    //         return result[ringInd];
    //     }
    //     visited[ringInd] = true;
    //     int left = 0;
    //     int right = 0; 
    //     for(int leftInd = (ringInd+1)%size ; leftInd != ringInd ; leftInd = (leftInd+1)%size){
    //         ++left;
    //         if(ring[leftInd] == key[keyInd] && !visited[leftInd]){
    //             left += getMinFreedomTrail(ring, key, size, result, visited, leftInd, keyInd+1); 
    //             break;
    //         }
    //     }
    //     for(int rightInd = ringInd-1 ; rightInd != ringInd ; --rightInd){
    //         if(rightInd < 0){
    //             rightInd = size-1;
    //         }
    //         ++right;
    //         if(ring[rightInd] == key[keyInd] && !visited[rightInd]){
    //             right += getMinFreedomTrail(ring, key, size, result, visited, rightInd, keyInd+1);
    //             break;
    //         }
    //     }
    //     visited[ringInd] = false;
    //     return result[ringInd] = 1 + min(left, right);
    // }

    // int findRotateSteps(string ring, string key) {
    //     int size = ring.size();
    //     vector<int> result(size, -1);
    //     vector<bool> visited(size, 0);
    //     int left , right;
    //     for(left = 0 ; left < size && ring[left] != key[0] ; ++left){};
    //     for(right = size-1 ; right >= 0 && ring[right] != key[01] ; --right){};
    //     left = 1 + getMinFreedomTrail(ring, key, size, result, visited, left, 1);
    //     right = 1 + getMinFreedomTrail(ring, key, size, result, visited, right, 1);
    //     return min(left,right);
    // }

    int findRotateSteps(string ring, string key) {
        vector<int> pos[26];
        int r = ring.size(), k = key.size();
        for(int i=0;i<r;i++) pos[ring[i]-'a'].push_back(i);
        vector<int> pre(r), cur(r,INT_MAX), *p_pre = &pre, *p_cur = &cur;
        for(int i=k-1;i>=0;i--) {
            for(int j=0;j<r;j++)
                for(int nxt:pos[key[i]-'a']) {
                    int dist = abs(j-nxt);
                    (*p_cur)[j]=min((*p_cur)[j],min(dist,r-dist)+(*p_pre)[nxt]);
                }
            swap(p_pre,p_cur);
            p_cur->assign(r,INT_MAX);
        }
        return (*p_pre)[0]+k;
    }
};