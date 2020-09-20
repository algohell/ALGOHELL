class Solution
{
public:
	static bool compare(pair<int, int> a, pair<int, int> b)
	{
		if (a.first == b.first)
		{
			return a.second < b.second;
		}
		return a.first < b.first;
	}

	int getStep(int num, unordered_map<int, int> &steps)
	{
		if (steps[num])
		{
			return steps[num];
		}
		if (num == 1)
		{
			return 0;
		}

		int pv = num % 2 == 0 ? num / 2 : num * 3 + 1;

		int step = getStep(pv, steps) + 1;
		steps[num] = step;

		return step;
	}

	int getKth(int lo, int hi, int k)
	{
		vector<pair<int, int>> ans;
		unordered_map<int, int> steps;

		for (int i = lo; i <= hi; ++i)
		{
			int pv = getStep(i, steps);

			ans.push_back(make_pair(pv, i));
		}

		sort(ans.begin(), ans.end(), compare);

		return ans[k - 1].second;
	}
};
