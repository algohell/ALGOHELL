int activityNotifications(vector<int> expenditure, int d) {
    int cnt = 0;
    float sum = accumulate(expenditure.begin(), expenditure.begin() + d, 0);
    for (int i = d; i < expenditure.size(); ++i) {
        int curr = expenditure[i];
        if (curr >= sum / d * 2.0) ++cnt;
        sum = sum - expenditure[i-d] + curr;
    }
    return cnt;
}