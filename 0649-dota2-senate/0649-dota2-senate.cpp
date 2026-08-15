class Solution {
public:
    string predictPartyVictory(string str) {
        queue<int> s;
        queue<int> r;
        queue<int> d;
        for(int i=0;i<str.size();i++){
            s.push(i);
            if(str[i]=='R') r.push(i);
            else d.push(i);     
        }

        while(s.size()>=1){
            if(str[s.front()]=='X') {
                s.pop();
                continue;
            }
            if(str[s.front()]=='R'){
                if(d.size()==0) return "Radiant";
                else{
                    str[d.front()]='X';
                    s.push(s.front());
                    s.pop();
                    r.push(r.front());
                    r.pop();
                    d.pop();
                }
            }else{
                if(r.size()==0) return "Dire";
                else{
                    str[r.front()]='X';
                    r.pop();
                    s.push(s.front());
                    s.pop();
                    d.push(d.front());
                    d.pop();
                }
                
            }
        }
        if(str[s.front()]=='D') return "Dire";
        return "Dire";
        
    }
};