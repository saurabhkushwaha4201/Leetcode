class TaskManager {
    unordered_map<int, pair<int, int>> taskMap; // taskId -> (userId, priority)
    priority_queue<tuple<int, int, int>> maxHeap; // (priority, taskId, userId)

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto& task : tasks) {
            int userId = task[0], taskId = task[1], priority = task[2];
            taskMap[taskId] = {userId, priority};
            maxHeap.push({priority, taskId, userId});
        }
    }

    void add(int userId, int taskId, int priority) {
        taskMap[taskId] = {userId, priority};
        maxHeap.push({priority, taskId, userId});
    }

    void edit(int taskId, int newPriority) {
        if (taskMap.find(taskId) != taskMap.end()) {
            int userId = taskMap[taskId].first;
            taskMap[taskId].second = newPriority;
            maxHeap.push({newPriority, taskId, userId});
        }
    }

    void rmv(int taskId) {
        taskMap.erase(taskId);
    }

    int execTop() {
        while (!maxHeap.empty()) {
            auto [priority, taskId, userId] = maxHeap.top();
            maxHeap.pop();
            if (taskMap.find(taskId) != taskMap.end() && taskMap[taskId].second == priority) {
                taskMap.erase(taskId);
                return userId;
            }
        }
        return -1;
    }
};


/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
