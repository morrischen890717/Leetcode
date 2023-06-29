class Course {
public: 
    int id;
    bool tested, visited; // if tested == true, then no cycle for this course ans its prerequisite courses, if tested == false and visited == true, then there comes a cycle
    vector<Course*> pre;
    Course(int id){
        this->id = id;
        tested = visited = false;
    }
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // using topological sort based on DFS (this solution can be a template of topological sort) 
        vector<int> ans;
        vector<Course*> courses(numCourses);
        for(int i = 0; i < numCourses; i++){
            courses[i] = new Course(i);
        }
        for(vector<int>& prerequisite: prerequisites){
            courses[prerequisite[0]]->pre.push_back(courses[prerequisite[1]]);
        }
        for(int i = 0; i < numCourses; i++){
            if(isCyclic(courses[i], ans))
                return {};
        }
        return ans;
    }

    bool isCyclic(Course* cur, vector<int>& ans){
        if(cur->tested)
            return false;
        if(cur->visited)
            return true;
        cur->visited = true;
        for(Course* preCourse: cur->pre){
            if(isCyclic(preCourse, ans))
                return true;
        }
        ans.push_back(cur->id);
        cur->tested = true;
        return false;
    }
};