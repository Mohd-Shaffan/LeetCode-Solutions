class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack<int> st;
        queue<int> q;
        for(int i=sandwiches.size()-1;i>=0;i--){
            st.push(sandwiches[i]);
        }
        for(int i=0;i<students.size();i++){
            q.push(students[i]);
        }
        int count=0;
        while(!q.empty()){
            if(st.top()==q.front()){
                q.pop();
                st.pop();
                count=0;
            }else{
                q.push(q.front());
                q.pop();
                count++;
            }
            if(count==q.size()) break;
        }
    
        return q.size();
        
    }
};