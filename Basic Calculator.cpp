class Solution {
public:

 int calculate(string s) {
   int num = 0;
   char sign = '+';
   stack<int> stack; 
   for(int i = 0; i < s.size(); i++) {
     char c = s[i];
     if (isdigit(c)) {
       num = num * 10 + (c - '0');
     }
     if(!isdigit(c) && c != ' ' || i == s.size() - 1) {
       if (sign == '+') {
         stack.push(num);
       } else if (sign == '-') {
         stack.push(-num);
       } else if (sign == '*') {
         int t = stack.top();
         stack.pop();
         stack.push(t * num);
       } else if (sign == '/') {
         int t = stack.top();
         stack.pop();
         stack.push(t / num);
       }
       sign = c;
       num = 0;
     }
   }
   int result = 0;
   while(!stack.empty()) {
     result += stack.top();
     stack.pop();
   }
   return result;
 }
};
