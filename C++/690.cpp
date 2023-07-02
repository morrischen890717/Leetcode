/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/


class Solution {
public:
    int dfs(vector<Employee*>& employees, vector<int>& pos, Employee* cur){
        int sum = cur->importance;
        for(int subordinate: cur->subordinates){
            sum += dfs(employees, pos, employees[pos[subordinate]]);
        }
        return sum;
    }
    int getImportance(vector<Employee*> employees, int id) {
        int n = employees.size();
        vector<int> pos(2001, -1); // pos[i] stands for the index in employees of the employee whose id = i
        for(int i = 0; i < n; i++){
            pos[employees[i]->id] = i;
        }
        return dfs(employees, pos, employees[pos[id]]);
    }
};