class Solution {
public:
    set<int> visited;
    map<int, vector<int>> courses;

    bool dfs(int course) {
        // Course not found in courses for some reason
        if (courses.find(course) == courses.end()) {
            return false;
        }
        // Loop detected
        if (visited.count(course) > 0 && courses[course].size() > 0) {
            return false;
        }

        visited.insert(course);

        // No prereqs
        if (courses[course].empty()) {
            return true;
        }

        for (int i = 0; i < courses[course].size(); ++i) {
            if(!dfs(courses[course][i]))
                return false;
        }

        // At this point I can clear prereqs for this course
        courses[course].clear();

        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        bool res = true;

        // Set courses set to default values (all courses having no prereqs)
        for (int i = 0; i < numCourses; ++i)
            courses[i] = vector<int>();

        // Set courses according to their prereqs
        for (int i = 0; i < prerequisites.size(); ++i) {
            courses[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        // Call dfs() for each course
        for (int i = 0; i < prerequisites.size(); ++i) {
            if (!dfs(prerequisites[i][0]))
                return false;
        }

        return res;
    }
};