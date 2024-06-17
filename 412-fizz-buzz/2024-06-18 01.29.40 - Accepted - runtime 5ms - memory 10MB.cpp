class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answer;
        string y;
        for (int i=1;i<=n;i++){
            if (i%15==0){
                y="FizzBuzz";
                answer.push_back(y);
            }
            else if(i%3==0){
                y="Fizz";
                answer.push_back(y);
            }
            else if(i%5==0){
                y="Buzz";
                answer.push_back(y);
            }
            else{
                answer.push_back(to_string(i));
            }
        }
        return answer;
    }
};