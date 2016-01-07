class Solution {
public:
    vector<int> dot;
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        int len = s.size();
        if(len < 4 && len > 12) return res;
        int point = 1;
        int cur = 1;
        for(int i = 0; i < 5; i++)dot.push_back(0);
        while(point < 4){
            while(cur < len){
                if(vaild(cur,point,len,s)){
                    dot[point] = cur;
                    cur ++;
                    break;
                }
                else{
                    if(cur - dot[point-1] > 3){
                       //point --;
                       //cur = dot[point] + 1;
                       break;
                    }
                    else cur ++;
                }
            }
            if(dot[point] == 0){
                if(point == 1) break;
                else{
                    point --;
                    cur = dot[point] + 1;
					dot[point] = 0;
                    continue;
                }
            }
            if(point == 3 && dot[point] != 0){
                point = 1;
                string temp;
                for(int i = 0;i < len;){
                    if(dot[point] == i){
                        temp += "."; 
						point ++;
                    }
                    else{
                        temp += s[i];
                        i++;
                    }
                }
				point --;
                res.push_back(temp);
                cur = dot[point] + 1;
                dot[point] = 0;
                //point --;
                continue;
            }
            point ++;
        }
        return res;
    }
private:
    bool vaild(int cur,int point,int len,string s){
        if(cur - dot[point - 1] > 3) return false;
        if(len - cur > 3*(4 - point) ||(len - cur) < (4 - point)) return false;
        string temp = s.substr(dot[point - 1],cur - dot[point - 1]);
        int num = atoi(temp.c_str());
        if(num < 0 || num > 255) return false;
        if(cur - dot[point - 1] > 1 && s[dot[point-1]] == '0') return false;
        if(point == 3 && len - cur > 1 && s[cur] == '0') return false;
        if(point == 3){
            string temp = s.substr(cur);
            int num = atoi(temp.c_str());
            if(num < 0 || num > 255) return false;  
        }
        return true;
    }
};