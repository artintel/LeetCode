class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        bool status = true;
        for(int i = 0; i < flowerbed.size(); i++){
            if(flowerbed[i] == 0){
                if(status == false) status = true;
                else if(status == true){
                    if(i + 1 < flowerbed.size() && flowerbed[i + 1] == 0){
                        count++;
                        i++;
                    }
                    else if (i + 1 >= flowerbed.size()){
                        count++;
                        break;
                    }
                }
            }
            else if(status == true) status = false;
        }
        return count >= n ? true : false;
    }
};