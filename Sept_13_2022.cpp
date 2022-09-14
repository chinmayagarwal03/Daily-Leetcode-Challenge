class Solution {
public:
    bool validUtf8(vector<int>& data) {
               int i = 0;
        int factor = 0;
        while(i<data.size()){
            if(data[i] <= 127 && data[i]>=0 && factor == 0){
                factor = 0;
            }else if(data[i] >= 192 && data[i] <= 223 && factor == 0){
                factor = 1;
            }else if(data[i] >= 224 && data[i] <= 239 && factor == 0){
                factor = 2;
            }else if(data[i]>=240 && data[i] <= 247 && factor == 0){
                factor = 3;
            }else if(data[i]>=128 && data[i] <= 191){
                factor--;
            }else{
                return false;
            }
            i++;
        }
        if(factor == 0) return true;
        else return false;
    }
};
